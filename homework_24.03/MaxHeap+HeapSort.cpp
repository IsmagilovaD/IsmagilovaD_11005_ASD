#include <iostream>
using namespace std;

struct MaxHeap
{
    int size = -1;
    int MaxSize = 6;
    int* array = new int[MaxSize];

    static int Parent(int i) { return (i - 1) / 2; }
    static int LeftChild(int i) { return 2 * i + 1; }
    static int RightChild(int i) { return 2 * i + 2; }

    int GetMaxSize()
    {
        return MaxSize;
    }

    int GetSize()
    {
        return size;
    }

    int* GetArray()
    {
        return array;
    }

    void SiftUp(int i)
    {
        while( (i > 0) && (array[i] > array[Parent(i)]))
        {
            int help = array[i];
            array[i] = array[Parent(i)];
            array[Parent(i)] = help;
            i = Parent(i);
        }
    }

    void SiftDown(int i)
    {
        int maxIndex = i;
            if ((array[LeftChild(i)] > array[maxIndex]) && (LeftChild(i) <= size)) maxIndex = LeftChild(i);
            if ((array[RightChild(i)] > array[maxIndex]) && (RightChild(i) <= size)) maxIndex = RightChild(i);
            if (maxIndex != i) {
                int help = array[i];
                array[i] = array[maxIndex];
                array[maxIndex] = help;
                SiftDown(maxIndex);
            }
    }

    void Insert(int p)
    {
        if (size < MaxSize)
        {
            size++;
            array[size] = p;
            SiftUp(size);
        }
        else
        {
            cout << "Heap is full";
        }
    }

    int ExtractMax()
    {
        int result = array[0];
            array[0] = array[size];
            array[size] = NULL;
            size--;
            SiftDown(0);

        return result;
    }

    int GetMax()
    {
        return array[0];
    }

    void PrintAll()
    {
        for (int i = 0; i < size+1; i++)
        {
            cout << array[i]<<" ";
        }
    }

};

int * HeapSort(int * array, int size)
{
    MaxHeap* heap = new MaxHeap;
    for (int i = 0; i < size; i++)
    {
        heap->Insert(array[i]);
    }
    for (int i = 0; i < size; i++)
    {
        array[i] = heap->ExtractMax();
    }
    return array;
}

int main() {
    MaxHeap* heap = new MaxHeap;
    heap->Insert(7);
    heap->Insert(2);
    heap->Insert(5);
    heap->Insert(3);
    heap->Insert(12);
    heap->Insert(1);


    heap->PrintAll();

    cout << endl << heap->ExtractMax()<<endl;
    heap->PrintAll();
    cout << endl << heap->ExtractMax()<<endl;
    heap->PrintAll();
    cout << endl << heap->ExtractMax()<< endl;
    heap->PrintAll();
    cout << endl << heap->ExtractMax()<< endl;
    heap->PrintAll();
    cout << endl << heap->ExtractMax()<< endl;
    heap->PrintAll();

    cout << endl << "----------------------------" << endl;
    int* a = new int[6]{7,1,3,5,12,2};
    cout << "Array: ";
    for (int i = 0; i < 6; i++)
    {
        cout << a[i] << " ";
    }
    a = HeapSort(a,6);
    cout << endl << "Sorted array: ";
    for (int i = 0; i < 6; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
