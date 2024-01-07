# Linear Sorting In C

## Description 

The goal of this project is to create a linear complexity algorithm that sorts non-negative integer values.

Linear complexity means that if the number of elements is increased by n, the execution time of the program will also increase by n.
More about time complexity you can read on this [link](https://www.freecodecamp.org/news/big-o-cheat-sheet-time-complexity-chart/).

## Implementation

As a solution to this task is used Radix sort algorithm.

Radix sort works by sorting elements based on their digits, starting from the least significant digit.
It's important to note that when sorting elements by digits, we need to use a stable sorting algorithm.
In this case, I chose counting sort.

<p align="center">
  <img width="711" alt="Screenshot 2024-01-07 151846" src="https://github.com/BaneTrifa/Linear-Sorting-In-C/assets/88882867/7f89f3c8-461a-439d-bc15-1ac2c80f7502">
</p>

Time complexity: O(d * (n + k)), Space complexity: O(n + k).
 - 'd' -> number of digits in the largest number in the array,
 - 'n' -> number of elements in the array.
 - each digit can take on up to 'k' possible values

It's important to mention that this algorithm (implementation) has limitations:

     1. The array should contain only non-negative numbers.
     
     2. In this implementation, it's expected that the largest value of an element is INT32_MAX (If there is a size that
        can fit a 32-bit value.) and the maximum possible length of the array is INT32_MAX.
        These limitations can be overcome by modifying certain variables in the linear_sorting.h file.

## Running


To run the program, follow these commands:

  1. Open the terminal in the /src/ directory and execute the compile.bat script.
  2. The compile.bat script will generate the main.exe file (for Windows). Proceed to execute main.exe.
     
After completing these two commands, the program will prompt you to enter the number of elements that the array will contain. The program will then generate these numbers and proceed to sort them.

## Time Complexity

The following table shows that the implemented algorithm has linear complexity:


| Number of elements | Execution time [sec] |
| --- | --- |
| 10.000 | 0.002 |
| 100.000 | 0.022000 |
| 1.000.000 | 0.227000 |
| 10.000.000 | 2.200000 |
| 100.000.000 | 22.425000 |


## Author

- [@BrankoTrifkovic](https://www.linkedin.com/in/branko-trifkovic/)
