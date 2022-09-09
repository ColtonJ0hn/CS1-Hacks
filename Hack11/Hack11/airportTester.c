#include <stdlib.h>

#include <stdio.h>

#include <string.h>

#include "airport.h"

//(airport#, gpsId, type, name, latitude, longitude, elevationFeet, city, countryAbbrv);
int main(int argc, char ** argv) { //elevation 1219 Latitude: 40.8507 Longitude: -96.7555

  int pass = 0;
  int fail = 0;

  Airport a1, a2, a3, a4, a5, a6;
  initAirport( & a1, "LNK", "Public/Military", "Lincoln Airport", 40.8507, -96.7555, 1219, "Lincoln", "USA");
  initAirport( & a2, "ADS", "Public/Military", "Addison Airport", 32.9678, -96.8351, 644, "Dallas", "USA");
  initAirport( & a3, "DCA", "Public/Military", "Ronald Reagan Washington National Airport", 38.8512, 77.0402, 15.09,
    "Arlington", "USA");
  initAirport( & a4, "LAX", "Public/Military", "Los Angeles International", 33.9416, 118.4085, 125, "Los Angeles", "USA");
  initAirport( & a5, "HNL", "Public/Military", "Honalulu International", 21.3069, 157.8583, 19.69, "Honalulu", "USA");

  double AD1 = getAirDistance( & a1, & a2);
  if (AD1 > 876.56 && AD1 < 876.569999) {
    printf("Passed!~~ actual:876.566936\n            Ours:%f\n\n", AD1);
    pass++;
  } else {
    printf("Failed!~~ actual:876.566936\n           Ours:%f\n\n", AD1);
    fail++;
  }
  double AD2 = getAirDistance( & a2, & a3);
  if (AD2 > 12004.185 && AD2 < 12004.185999) {
    printf("Passed!~~ actual:12004.185554\n            Ours:%f\n\n", AD2);
    pass++;
  } else {
    printf("Failed!~~ actual:12004.185554\n        Ours:%f\n\n", AD2);
    fail++;
  }

  double AD3 = getAirDistance( & a3, & a4);
  if (AD3 > 3710.76 && AD3 < 3710.769480) {
    printf("Passed!~~ actual:3710.769480\n            Ours:%f\n\n", AD3);
    pass++;
  } else {
    printf("Failed!~~ actual:4102.894902\n           Ours:%f\n\n", AD3);
    fail++;
  }

  double AD4 = getAirDistance( & a4, & a5);
  if (AD4 > 4102.89 && AD4 < 4102.89999) {
    printf("Passed!~~ actual:4102.894902\n            Ours:%f\n\n", AD4);
    pass++;
  } else {
    printf("Failed!~~ actual:4102.894902\n           Ours:%f\n\n", AD4);
    fail++;
  }
  double AD5 = getAirDistance( & a5, & a6);
  if (AD5 > 16640.15 && AD5 < 16640.169999) {
    printf("Passed!~~ actual:16640.166845\n            Ours:%f\n\n", AD5);
    pass++;
  } else {
    printf("Failed!~~ actual:16640.166845\n           Ours:%f\n\n", AD5);
    fail++;
  }

  int n = 3;
  Airport * library = (Airport * ) malloc(sizeof(Airport) * n);
  library[0] = a1;
  library[1] = a2;
  library[2] = a3;

  Airport * library2 = (Airport * ) malloc(sizeof(Airport) * n);
  library2[0] = a1;
  library2[1] = a4;
  library2[2] = a5;

  Airport * library3 = (Airport * ) malloc(sizeof(Airport) * n);
  library3[0] = a1;
  library3[1] = a3;
  library3[2] = a5;

  double time = getEstimatedTravelTime(library, 3, 900, 3);

  if (time > 17.3119 && time < 17.31199999) {
    printf("Passed!~~ actual:17.311947\n            Ours:%f\n\n", time);
    pass++;
  } else {
    printf("Failed!~~ actual:17.311947\n        Ours:%f\n\n", time);
    fail++;
  }

  time = getEstimatedTravelTime(library2, 3, 900, 3);

  if (time > 19.72 && time < 19.7299999) {
    printf("Passed!~~ actual:19.728366\n            Ours:%f\n\n", time);
    pass++;
  } else {
    printf("Failed!~~ actual:19.728366\n        Ours:%f\n\n", time);
    fail++;
  }

  time = getEstimatedTravelTime(library3, 3, 900, 3);

  if (time > 24.002 && time < 24.0099999) {
    printf("Passed!~~ actual:24.002744\n            Ours:%f\n\n", time);
    pass++;
  } else {
    printf("Failed!~~ actual:24.002744\n        Ours:%f\n\n", time);
    fail++;
  }

  printf("\n # Passed: %d   # Failed: %d", pass, fail);

  return 0;
}