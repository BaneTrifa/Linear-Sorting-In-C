#ifndef LINEAR_SORTING_H
#define LINEAR_SORTING_H

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <limits.h>
#include <stdlib.h>

#define FORMAT_SPECIFIER PRIdLEAST32
#define MAX_ARRAY_VALUE INT32_MAX
#define MAX_ARRAY_LENGTH INT32_MAX

typedef int_least32_t array_t;
typedef int_least32_t length_array_t;


/*
 * A function that implements the radix sort algorithm.
 * @param array - Array that we are sorting.
 * @param size - Length of the array.
 * */
void radixSort(array_t* array, length_array_t size);

/*
 * A function that implements the radix sort algorithm.
 * @param array - Array that we are printing.
 * @param size - Length of the array.
 * */
void printArray(array_t arr[], length_array_t size);


#endif