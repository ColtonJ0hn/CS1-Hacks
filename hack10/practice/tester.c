#include <stdlib.h>
#include <stdio.h>

#include "file_utils.h"

int main(int argc, char **argv) {
int n = 0;

char **arr = getFileLines("data.txt", &n);

printf("number of lines : %d\n", n);
for(int i=0; i < n; i++){
    
  printf("%s\n", arr[i]);

}

}