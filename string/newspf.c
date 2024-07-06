#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define s21_NULL (void *)0
#define true 1
#define false 0
typedef unsigned long s21_size_t;
typedef int bool;
typedef struct {
  int toch;
  char znak;

} set;
void kluch_e(double num, char *ss, int counter);
char *itoa(int number, char *destination, int base);
void process(char *str2, const char *format, ...);
void kluch_f(double num, char *ss, int counter);
void kluch_o(int num, char result[]);

int main() {
  char *mss;
  mss = calloc(1000, sizeof(char));

  process(mss, "s %s %c %e %d %i %f %o d", "mss", 's', -50.345, 500, 1000,
          -100.4, 255);
  printf("\n%s\n", mss);
  free(mss);
  return 0;
}
const char hexChars[] = "0123456789ABCDEF";
typedef struct {
  char *num;
  char xx;
} hex;

hex *init_hex() {
  hex *hex = calloc(16, sizeof(hex));

  hex[0].num = "000";
  hex[0].xx = '0';

  hex[1].num = "001";
  hex[1].xx = '1';

  hex[2].num = "010";
  hex[2].xx = '2';

  hex[3].num = "011";
  hex[3].xx = '3';

  hex[4].num = "100";
  hex[4].xx = '4';

  hex[5].num = "101";
  hex[5].xx = '5';

  hex[6].num = "110";
  hex[6].xx = '6';

  hex[7].num = "111";
  hex[7].xx = '7';

  return hex;
}

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
char int_to_char(int digit) { return '0' + digit; }

void process(char *str2, const char *format, ...) {
  va_list args;
  set set;
  va_start(args, format);
  int i = 0, i2 = 0;
  char *str = calloc(256, sizeof(char));
  while (format[i] != '\0') {
    set.toch = 6;
    set.znak = ' ';

    // printf("%c",format[i]);
    if (format[i] == '%') {
      if (format[i + 1] == '.') {
        set.toch = format[i + 2] - '0';

        if (format[i + 3] > 47 && format[i + 3] < 58) {
          set.toch = set.toch * 10;
          set.toch += format[i + 3] - '0';

          i += 1;
        }
        i += 2;
      }
      switch (format[i + 1]) {
        case 's': {  // Обработка строк

          str = (char *)va_arg(args, char *);
          strcat(str2, str);
          printf("Строка: %s\n", str);

          break;
        }
        case 'c': {  // Обработка символов
          char ch = (char)va_arg(args, int);
          int i2 = 0;
          while (str2[i2] != '\0') {
            i2++;
          }

          str2[i2] = ' ';
          str2[i2++] = ch;
          str2[i2++] = '\0';
          i2 = 0;
          printf("Символ: %c\n", ch);

          break;
        }
        case 'd':
        case 'i': {  // Обработка цифра

          int ch = (int)va_arg(args, int);

          int i2 = 0;
          while (str2[i2] != '\0') {
            i2++;
          }

          itoa(ch, str2 + i2, 10);

          i2 = 0;
          printf("цифра: %d\n", ch);

          break;
        }
        case 'e': {
          double num = va_arg(args, double);
          int i2 = 0;
          while (str2[i2] != '\0') {
            i2++;
          }
          kluch_e(num, str2 + i2, set.toch);

          i2 = 0;
          printf("цифра: %f\n", num);

          break;
        }
        case 'f': {
          double num = va_arg(args, double);
          int i2 = 0;
          while (str2[i2] != '\0') {
            i2++;
          }
          kluch_f(num, str2 + i2, set.toch);

          i2 = 0;
          printf("цифра: %f\n", num);

          break;
        }
        case 'o': {
          int num = va_arg(args, int);
          int i2 = 0;
          while (str2[i2] != '\0') {
            i2++;
          }
          kluch_o(num, str2 + i2);

          i2 = 0;
          printf("цифра: %d\n", num);

          break;
        }
      }
      // printf("%dd\n", set.toch);
      // printf("%c\n", format[i + 1]);
      i++;
    } else {
      char ch2 = format[i];
      int len = 0;
      while (str2[len] != '\0') {
        len++;
      }

      str2[len] = ' ';
      str2[len++] = ch2;
      str2[len++] = '\0';
      len = 0;
    }

    i++;
  }
  va_end(args);
  // free(str);
}
void kluch_o(int num, char result[]) {
  hex *hexArray = init_hex();
  int index = 0;
  char buff[200];

  for (int i = 23; i >= 0; --i) {
    int bit = (num >> i) & 1;
    buff[index++] = bit + '0';
  }
  buff[index] = '\0';
  index = 0;

  int i = 0, counter = 0;
  while (i < 23 && buff[i] != '\0') {
    int digit = 0;
    while (digit < 8) {
      for (int j = 0; j < 3; ++j) {
        if (buff[i + j] == hexArray[digit].num[j]) {
          counter++;
        }
        if (counter == 3) {
          result[index++] = hexArray[digit].xx;
        }
      }
      counter = 0;
      digit++;
    }
    digit = 0;
    i += 3;
  }

  result[index] = '\0';
  char buff_2;
  index = 0;
  while (result[index] == '0') {
    index++;
  }
  i = 0;

  while (result[i + index] != '\0') {
    result[i] = result[i + index];
    // printf("%c", result[i + index]);
    i++;
  }
  result[i] = '\0';
  // printf("%d", index);
}
void kluch_f(double num, char *ss, int counter) {
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
    // ost = ost + (1 / pow(10, counter));

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
    // ost = ost + (1 / pow(10, counter));

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

void kluch_e(double num, char *ss, int counter) {
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

// while (format[i] != '\0') {
//   if (format[i] == '%' && format[i] != '\0') {
//     switch (format[i + 1]) {
//       case 's': {  // Обработка строк
//         char *str = (char *)va_arg(args, char *);
//         strcat(str2, str);
//         printf("Строка: %s\n", str);

//         break;
//       }
//       case 'c': {  // Обработка символов
//         char ch = (char)va_arg(args, int);
//         int i2 = 0;
//         while (str2[i2] != '\0') {
//           i2++;
//         }

//         str2[i2] = ' ';
//         str2[i2++] = ch;
//         str2[i2++] = '\0';
//         i2 = 0;
//         printf("Символ: %c\n", ch);

//         break;
//       }
//       case 'd':
//       case 'i': {  // Обработка цифра

//         int ch = (int)va_arg(args, int);

//         int i2 = 0;
//         while (str2[i2] != '\0') {
//           i2++;
//         }

//         itoa(ch,str2+i2,10);

//         i2 = 0;
//         printf("цифра: %d\n", ch);

//         break;
//       }
//       case 'e': {  // Обработка цифра
//         int ch = (int)va_arg(args, int);
//         printf("цифра: %d\n", ch);

//         break;
//       }
//       default:
//         // i += pizdos(str2, &format[i + 1]);
//         printf("Неизвестный формат: %c\n", *format - 1);
//     }

//     i += 1;
//   } else {
//     char ch2 = format[i];
//     int len = 0;
//     while (str2[len] != '\0') {
//       len++;
//     }

//     str2[len] = ' ';
//     str2[len++] = ch2;
//     str2[len++] = '\0';
//     len = 0;
//   }
//   i++;
// }