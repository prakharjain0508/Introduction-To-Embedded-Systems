/******************************************************************************
 * Copyright (C) 2019 by Prakhar Jain - Iowa State University
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Prakhar Jain and Iowa State University are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/*
 * @file stats.c 
 * @brief C-program that performs statistical analytics on a given dataset
 * 
 * A C-Program that exhibits a handful of basic c-programming
 * features to show how to calculate some statistics on a given set of numbers:
 *     -Maximum
 *     -Minimum
 *     -Sorting an array of numbers
 *     -Mean
 *     -Median
 *
 * @author Prakhar Jain
 * @date 6th Sept 2019
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

}

/* Add other Implementation File Code Here */

void sort_array(unsigned char * ptr, unsigned int length) {
  
}

unsigned char find_maximum(unsigned char * ptr, unsigned int length) {
  
}

unsigned char find_minimum(unsigned char * ptr, unsigned int length) {
  
}

unsigned char find_mean(unsigned char * ptr, unsigned int length) {
 
}

unsigned char find_median(unsigned char * ptr, unsigned int length) {
  
}

void print_statistics(unsigned char * ptr, unsigned int length) {
   
}


void print_array(unsigned char * ptr, unsigned int length) {
 
}
