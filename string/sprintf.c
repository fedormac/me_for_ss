#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define s21_NULL (void *)0
#define true 1
#define false 0
typedef unsigned long s21_size_t;

typedef struct bool {
  int bool;
}
bool;

void process(char *str2, const char *format, ...) {
  va_list args;
  bool a = true;
  va_start(args, format);
  int i = 0;
  int counter = 0;
  while (format[i] != '\0') {
    if (format[i] == '%' && format[i] != '\0') {
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

          printf("\n%s\n", str2);

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

          sprintf(&str2[i2++], "%d", ch);
          // str2[i2++] = '\0';

          i2 = 0;
          printf("цифра: %d\n", ch);
          break;
        }
        default:
          printf("Неизвестный формат: %c\n", *format - 1);
      }
      i++;
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
  char mss[100];

  process(mss, "sss%smss%sprod%c%d %i", "Hello ", "World!", 'w', 500, 1000);
  printf("\n%s\n", mss);
  return 0;
}
// void print_values(int count,...) {
//     va_list args;
//     va_start(args, count);

//     for (int i = 0; i < count; ++i) {
//         int value = va_arg(args, int);
//         printf("%d ", value);
//     }

//     va_end(args);
// }

// int main() {
//     print_values(3, 10, 20, 30);
//     return 0;
// }

// int sprintf(char *str, const char *format, ...) ;
// int main(){
// sprintf("sdf","%s","hjgfg");
//     return 0;

// }

// int sprintf(char *str, const char *format, ...) {
//     va_list args;
//     char *ss;
//     ss=malloc(sizeof(char)*100);
//     va_start(args,format);
//     while (args!='\0')
//     {

//        printf("%d",1);
//     }

// return 0;
// }
