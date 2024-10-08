#pragma once

#include "ArrayBase.h"

template<class T>
class OrderedArray : public ArrayBase<T>
{
private:
	bool m_allowDuplicateData;

public:
	OrderedArray(int size, bool allowDuplicateData = false) : ArrayBase<T>::ArrayBase(size) {}

	void push(T value) override
	{
		assert(this->m_array != nullptr);
		if (!m_allowDuplicateData && search(value) != -1) return;

		if (this->m_numElements >= this->m_maxSize)
		{
			this->Expand();
		}

		int i, k;
		for (i = 0; i < this->m_numElements; i++)
		{
			if (this->m_array[i] > value) break;
		}

		for (k = this->m_numElements; k > i; k--)
		{
			this->m_array[k] = this->m_array[k - 1];
		}

		this->m_array[i] = value;
		this->m_numElements++;
	}

	int search(T value) override
	{
		return binarySearch(value, 0, this->m_numElements - 1);
	}

private:
	int binarySearch(T value, int lowerBound, int upperBound)
	{
		assert(this->m_array != nullptr);
		assert(lowerBound >= 0);
		assert(upperBound < this->m_numElements);

		int current = (lowerBound + upperBound) >> 1;

		if (this->m_array[current] == value) return current;
		else if (lowerBound > upperBound) return -1;
		else
		{
			if (this->m_array[current] < value) return binarySearch(value, current + 1, upperBound);
			else return binarySearch(value, lowerBound, current - 1);
		}

		return -1;
	}
};