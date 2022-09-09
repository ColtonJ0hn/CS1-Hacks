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

int main(int argc, char ** argv) {

  double degree;
  double originLatitude;
  double originLongitude;
  double destinationLatitude;
  double destinationLongitude;
  double t;
  double percentC;
  double result;
  int numPassed = 0;
  int numFailed = 0;

  degree = 180;
  printf("TESTING: degreesToRadians(%f): ", degree);
  result = degreesToRadians(degree);
  result = round(result * 1000000) / 1000000;
  if (result != 3.141593) {
    printf("FAILED: degreesToRadians returned %f, expected 3.141593\n", result);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  degree = 900;
  printf("TESTING: degreesToRadians(%f): ", degree);
  result = degreesToRadians(degree);
  result = round(result * 1000000) / 1000000;
  if (result != 15.707963) {
    printf("FAILED: degreesToRadians returned %f, expected 15.707963\n", result);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  degree = 420;
  printf("TESTING: degreesToRadians(%f): ", degree);
  result = degreesToRadians(degree);
  result = round(result * 1000000) / 1000000;
  if (result != 7.330383) {
    printf("FAILED: degreesToRadians returned %f, expected 7.330383\n", result);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  originLatitude = 22;
  originLongitude = 34;
  destinationLatitude = 34;
  destinationLongitude = 22;
  // Int Cord 22, 34 Fin Cord 34, 22
  printf("TESTING: getAirDistance(%f, %f, %f, %f): ", originLatitude, originLongitude, destinationLatitude, destinationLongitude);
  result = getAirDistance(originLatitude, originLongitude, destinationLatitude, destinationLongitude);
  result = round(result * 1000000) / 1000000;
  if (result != 1777.069443) {
    printf("FAILED: getAirDistance returned %f, expected 1777.069443\n", result);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  originLatitude = -20;
  originLongitude = 25;
  destinationLatitude = 0;
  destinationLongitude = 46;
  // Int Cord -20, 25 Fin Cord 0, 46
  printf("TESTING: getAirDistance(%f, %f, %f, %f): ", originLatitude, originLongitude, destinationLatitude, destinationLongitude);
  result = getAirDistance(originLatitude, originLongitude, destinationLatitude, destinationLongitude);
  result = round(result * 1000000) / 1000000;
  if (result != 3189.536454) {
    printf("FAILED: getAirDistance returned %f, expected 3189.536454\n", result);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  originLatitude = 48.98;
  originLongitude = -23.4;
  destinationLatitude = 12.3;
  destinationLongitude = 22;
  // Int Cord 48.98, -23.4 Fin Cord 12.3, 22
  printf("TESTING: getAirDistance(%f, %f, %f, %f): ", originLatitude, originLongitude, destinationLatitude, destinationLongitude);
  result = getAirDistance(originLatitude, originLongitude, destinationLatitude, destinationLongitude);
   result = round(result * 1000000) / 1000000;
  if (result != 5819.835628) {
    printf("FAILED: getAirDistance returned %f, expected 5819.835628\n", result);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  t = 400;
  percentC = .5;
  // test case numbers : t = 400, percentC = 50
  printf("TESTING: lorentzTimeDilation(%f, %f): ", t, percentC);
  result = lorentzTimeDilation(t, percentC);
  result = round(result * 1000000) / 1000000;
  if (result != 461.880215) {
    printf("FAILED: lorentzTimeDilation returned %f, expected 461.880215\n", result);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  // test case numbers : t = 120 , percentC = 30
  t = 120;
  percentC = .3;
  printf("TESTING: lorentzTimeDilation(%f, %f): ", t, percentC);
  result = lorentzTimeDilation(t, percentC);
  result = round(result * 1000000) / 1000000;
  if (result != 125.794180) {
    printf("FAILED: lorentzTimeDilation returned %f, expected 125.794180\n", result);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  // test case numbers : t = 224 , percentC = 42
  t = 224;
  percentC = .42;
  printf("TESTING: lorentzTimeDilation(%f, %f): ", t, percentC);
  
  result = lorentzTimeDilation(t, percentC);
  result = round(result * 1000000) / 1000000;
  if (result != 246.825400 ) {
    printf("FAILED: lorentzTimeDilation returned %f, expected 246.825400\n", result);
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