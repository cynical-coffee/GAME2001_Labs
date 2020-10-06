#pragma once
#include <cassert>

template <class T>
class OrderedArray
{
public:
	// Constructor
	OrderedArray(int size, int growby = 1) : m_Array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0)
	{
		if (size)
		{
			m_maxSize = size;
			m_Array = new T[m_maxSize]; // Dynamically allocated new array.
			memset(m_Array, 0, sizeof(T) * m_maxSize);

			m_growSize = ((growby > 0) ? growby : 0);
		}
	}
	// Destructor
	~OrderedArray()
	{
		if(m_Array != NULL)
		{
			delete[] m_Array;
			m_Array = NULL;  // Good programming practice to set unused pointers to NULL.
		}
	}
	// Insertion - Big O = O(N)
	int Push(T val)
	{	
		assert(m_Array != Null);
		
		if(m_numElements >= m_maxSize)
		{
			//Expand();
		}

		int i, k;
		// Step 1: Find the index to insert val.
		for (i = 0; i < m_numElements; i++) 
		{
			if (m_Array[i] > val)
			{
				break;
			}
		}

		// Step 2: Shift everything to the right of the index forward by one.
		for (int k = m_numElements; k > i; k--) // Moving backwards through the array starting at m_numElements.
		{
			m_Array[k] = m_Array[k - 1];
		}
		
		// Step 3: Insert val into index.
		m_Array[i] = val;

		m_numElements++;

		return i;
	}
	
	// Deletion ( 2 methods)
	// Remove the last item in the array.
	void Pop()
	{
		if (m_numElements > 0)
		{
			m_numElements--;
		}
	}

	void Remove(int index)
	{
		assert(m_Array != NULL);

		if (index >= m_numElements)
		{
			return;
		}

		for (int i = index; i < m_numElements; i++)
		{
			if (i + 1 < m_numElements)
			{
				m_Array[i] = m_Array[i + 1];
			}
		}

		m_numElements--;
	}
	// Searching -- Binary Search -- Big O = O(log N)
	int Search(T searchKey)
	{
		assert(m_Array != NULL);

		// Helper variables.
		int lowerBound = 0;
		int upperBound = m_numElements - 1;
		int current = 0;

		while (1)   // <-- Replaced with recursion.
		{
			current = (lowerBound + upperBound) >> 1; // Preview of Bitwise operations. Divides by 2.

			// Binary search steps:
			// Step 1: Check if the middle is the value we are looking for.
			if (m_Array[current] == searchKey)
			{
				// Found the item in the middle of the array. return the index.
				return current;
			}
			// Step 2: Check that we've exhausted all option. Can't find the item.
			else if (lowerBound > upperBound)
			{
				return -1;
			}
			else
			{
				// Step 3: Check which half of the array the value is in.
				if ( m_Array[current] < searchKey)
				{
					lowerBound = current + 1;
				}
				else
				{
					upperBound = current - 1;
				}
			}
		}

		return -1;
	}
	// Overloaded [] operator
	const T& operator[](int index)
	{
		assert(m_Array != NULL && index < m_numElements);
		return m_Array[index];
	}
	// Clear
	void Clear()
	{
		m_numElements = 0;
	}
	// Gets and Sets
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
private:
	// Expand
	bool Expand()
	{
		if (m_growSize <= 0)
		{
			return false;
		}

		T* temp = new T[m_maxSize + m_growSize];
		assert(temp != NULL);

		memcpy(temp, m_Array, sizeof(T) * m_maxSize);

		delete[] m_Array;
		m_Array = temp;
		temp = NULL;

		return true;
	}
private:
	// Variables
	T* m_Array; // Pointer to the beginning of the array.

	int m_maxSize; // Maximum number of items the array can hold.
	int m_growSize; // How large will the array grow by.
	int m_numElements; // Number of items currently in the array.
};
