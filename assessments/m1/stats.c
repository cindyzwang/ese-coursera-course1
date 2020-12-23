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
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  print_statistics(test);
  return 0;
}

/* Add other Implementation File Code Here */
void print_statistics(unsigned char data[]) {
  double median = find_median(data, SIZE);
  double mean = find_mean(data, SIZE);
  int maximum = find_maximum(data, SIZE);
  int minimum = find_minimum(data, SIZE);
  printf("Median: %.2f\n", median);
  printf("Mean: %.2f\n", mean);
  printf("Minimum: %i\n", minimum);
  printf("Maximum: %i\n", maximum);
}

void print_array(unsigned char data[], int length) {
  for (int i = 0; i < length - 1; i++) {
    printf("%i, ", data[i]);
  }
  printf("%i\n", data[length - 1]);
}

int find_median(unsigned char data[], int length) {
  sort_array(data, length); // ensure the data is sorted
  unsigned char is_odd = length % 2;
  if (is_odd) {
    int median_1 = (double) data[length / 2];
    int median_2 = (double) data[(length / 2) + 1];
    return (median_1 + median_2) / 2.0;
  } else {
    return data[length / 2];
  }
}

double find_mean(unsigned char data[], int length) {
  sort_array(data, length);  // ensure the data is sorted
  int sum = 0;
  for (int i = 0; i < length; i++) {
    sum += data[i];
  }

  return (double) sum / length;
}

int find_maximum(unsigned char data[], int length) {
  sort_array(data, length);  // ensure the data is sorted
  return data[0];
}

int find_minimum(unsigned char data[], int length) {
  sort_array(data, length);  // ensure the data is sorted
  return data[length - 1];
}

void sort_array(unsigned char data[], int length) {
  // implementation of bubble sort
  for (int i = 0; i < length; i++) {
    unsigned char swapped = 0;
    for (int j = 0; j < length - i - 1; j++) {
      if (data[j] < data[j + 1]) {
        unsigned char temp = data[j];
        data[j] = data[j + 1];
        data[j + 1] = temp;
        if (!swapped) swapped = 1;
      }
    }
    if (!swapped) break;  // everything is sorted, no more iterations necessary
  }
}

