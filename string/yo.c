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

  hex[0].num = "000";
  hex[0].xx = '0';

  hex[1].num = "001";
  hex[1].xx = '1';

  hex[2].num = "010";
  hex[2].xx = '2';

  hex[3].num = "011";
  hex[3].xx = '3';

  hex[4].num = "100";
  hex[4].xx = '4';

  hex[5].num = "101";
  hex[5].xx = '5';

  hex[6].num = "110";
  hex[6].xx = '6';

  hex[7].num = "111";
  hex[7].xx = '7';

  return hex;
}
void intToHexStatic(int num, char result[]) {
  hex *hexArray = init_hex();
  int index = 0;
  char buff[200];

  for (int i = 23; i >= 0; --i) {
    int bit = (num >> i) & 1;
    buff[index++] = bit + '0';
  }
  buff[index] = '\0';
  index = 0;

  int i = 0, counter = 0;
  while (i < 23 && buff[i] != '\0') {
    int digit = 0;
    while (digit < 8) {
      for (int j = 0; j < 3; ++j) {
        if (buff[i + j] == hexArray[digit].num[j]) {
          counter++;
        }
        if (counter == 3) {
          result[index++] = hexArray[digit].xx;
        }
      }
      counter = 0;
      digit++;
    }
    digit = 0;
    i += 3;
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
    // printf("%c", result[i + index]);
    i++;
  }
  result[i] = '\0';
  // printf("%d", index);
}

int main() {
  int number = 255;
  char hexString[200];

  intToHexStatic(number, hexString);

  printf("8ричное представление: %s\n", hexString);

  free(init_hex());
  return 0;
}