#include "sort.h"

/**
 * heap_sort - sorts an array ising a heapsort mathod
 * @array: the array
 * @size: the size of the array
 */
void heap_sort(int *array, size_t size)
{
    int end = (int)size;

    heapify(array, size);

    while (end > 1)
    {
        end = end - 1;

        swap(array, end, 0);
        print_array(array, size);

        shift_down(array, 0, end, size);
    }
}

/**
 * heapify - builds a heap in-place from an array
 * @array: the array
 * @size: the size of the array
 */
void heapify(int *array, size_t size)
{
    int start = ((int)size - 1) / 2 + 1;

    while (start > 0)
    {
        start = start - 1;

        shift_down(array, start, (int)size, size);
    }
}

/**
 * shift_down - shifts down the greatest value in a heap structure
 * @array: the array
 * @root: the element to shift down
 * @end: the end of the array to consider
 * @size: the size of the array
 */
void shift_down(int *array, int root, int end, size_t size)
{
    int child = 0;

    while (2 * root + 1 < end)
    {
        child = 2 * root + 1;

        if (child + 1 < end && array[child + 1] > array[child])
            child = child + 1;

        if (array[root] < array[child])
        {
            swap(array, root, child);
            print_array(array, size);

            root = child;
        }
        else
            break;
    }
}

/**
 * swap - swap two elements of an array
 * @array: the array
 * @i: the first element
 * @j: the second element
 */
void swap(int *array, int i, int j)
{
    int temp;

    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}
