#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  char str1[50] = "Hello, ";
  char str2[] = "World";

  strncat(str1, str2, 6);  // Конкатенируем первые 6 символов str2 к str1

  printf("%s\n", str1);  // Вывод: Hello, Worl

  return 0;
}
// int main() {
//   char str1[50] = "Hello, ";
//   char str2[] = "World";

//   strcat(str1, str2);  // Конкатенируем str2 к str1

//   printf("%s\n", str1);  // Вывод: Hello, World!

//   return 0;
// }
// int main() {
//   char buffer[50];

//   // Заполняем весь буфер нулями
//   memset(buffer, 0, sizeof(buffer));

//   // Заполняем первые 5 символов пробелами
//   memset(buffer, ' ', 5);

//   // Заполняем последние 5 символов символом '*'
//   memset(buffer + 5, '*', 5);

//   printf("%s\n", buffer);

//   return 0;
// }
// int main() {
//   char src[] = "Привет, мир!";
//   char *dest;
//   dest = malloc(200 * sizeof(char));
//   dest = "mss ";

//   memmove(dest + 4, src,
//           strlen(src) + 1);  // Копируем оставшуюся часть строки src в dest

//   printf("Измененная строка: %s\n", dest);

//   return 0;
// }

// int main() {
//   char src[] = "Привет, мир!";
//   char *dest;
//   // dest=calloc(20,sizeof(char));

//   memcpy(dest, src, sizeof(src));  // Копируем всю строку src в dest

//   printf("Копированная строка: %s\n", dest);

//   return 0;
// }

// int main() {
//   char block1[] = "abc";
//   char block2[] = "abd";
//   char block3[] = "abc";

//   int result1 = memcmp(block1, block2, sizeof(block1));
//   int result2 = memcmp(block1, block3, sizeof(block1));
//   printf("%ld\n", sizeof(block1));
//   printf("Result 1: %d\n", result1);  // Вернет 0, так как блоки идентичны
//   printf("Result 2: %d\n",
//          result2);  // Вернет отрицательное число, так как block1 меньше
//          block3

//   return 0;
// }