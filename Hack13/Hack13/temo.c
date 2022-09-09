#include <stdlib.h>

#include <stdio.h>

#include <string.h>

#include "airport.h"

//(airport#, gpsId, type, name, latitude, longitude, elevationFeet, city, countryAbbrv);
int main(int argc, char ** argv) {



void printReport() {
    printf("=========================\n");
    printf("Totals Report\n");
    printf("=========================\n");
    printf("Type    Count    Total\n");
     printf("=========================\n");
     printf("Payment   0  $   0.0\n");
     printf("Transfer   0  $   0.0\n");
     printf("Withdraw   0  $   0.0\n");
     printf("Debit   0  $   0.0\n");
     printf("Deposit   0  $   0.0\n");
      printf("=========================\n");
      printf("Total   0  $   0.0\n");
      
}
    //for(int i=0; i<n; i++) {
        // printf("GPS-ID:%-7s Type:%-15s Name:%-35s Lat:%-10f Long:%-11f Elevation:%-4d City:%-12s Country:%s\n",

        //       airports[i].gpsId,
        //       airports[i].type,    //gpsId, type, name, latitude, longitude, elevationFeet, city, countryAbbrv
        //       airports[i].name,
        //       airports[i].latitude,
        //       airports[i].longitude,
        //       airports[i].elevationFeet,
        //       airports[i].city,
        //       airports[i].countryAbbrv
        //       );

    //}
   // printf("\n\n");
//}
// void printOneAirport(const Airport *airports, int i) {
//     printf("Airport\n");
//     printf("=========================\n");
//     printf("GPS-ID:%s Type:%s Name:%s Lat:%f Long:%f Elevation:%d City:%s Country:%s\n",
//           airports[i].gpsId,
//           airports[i].type,    //gpsId, type, name, latitude, longitude, elevationFeet, city, countryAbbrv
//           airports[i].name,
//           airports[i].latitude,
//           airports[i].longitude,
//           airports[i].elevationFeet,
//           airports[i].city,
//           airports[i].countryAbbrv
//           );
//     printf("\n\n");
}



void printOneStructure(const Transaction *singleTrans, int i) {
    printf("test\n"); printf("=========================\n");
    printf(":%s :%s :%s :%f :%s :%f :%f :%s\n",
           singletrans[i].UUID,
           singleTrans[i].type,    //gpsId, type, name, latitude, longitude, elevationFeet, city, countryAbbrv
           singleTrans[i].amount,
           singleTrans[i].accountNumber,
           singleTrans[i].beforeBalance,
           singleTrans[i].afterBalance,
           singleTrans[i].transferAccountNumber,
          );
    printf("\n\n");
}






    FILE *in = fopen(argv[1], "r");
    if (in == NULL) {
    fprintf(stderr, "Unable to open file: %s\n", argv[1]);
    exit(1);
  }
    char buffer[200];
    memset(buffer, '\0', 200);

    int n = atoi(fgets(buffer,200, in));
     Transaction *singleTrans = NULL;
     singleTrans = (Transaction*) malloc(sizeof(Transaction) * n);
    printf("%d\n", n);

    int i = 0;
   


    //for(int k = 0; k < n; k++ ) {
    
    
    while ( buffer != NULL) {

  fgets(buffer, 200, in);

buffer[strlen(buffer) - 1] = '\0';


Transaction stringToTransaction(char *buffer) {

         char *UUID = strtok(buffer, ",");

        char *type = strtok(NULL, ",");

        char *amountStr = strtok(NULL, ",");
        double amount = atof(amountStr);

        char *accountNumber = strtok(NULL, ",");

       char *beforeBalanceStr = strtok(NULL, ",");
        double beforeBalance = atof(beforeBalanceStr);

       char *afterBalanceStr = strtok(NULL, ",");
        double afterBalance = atof(afterBalanceStr);

        char *transferAccountNumber = strtok(NULL, ",");

     initTransaction(&singleTrans[i],
                UUID,
                type,
                amount,
                accountNumber,
                beforeBalance,
                afterBalance,
                transferAccountNumber);

    Transaction * struct = (Transaction * ) malloc(sizeof(struct) * 1);
    initTransaction(struct,
                UUID,
                type,
                amount,
                accountNumber,
                beforeBalance,
                afterBalance,
                transferAccountNumber);
    return struct;

}
    
