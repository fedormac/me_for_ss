#include <math.h>
#include <stdio.h>
int main() {
  double dividend = 10.123;
  double divisor = 5.0;
  double remainder;

  // Вычисление остатка от деления
  remainder = fmod(dividend, 10);
  while (/* condition */) {
    /* code */
  }

  printf("Остаток от деления %.2f на %.2f равен %f\n", dividend, divisor,
         remainder);

  return 0;
}