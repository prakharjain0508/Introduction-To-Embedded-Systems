/**
 * @file data.c
 * @brief Convert data from a standard integer type into an ASCII string and vice-versa.
 *
 * @author Prakhar Jain
 * @date October 14 2020
 *
 */


#include "data.h"
#include "memory.h"
#include "platform.h"
#include <stdint.h>

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
  int32_t num = abs(data);
  uint8_t i=0;
  
  while(num){
    uint32_t rem = num % base;
    if(rem >= 10)
      *(ptr + i++) = 65 + (rem - 10);
    else
      *(ptr + i++) = 48 + rem;

    num = num / base;
  }
   
  if(i == 0)  			// if number is 0
    *(ptr + i++) = '0';  
  
  // If base is 10 and value is negative, the resulting string
  // is preceded with a minus sign (-)
  // With any other base, value is always considered unsigned
  if(data < 0 && base == 10)
    *(ptr + i++) = '-';
 
  *(ptr + i) = '\0';   // null terminate string

  my_reverse(ptr, i);   // reverse the string
  return i;

}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){ 
    int32_t result = 0; 
    int isPositive = 1; 
    // Initialize index of first digit 
    int i = 0; 
    int32_t value;
    // If number is negative, 
    // then update sign 
    if (*ptr == '-') { 
        isPositive = -1; 
        i++; 
    }
    // Iterate through all digits and update the result 
    for (; *(ptr+i) != '\0'; ++i){ 
	if(*(ptr+i) >= '0' && *(ptr+i) <= '9') 
  	   value = *(ptr+i) - '0';
	else
	   value = *(ptr+i) - 'A' + 10;
        result = (result * base) + value;
    }
  
    // Return result with sign 
    return isPositive * result; 
} 

