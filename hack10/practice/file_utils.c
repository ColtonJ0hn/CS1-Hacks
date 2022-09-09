#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include"file_utils.h"

 char *getFileContents(const char *filePath) {
    if(filePath == NULL ) {
        return NULL;

    }

    FILE *fileData = fopen(filePath, "r");
    if(fileData == NULL){
        return NULL;
    }
    
    char buffer[1000000];
    char *singleLine = fgets(buffer, 1000000, fileData);
    char *allLines = NULL;
    allLines = malloc(sizeof(char) * 1000000);
    memset(allLines, '\0', 1000001);
    while(singleLine != NULL) {

        strcat(allLines, singleLine);

        singleLine = fgets(buffer, 1000000, fileData);

    }
    allLines[strlen(allLines)+1] = '\0';
    fclose(fileData);
    return(allLines);
}



char **getFileLines(const char *filePath, int *numLines) {
    if(filePath == NULL || numLines == NULL ) {
        return NULL;
    }
     FILE *fileData = fopen(filePath, "r");
    if(fileData == NULL) {
        return NULL;
    }
    
     int lineCount = 0;
for (char c = getc(fileData); c != EOF; c = getc(fileData)){
        if (c == '\n'){          // Increment lineCount if this character is newline
            lineCount++;

        }

  }  // Close the file


    fclose(fileData);
    *numLines = lineCount;


    char ** lineString = NULL;
    lineString = (char ** ) malloc((sizeof(char * ) * (lineCount)));
    for(int i=0; i < lineCount; i++) {
        lineString[i] = (char *) malloc((sizeof(char *) * (1001)));
    }

    fileData = fopen(filePath, "r");
     if(fileData == NULL) {
        return NULL;
    }

    char buffer[1001];

   char *singleLine = fgets(buffer, 1001, fileData);

   int j = 0;
   int n = 0;
        while(singleLine != NULL) {


            if(singleLine[strlen(singleLine)-1] == '\n') {
                singleLine[strlen(singleLine)-1] = '\0';
            }

            strcpy(lineString[j], singleLine);
            n = strlen(lineString[j]);
            lineString[j][n +1] = '\0';
             singleLine = fgets(buffer, 1001, fileData);



                  j++;
        }

    fclose(fileData);

    return(lineString);


}





