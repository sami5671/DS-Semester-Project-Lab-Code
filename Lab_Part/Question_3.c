/*MAX HEAP TREE*/

#include <stdio.h>
#include <stdlib.h>

struct MaxHeap
{
    int *array;
    int size;
};

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(struct MaxHeap *maxHeap, int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < maxHeap->size && maxHeap->array[left] > maxHeap->array[largest])
    {
        largest = left;
    }

    if (right < maxHeap->size && maxHeap->array[right] > maxHeap->array[largest])
    {
        largest = right;
    }

    if (largest != index)
    {
        swap(&maxHeap->array[index], &maxHeap->array[largest]);
        maxHeapify(maxHeap, largest);
    }
}

struct MaxHeap *createMaxHeap(int *array, int size)
{
    struct MaxHeap *maxHeap = (struct MaxHeap *)malloc(sizeof(struct MaxHeap));
    maxHeap->array = array;
    maxHeap->size = size;

    for (int i = (maxHeap->size - 2) / 2; i >= 0; i--)
    {
        maxHeapify(maxHeap, i);
    }

    return maxHeap;
}

void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}

int main()
{
    int array[] = {25, 59, 19, 34, 44, 29, 38, 46, 8, 17, 22};
    int size = sizeof(array) / sizeof(array[0]);

    printf("Original array: ");
    printArray(array, size);

    struct MaxHeap *maxHeap = createMaxHeap(array, size);

    printf("Max heap: ");
    printArray(maxHeap->array, maxHeap->size);

    return 0;
}
