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
                                7,  87, 250, 230,  99,   3, 100, 90};

  /* Other Variable Declarations Go Here */

  /* Statistics and Printing Functions Go Here */
  print_array(test, SIZE);
  sort_array(test, SIZE);									   // The original array is now SORTED!					
  print_statistics(test, SIZE);
}

/* Add other Implementation File Code Here */

void sort_array(unsigned char * ptr, unsigned int length) {
  int i,j;
  unsigned char temp;
  for(i = 0; i < length-1; i++){
    for(j = 0; j < length-i-1; j++){
      if(ptr[j] < ptr[j+1]){
        temp = ptr[j]; 
        ptr[j] = ptr[j+1];
	ptr[j+1] = temp;
      }
    }
  }

/**************** UNCOMMENT THE FOLLOWING BLOCK OF CODE TO PRINT THE SORTED ARRAY **********************/

/*printf("\nThe SORTED version (largest to smallest) of the given array elements with their corresponding indices are { element[index] } : \n");
  for(i=0; i < length; i++) {
    if(i==10 || i==20 || i==30)
      printf("\n");
    printf("%d[%d] ", ptr[i], i); 
  }*/

}

unsigned char find_maximum(unsigned char * ptr, unsigned int length) {
  unsigned char max;                                                   			          // Directly pick the first element of the array as it is already sorted!
  max = ptr[0];
  return max;
}

unsigned char find_minimum(unsigned char * ptr, unsigned int length) {
  unsigned char min;
  min = ptr[length-1];										  // Directly pick the last element of the array as it is already sorted!
  return min;
}

unsigned char find_mean(unsigned char * ptr, unsigned int length) {
  int i;
  float average=0;
  for(i = 0; i < length; i++){
    average += ptr[i];
  }
  average /= length;
  return average < 0 ? average - 0.5 : average + 0.5;                                             // Rounding to nearest integer
}

unsigned char find_median(unsigned char * ptr, unsigned int length) {
  float median;
  if(length % 2 == 0)
    median = (ptr[length/2] + ptr[(length-1)/2]) / 2;
  else
    median = ptr[length/2];
  return median < 0 ? median - 0.5 : median + 0.5;						  // Rounding to nearest integer
}

void print_statistics(unsigned char * ptr, unsigned int length) {
  printf("\n\n*********** The values for Mean and Median have been rounded off to the nearest integer ***********");
  printf("\n\nThe Minimum in the given array is : %d", find_minimum(ptr, length));
  printf("\nThe Maximum in the given array is : %d", find_maximum(ptr, length));
  printf("\nThe Mean of the given array is : %d", find_mean(ptr, length));
  printf("\nThe Median of the given array is : %d \n", find_median(ptr, length));
}


void print_array(unsigned char * ptr, unsigned int length) {
  printf("\nThe given array elements with their corresponding indices are { element[index] }: \n");
  int i;
  for(i = 0; i < length; i++) {
    if(i==10 || i==20 || i==30)
      printf("\n");
    printf("%d[%d] ", ptr[i], i);
  }
  printf("\n");
}
