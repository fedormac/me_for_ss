#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
  char name[10];
  int value;
} CharInfo;
size_t s21_str_len(const char *str);
void *s21_memchr(const void *_str, int c, size_t n);
int s21_memcmp(const void *_str1, const void *_str2, size_t n);
void *s21_memcpy(void *_dest, const void *_src, size_t n);
void *s21_memmove(void *_dest, const void *_src, size_t n);
void *s21_memset(void *_str, int c, size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, size_t n);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, size_t n);
/*
1
2
3
4
5
6
7
8
9
10
11
12
15

*/
int main() {
  char *str = "adgbc";
  char *str2 = "Hello, World!";

  char find[200];
  /*
  // int comparison_result = s21_strcmp(str, str2);  // printf("%d\n",
 comparison_result);
  // s21_strcat(find, str2);s21_strncat(find, str2,1);char *found =  //
 s21_strchr(str, 'z');
  // printf("%s\n", find); find = calloc(200, sizeof(char));  find[0] = 'm';
 find[1] = 's';  find[2] = 'a'; find[3] = ' ';  int i = 0;  int size, razn; size
 = s21_str_len(str); printf("%d\n", size); find = s21_memchr(str, ' ',
 s21_str_len(str)); printf("%ld\n", find - str); razn = s21_memcmp(str, str2,
 sizeof(str)); printf("%d\n", razn);  s21_memcpy(find, str, sizeof(str));
 s21_memmove(find + 4, str, s21_str_len(str) + 1);  s21_memset(find, '*', 2);
 s21_memset(find + 2, ' ', 2); s21_memset(find + 4, '*', 2);
 */
  // int comparison_result = s21_strncmp(str, str2, 5);
  // printf("%d\n", comparison_result);
  //   s21_strcpy(find, str2);
  // printf("%s\n", find);
  s21_strncpy(find, str2, 8);

  find[sizeof(find) - 1] = '\0';

  printf("%s\n", find);  // Вывод: Hello, World!

  return 0;
}
char *s21_strncpy(char *dest, const char *src, size_t n) {
  int i = 0, size = s21_str_len(src) + 1;
  while (i != size && i < n) {
    dest[i] = src[i];
    i++;
  }

  return dest;
}
char *s21_strcpy(char *dest, const char *src) {
  int i = 0, size = s21_str_len(src) + 1;
  while (i != size) {
    dest[i] = src[i];
    i++;
  }

  return dest;
}

int s21_strncmp(const char *str1, const char *str2, size_t n) {
  int *mas1, *mas2;
  mas1 = calloc(s21_str_len(str1) + 1, sizeof(int));
  mas2 = calloc(s21_str_len(str1) + 1, sizeof(int));
  for (int i = 0; i < s21_str_len(str1) + 1; i++) {
    mas1[i] = (int)str1[i];
  }
  for (int i = 0; i < s21_str_len(str1) + 1; i++) {
    mas2[i] = (int)str2[i];
  }
  //   for (int i = 0; i < s21_str_len(str1)+1; i++) {
  //  printf("%d\n",mas1[i] ) ;
  // }

  int i = 0;
  while (mas1[i] == mas2[i] && i < s21_str_len(str1) && i != n - 1) {
    i++;
  }
  int buff;
  buff = mas1[i] - mas2[i];
  free(mas1);
  free(mas2);

  return buff;
}
int s21_strcmp(const char *str1, const char *str2) {
  int *mas1, *mas2;
  mas1 = calloc(s21_str_len(str1) + 1, sizeof(int));
  mas2 = calloc(s21_str_len(str1) + 1, sizeof(int));
  for (int i = 0; i < s21_str_len(str1) + 1; i++) {
    mas1[i] = (int)str1[i];
  }
  for (int i = 0; i < s21_str_len(str1) + 1; i++) {
    mas2[i] = (int)str2[i];
  }
  //   for (int i = 0; i < s21_str_len(str1)+1; i++) {
  //  printf("%d\n",mas1[i] ) ;
  // }

  int i = 0;
  while (mas1[i] == mas2[i] && i < s21_str_len(str1)) {
    i++;
  }
  int buff;
  buff = mas1[i] - mas2[i];
  free(mas1);
  free(mas2);

  return buff;
}

char *s21_strchr(const char *str, int c) {
  int i = 0;
  while (str[i] != c && str[i] != '\0') {
    i++;
  }
  if (str[i] == '\0') {
    return (char *)NULL;
  } else {
    return (char *)&str[i];
  }
}
char *s21_strncat(char *dest, const char *src, size_t n) {
  int i = 0, i2 = 0;
  while (dest[i] != '\0') {
    i++;
  }
  dest[i] != ' ';
  while (src[i2] != '\0' && i2 != n) {
    dest[i] = src[i2];
    i2++;
    i++;
  }

  return dest;
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
size_t s21_str_len(const char *str) {
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