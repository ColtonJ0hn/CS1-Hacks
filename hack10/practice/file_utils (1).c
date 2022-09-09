#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "file_utils.h"

char *getFileContents(const char *filePath) {
    if(filePath == NULL) {
        return NULL;

}

    FILE *content = fopen(filePath, "r");
    char buffer[1000000];
    char *s = fgets(buffer, 1000000, content);
    char *longs = NULL;
    longs = malloc(sizeof(char) * 1000000);
    memset(longs, '\0', 1000001);
    while(s != NULL) {

     strcat(longs , s);

    s = fgets(buffer, 1000000, content);

    }
longs[strlen(longs)+1] = '\0';
 fclose(content);
 return(longs);
}



  char **getFileLines(const char *filePath, int *numLines) {




  //char** all = malloc(sizeof(char) * 100000);
//   for(int i=0; i<100000; i++)
//   {
//     all[i] = malloc(sizeof(char) * *numLines);

//   }
//   FILE *content = fopen(filePath, "r");

//   for (int i=0; i < *numLines; i++){
//       for (int f=0; f <; i++){

//      char s = fgetc(content);
//      all[i][f]= s
//      while(s != EOF) {
//          s = fgetc(content);
//      }

//   }

//   return all;
}



