/**
 * Author: Luke Whipple and Colton Johnson and David Dubchakov
 *         lwhipple9@huskers.unl.edu and cjohnson184@huskers.unl.edu and ddubchakov2@huskers.unl.edu
 * Date: 2020/10/30
 *
 * Purpose: This program encapsulates airport information to model an airport record from the ICAO database.
 */
#include <stdlib.h>

#include <stdio.h>

#include <string.h>

#include <math.h>

#include "airport.h"


char * deepStringCopy(const char * s) {
  if (s == NULL) {

  }
  char * c = (char * ) malloc((strlen(s) + 1) * sizeof(char));
  strcpy(c, s);
  return c;
}

Airport * createAirport(const char * gpsId,
  const char * type,
    const char * name,
      double latitude,
      double longitude,
      int elevationFeet,
      const char * city,
        const char * countryAbbrv) {
  Airport * airport = (Airport * ) malloc(sizeof(Airport) * 1);
  initAirport(airport, gpsId, type, name, latitude, longitude, elevationFeet, city, countryAbbrv);
  return airport;

}

void initAirport(Airport * airport,
  const char * gpsId,
    const char * type,
      const char * name,
        double latitude,
        double longitude,
        int elevationFeet,
        const char * city,
          const char * countryAbbrv) {
  airport -> gpsId = deepStringCopy(gpsId);
  airport -> type = deepStringCopy(type);
  airport -> name = deepStringCopy(name);
  airport -> latitude = latitude;
  airport -> longitude = longitude;
  airport -> elevationFeet = elevationFeet;
  airport -> city = deepStringCopy(city);
  airport -> countryAbbrv = deepStringCopy(countryAbbrv);
  return;
}

char * airportToString(const Airport * airport) {
  char temp[9999];
  sprintf(temp, "%s%s%s%f%f%d%s%s", airport -> gpsId, airport -> type, airport -> name, airport -> latitude,
    airport -> longitude, airport -> elevationFeet, airport -> city, airport -> countryAbbrv);
  return deepStringCopy(temp);
}

double getAirDistance(const Airport * origin,
  const Airport * destination) {
  double EarthRadius = 6371.0;
  double latOrg = origin -> latitude;
  double longOrg = origin -> longitude;

  double latDest = destination -> latitude;
  double longDest = destination -> longitude;

  longOrg = (longOrg / 180) * M_PI;
  latOrg = (latOrg / 180) * M_PI;

  longDest = (longDest / 180) * M_PI;
  latDest = (latDest / 180) * M_PI;

  return (acos((sin(latOrg) * sin(latDest)) +
    cos(latOrg) * cos(latDest) * cos(longOrg - longDest)) * (EarthRadius));

}

double getEstimatedTravelTime(const Airport * stops,
  int size,
  double aveKmsPerHour,
  double aveLayoverTimeHrs) {
  if (stops == NULL || size <= 1 || aveKmsPerHour <= 0 || aveLayoverTimeHrs < 0) {
    return 0;
  }
  double currDist = 0;
  double currHours = 0;
  double totHours = 0;
  for (int i = 0; i < size - 1; i++) {
    currDist = getAirDistance( & stops[i], & stops[i + 1]);
    currHours = currDist / aveKmsPerHour;
    totHours += currHours;
    if (i != 0) {
      totHours += aveLayoverTimeHrs;
    }

  }
  return (totHours);

}

int cmpByLatitude(const void* a, const void* b) {
  const int Airport *lat1 = (const int *) a;
  const int Airport *lat2 = (const int *) b;
  if( lat1.latitude < lat2.latitude ) {
    return -1;
  } else if( lat1.latitude > lat2.latitude ) {
    return 1;
  } else {
    return 0;
  }
}