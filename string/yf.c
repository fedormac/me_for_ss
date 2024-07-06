
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
  if (num > 0) {
    double num2 = num;
    int cheld = 0;
    double ost = 0;
    int ostd = 0;
    char t = '.';
    double zdvig = 0;
    int zcounter = 0;
    while (num2 > 10) {
      num2 /= 10;
      zcounter++;
    }

    cheld = (int)num;
    ost = num - cheld;
    int i = 0;
    printf("%d\n", cheld);
    itoa(cheld, ss, 10);
    int len2 = strlen(ss);
    ss[len2] = t;

    double ttt = 0;
    double sss = 0;
    ttt = (int)ost;
    sss = ost - ttt;
    if (sss * 10 >= 5) {
      ost = ost + 1;
    }
    ost = ost + (1 / pow(10, counter));

    printf("%f\n", ost);
    zcounter = 0;
    int i5 = 0;
    while (i5 != counter && ostd == 0) {
      ost *= 10;
      ostd = (int)ost;
      printf("%d\n", ostd);
      itoa(ostd, ss + (len2 + i5 + 1), 10);
      i5++;
      zcounter++;
    }
    i5 = 0;
    while (i5 != counter - zcounter) {
      ost *= 10;
      i5++;
    }
    ostd = (int)ost;
    itoa(ostd, ss + (len2 + zcounter), 10);
  } else {
    num *= -1;
    double num2 = num;
    int cheld = 0;
    double ost = 0;
    int ostd = 0;
    char t = '.';
    double zdvig = 0;
    int zcounter = 0;
    while (num2 > 10) {
      num2 /= 10;
      zcounter++;
    }

    cheld = (int)num;
    ost = num - cheld;
    int i = 0;
    printf("%d\n", cheld);
    ss[0] = '-';
    itoa(cheld, ss + 1, 10);
    int len2 = strlen(ss);
    ss[len2] = t;

    double ttt = 0;
    double sss = 0;
    ttt = (int)ost;
    sss = ost - ttt;
    if (sss * 10 >= 5) {
      ost = ost + 1;
    }
    ost = ost + (1 / pow(10, counter));

    printf("%f\n", ost);
    zcounter = 0;
    int i5 = 0;
    while (i5 != counter && ostd == 0) {
      ost *= 10;
      ostd = (int)ost;
      printf("%d\n", ostd);
      itoa(ostd, ss + (len2 + i5 + 1), 10);
      i5++;
      zcounter++;
    }
    i5 = 0;
    while (i5 != counter - zcounter) {
      ost *= 10;
      i5++;
    }
    ostd = (int)ost;
    itoa(ostd, ss + (len2 + zcounter), 10);
  }
}

int main() {
  double number = -12340.15;
  char ss[50] = {};
  prod(number, ss, 6);
  printf("Original Number: %f\n", number);
  printf("f : %f\n", number);
  printf("st: %s\n", ss);
  return 0;
}