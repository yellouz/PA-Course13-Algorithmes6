#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDynamicArray
{
private:
    int _Size = 0;
    T* TempArray;

public:
    T* OriginalArray;

    clsDynamicArray(int Size = 0)
    {
        if (Size < 0)
        {
            Size = 0;
        }

        _Size = Size;

        OriginalArray = new T[_Size];
    }

    ~clsDynamicArray()
    {
        delete[] OriginalArray;
    }

    bool SetItem(int index, T value)
    {
        if (index < 0 || index >= _Size)
        {
            return false;
        }

        OriginalArray[index] = value;
        return true;
        
    }

    int Size()
    {
        return _Size;
    }

    bool IsEmpty()
    {
        return _Size == 0;
    }

    void PrintList()
    {
        for (int i = 0; i < _Size; i++)
        {
            cout << OriginalArray[i] << " ";
        }

        cout << endl;

    }

    void Resize(int NewSize)
    {
        if (NewSize < 0)
            NewSize = 0;
        
        TempArray = new T[NewSize];
        
        if (NewSize < _Size)
            _Size = NewSize;

        for (int i = 0; i < _Size; i++)
        {
            TempArray[i] = OriginalArray[i];
        }

        _Size = NewSize;

        delete[] OriginalArray;
        OriginalArray = TempArray;
    }

    T GetItem(int index)
    {
        return OriginalArray[index];
    }

    void Clear()
    {
        _Size = 0;
        TempArray = new T[0];
        delete[] OriginalArray;
        OriginalArray = TempArray;
    }

    void Reverse()
    {
        TempArray = new T[_Size];

        int counter = 0;

        for (int i = _Size - 1; i >= 0; i--)
        {
            TempArray[counter] = OriginalArray[i];
            counter++;
        }
        
        delete[] OriginalArray;
        OriginalArray = TempArray;

    }

    bool DeleteItemAt(int index)
    {
        if(index < 0 || index > _Size - 1)
            return false;
        
        _Size = _Size - 1;
        TempArray = new T[_Size];

        int counter = 0;

        for (int i = 0; i <= _Size; i++)
        {
            if (i != index)
            {
                TempArray[counter] = OriginalArray[i];
                counter++;
            }
        }

        delete[] OriginalArray;
        OriginalArray = TempArray;
        return true;
    }

    void DeleteFirstItem()
    {
        DeleteItemAt(0);
    }

    void DeleteLastItem()
    {
        DeleteItemAt(_Size - 1);
    }

    int Find(T value)
    {
        for (int i = 0; i < _Size; i++)
        {
            if (OriginalArray[i] == value)
            {
                return i;
            }
        }
        
        return -1;
    }

    bool DeleteItem(T value)
    {
        int index = Find(value);

        if (index != -1)
        {
            DeleteItemAt(index);
            return true;
        }

        return false;
        
    }

    bool InsertAt(int index, T value)
    {
        if (index < 0 || index > _Size)
        {
            return false;
        }

        _Size++;
        TempArray = new T[_Size];

        for (int i = 0; i < index; i++)
        {
            TempArray[i] = OriginalArray[i];
        }
        
        TempArray[index] = value;

        for (int i = index; i < _Size; i++)
        {
            TempArray[i + 1] = OriginalArray[i];
        }
        
        // int counter = 0;
        // for (int i = 0; i < _Size; i++)
        // {
        //     if (i == index)
        //     {
        //         counter++;
        //     }

        //     TempArray[counter] = OriginalArray[i];
        //     counter++;
        // }

        // TempArray[index] = value;

        delete[] OriginalArray;
        OriginalArray = TempArray;
        return true;
    }

    void InsertAtBeginning(T value)
    {
        InsertAt(0, value);
    }

    void InsertAtEnd(T value)
    {
        InsertAt(_Size, value);
    }

    void InsertAfter(int index, T value)
    {
        InsertAt(index + 1, value);
    }

    void InsertBefore(int index, T value)
    {
        InsertAt(index , value);
    }
};