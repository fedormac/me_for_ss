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
void process(char *str2, const char *format, ...) {
  va_list args;
  va_start(args, format);
  // char *ss = (char *)va_arg(args, char *);
  // printf("%s\n", ss);

  // ss = (char *)va_arg(args, char *);
  // printf("%s\n", ss);

  // ss = (char )va_arg(args, int);
  // printf("%c\n", ss);

  // ss = (int)va_arg(args, int);
  // printf("%d\n", ss);

  // ss = (int)va_arg(args, int);
  // printf("%i\n", ss);
  int i = 0;
  while (format[i] != '\0') {
    if (format[i] == '%' && format[i] != '\0') {
      switch (format[i + 1]) {
        case 's': {  // Обработка строк
          char *str = (char *)va_arg(args, char *);
          printf("Строка: %s\n", str);

          break;
        }
        case 'c': {  // Обработка символов
          char ch = (char)va_arg(args, int);
          printf("Символ: %c\n", ch);

          break;
        }
        case 'd':
        case 'i': {  // Обработка цифра
          int ch = (int)va_arg(args, int);
          printf("цифра: %d\n", ch);

          break;
        }
        case 'e': {  // Обработка цифра
          int ch = (int)va_arg(args, int);
          printf("цифра: %d\n", ch);

          break;
        }
        default:
          // i += pizdos(str2, &format[i + 1]);
          printf("Неизвестный формат: %c\n", *format - 1);
      }

      i += 1;
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
}

int main() {
  char *mss;
  mss = calloc(1000, sizeof(char));

  process(mss, "s%smss%sprod%c %d %i a", "Hello ", "World!", 'w', 500, 1000);
  printf("\n%s\n", mss);
  free(mss);
  return 0;
}
