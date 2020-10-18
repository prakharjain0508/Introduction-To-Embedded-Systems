/**
 * @file data.h
 * @brief Some very basic data manipulation
 *
 * This header file does some very basic data 
 * manipulation via function calls. 
 *
 * @author Prakhar Jain
 * @date October 16 2020
 *
 */
#include<stdlib.h>
#include<stdint.h>

#ifndef __DATA_H__
#define __DATA_H__

/**
 * @brief Convert integer type into an ASCII string.
 *
 * Integer-to-ASCII converts data from
 * a standard integer type into an ASCII string.
 *
 * @param data Signed 32-bit integer
 * @param ptr Pointer passed in to store the converted ASCII string
 * @param base Base of ASCII string you wish to convert to
 *
 * @return Length of the converted data (including a negative sign).
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Converts ASCII string into an integer type.
 *
 * ASCII-to-Integer needs to convert data back from 
 * an ASCII represented string into an integer type.
 *
 * @param ptr Pointer to the character string to convert
 * @param digits The number of digits in your character set
 * @param base Base of ASCII string you wish to convert integer to
 *
 * @return void.
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
