#include <stdio.h>

int main(int argc, char *argv[]) {
  int i;
  int count = 0;
  int *p = &count;

  for (i = 0; i < 10; i++) {
    printf("%d\t", (*p)++); // Do you understand this line of code and all the
                            // other permutations of the operators? ;)
  }
  printf("\nThanks for waddling through this program. Have a nice day.");
  return 0;
}