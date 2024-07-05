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
        case 'e': {  // Обработка e

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

int main() {
  char *mss;
  mss = calloc(1000, sizeof(char));

  process(mss, "s %s %c %e %d %d %d d", "mss", 's', -5.345, 500, 1000, 100);
  printf("\n%s\n", mss);
  free(mss);
  return 0;
}
void kluch_e(double num, char *ss, int counter) {
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