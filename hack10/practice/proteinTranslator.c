#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<math.h>
#include "protein_utils.h"

#include "file_utils.h"

int main(int argc, char ** argv) {

if(argc != 3) {
    break;
  }


  char * input = argv[1];
  char * output = argv[2];
  char * arr = getFileContents(input);

  char c = ' '; //removing white space
  removeChar(arr, c);

  dnaToRna(arr);

  char ** splitArr = lengthSplit(arr, 3);

  FILE * out = fopen(output, "w");
   double q = 3;
  for (int i = 0; i < ceil(strlen(arr) / q); i++) {
    char proteinLetter = rnaToProtein(splitArr[i]);
    if(proteinLetter == 'x'){
      fclose(out);
      
    }else{
      fprintf(out, "%c", proteinLetter);
    }


  }

  fclose(out);

}
// char * getFileContents(const char * filePath) {
//   if (filePath == NULL) {
//     return NULL;

//   }

//   FILE * content = fopen(filePath, "r");
//   if (content == NULL) {
//     return NULL;
//   }
//   int count = 0;
//   char c = fgetc(content);
//   while (c != EOF) {
//     count++;
//     c = fgetc(content);
//   }
//   rewind(content);
//   char buffer[1000];
//   char * s = fgets(buffer, 1000, content);
//   char * longs = NULL;
//   //printf("%d\n", count);
//   longs = (char * ) malloc(sizeof(char) * (count + 1));
//   memset(longs, '\0', count + 1);
//   while (s != NULL) {
//     strcat(longs, s);
//     s = fgets(buffer, 1000, content);
//     //printf("%s\n", buffer);

//   }

//   //printf("%s\n", longs);
//   longs[strlen(longs) + 1] = '\0';

//   fclose(content);
//   return (longs);
// }

void removeChar(char * s, char c) {
  if (s == NULL) {
    exit(0);
  }
  int len = strlen(s);
  int k = 0;
  for (int i = 0; i < len; i++) {
    if (s[i] != c) {
      s[k] = s[i];
      k++;
    }
  }

  s[k] = '\0';
}

void dnaToRna(char * arr) {
  for (int i = 0; i < strlen(arr); i++) {

    if (arr[i] == 'T') {
      arr[i] = 'U';
    }
  }
}

char ** lengthSplit(const char * s, int n) {
  if (s == NULL || n <= 0) {
    return NULL;
  }
  int len = strlen(s);
  int numSegments = ceil(len / (double) n);
  char ** lenSplit = NULL;
  lenSplit = (char ** ) malloc((sizeof(char * ) * (numSegments)));
  int k = 0;
  for (int i = 0; i < numSegments; i++) {
    char * lens = (char * ) malloc(sizeof(char) * (n + 1));
    memset(lens, '\0', n + 1);
    strncpy(lens, & s[k], n);
    lenSplit[i] = lens;
    k += n;

  }


  return (lenSplit);

}
// char rnaToProtein(const char * rna) {
//   if (rna == NULL || strlen(rna) != 3) {
//     return 0;
//   }
//   ProteinMap key = {
//     "",
//     '\0'
//   };
//   strcpy(key.trigram, rna);
//   ProteinMap * match = bsearch( & key, pMap, NUM_TRIGRAMS, sizeof(ProteinMap), proteinMapComp);
//   return (match == NULL) ? 0 : match -> protein;

// }

// int proteinMapComp(const void * a,
//   const void * b) {
//   const ProteinMap * x = (const ProteinMap * ) a;
//   const ProteinMap * y = (const ProteinMap * ) b;
//   return strcmp(x -> trigram, y -> trigram);
// }
