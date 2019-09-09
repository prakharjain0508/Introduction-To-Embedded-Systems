/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.h 
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

#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief print_array
 *
 * This function takes a set of numbers (array) and prints that array
 * of the screen with the indices of each element of the array. 
 *
 * @param unsigned char * ptr: Pointer to a data set
 * @param unsigned int length: Number of items in data set
 *
 * @return NULL
 */
void print_array(unsigned char * ptr, unsigned int length);


/**
 * @brief sort_array
 *
 * This function takes a set of numbers (array) and it's length and sorts 
 * that array from largest to smallest. 
 *
 * @param unsigned char * ptr: Pointer to a data set
 * @param unsigned int length: Number of items in data set
 *
 * @return NULL
 */
void sort_array(unsigned char * ptr, unsigned int length);


/**
 * @brief find_maximum
 *
 * This function takes a set of numbers (array) and 
 * find the maximum of all the elements.
 *
 * @param unsigned char * ptr: Pointer to a data set
 * @param unsigned int length: Number of items in data set
 *
 * @return Maximum element in the array.
 */
unsigned char find_maximum(unsigned char * ptr, unsigned int length);


/**
 * @brief find_minimum
 *
 * This function takes a set of numbers (array) and 
 * find the minimum of all the elements.
 *
 * @param unsigned char * ptr: Pointer to a data set
 * @param unsigned int length: Number of items in data set
 *
 * @return Minimum element in the array.
 */
unsigned char find_minimum(unsigned char * ptr, unsigned int length);


/**
 * @brief find_mean
 *
 * This function takes a set of numbers (array) and 
 * finds the mean of the all elements of the array.
 *
 * @param unsigned char * ptr: Pointer to a data set
 * @param unsigned int length: Number of items in data set
 *
 * @return Mean of all the elements of the given array.
 */
unsigned char find_mean(unsigned char * ptr, unsigned int length);


/**
 * @brief find_median
 *
 * This function takes a set of numbers (array) and 
 * finds the median of the array.
 *
 * @param unsigned char * ptr: Pointer to a data set
 * @param unsigned int length: Number of items in data set
 *
 * @return Median of the given array.
 */
unsigned char find_median(unsigned char * ptr, unsigned int length);


/**
 * @brief print_statistics
 *
 * This function takes a set of numbers (array) and prints
 * the statistics of the array including minimum, maximum, mean, and median.
 *
 * @param unsigned char * ptr: Pointer to a data set
 * @param unsigned int length: Number of items in data set
 *
 * @return NULL
 */
void print_statistics(unsigned char * ptr, unsigned int length);

#endif /* __STATS_H__ */
