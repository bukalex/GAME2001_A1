#pragma once

#include <cassert>
#include <math.h>

using namespace std;

template<class T>
class ArrayBase
{
protected:
	T* m_array;

	int m_maxSize;
	int m_numElements;

public:
	ArrayBase(int size) : m_array(NULL), m_maxSize(0), m_numElements(0)
	{
		if (size <= 0) size = 1;

		m_maxSize = pow(2, ceil(log2(size)));
		m_array = new T[m_maxSize];
		memset(m_array, 0, sizeof(T) * m_maxSize);

		cout << "Array created. m_maxSize = " << m_maxSize << endl;
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

	T& operator[](int index)
	{
		assert(m_array != nullptr && index < m_numElements);
		return m_array[index];
	}

protected:
	bool Expand()
	{
		T* temp = new T[m_maxSize * 2];
		assert(temp != nullptr);

		memcpy(temp, m_array, sizeof(T) * m_maxSize);

		delete[] m_array;

		m_array = temp;
		temp = nullptr;

		m_maxSize *= 2;

		cout << "Array expanded. m_maxSize = " << m_maxSize << endl;
		return true;
	}
};