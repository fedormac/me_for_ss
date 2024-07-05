
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define s21_NULL (void *)0
#define true 1
#define false 0
typedef unsigned long s21_size_t;
typedef int bool;
char *itoa(int number, char *destination, int base) {
  int count = 0;
  do {
    int digit = number % base;
    destination[count++] = (digit > 9) ? digit - 10 + 'A' : digit + '0';
  } while ((number /= base) != 0);
  destination[count] = '\0';
  int i;
  for (i = 0; i < count / 2; ++i) {
    char symbol = destination[i];
    destination[i] = destination[count - i - 1];
    destination[count - i - 1] = symbol;
  }
  return destination;
}
void prod(double num, char *ss, int counter) {
  double num2 = num;
  double ost;
  int ostd;
  int zdvig = 0;
  int cheld = 0;
  int zcounter = 0;

  // double num2 = num;
  // double ost;
  // int ostd;
  // int zdvig = 0;
  // int cheld = 0;
  // while (num2 >= 1) {
  //   num2 /= 10;
  //   zdvig++;
  // }
  // cheld = (int)num;

  // itoa(cheld, ss, 10);
  // ost = num - cheld;

  // ostd = (int)ost;
  // ostd += 1;
  // ss[zdvig] = '.';
  // itoa(ostd, ss + zdvig + 1, 10);
}

int main() {
  double number = 12340.15;
  char ss[50] = {};
  prod(number, ss, 6);
  printf("Original Number: %f\n", number);
  printf("f : %f\n", number);
  printf("st: %s\n", ss);
  return 0;
}