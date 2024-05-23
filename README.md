# Parallel Array Summation with OpenMP

This project demonstrates the use of OpenMP to perform parallel array summation in C++. The main goal is to calculate the sum of elements in an array using a parallel reduction approach, and then measure the number of tasks created during this process.

## Features
**Parallel Initialization**: Initializes an array of size 99,999 with all elements set to 1 using OpenMP.
**Ceil Log2 Calculation**: Computes the smallest power of 2 greater than or equal to the array size.
**Array Extension**: Extends the array to the next power of 2 length.
**Parallel Reduction**: Uses OpenMP tasks and dependencies to perform a tree-based reduction to sum the elements of the array.
**Task Counter**: Counts the total number of tasks created during the reduction process.

## Files

`task_test.cpp`: The task_test C++ file containing the implementation.
`README.md`: This file.

## Getting Started

### Prerequisites

A C++ compiler that supports C++11 (or later).
OpenMP support in your compiler.

### Compilation

To compile the program, use the following command:
```sh
g++ -fopenmp task_test.cpp -o parallel_sum
