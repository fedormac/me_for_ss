#include <stdio.h>

int main() {
  // Example unsigned integer value
  unsigned int num = -2;

  // Buffer to hold the string representation of the number
  char buffer[20];  // Assuming we need at most 19 characters for the number +
                    // null terminator

  // Convert the unsigned integer to a string
  sprintf(buffer, "%u", num);

  // Print the result
  printf("The string representation of %u is: %s\n", num, buffer);

  return 0;
}
