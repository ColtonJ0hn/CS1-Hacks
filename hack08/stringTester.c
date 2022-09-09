/**
 * A complicated tester for multiple string functions.
 */

#include <stdlib.h>

#include <stdio.h>

#include "string_utils.h"

#include <string.h>

#include <math.h>

int main(int argc, char ** argv) {

  int pass = 0;
  int fail = 0;

  char test1[] = "bat bucks";
  int len = strlen(test1);
  test1[len + 1] = '\0';

  char oldChar = 'b';
  char newChar = 'h';

  replaceChar(test1, oldChar, newChar);

  if (test1[0] == 'h' && test1[1] == 'a' && test1[2] == 't' && test1[3] == ' ' && test1[4] == 'h' && test1[5] == 'u' && test1[6] == 'c' && test1[7] == 'k' && test1[8] == 's') {

    printf("Org:bat bucks New:%s : ReplaceChar Passed\n", test1);
    pass++;

  } else {
    printf("Org:bat bucks New:%s : ReplaceChar Failed\n", test1);
    fail++;
  }

  char test2[] = "bourke";
  len = strlen(test2);
  test2[len + 1] = '\0';

  oldChar = 'b';
  newChar = 't';

  replaceChar(test2, oldChar, newChar);

  if (test2[0] == 't' && test2[1] == 'o' && test2[2] == 'u' && test2[3] == 'r' && test2[4] == 'k' && test2[5] == 'e') {

    printf("Org:bourke New:%s : ReplaceChar Passed\n", test2);
    pass++;
  } else {
    printf("Org:bourke New:%s : ReplaceChar Failed\n", test2);
    fail++;
  }

  char test3[] = "rodgers";
  len = strlen(test3);
  test3[len + 1] = '\0';

  oldChar = 'r';
  newChar = 'g';

  replaceChar(test3, oldChar, newChar);

  if (test3[0] == 'g' && test3[1] == 'o' && test3[2] == 'd' && test3[3] == 'g' && test3[4] == 'e' && test3[5] == 'g' && test3[6] == 's') {

    printf("Org:rodgers New:%s : ReplaceChar Passed\n", test3);
    pass++;
  } else {
    printf("Org:rodgers New:%s : ReplaceChar Failed\n", test3);
    fail++;
  }

  char test4[] = "rat";
  len = strlen(test4);
  test4[len + 1] = '\0';

  oldChar = 'r';
  newChar = 't';

  char * copy = replaceCharCopy(test4, oldChar, newChar);

  if (copy[0] == 't' && copy[1] == 'a' && copy[2] == 't') {

    printf("Org:rat New:%s : ReplaceCharCopy Passed\n", copy);
    pass++;

  } else {
    printf("Org:rat New:%s : ReplaceCharCopy Failed\n", copy);
    fail++;
  }

  char test5[] = "bourke";
  len = strlen(test5);
  test5[len + 1] = '\0';

  oldChar = 'o';
  newChar = 'b';

  copy = replaceCharCopy(test5, oldChar, newChar);

  if (copy[0] == 'b' && copy[1] == 'b' && copy[2] == 'u' && copy[3] == 'r' && copy[4] == 'k' && copy[5] == 'e') {

    printf("Org:bourke New:%s  : ReplaceChar Passed\n", copy);
    pass++;
  } else {
    printf("Org:bourke New:%s  : ReplaceChar Failed\n", copy);
    fail++;
  }

  char test6[] = "rodgers";
  len = strlen(test6);
  test6[len + 1] = '\0';

  oldChar = 'r';
  newChar = 'g';

  copy = replaceCharCopy(test6, oldChar, newChar);

  if (copy[0] == 'g' && copy[1] == 'o' && copy[2] == 'd' && copy[3] == 'g' && copy[4] == 'e' && copy[5] == 'g' && copy[6] == 's') {

    printf("Org:rodgers New:%s : ReplaceChar Passed\n", copy);
    pass++;
  } else {
    printf("Org:rodgers New:%s : ReplaceChar Failed\n", copy);
    fail++;
  }

  char test7[] = "dada";
  len = strlen(test2);
  test2[len + 1] = '\0';

  char c = 'd';

  removeChar(test7, c);

  if (test7[0] == 'a' && test7[1] == 'a') {

    printf("ReplaceChar Passed\n");
    pass++;

  } else {
    printf("ReplaceChar Failed\n");
    fail++;
  }

  char test8[] = "luke";
  len = strlen(test8);
  test8[len + 1] = '\0';

  c = 'e';

  removeChar(test8, c);

  if (test8[0] == 'l' && test8[1] == 'u' && test8[2] == 'k') {

    printf("ReplaceChar Passed\n");
    pass++;

  } else {
    printf("ReplaceChar Failed\n");
    fail++;;
  }

  char test9[] = "pineapple";
  len = strlen(test9);
  test9[len + 1] = '\0';

  c = 'p';

  removeChar(test9, c);

  if (test9[0] == 'i' && test9[1] == 'n' && test9[2] == 'e' && test9[3] == 'a' && test9[4] == 'l' && test9[5] == 'e') {

    printf("ReplaceChar Passed\n");
    pass++;

  } else {
    printf("ReplaceChar Failed\n");
    fail++;
  }

  char test10[] = "dada";
  len = strlen(test10);
  test10[len + 1] = '\0';

  c = 'd';

  copy = removeCharCopy(test10, c);

  if (copy[0] == 'a' && copy[1] == 'a') {

    printf("ReplaceCharCopy Passed\n");
    pass++;

  } else {
    printf("ReplaceCharCopy Failed\n");
    fail++;
  }

  char test11[] = "luke";
  len = strlen(test11);
  test11[len + 1] = '\0';

  c = 'l';

  copy = removeCharCopy(test11, c);

  if (copy[0] == 'u' && copy[1] == 'k' && copy[2] == 'e') {

    printf("ReplaceCharCopy Passed\n");
    pass++;

  } else {
    printf("ReplaceCharCopy Failed\n");
    fail++;
  }
  char test12[] = "pineapple";
  len = strlen(test12);
  test12[len + 1] = '\0';

  c = 'p';

  copy = removeCharCopy(test12, c);

  if (copy[0] == 'i' && copy[1] == 'n' && copy[2] == 'e' && copy[3] == 'a' && copy[4] == 'l' && copy[5] == 'e') {

    printf("ReplaceCharCopy Passed\n");
    pass++;

  } else {
    printf("ReplaceCharCopy Failed\n");
    fail++;
  }

  int n = 3;
  char answer[6][4] = {
    "Yay",
    "! C",
    "ame",
    "ron",
    "!!!",
    "!"
  };
  char testsplit1[] = "Yay! Cameron!!!!";
  char ** result = lengthSplit(testsplit1, n);
  int flag = 1;
  for (int i = 0; i < ceil(strlen(testsplit1) / (double) n); i++) {
    if (strcmp(answer[i], result[i]) == 0) {} else {
      printf("LenSplit failed");
      flag = 0;
    }

  }
  if (flag == 1) {
    printf("lengthSplit Passed\n");
    pass++;
  } else {
    printf("lengthSplit Failed\n");
    fail++;
  }

  n = 6;
  char answer2[3][7] = {
    "Yay! C",
    "ameron",
    "!!!!"
  };
  char testsplit2[] = "Yay! Cameron!!!!";
  char ** result2 = lengthSplit(testsplit2, n);
  flag = 1;
  for (int i = 0; i < ceil(strlen(testsplit2) / (double) n); i++) {
    if (strcmp(answer2[i], result2[i]) == 0) {

    } else {
      printf("LenSplit failed");
      flag = 0;
    }

  }
  if (flag == 1) {
    printf("lengthSplit Passed\n");
    pass++;
  } else {
    printf("lengthSplit Failed\n");
    fail++;
  }

  n = 1;
  char answer3[16][2] = {
    "Y",
    "a",
    "y",
    "!",
    " ",
    "C",
    "a",
    "m",
    "e",
    "r",
    "o",
    "n",
    "!",
    "!",
    "!",
    "!"
  };
  char testsplit3[] = "Yay! Cameron!!!!";
  char ** result3 = lengthSplit(testsplit3, n);
  flag = 1;
  for (int i = 0; i < ceil(strlen(testsplit3) / (double) n); i++) {
    if (strcmp(answer3[i], result3[i]) == 0) {

    } else {
      printf("LenSplit failed");
      flag = 0;
    }

  }
  if (flag == 1) {
    printf("lengthSplit Passed\n");
    pass++;
  } else {
    printf("lengthSplit Failed\n");
    fail++;
  }

  printf("Number Passed: %d\nNumber Failed: %d\n", pass, fail);
}