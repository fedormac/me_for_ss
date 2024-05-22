#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define s21_NULL (void*)0
typedef unsigned long s21_size_t;

void process_strings_and_chars(const char* format, ...) {
  va_list args;
  va_start(args, format);

  while (*format != '\0') {
    switch (*format++) {
      case 's': {  // Обработка строк
        char* str = va_arg(args, char*);
        printf("Строка: %s\n", str);
        break;
      }
      case 'c': {  // Обработка символов
        char ch = (char)va_arg(args, int);  // Приведение типа, так как va_arg
                                            // требует полностью описанных типов
        printf("Символ: %c\n", ch);
        break;
      }
      default:
        printf("Неизвестный формат: %c\n", *format - 1);
    }
  }

  va_end(args);
}

int main() {
  process_strings_and_chars("scs", "Hello", 'W', "World!");
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
