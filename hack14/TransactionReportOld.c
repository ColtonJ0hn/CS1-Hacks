#include <stdlib.h>

#include <stdio.h>

#include <string.h>

#include "transaction.h"

int main(int argc, char ** argv) {


    FILE *in = fopen(argv[1], "r");
    if (in == NULL) {
    fprintf(stderr, "Unable to open file: %s\n", argv[1]);
    exit(1);
  }
    char buffer[200];


    int n = atoi(fgets(buffer,200, in));

    Transaction *singleTrans = NULL;
    singleTrans = (Transaction *) malloc(sizeof(Transaction) * n);

    printf("%d\n", n);
    // char **transactions = NULL;
    // transactions = (char**) malloc(sizeof(char *) * (n));
    int i = 0;
    while (fgets(buffer, 200, in) != NULL) {
        buffer[strlen(buffer) - 1] = '\0';
        // transactions[i] = (char *) malloc(sizeof(char) * 200);

        // strcpy(transactions[i], buffer);
        
        //transactions[i][strlen(transactions[i]) - 1] = '\0';
        printf("%s\n",buffer);
        char *UUID = strtok(buffer, ",");

        char *type = strtok(NULL, ",");

        char *amountStr = strtok(NULL, ",");
        double amount = atof(amountStr);

        char  *accountNumber = strtok(NULL, ",");

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

                printOneStructure(&singleTrans[i], i);
        i++;


        }

    fclose(in);



//     tempBuffer[strlen(tempBuffer) - 1] = '\0';

//     char *UUID = strtok(tempBuffer, ",");
//     strcpy(teams[i], teamToken);
//     char *winToken = strtok(NULL, " ");
//     char *loseToken = strtok(NULL, " ");
//     double win = atoi(winToken);
//     double lose = atoi(loseToken);
//     double winPerc = win/(win+lose);
//     winPercentages[i] = winPerc;
//     i++;
//   }

//     fclose(*in);

return 0;
}





