#pragma once

#include <cassert>

using namespace std;

template<class T>
class ArrayBase
{
protected:
	T* m_array;

	int m_maxSize;
	int m_growSize;
	int m_numElements;

public:
	ArrayBase(int size, int growBy = 1) : m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0)
	{
		if (size)
		{
			m_maxSize = size;
			m_array = new T[m_maxSize];
			memset(m_array, 0, sizeof(T) * m_maxSize);

			m_growSize = growBy > 0 ? growBy : 0;
		}
	}

	~ArrayBase()
	{
		if (m_array != nullptr)
		{
			delete[] m_array;
			m_array = nullptr;
		}
	}

	virtual void push(T value) = 0;
	virtual int search(T value) = 0;

	void pop()
	{
		if (m_numElements > 0)
		{
			m_numElements--;
		}
	}

	void remove(int index)
	{
		assert(m_array != nullptr);
		if (index >= m_numElements) return;

		for (int i = index; i < m_numElements; i++)
		{
			if (i + 1 < m_numElements)
			{
				m_array[i] = m_array[i + 1];
			}
		}

		m_numElements--;
	}

	void clear()
	{
		m_numElements = 0;
	}

	int GetSize()
	{
		return m_numElements;
	}

	int GetMaxSize()
	{
		return m_maxSize;
	}

	int GetGrowSize()
	{
		return m_growSize;
	}

	void SetGrowSize(int val)
	{
		assert(val >= 0);
		m_growSize = val;
	}

	T& operator[](int index)
	{
		assert(m_array != nullptr && index < m_numElements);
		return m_array[index];
	}

protected:
	bool Expand()
	{
		if (m_growSize <= 0) return false;

		T* temp = new T[m_maxSize + m_growSize];
		assert(temp != nullptr);

		memcpy(temp, m_array, sizeof(T) * m_maxSize);

		delete[] m_array;

		m_array = temp;
		temp = nullptr;

		m_maxSize += m_growSize;

		return true;
	}
};