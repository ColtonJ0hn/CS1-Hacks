/**
 * This program performs several ad-hoc unit
 * tests on turning degrees into radians and the
 * air distance between two objects as well as
 * the time dilation between objects in space.
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "utils.h"

int main(int argc, char **argv) {

   double degree = 180;
   double originLatitude;
   double originLongitude;
   double destinationLatitude;
   double destinationLongitude;
   double t = 400;
   double percentC = 50;
   int result;
   int expectedResult;
   int numPassed = 0;
   int numFailed = 0;

    printf("TESTING: degreesToRadians(%lf): ", degree);
  result = degreesToRadians(degree);
  if(result !=3) {
    printf("FAILED: degreesToRadians returned %d, expected 3\n", result);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  degree = 900;
  printf("TESTING: degreesToRadians(%lf): ", degree);
  result = degreesToRadians(degree);
  if(result !=16) {
    printf("FAILED: degreesToRadians returned %d, expected 6\n", result);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

    degree = 420;
  printf("TESTING: degreesToRadians(%lf): ", degree);
  result = degreesToRadians(degree);
  if(result !=7) {
    printf("FAILED: degreesToRadians returned %d, expected 7\n", result);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

   printf("TESTING: getAirDistance(%lf, %lf, %lf, %lf): ",originLatitude, originLongitude, destinationLatitude, destinationLongitude);
  result = degreesToRadians(degree);
  if(result !=3) {
    printf("FAILED: degreesToRadians returned %d, expected 3\n", result);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }


   printf("TESTING: lorentzTimeDilation(%lf, %lf): ",t, percentC);
  result = lorentzTimeDilation(t, percentC);
  if(result !=408) {
    printf("FAILED: lorentzTimeDilation returned %d, expected 408\n", result);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }






    printf("Number Test Cases Passed: %6d\n", numPassed);
  printf("Number Test Cases Failed: %6d\n", numFailed);
  printf("Percent Passed:           %6.2f\n", 100.0 * numPassed / (numPassed + numFailed));

  return 0;
  }