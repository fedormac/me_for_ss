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
void process(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  printf
}

int main() {
  char mss[1000];

  process(mss, "%smss%sprod%c %d %i ", "Hello ", "World!", 'w', 500, 1000);
  printf("\n%s\n", mss);
  return 0;
}
