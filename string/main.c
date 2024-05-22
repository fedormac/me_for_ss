#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
  char name[10];
  int value;
} CharInfo;
size_t s21_str_len(char *str);
void *s21_memchr(const void *_str, int c, size_t n);
int s21_memcmp(const void *_str1, const void *_str2, size_t n);
void *s21_memcpy(void *_dest, const void *_src, size_t n);
void *s21_memmove(void *_dest, const void *_src, size_t n);
void *s21_memset(void *_str, int c, size_t n);
char *s21_strcat(char *dest, const char *src);
/*
1
2
3
4
5
6
15

*/
int main() {
  char *str = "adgbc";
  char *str2 = "abdprod";

  char find[200] = "mss ";
  s21_strcat(find, str2);
  printf("%s\n", find);
  /*
 find = calloc(200, sizeof(char));  find[0] = 'm';  find[1] = 's';  find[2] =
 'a'; find[3] = ' ';  int i = 0;  int size, razn;  size = s21_str_len(str);
 printf("%d\n", size); find = s21_memchr(str, ' ', s21_str_len(str));
 printf("%ld\n", find - str); razn = s21_memcmp(str, str2, sizeof(str));
 printf("%d\n", razn);  s21_memcpy(find, str, sizeof(str)); s21_memmove(find +
 4, str, s21_str_len(str) + 1);  s21_memset(find, '*', 2);  s21_memset(find + 2,
 ' ', 2); s21_memset(find + 4, '*', 2);
 */
  return 0;
}
char *s21_strcat(char *dest, const char *src) {
  int i = 0, i2 = 0;
  while (dest[i] != '\0') {
    i++;
  }
  dest[i] != ' ';
  while (src[i2] != '\0') {
    dest[i] = src[i2];
    i2++;
    i++;
  }

  return dest;
}

void *s21_memset(void *_str, int c, size_t n) {
  char *str = _str;
  int i = 0;
  while (i < n) {
    str[i] = c;
    i++;
  }

  return (void *)str;
}
void *s21_memmove(void *_dest, const void *_src, size_t n) {
  char *dest = _dest;

  const char *str = _src;
  int i = 0;
  while (dest[i] != '\0') {
    i++;
  }
  dest[i] != ' ';
  printf("%s\n", dest);

  while (i < n + 1) {
    dest[i] = str[i];

    i++;
  }

  return (void *)dest;
}

void *s21_memcpy(void *_dest, const void *_src, size_t n) {
  char *dest = _dest;
  const char *str = _src;
  int i = 0;
  while (i < n + 1) {
    dest[i] = str[i];

    i++;
  }

  return (void *)dest;
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
int s21_memcmp(const void *_str1, const void *_str2, size_t n) {
  const char *str1 = _str1, *str2 = _str2;
  int *mas1, *mas2;
  mas1 = calloc(n, sizeof(int));
  mas2 = calloc(n, sizeof(int));
  for (int i = 0; i < n; i++) {
    mas1[i] = (int)str1[i];
  }
  for (int i = 0; i < n; i++) {
    mas2[i] = (int)str2[i];
  }

  int i = 0;
  while (mas1[i] == mas2[i] && i < n) {
    i++;
  }
  int buff;
  buff = mas1[i] - mas2[i];
  free(mas1);
  free(mas2);

  return buff;
}