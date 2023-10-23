#ifndef LINEAR_SORTING_H
#define LINEAR_SORTING_H

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <limits.h>
#include <stdlib.h>

#define FORMAT_SPECIFIER PRIdLEAST32
#define MAX_ARRAY_LENGTH INT32_MAX
#define MAX_ARRAY_VALUE INT32_MAX

typedef int_least32_t array_t;
typedef int_least32_t length_array_t;

/*
 * A function for finding the number with the most digits in an array.
 * @param array - An array in which to search for the number with the most digits.
 * @param size - Length of the array.
 * @return The number of digits in the largest number in the array.
 * */
static int_least8_t getMaxDigits(const array_t* array, length_array_t size);

/*
 * A function that implements the counting sort algorithm.
 * @param array - Array that we are sorting.
 * @param size - Length of the array.
 * @param place - The position of the digit relative to which we are sorting the array where 1 mean LSD.
 * */
static void countingSort(array_t* array, length_array_t size, array_t place);

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