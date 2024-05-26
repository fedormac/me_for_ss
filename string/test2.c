#include <math.h>
#include <stdio.h>
int main() {
  double dividend = 10.123;
  double divisor = 5.0;
  double remainder;

  // Вычисление остатка от деления
  remainder = fmod(dividend, 10);
  //  printf("%f ",remainder);
  int co = 0;
  while (remainder != .0) {
    remainder *= 10;

    printf("%f ", remainder);
    co++;
  }

  printf("Остаток от деления %.2f на %.2f равен %f %d\n", dividend, divisor,
         remainder, co);

  return 0;
}