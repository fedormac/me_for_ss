#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  char str1[] = "hello";
  char str2[] = "world";

  int result = memcmp(str1, str2, sizeof(str1));

  if (result < 0) {
    printf("str1 меньше str2\n");
  } else if (result > 0) {
    printf("str1 больше str2\n");
  } else {
    printf("str1 и str2 равны\n");
  }

  return 0;
}