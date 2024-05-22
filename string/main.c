#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
  int value;
  char name[40];

} erreoz;
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
size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
size_t s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
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
13
14 надо сделать косяк есть un err
15
16
17
18
19
20
*/
int main() {
  //   char *str = "mss prod";
  //   char *str2 = "mss";

  //   char find[200];
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
  // s21_strncpy(find, str2, 8);

  // find[sizeof(find) - 1] = '\0';

  // printf("%s\n", find);  // Вывод: Hello, World!
  // size_t len = s21_strcspn(str, str2);

  //   printf("Наибольший : '%ld'\n", len);
  // printf("%s", s21_strerror(10));
  // char *sss=s21_strpbrk(str,str2);
  // printf("Первый найденный символ '%c' находится на позиции %ld\n", *sss, sss
  // - str);
  // char *lastSpacePtr = s21_strrchr(str, 'z');
  // size_t len = s21_strspn(str, str2);
  //     printf("Количество символов в начале строки, принадлежащих набору:
  //     %zu\n", len);
  //   char *found = s21_strstr(str, str2);

  //   if (found != NULL) {
  //     printf("Подстрока '%s' найдена в строке.\n", found);
  //   } else {
  //     printf("Подстрока '%s' не найдена в строке.\n", str2);
  //   }

  char str[] = "Привет, мир, Как, дела?";
  char delimiters[] = ",.!?";

  char *token = s21_strtok(str, delimiters);

  while (token != NULL) {
    printf("%s\n", token);
    token = s21_strtok(NULL, delimiters);
  }

  return 0;
}
char *s21_strtok(char *str, const char *delim) {
  static char *p = NULL;
  if (str != NULL) p = str;
  if (p == NULL) return NULL;
  char *save = p;
  p += s21_strspn(p, delim);
  if (*p == '\0') {
    p = NULL;
    return NULL;
  }
  char *token = p;
  p += s21_strcspn(p, delim);
  if (*p != '\0') {
    *p++ = '\0';
  }
  return token;
}

char *s21_strstr(const char *haystack, const char *needle) {
  int i = 0, i2 = 0;
  int size = s21_str_len(needle), counter = 0;
  while (haystack[i] != '\0') {
    while (needle[i2] != '\0') {
      if (haystack[i + i2] == needle[i2]) {
        counter++;
      }
      if (counter == size) {
        return (char *)needle;
      }

      i2++;
    }
    i2 = 0;

    i++;
  }
}

size_t s21_strspn(const char *str1, const char *str2) {
  int i = 0;
  size_t conter = 0;
  while (str2[i] != '\0' || str1[i] != '\0') {
    if (str2[i] != str1[i]) {
      break;
    } else {
      conter++;
      i++;
    }
  }

  return conter;
}
char *s21_strrchr(const char *str, int c) {
  int i = 0;
  static char *buff = NULL;
  buff = malloc(10 * sizeof(char));

  while (str[i] != '\0') {
    if (str[i] == c) {
      buff = (char *)&str[i];
    }
    i++;
  }
  return NULL;
}

char *s21_strerror(int errnum) {
  static char line[100];

  char buff[20];
  char ss = (char)errnum;
  FILE *file = fopen("a.txt", "r");
  if (!file) {
    printf("Failed to open file for writing");
    return NULL;
  }
  int i = 0;

  while (fgets(line, sizeof(line), file)) {
    while (line[i] != ':') {
      buff[i] = line[i];
      i++;
    }
    buff[i] = '\0';

    if (atoi(buff) == errnum) {
      return (char *)line + (i + 2);
      //(line (i+2))
    }

    i = 0;
  }
  fclose(file);

  return "Unknown error ";
}
char *s21_strpbrk(const char *str1, const char *str2) {
  int i = 0, i2 = 0;
  while (str1[i] != '\0') {
    while (str2[i2] != '\0') {
      if (str2[i2] == str1[i]) {
        return (char *)&str1[i];
      }
      i2++;
    }

    i2 = 0;
    i++;
  }
  return NULL;
}

size_t s21_strcspn(const char *str1, const char *str2) {
  int i = 0, i2 = 0;
  size_t couter = 0;
  while (str2[i] != '\0') {
    while (str1[i2] != '\0') {
      if (str1[i2] == str2[i]) {
        break;
      }
      couter++;
      i2++;
    }
    if (str1[i2] == str2[i]) {
      break;
    }
    couter = 0;
    i++;
    i2 = 0;
  }
  return couter;
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