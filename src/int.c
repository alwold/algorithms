#include <math.h>
#include <stdlib.h>

char *int_to_str(int number) {
  // sample = 400
  if (number == 0) {
    char *str = malloc(sizeof(char)*2);
    str[0] = '0';
    str[1] = '\0';
    return str;
  }
  int negative = number < 0 ? 1 : 0;
  number = abs(number);
  int digits = log10(number)+1;
  // digits = 3
  char *str = malloc(sizeof(char)*(digits+1));
  str[digits] = '\0';
  for (int i = 0; i < digits; i++) {
    // if i = 0, digits - i - 1 = 2, pow(10, 2) = 100
    int power = pow(10, digits-i-1);
    int digit = number/power;
    number = number - digit * power;
    // digit = 4
    str[i] = '0'+digit;
  }
  if (negative) {
    char *nstr = malloc(sizeof(char)*(digits+2));
    nstr[0] = '-';
    nstr[1] = '\0';
    strcat(nstr, str);
    free(str);
    return nstr;
  } else {
    return str;
  }
}