#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
  char name[10];
  int value;
} CharInfo;
size_t s21_str_len(char *str);
void *s21_memchr(const void *_str, int c, size_t n);

/*
1
15

*/
int main() {
  char *str = "sdfsdfs";
  char *find;
  int i = 0;
  int size;
  size = s21_str_len(str);
  printf("%d\n", size);
  find = s21_memchr(str, ' ', s21_str_len(str));
  printf("%ld\n", find - str);
  return 0;
}
size_t s21_str_len(char *str) {
  int i = 0;
  while (str[i] != '\0') {
    i++;
  }

  return i;
}
void *s21_memchr(const void *_str, int c, size_t n) {
  const char *str = _str;
  int i = 0;
  while (i <= n && str[i] != c) {
    i++;
  }
  if (i < n) {
    return (void *)&str[i];
  } else {
    return NULL;
  }
}