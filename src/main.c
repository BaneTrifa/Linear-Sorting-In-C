/*  Branko Trifkovic RA49/2020
 *
 *  Task: Write a program that arranges the given array of integers in non-decreasing order using a linear complexity algorithm.
 *        Create a module from it and implement it as a static library. Include this library in the main program that will
 *        communicate with the environment.
 *
 *  Solution: As a solution to this task, I decided to implement the Radix sort algorithm.
 *            Radix sort works by sorting elements based on their digits, starting from the least significant digit.
 *            It's important to note that when sorting elements by digits, we need to use a stable sorting algorithm.
 *            In this case, I chose counting sort.
 *
 *            Time complexity: O(d * (n + k)), Space complexity: O(n + k).
 *              - 'd' -> number of digits in the largest number in the array,
 *              - 'n' -> number of elements in the array.
 *              - each digit can take on up to 'k' possible values
 * 
 *            It's important to mention that this algorithm (implementation) has limitations:
 *                  1. The array should contain only non-negative numbers.
 *                  2. In this implementation, it's expected that the largest value of an element is INT32_MAX (If there is a size that
 *                     can fit a 32-bit value.) and the maximum possible length of the array is INT32_MAX.
 *                     These limitations can be overcome by modifying certain variables in the linear_sorting.h file.
 *
 *  MISRA: Rules from the MISRA standard that have been violated:
 *         1. Rule 20.9 - The input/output library <stdio.h> shall not be used in production code. (printf, scanf)
 *         2. Rule 20.4 - Dynamic heap memory allocation shall not be used. (calloc)
 *         3. Rule 10.1 - The value of an expression of integer type shall not be implicitly converted to a different underlying type if it is not a 
 *                        conversion to a wider integer type of the same signedness
 *         4. Rule 20.12 - The time handling functions of library <time.h> shall not be used.
 *         5. Rule 17.4 - Array indexing shall be the only allowed form of pointer arithmetic.
 *         6. Rule 5.7 - No identifier name should be reused.
 *
 * */

#include <time.h>
#include "linear_sorting.h"

static void generateNumbers(array_t* array, length_array_t size);

int main(void) {

    array_t* array;
    length_array_t size = 120;

    /* User enters length of the array */
    #if 1 
        int_least64_t input_size;
        do{
            printf("Enter size of array (max. %d): ", MAX_ARRAY_LENGTH);
            scanf("%" SCNdLEAST64, &input_size);
            printf("\n");
        } while(input_size > MAX_ARRAY_LENGTH || input_size <= 0);

        size = (length_array_t) input_size;
    #endif

    /* Generate random numbers*/
    array = (array_t*) calloc(size, sizeof(array_t));
    generateNumbers(array, size);

    /* Sort array using radix sort */
    clock_t t = clock();
    radixSort(array, size);
    t = clock() - t; 

    /* Print sorted array and execution time*/
    printArray(array, size);
    printf("Took %lf seconds to execute \n", ((double)t)/CLOCKS_PER_SEC); 

    /* Free alocated memory */
    free(array);

    return 0;
}

static void generateNumbers(array_t* array, length_array_t size) {
    srand(time(0));

    for(length_array_t i = 0 ; i < size ; i++ ) {
        array[i] = MAX_ARRAY_VALUE / INT16_MAX * rand();;
    }
}
