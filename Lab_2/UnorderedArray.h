//#pragma once
//#include <cassert>
//
//template<class T>
//class UnorderedArray
//{
//public:
//	// Constructor
//	UnorderedArray(int size, int growBy = 1) :
//		m_Array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0)
//	{
//		if(size)
//		{
//			m_maxSize = size;
//			m_Array = new T[m_maxSize]; // Dynamically allocating an array to m_maxSize.
//			memset(m_Array, 0, sizeof(T) * m_maxSize); // Explicitly allocating memory based on the type T.
//
//			m_growSize = ((growBy > 0) ? growBy : 0);
//		}
//	}
//	// Destructor
//	~UnorderedArray()
//	{
//		if(m_Array != NULL)
//		{
//			delete[] m_Array;
//			m_Array = NULL;
//		}
//	}
//	// Insertions
//	// Fast insertion of UnorderedArray -- Big-O is 0(1)
//	void Push(T val)
//	{
//		assert(m_Array != NULL);  // Debugging purposes.
//		if (m_numElements >= m_maxSize)
//		{
//			// Expand();
//		}
//
//		// My array has space for the new value.
//		m_Array[m_numElements] = val;
//		m_numElements++;
//	}
//	// Deletions (2 ways)
//	// Remove the last item inserted into the array.
//	void Pop()
//	{
//		if(m_numElements > 0)
//		{
//			m_numElements--;
//		}
//	}
//	// Remove an item given an index value.
//	// (Almost) Brute-Force excution -- Big-O = O(N).
//	void Remove(int index)
//	{
//		assert(m_Array != NULL);
//
//		if (index >= m_numElements)
//		{
//			return;
//		}
//
//		for (int i = index; i < m_numElements; i++)
//		{
//			if(i + 1 < m_numElements)
//			{
//				m_Array[i] = m_Array[i + 1];
//			}
//		}
//		m_numElements--;
//	}
//	// Searching (Linear search) -- Big 0 =
//	int Search(T val)
//	{
//		assert(m_Array != NULL);
//
//		// Brute-force search.
//		for (int i = 0; i < m_numElements; i++)
//		{
//			if(m_Array[i] == val)
//			{
//				return i;
//			}
//		}
//
//		return -1;
//	}
//	// Overload the [] operator
//	T& operator[](int index)
//	{
//		assert(m_Array != NULL && index < m_numElements);
//		return m_Array[index];
//	}
//	// Clear - Big O = 0(1)
//	void Clear()
//	{
//		m_numElements = 0;
//	}
//	// Gets and Sets
//	int GetSize()
//	{
//		return m_numElements;
//	}
//	int GetMaxSize()
//	{
//		return m_maxSize;
//	}
//	int GetGrowSize()
//	{
//		return m_growSize;
//	}
//	void SetGrowSize(int val)
//	{
//		assert(val >= 0);
//		m_growSize = val;
//	}
//private:
//	// Expansion
//	bool Expand()
//	{
//		if(m_growSize <= 0)
//		{
//			return false;
//		}
//
//		// Create a new array.
//		T* temp = new T[m_maxSize + m_growSize];
//		assert(temp != NULL);
//		
//		// Copy the contents of the original array to the new array.
//		memcpy(temp, m_Array, sizeof(T) * m_maxSize);
//
//		// Delete the old array.
//		delete[] m_Array;
//
//		// Clean up variable assignments.
//		m_Array = temp;
//		temp = NULL;
//
//		m_maxSize += m_growSize;
//		return true;
//	}
//private:
//	// Variables
//	T* m_Array; // Pointer to the beginning of the array.
//
//	int m_maxSize; // Maximum size of my array.
//	int m_growSize; // Amount the array can grow.
//	int m_numElements; // Number of items currently in my array.
//};