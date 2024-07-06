

#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* itoa(int number, char* destination, int base) {
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
#include <stdint.h>
#include <stdio.h>
#include <string.h>

// Функция для конвертации числа в шестнадцатеричную строку
void uint_to_hex(uint64_t* value, char* out) {
  static const char hexchars[] = "0123456789abcdef";
  char* p = out + strlen(out);
  for (; value > 0; value /= 16) {
    *--p = hexchars[value % 16];
  }
  *--p = 'x';
  *--p = '0';
  strcpy(out, p);
}

int main() {
  int myVar = 42;  // Переменная, адрес которой мы захотим записать
  char buffer[2000];  // Буфер для хранения адреса переменной

  // Получаем адрес переменной
  uint64_t myVar = (uint64_t)&myVar;

  // Конвертируем адрес в шестнадцатеричную строку
  uint_to_hex(&myVar, buffer);

  // Выводим полученный адрес
  printf("Адрес переменной: %s\n", buffer);
  printf("Адрес переменной: %p\n", &myVar);

  return 0;
}
