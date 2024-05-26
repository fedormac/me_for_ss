
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define s21_NULL (void *)0
#define true 1
#define false 0
typedef unsigned long s21_size_t;
typedef int bool;
void reverse(char *str, int len) {
  int i = 0, j = len - 1, temp;
  while (i < j) {
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    i++;
    j--;
  }
}
int intToStr(int x, char str[], int d) {
  int i = 0;
  while (x) {
    str[i++] = (x % 10) + '0';
    x = x / 10;
  }
  while (i < d) str[i++] = '0';

  reverse(str, i);
  str[i] = '\0';
  return i;
}

void ftoa(float n, char *res, int afterpoint) {
  int ipart = (int)n;
  float fpart = n - (float)ipart;
  int i = intToStr(ipart, res, 0);
  if (afterpoint != 0) {
    res[i] = '.';
    fpart = fpart * pow(10, afterpoint);

    intToStr((int)fpart, res + i + 1, afterpoint);
  }
}
void prod(double num, char *ss) {
  int zdvig = 0;
  int munber_int = 0;
  if (num < 1) {
    while (num < 1) {
      num *= 10;
      zdvig++;
    }
    printf("%f", num);
  }
  if (num > 10) {
    while (num > 10) {
      num /= 10;
      zdvig++;
    }
    printf("%f", num);
  }
  printf(" %d ", zdvig);
  ftoa(num, ss, 9);
}
int main() {
  double number = 0.00012345;
  char ss[50] = {};
  prod(number, ss);
  printf("Original Number: %f\n", number);
  printf("Exponential Representation: %e\n", number);
  printf("str: %s\n", ss);
  return 0;
}