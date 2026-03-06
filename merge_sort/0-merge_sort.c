#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

static void merge_recursive(int *array, int *tmp, size_t size);

/**
 * merge_sort - sorts an array of integers in ascending order
 *               using the merge sort algorithm (top-down)
 * @array: pointer to the first element of the array to sort
 * @size: number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
    int *tmp;

    if (!array || size < 2)
        return;

    tmp = malloc(sizeof(int) * size);
    if (!tmp)
        return;

    merge_recursive(array, tmp, size);
    free(tmp);
}

/**
 * merge_recursive - helper that divides and merges subarrays
 * @array: pointer to current segment of the original array
 * @tmp:  pointer to temporary buffer of same total size
 * @size: length of the segment
 */
static void merge_recursive(int *array, int *tmp, size_t size)
{
    size_t left_size, right_size, i, j, k;

    if (size < 2)
        return;

    left_size = size / 2;
    right_size = size - left_size;

    /* sort left then right halves */
    merge_recursive(array, tmp, left_size);
    merge_recursive(array + left_size, tmp + left_size, right_size);

    /* print merging information */
    printf("Merging...\n");
    printf("[left]: ");
    print_array(array, left_size);
    printf("[right]: ");
    print_array(array + left_size, right_size);

    /* merge two sorted halves into tmp buffer */
    i = 0;
    j = 0;
    k = 0;
    while (i < left_size && j < right_size)
    {
        if (array[i] <= array[left_size + j])
            tmp[k++] = array[i++];
        else
            tmp[k++] = array[left_size + j++];
    }
    while (i < left_size)
        tmp[k++] = array[i++];
    while (j < right_size)
        tmp[k++] = array[left_size + j++];

    /* copy merged result back into original array segment */
    for (i = 0; i < size; i++)
        array[i] = tmp[i];

    /* print result of merge */
    printf("[Done]: ");
    print_array(array, size);
}
