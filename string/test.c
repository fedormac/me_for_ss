#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char source[] = "Hello, World!";
  char destination[50];

  strcpy(destination, source);  // Копируем строку source в destination

  printf("%s\n", destination);  // Вывод: Hello, World!

  return 0;
}
// int main() {
//   char str1[] = "Hello, world!";
//   char str2[] = "Hello, universe";

//   int comparison_result = strncmp(str1, str2, 5);

//   if (comparison_result < 0) {
//     printf("Первые 5 символов str1 меньше первых 5 символов str2\n");
//   } else if (comparison_result > 0) {
//     printf("Первые 5 символов str1 больше первых 5 символов str2\n");
//   } else {
//     printf("Первые 5 символов str1 и str2 равны\n");
//   }

//   return 0;
// }
// int main() {
//   char str1[] = "aaa";
//   char str2[] = "aab";

//   int comparison_result = strcmp(str1, str2);
//   printf("%d\n", comparison_result);
//   if (comparison_result < 0) {
//     printf("str1 меньше str2\n");
//   } else if (comparison_result > 0) {
//     printf("str1 больше str2\n");
//   } else {
//     printf("str1 и str2 равны\n");
//   }

//   return 0;
// }

// int main() {
//   char str[] = "qwert";
//   char ch = 'w';

//   char *found = strchr(str, ch);

//   if (found != NULL) {
//     printf("Первое вхождение '%c' находится на позиции %ld.\n", ch,
//            found - str);
//   } else {
//     printf("Символ '%c' не найден.\n", ch);
//   }

//   return 0;
// }

// int main() {
//   char str1[50] = "Hello, ";
//   char str2[] = "World";

//   strncat(str1, str2, 6);  // Конкатенируем первые 6 символов str2 к str1

//   printf("%s\n", str1);  // Вывод: Hello, Worl

//   return 0;
// }
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