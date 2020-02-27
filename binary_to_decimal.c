/*
 * binary_to_decimal.c
 *
 * A program to convert binary numbers to decimal or vice versa.
 *
 * author: Ryan Morehouse
 * license: MIT
 *
 * Compilation:
 * gcc -lm -o binary_to_decimal.o binary_to_decimal.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void error_msg() {
  printf("Usage: ./binary_to_decimal.o [n] [option]\n");
  printf("[n] is a binary number or a positive integer\n");
  printf("[options]\n");
  printf("-d = input is decimal, convert it to binary\n");
  printf("This program assumes input is binary by default.\n");
  exit(1);
}

void binary_to_decimal(char* binary) {
  double decimal = 0.0;
  int len = strlen(binary);
  for(int i = 0; i < len; i++) {
    if(binary[i] == '0' || binary[i] == '1') {
      double digit = (double)(binary[i] - '0');
      double power = (double)(len) -1.0 -(double)(i);
      decimal += digit * pow(2, power);
    } else {
      error_msg();
    }
  }
  printf("%d\n", (int)(decimal));
}

void decimal_to_binary(int n) {
  int binary_output = 0;
  int step = 1;
  while(n > 0) {
    int remainder = n % 2;
    n /= 2;
    binary_output += remainder * step;
    step *= 10;
  }
  printf("%d\n", binary_output);
}
    
    



int main(int argc, char* argv[]) {
  // determine args
  if(argc < 2)
    error_msg();

  int n = atoi(argv[1]);
  if(n < 1)
    error_msg();

  // determine mode
  int binary_input = 1;
  if(argc > 2) {
    char *option = argv[2];
    if(strcmp(option, "-d") == 0)
      binary_input = 0;
    else
      binary_input = 1;
  }

  // test
  if(binary_input) {
    char *binary = argv[1];
    binary_to_decimal(binary);
  }
  else
    decimal_to_binary(n);

  return 0;
}
