#include <stdio.h>
#include <string.h>

#define MAX 255

int main(void) {
  char buf[MAX];
  char *str_1, *str_2;

  str_1 = fgets(buf, MAX, stdin);
  // str_2 = fgets(buf, MAX, stdin);

  //printf("%s == %s", str_1, str_2);
  int len = strlen(str_1);
  for(int i=0; i <= len; i++) {
    buf[i] = (str_1[i] > 'Z') ? str_1[i] - ('z'-'Z') : str_1[i];
  }
  buf[len-1] = '\0';

  printf("%s\n", buf);

  return 0;
}
