#include <stdio.h>

int main() {
  float number = 42.0f;  // Объявление переменной типа float
  int ptr = &number;
  int b = 2;
  float result = ptr << b;
  printf("Result: %f\n", result);
  return 0;
}