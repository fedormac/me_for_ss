#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define s21_NULL (void *)0
typedef unsigned long s21_size_t;
typedef struct {
  const char *ptr;  // Текущая позиция в строке
  char buffer[256];  // Буфер для временного хранения данных
  int buffer_index;  // Индекс в буфере
} ScanState;
int scan_int(const char *str) {
  ScanState state = {.ptr = str};
  int sign = 1;
  int result = 0;

  while (state.ptr < str + strlen(str)) {
    char c = *state.ptr++;

    if (c == '-') {
      sign = -sign;
    } else if (isdigit(c)) {
      result = result * 10 + (c - '0');
    } else {
      break;
    }
  }

  return sign * result;
}
int my_sscanf(const char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);

  int count = 0;
  while (*format != '\0') {
    if (*format == '%') {
      format++;
      if (*format == 'd') {
        int i = scan_int(str);
        va_arg(args, int *);
        *va_arg(args, int *) = i;
        count++;
      } else if (*format == 's') {
        char *s = (char *)str;
        while (isspace(*s)) s++;  // Пропускаем пробелы в начале строки
        va_arg(args, char **);
        *va_arg(args, char **) = s;
        count++;
      }
      format++;
    } else {
      break;
    }
  }

  va_end(args);
  return count;
}
int main() {
  const char *input = "42 Hello";
  int num;
  char *str;

  my_sscanf(input, "%d %s", &num, &str);
  printf("Число: %d, Строка: %s\n", num, str);

  return 0;

  return 0;
}