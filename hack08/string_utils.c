/**
 * Author: Luke Whipple and Colton Johnson
 *         lwhipple9@huskers.unl.edu,  cjohnson184@huskers.unl.edu
 * Date: 2020/10/19
 *
 * 
 */
#include <stdlib.h>

#include <stdio.h>

#include <math.h>

#include <string.h>

#include "string_utils.h"

void replaceChar(char * s, char oldChar, char newChar) {
  if(s == NULL) {
     exit(0);
  }
  int strLength = strlen(s);
  for (int i = 0; i < strLength; i++) {
    if (oldChar == s[i]) {
      s[i] = newChar;
    }
  }
}

char * replaceCharCopy(const char * s, char oldChar, char newChar) {
     if (s == NULL) {
    return NULL;
  }
  char * copy = stringCopy(s);
  replaceChar(copy, oldChar, newChar);
  return (copy);
}

char * stringCopy(const char * s) {
     if (s == NULL) {
    return NULL;
  }
  char * copy = (char * ) malloc(sizeof(char) * (strlen(s) + 1));
  strcpy(copy, s);
  return copy;
}

void removeChar(char * s, char c) {
  if(s == NULL) {
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

char * removeCharCopy(const char * s, char c) {
     if (s == NULL) {
    return NULL;
  }
  char * copy = stringCopy(s);
  removeChar(copy, c);
  return (copy);
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