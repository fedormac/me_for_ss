#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  char *str = "gggggjjujj";
  char *ptr;

  // Поиск первого пробела в строке
  ptr = memchr(str, ' ', strlen(str));

  printf("П %ld\n", ptr - str);

  return 0;
}