#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char hexChars[] = "0123456789ABCDEF";
typedef struct {
  char *num;
  char xx;
} hex;

hex *init_hex() {
  hex *hex = calloc(16, sizeof(hex));

  hex[0].num = "0000";
  hex[0].xx = '0';

  hex[1].num = "0001";
  hex[1].xx = '1';

  hex[2].num = "0010";
  hex[2].xx = '2';

  hex[3].num = "0011";
  hex[3].xx = '3';

  hex[4].num = "0100";
  hex[4].xx = '4';

  hex[5].num = "0101";
  hex[5].xx = '5';

  hex[6].num = "0110";
  hex[6].xx = '6';

  hex[7].num = "0111";
  hex[7].xx = '7';

  hex[8].num = "1000";
  hex[8].xx = '8';

  hex[9].num = "1001";
  hex[9].xx = '9';

  hex[10].num = "1010";
  hex[10].xx = 'A';

  hex[11].num = "1011";
  hex[11].xx = 'B';

  hex[12].num = "1100";
  hex[12].xx = 'C';

  hex[13].num = "1101";
  hex[13].xx = 'D';

  hex[14].num = "1110";
  hex[14].xx = 'E';

  hex[15].num = "1111";
  hex[15].xx = 'F';

  return hex;
}
// Функция для преобразования int в шестнадцатеричную строку
void intToHexStatic(int num, char result[]) {
  hex *xex = init_hex();

  int index = 0;
  char buff[200];
  // Статический массив для хранения шестнадцатеричного представления
  // Максимально возможное шестнадцатеричное представление для int (8 символов)
  // + нулевой символ
  for (int i = sizeof(num) * 8 - 1; i >= 0; --i) {
    // printf("%d ",i);
    //  Получаем текущий бит числа
    int bit = (num >> i) & 1;

    // Добавляем соответствующий шестнадцатеричный символ в строку
    buff[index++] = bit + '0';
  }
  int i2 = 0, i3 = 0, counter = 0, zzz = 0;
  for (int i = 0; i < sizeof(num) * 8 - 1; i = i + 4) {
    printf("%d ", i);
    while (i2 < 10) {
      while (i3 < 5) {
        if (buff[i + i3] == xex[i2].num[i3]) {
          counter++;
        }
        if (counter == 4) {
          // result[zzz++]=xex[i2].xx;
          printf("%c", xex[i2].xx);
        }
        // printf("%d ",i);
        i3++;
      }
      i3 = 0;
      counter = 0;
      i2++;
    }
    i2 = 0;
  }
}

int main() {
  int number = 25;
  char hexString[200];  // Массив для хранения шестнадцатеричного представления

  intToHexStatic(number, hexString);

  printf("Шестнадцатеричное представление: %s\n", hexString);

  return 0;
}
