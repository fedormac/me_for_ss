#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char hexChars[] = "0123456789ABCDEF";
typedef struct {
  char *num;
  char xx;
} hex;

hex *init_hex_16() {
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
void intToHexStatic(int num, char result[]) {
  hex *hexArray = init_hex_16();
  int index = 0;
  char buff[200];

  for (int i = 31; i >= 0; --i) {
    int bit = (num >> i) & 1;
    buff[index++] = bit + '0';
  }
  index = 0;

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
        }
      }
      counter = 0;
      digit++;
    }
    digit = 0;
    i += 4;
  }

  result[index] = '\0';
  char buff_2;
  index = 0;
  while (result[index] == '0') {
    index++;
  }
  i = 0;

  while (result[i + index] != '\0') {
    result[i] = result[i + index];
    printf("%c", result[i + index]);
    i++;
  }
  result[i] = '\0';
  printf("%d", index);
}

int main() {
  int number = 2543;
  char hexString[200];

  intToHexStatic(number, hexString);

  printf("Шестнадцатеричное представление: %s\n", hexString);

  free(init_hex());
  return 0;
}