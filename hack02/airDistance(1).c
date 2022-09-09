/**
 * Author: Luke Whipple and Colton Johnson
 *         lwhipple9@huskers.unl.edu,  cjohnson184@huskers.unl.edu
 * Date: 2020/08/27
 *
 * A program that computes the distance of 2 longitude and laditude locations.
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int main(int argc, char **argv) {


   double longitudeI, latitudeI; //Initial Coords
   double longitudeF, latitudeF; //Final Coords
   double airDistance;
   double EarthRadius = 6371.0;

  


   printf("Please input the Latitude and Longitude of the initial location.\n");
   scanf("%lf %lf", &latitudeI, &longitudeI);

   printf("Please input Latitude and Longitude of the final location\n");
   scanf("%lf %lf", &latitudeF, &longitudeF);

   printf("Location Distance\n =====================\nInitial Coords: (%f) , (%f)\n", latitudeI, longitudeI);
   printf("Final Coords: (%f) , (%f)\n", latitudeF, longitudeF);


   // equations to convert degrees to radians
   longitudeI = (longitudeI / 180) * M_PI;
   latitudeI = (latitudeI /180) * M_PI;

   longitudeF = (longitudeF / 180) * M_PI;
   latitudeF = (latitudeF / 180) * M_PI;




   // Long ass equation vvv
   airDistance = acos((sin(latitudeI) * sin(latitudeF)) + cos(latitudeI) * cos(latitudeF) * cos(longitudeI - longitudeF)) * (EarthRadius);

   printf("Air Distance is %f kms\n", airDistance);



}









