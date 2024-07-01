#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char hexChars[] = "0123456789ABCDEF";

typedef struct {
  char *num;
  char xx;
} hex;

hex *init_hex() {
  hex *hexArray = calloc(16, sizeof(hex));
  if (!hexArray) {
    fprintf(stderr, "Ошибка выделения памяти для массива hex.\n");
    exit(1);
  }

  hexArray[0].num = "0000";
  hexArray[0].xx = '0';
  hexArray[1].num = "0001";
  hexArray[1].xx = '1';
  hexArray[2].num = "0010";
  hexArray[2].xx = '2';
  hexArray[3].num = "0011";
  hexArray[3].xx = '3';
  hexArray[4].num = "0100";
  hexArray[4].xx = '4';
  hexArray[5].num = "0101";
  hexArray[5].xx = '5';
  hexArray[6].num = "0110";
  hexArray[6].xx = '6';
  hexArray[7].num = "0111";
  hexArray[7].xx = '7';
  hexArray[8].num = "1000";
  hexArray[8].xx = '8';
  hexArray[9].num = "1001";
  hexArray[9].xx = '9';
  hexArray[10].num = "1010";
  hexArray[10].xx = 'A';
  hexArray[11].num = "1011";
  hexArray[11].xx = 'B';
  hexArray[12].num = "1100";
  hexArray[12].xx = 'C';
  hexArray[13].num = "1101";
  hexArray[13].xx = 'D';
  hexArray[14].num = "1110";
  hexArray[14].xx = 'E';
  hexArray[15].num = "1111";
  hexArray[15].xx = 'F';

  return hexArray;
}

void intToHexStatic(int num, char result[]) {
  hex *hexArray = init_hex();
  int index = 0;
  char buff[200];  // Инициализация нулями для избежания случайных значений

  // Преобразование числа в двоичное представление
  for (int i = 31; i >= 0; --i) {
    int bit = (num >> i) & 1;
    buff[index++] = bit + '0';  // Добавляем бит в буфер
  }

  // Преобразование двоичного представления в шестнадцатеричное
  int i = 0, counter = 0;
  while (i < 32 && buff[i] != '\0') {
    int digit = 0;
    while (digit < 16) {
      for (int j = 0; j < 4; ++j) {
        if (buff[i + j] == hexArray[digit].num[j]) {
          counter++;
        }
        if (counter == 4) {
          result[index++] = hexArray[digit].xx;
          printf("%c ", hexArray[digit].xx);
        }
      }
      counter = 0;
      digit++;
    }
    digit = 0;
    i += 4;
  }
  printf("%s", result);
  result[index] = '\0';  // Добавляем нулевой символ в конец строки
}

int main() {
  int number = 255;
  char hexString[200];

  intToHexStatic(number, hexString);

  printf("Шестнадцатеричное представление: %s\n", hexString);

  free(init_hex());  // Освобождаем память, выделенную под массив hex
  return 0;
}
