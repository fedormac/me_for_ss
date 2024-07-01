#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned long s21_size_t;
typedef int bool;
#define true 1
#define false 0

#include <math.h>
#include <stdio.h>

int main() {
  int number = 15;     // Пример числа
  char hexString[10];  // Массив для хранения шестнадцатеричного представления

  // Преобразование числа в шестнадцатеричную строку
  sprintf(hexString, "%x", number);

  // Вывод результата
  printf("Шестнадцатеричное представление: %s\n", hexString);

  return 0;
}

// float ost(float number) { return number = number - (int)number; }

// int countDigitsAfterDot(float number) {
//   int digits = 0;
//   float fraction = ost(number);  // Извлекаем дробную часть числа

//   // Удаляем знак минус, если число отрицательное
//   if (fraction < 0) {
//     fraction = -fraction;
//   }
//   while (fmod(fraction, 10) != 0.0) {
//     printf("%f ", fraction);
//     fraction *= 10;
//     digits++;
//   }

//   return --digits;
// }

// int main() {
//   float number = 123.85559f;
//   int digits = countDigitsAfterDot(number);
//   printf("Количество цифр после десятичной точки: %d\n", digits);
//   return 0;
// }

// #include <ctype.h>
// #include <stdarg.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define s21_NULL (void *)0
// #define true 1
// #define false 0
// typedef unsigned long s21_size_t;
// typedef int bool;

// int pizdos(char *str, const char *format) {
//   int i = 0;
//   char str2[20] = "";  // Инициализируем как пустую строку
//   while (format[i] != '%' && format[i] != '\0') {
//     str2[i] = format[i];
//     i++;
//   }
//   str2[i] = '\0';  // Завершаем строку нулевым символом
//   return i;
// }

// void process(char *str2, const char *format, ...) {
//   va_list args;
//   va_start(args, format);
//   int i = 0;
//   while (format[i] != '\0') {
//     if (format[i] == '%' && format[i + 1] != '\0') {
//       i++;  // Увеличиваем i, чтобы пропустить символ %
//       switch (format[i]) {
//         case 's':  // Обработка строк
//           char *str = va_arg(args, char *);
//           strcat(str2, str);
//           printf("Строка: %s\n", str);
//           break;
//         case 'c':  // Обработка символов
//           char ch = va_arg(args, int);
//           strcat(str2, &ch);
//           printf("Символ: %c\n", ch);
//           break;
//         case 'd':  // Обработка целых чисел
//           int num = va_arg(args, int);
//           char buffer[50];
//           sprintf(buffer, "%d", num);
//           strcat(str2, buffer);
//           printf("Целое число: %d\n", num);
//           break;
//         default:
//           i += pizdos(str2, &format[i]);
//       }
//     } else {
//       char ch = format[i];
//       strcat(str2, &ch);
//     }
//     i++;
//   }
//   va_end(args);
// }

// int main() {
//   char mss[1000] = "";
//   process(mss, "sss%smss%sprod%c%d %i", "Hello ", "World!", 'w', 500, 1000);
//   printf("\n%s\n", mss);
//   return 0;
// }
// typedef unsigned long s21_size_t;
// int main() {
//   char dest[200] = "pii";
//   char src[] = " prod!";
//   char src1[] = " mss";
//   strcat(dest, src);  // Добавляем " prod!" к "pii"
//   strcat(dest, src1);  // Добавляем " mss" к получившейся строке
//   printf("%s", dest);

//   return 0;
// }
// int main() {
//   s21_size_t a = -5.4;
//   printf("%ld", a);

//   return 0;
// }

// int main() {
//    char str[] = "Привет, мир! Как, дела?";
//    char delimiters[] = ",.!?";

//   char *token = strtok(str, delimiters);

//   while (token != NULL) {
//     printf("%s\n", token);
//     token = strtok(NULL, delimiters);
//   }

//   return 0;
// }
// int main() {
//   char str[] = "mss1";
//   char substr[] = "prid mss";

//   char *found = strstr(str, substr);

//   if (found != NULL) {
//     printf("Подстрока '%ld' найдена в строке.\n", found - substr);
//   } else {
//     printf("Подстрока '%s' не найдена в строке.\n", substr);
//   }

//   return 0;
// }
// int main() {
//   char str[] = "mss ";
//   char validChars[] = "mss prod";
//   size_t len = strspn(str, validChars);

//   printf("Количество символов в начале строки, принадлежащих набору: %zu\n",
//          len);

//   return 0;
// }
// int main() {
//   char str[] = "mss prod rod";
//   char *lastSpacePtr = strrchr(str, ' ');

//   if (lastSpacePtr != NULL) {
//     printf("Последний пробел найден на позиции: %ld\n", lastSpacePtr - str);
//   } else {
//     printf("Пробел не найден.\n");
//   }

//   return 0;
// }

// int main() {
//   const char *str = "adgb!c";
//   const char *accept = ",!";

//   char *found = strpbrk(str, accept);

//   if (found) {
//     printf("Первый найденный символ '%c' находится на позиции %ld\n", *found,
//            found - str);
//   } else {
//     printf("Символов из набора '%s' не найдено\n", accept);
//   }

//   return 0;
// }
// int main() {
//     const char *source = "Hello, World!";
//     char *copy = strdup(source);

//     if (copy!= NULL) {
//         printf("Original string: %s\n", source);
//         printf("Copied string: %s\n", copy);
//         free(copy); // Не забываем освободить память
//     } else {
//         printf("Memory allocation failed.\n");
//     }

//     return 0;
// }

// int main() {
//   FILE *file = fopen("a.txt", "w");
//   if (!file) {
//     perror("Failed to open file for writing");
//     return EXIT_FAILURE;
//   }

//   for (int i = 1; i <= 134; ++i) {
//     char *error_msg = strerror(i);
//     if (error_msg != NULL) {
//       fprintf(file, "%d: %s\n", i, error_msg);
//     } else {
//       fprintf(file, "%d: No description available\n", i);
//     }
//   }

//   fclose(file);
//   return EXIT_SUCCESS;
// }
// int main() {
//     const char *str = "aaa,aaaaaa,";
//     const char *bad_chars = "!?";

//     size_t len = strcspn(str, bad_chars);

//     printf("Наибольший : '%ld'\n", len);

//     return 0;
// }
// int main() {
//   char source[] = "Hello, World!";
//   char destination[50];

//   strncpy(
//       destination, source,
//       8);  // Копируем строку source в destination, не включая нулевой символ

//   destination[sizeof(destination) - 1] =
//       '\0';  // Добавляем нулевой символ в конец

//   printf("%s\n", destination);  // Вывод: Hello, World!

//   return 0;
// }
// int main() {
//   char source[] = "Hello, World!";
//   char destination[50];

//   strcpy(destination, source);  // Копируем строку source в destination

//   printf("%s\n", destination);  // Вывод: Hello, World!

//   return 0;
// }
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