#include <fstream>
#include "library.h"
#include <cassert>
#include <sstream>
#include <string>

template<typename T>
class Matrix
{
  public:
    Matrix()
    {
      size_t BOOK_QTY = 400; // change this for performance
      size_t initialCapacity = BOOK_QTY;
      std::ifstream file("books");
      // initiate array with that size
      ReAlloc(initialCapacity);
    }

    // Add element
    void PushBack(const T& value)
    {
      // if at/over capacity alloc more space
      if (m_Size >= m_Capacity){
        ReAlloc(m_Capacity + m_Capacity / 2);
      }
      // add new element to the end
      m_Data[m_Size] = value;
      m_Size++;
    }

    // Access data
    const T& operator[](size_t index) const {
      return m_Data[index];
    }

    T& operator[](size_t index){
      return m_Data[index];
    }

    // Size
    size_t GetSize() const { return m_Size; }

    // Remove last element
    void PopBack(int pos){
      T tmp;
      if (m_Size > 0)
      {
        for (int i = pos; i < m_Size; i++){
          tmp = m_Data[i];
          m_Data[i] = m_Data[i + 1];
          m_Data[i + 1] = tmp;
        }
        m_Size--;
        m_Data[m_Size].~T();
      }
    }


  private:
    // Dynamically allocate space
    void ReAlloc(size_t newCapacity)
    {
      // 1. allocate  a new block of memory
      T* newBlock = new T[newCapacity];
      if (newCapacity < m_Size)
        m_Size = newCapacity;
      // 2. move old elements to new block
      for (size_t i = 0; i < m_Size; i++)
        newBlock[i] = m_Data[i];
      // 3. delete old and point to new block
      delete[] m_Data;
      m_Data = newBlock;
      m_Capacity = newCapacity;
    }

  private:
    T* m_Data = nullptr;
    size_t m_Size = 0;
    size_t m_Capacity = 0;

};

