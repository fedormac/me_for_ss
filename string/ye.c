#include <stdio.h>
char digit_to_char(int digit) { return '0' + digit; }

int main() {
  int number = 5;
  char symbol = digit_to_char(number);

  printf("Number: %d\n", number);
  printf("Symbol: %c\n", symbol);

  return 0;
}