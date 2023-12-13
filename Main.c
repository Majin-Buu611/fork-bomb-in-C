#include <stdio.h>
#include <unistd.h>

int main() {
  while (1) {
    printf("hello world!");
    fork();
  }

    return 1;
}
