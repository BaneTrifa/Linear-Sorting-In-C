#include "linear_sorting.h"

static int_least8_t getMaxDigits(const array_t* array, length_array_t size) 
{
    array_t max = array[0];

    for (length_array_t i = 1; i < size; i++)
    {
        if (array[i] > max) 
        {
            max = array[i];
        }
    }

    int_least8_t digits = 0;
    while(max > 0)
    {
        max = max / 10;
        digits++;
    }

    return digits;
}

static void countingSort(array_t* array, length_array_t size, array_t place) 
{
    /* Output array */
    array_t* output = (array_t*) calloc(size, sizeof(array_t));

    /* Find max digit in place 'place' */
    array_t max = (array[0] / place) % 10;
    for (length_array_t i = 1; i < size; i++)
    {
        if ((array[i] / place) % 10 > max) 
        {
            max = (array[i] / place) % 10;
        }
    }

    /* Making counting array */
    length_array_t counting_array[max + 1];
    for (array_t i = 0; i <= max; i++) {
        counting_array[i] = 0;
    }

    /* Count frequency */
    for (length_array_t i = 0; i < size; i++)
    {
        array_t index = (array[i] / place) % 10;
        counting_array[index]++;
    }

    /* Cumulating sum */
    for (int_least8_t i = 1; i <= max; i++)
    {
        counting_array[i] += counting_array[i-1];
    }

    /* Sorting array by digit on place 'place' */
    for (length_array_t  i = size - 1; i >= 0; i--)
    {
        array_t index = (array[i] / place) % 10;
        output[counting_array[index] - 1] = array[i];
        counting_array[index]--;
    }

    for (length_array_t i = 0; i < size; i++) 
    {
        array[i] = output[i];
    }

    free(output);
}

void radixSort(array_t* array, length_array_t size) 
{
    int_least8_t max_digits = getMaxDigits(array, size);

    array_t place = 1;
    for (int_least8_t i = 0; i < max_digits ; i++)
    {
        countingSort(array, size, place);
        place *= 10;
    }
}

void printArray(array_t arr[], length_array_t size) 
{
    for (int i = 0; i < size; i++)
    {
        printf("%" FORMAT_SPECIFIER " ", arr[i]);
    }
    printf("\n");
}