#pragma once

#include "ArrayBase.h"

template<class T>
class UnorderedArray : public ArrayBase<T>
{
public:
	UnorderedArray(int size) : ArrayBase<T>::ArrayBase(size){}

	void push(T value) override
	{
		assert(this->m_array != nullptr);

		if (this->m_numElements >= this->m_maxSize)
		{
			this->Expand();
		}

		this->m_array[this->m_numElements] = value;
		this->m_numElements++;
	}

	int search(T value) override
	{
		assert(this->m_array != nullptr);

		for (int i = 0; i < this->m_numElements; i++)
		{
			if (this->m_array[i] == value) return i;
		}

		return -1;
	}
};