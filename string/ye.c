
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
    zcounter += strlen(ss) - 2;

    int len = 0;
    len = strlen(ss);
    ss[len] = 'e';

    ss[len + 1] = '+';
    zdvig = zdvig * pow(10, -1);
    itoa((int)zdvig, ss + len + 2, 10);
    zdvig = zdvig * 10;
    itoa((int)zdvig, ss + len + 3, 10);
    char mss_pp[120] = {};
    mss_pp[0] = ss[0];
    mss_pp[1] = ss[1];
    int i5 = 0;
    while (i5 < (counter - zcounter + 2)) {
      mss_pp[i5 + 2] = '0';
      i5++;
    }
    strcpy(mss_pp + (counter - zcounter + 4), ss + 2);
    strcpy(ss, mss_pp);

  } else if (num >= 0 && num < 1) {
    double num2 = num;
    int cheld = 0;
    double ost = 0;
    int ostd = 0;
    char t = '.';
    double zdvig = 0;
    int zcounter = 0;
    while (num2 < 1) {
      num2 *= 10;
      zcounter++;
    }
    while (num < 1) {
      num *= 10;

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
    zcounter += strlen(ss) - 2;

    int len = 0;
    len = strlen(ss);
    ss[len] = 'e';

    ss[len + 1] = '-';
    zdvig = zdvig * pow(10, -1);
    itoa((int)zdvig, ss + len + 2, 10);
    zdvig = zdvig * 10;
    itoa((int)zdvig, ss + len + 3, 10);
    char mss_pp[120] = {};
    mss_pp[0] = ss[0];
    mss_pp[1] = ss[1];
    int i5 = 0;
    while (i5 < (counter - zcounter + 2)) {
      mss_pp[i5 + 2] = '0';
      i5++;
    }
    strcpy(mss_pp + (counter - zcounter + 4), ss + 2);
    strcpy(ss, mss_pp);

  } else if (num < 0) {
    num *= -1;

    if (num >= 1) {
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
      zcounter += strlen(ss) - 2;

      int len = 0;
      len = strlen(ss);
      ss[len] = 'e';

      ss[len + 1] = '+';
      zdvig = zdvig * pow(10, -1);
      itoa((int)zdvig, ss + len + 2, 10);
      zdvig = zdvig * 10;
      itoa((int)zdvig, ss + len + 3, 10);
      char mss_pp[120] = {};
      mss_pp[0] = '-';
      mss_pp[1] = ss[0];
      mss_pp[2] = ss[1];
      int i5 = 0;
      while (i5 < (counter - zcounter + 3)) {
        mss_pp[i5 + 3] = '0';
        i5++;
      }
      strcpy(mss_pp + (counter - zcounter + 5), ss + 2);
      strcpy(ss, mss_pp);

    } else if (num >= 0 && num < 1) {
      double num2 = num;
      int cheld = 0;
      double ost = 0;
      int ostd = 0;
      char t = '.';
      double zdvig = 0;
      int zcounter = 0;
      while (num2 < 1) {
        num2 *= 10;
        zcounter++;
      }
      while (num < 1) {
        num *= 10;

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
      zcounter += strlen(ss) - 2;

      int len = 0;
      len = strlen(ss);
      ss[len] = 'e';

      ss[len + 1] = '-';
      zdvig = zdvig * pow(10, -1);
      itoa((int)zdvig, ss + len + 2, 10);
      zdvig = zdvig * 10;
      itoa((int)zdvig, ss + len + 3, 10);
      char mss_pp[120] = {};
      mss_pp[0] = '-';
      mss_pp[1] = ss[0];
      mss_pp[2] = ss[1];
      int i5 = 0;
      while (i5 < (counter - zcounter + 3)) {
        mss_pp[i5 + 3] = '0';
        i5++;
      }
      strcpy(mss_pp + (counter - zcounter + 5), ss + 2);
      strcpy(ss, mss_pp);
    }
  }
}
int main() {
  double number = -0.0105;
  char ss[500] = {};
  prod(number, ss, 6);
  printf("Original Number: %f\n", number);
  printf("Exponential Representation: %e\n", number);
  printf("str: %s\n", ss);
  return 0;
}

// double ost = 0;
// int ostd = 0;
// char t = '.';
// double zdvig = 0;
// num = num * (-1);
// while (num > 10)
// {
//   num /= 10;

//   zdvig++;
// }
// //printf("%f\n", num);
// cheld = (int)num;
// //printf("%d\n", cheld);
// ost = num - cheld;
// int i = 0;
// while (i < counter)
// {
//   ost *= 10;
//   i++;
// }
// //printf("%f\n", ost);
// double ttt = 0;
// double sss = 0;
// ttt = (int)ost;
// sss = ost - ttt;
// if (sss * 10 >= 5)
// {
//   ost = ost + 1;
// }

// ostd = (int)ost;
// //printf("%d\n", cheld);
// ss[0] = cheld + '0';
// ss[1] = t;
// itoa(ostd, ss + 2, 10);
// int len = 0;
// len = strlen(ss);
// ss[len] = 'e';

// ss[len + 1] = '-';
// zdvig = zdvig * pow(10, -1);
// itoa((int)zdvig, ss + len + 2, 10);
// zdvig = zdvig * 10;
// itoa((int)zdvig, ss + len + 3, 10);