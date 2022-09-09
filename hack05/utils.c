/**
 * Author: Luke Whipple and Colton Johnson
 *         lwhipple9@huskers.unl.edu,  cjohnson184@huskers.unl.edu
 * Date: 2020/09/18
 *
 * A program that turns simple degrees into radians, and then calculates air distance.
 * As well as calculates the time dilation between objects moving fast and stationary.
 *
 */
#include <stdlib.h>

#include <stdio.h>

#include <math.h>

  double degreesToRadians(double degree) {
  double rad;
  rad = (degree * M_PI) / 180.0;
  return(rad);
}
  double  getAirDistance(
  double originLatitude,
  double originLongitude,
  double destinationLatitude,
  double destinationLongitude) {
  double airDistance;
  double earthRadius = 6371.0;

  originLatitude = degreesToRadians(originLatitude);
  originLongitude = degreesToRadians(originLongitude);
 
  destinationLongitude = degreesToRadians(destinationLongitude);
  destinationLatitude = degreesToRadians(destinationLatitude);
 
  airDistance = acos((sin(originLatitude) * sin(destinationLatitude)) + cos(originLatitude) *
    cos(destinationLatitude) * cos(originLongitude - destinationLongitude)) * (earthRadius);

  return airDistance;
}

  double lorentzTimeDilation(double t, double percentC) {
  double dilatedTime;
  dilatedTime = t / sqrt(1 - pow(percentC, 2));
  return dilatedTime;
}