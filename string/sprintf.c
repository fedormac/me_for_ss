#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define s21_NULL (void *)0
#define true 1
#define false 0
typedef unsigned long s21_size_t;
typedef int bool;
char int_to_char(int digit) { return '0' + digit; }

int pizdos(char *str, const char *format) {
  int i = 0;
  char str2[20];
  while (format[i] != '%' || format[i] != '\0') {
    // str2[i] = format[i];

    i++;
  }
  i = 0;
  printf("%s", format);
  return i;
}

void process(char *str2, const char *format, ...) {
  va_list args;

  va_start(args, format);
  int i = 0;
  int counter = 0;
  while (format[i] != '\0') {
    if (format[i] == '%' && format[i] != '\0') {
      printf("%c\n", (char)format[i + 1]);

      switch (format[i + 1]) {
        case 's': {  // Обработка строк
          char *str = (char *)va_arg(args, char *);

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

          str2[i2] = ' ';
          str2[i2] = int_to_char(ch);
          str2[i2++] = '\0';

          i2 = 0;
          printf("цифра: %d\n", ch);
          break;
        }
        default:
          i += pizdos(str2, &format[i + 1]);
          // printf("Неизвестный формат: %c\n", *format - 1);
      }

      i += 2;
    }
    i++;
    if (format[i] != '%') {
      char ch2 = format[i];
      int i2 = 0;
      while (str2[i2] != '\0') {
        i2++;
      }

      str2[i2] = ' ';
      str2[i2++] = ch2;
      str2[i2++] = '\0';
      i2 = 0;
    }
  }

  va_end(args);
}

int main() {
  char mss[1000];

  process(mss, "%smss%sprod%c%d %i ", "Hello ", "World!", 'w', 500, 1000, 140);
  printf("\n%s\n", mss);
  return 0;
}
