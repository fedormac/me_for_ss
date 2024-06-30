
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
  if (num >= 1) {
    int cheld = 0;
    double ost = 0;
    int ostd = 0;
    char t = '.';
    double zdvig = 0;
    while (num > 10) {
      num /= 10;
      zdvig++;
    }
    cheld = (int)num;
    ost = num - cheld;
    int i = 0;
    while (i < counter) {
      ost *= 10;
      i++;
    }
    double ttt = 0;
    double sss = 0;
    ttt = (int)ost;
    sss = ost - ttt;
    if (sss * 10 >= 5) {
      ost = ost + 1;
    }

    ostd = (int)ost;
    ss[0] = cheld + '0';
    ss[1] = t;
    itoa(ostd, ss + 2, 10);
    int len = 0;
    len = strlen(ss);
    ss[len] = 'e';

    ss[len + 1] = '+';
    zdvig = zdvig * pow(10, -1);
    itoa((int)zdvig, ss + len + 2, 10);
    zdvig = zdvig * 10;
    itoa((int)zdvig, ss + len + 3, 10);

  } else {
    int cheld = 0;
    double ost = 0;
    int ostd = 0;
    char t = '.';
    double zdvig = 0;
    while (num < 1) {
      num *= 10;
      zdvig++;
    }
    printf("%f", num);
    cheld = (int)num;
    ost = num - cheld;
    int i = 0;
    while (i < counter) {
      ost *= 10;
      i++;
    }
    double ttt = 0;
    double sss = 0;
    ttt = (int)ost;
    sss = ost - ttt;
    if (sss * 10 >= 5) {
      ost = ost + 1;
    }

    ostd = (int)ost;
    ss[0] = cheld + '0';
    ss[1] = t;
    itoa(ostd, ss + 2, 10);
    int len = 0;
    len = strlen(ss);
    ss[len] = 'e';

    ss[len + 1] = '-';
    zdvig = zdvig * pow(10, -1);
    itoa((int)zdvig, ss + len + 2, 10);
    zdvig = zdvig * 10;
    itoa((int)zdvig, ss + len + 3, 10);
  }
}
int main() {
  double number = 10.015;
  char ss[50] = {};
  prod(number, ss, 2);
  printf("Original Number: %f\n", number);
  printf("Exponential Representation: %e\n", number);
  printf("str: %s\n", ss);
  return 0;
}