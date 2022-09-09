/**
 * Author: Colton Johnson
 * Date 2020/11/20
 * A complex program to output multiple reports
 * on the legitimiacy of bank and transaction record
 */
#include <stdlib.h>

#include <stdio.h>

#include <string.h>

#include <math.h>

#include "transaction.h"

int main(int argc, char ** argv) {

    int numTransactions;

    Transaction *transactions = loadFile(argv[1], &numTransactions);

    int origNumTrans = numTransactions;

    int paymentCount = 0;
    int transferCount = 0;
    int withdrawCount = 0;
    int debitCount = 0;
    int depositCount = 0;
    int totalCount = 0;
    int invalidCount = 0;

    long double invalidBeforeInt = 0;  //Doubles are poor varaibles for money. use int to store
    long double invalidAfterInt = 0;   //than convert to double to display
    long double invalidAmountInt = 0;

    double totalPayment = 0;
    double totalTransfer = 0;
    double totalWithdraw = 0;
    double totalDebit = 0;
    double totalDeposit = 0;
    double totalAmount = 0;
    double invalidDifference = 0;



    for(int k=0; k<numTransactions; k++) {
        if(strcmp(transactions[k].type, "PAYMENT") == 0) {
            paymentCount++;

            totalPayment += transactions[k].amount;

        }
        else if(strcmp(transactions[k].type, "TRANSFER") == 0) {
            transferCount++;

            totalTransfer += transactions[k].amount;

        }
        else if(strcmp(transactions[k].type, "WITHDRAWAL") == 0) {
            withdrawCount++;

            totalWithdraw += transactions[k].amount;

        }

        else if(strcmp(transactions[k].type, "DEBIT") == 0) {
            debitCount++;

            totalDebit += transactions[k].amount;

        }

        else if(strcmp(transactions[k].type, "DEPOSIT") == 0) {
            depositCount++;

            totalDeposit += transactions[k].amount;

        }

    }

    totalAmount = totalPayment + totalTransfer + totalWithdraw + totalDebit + totalDeposit;
    totalCount = paymentCount + transferCount + withdrawCount + debitCount + depositCount + totalCount;

    printReport(paymentCount, transferCount, withdrawCount, debitCount, depositCount, totalCount,
                totalPayment, totalTransfer, totalWithdraw, totalDebit, totalDeposit, totalAmount);

    for(int k=0; k<numTransactions; k++) {
        invalidBeforeInt = transactions[k].beforeBalance;
        invalidAfterInt = transactions[k].afterBalance;
        invalidAmountInt = transactions[k].amount;


        if(strcmp(transactions[k].type, "DEPOSIT") == 0 && round(invalidAfterInt * 100) !=
                round(invalidAmountInt * 100) + round(invalidBeforeInt * 100)) {
            invalidCount++;


            invalidDifference = (transactions[k].beforeBalance + transactions[k].amount) - transactions[k].afterBalance;

            printValidationReport(transactions, k, invalidDifference);
        }
        else if(round(invalidAmountInt * 100) != round(invalidBeforeInt * 100) - round(invalidAfterInt * 100) && (
                    strcmp(transactions[k].type, "PAYMENT") == 0 || strcmp(transactions[k].type, "TRANSFER") == 0 ||
                    strcmp(transactions[k].type, "WITHDRAWAL") == 0 || strcmp(transactions[k].type, "DEBIT") == 0 )) {
            invalidCount++;

            invalidDifference = ((transactions[k].afterBalance - transactions[k].beforeBalance) + transactions[k].amount);

            printValidationReport(transactions, k, invalidDifference);
        }




    }

    printf("Number of invalid balances found: %d\n", invalidCount);
    printf("=========================\n");

    int depositExceedingCount = 0;
    int depositApproachingCount = 0;
    int repeatedTransactionCount = 0;

    for(int i=0; i<numTransactions; i++) {
        if(strcmp(transactions[i].type, "DEPOSIT") == 0 && transactions[i].amount >= 10000) {
            depositExceedingCount++;
        }
        if(strcmp(transactions[i].type, "DEPOSIT") == 0 && (transactions[i].amount < 10000 &&
                transactions[i].amount > 9900)) {
            depositApproachingCount++;
        }
    }
    printDepositLimitReport(depositApproachingCount, depositExceedingCount);
//use comparators, sort by account, transfer and amount.

    qsort(transactions, numTransactions, sizeof(Transaction), cmpByRepeatedTransaction);




    for(int i=0; i < numTransactions - 1; i++) {
        while((strcmp(transactions[i].accountNumber, transactions[i+1].accountNumber) == 0) &&
                (strcmp(transactions[i].transferAccountNumber, transactions[i+1].transferAccountNumber) == 0) &&
                (transactions[i].amount == transactions[i+1].amount)) {
            printRepeatedTransactions(transactions, i);
            i++;
            repeatedTransactionCount++;

            if((strcmp(transactions[i].accountNumber, transactions[i+1].accountNumber) != 0) ||
                    (strcmp(transactions[i].transferAccountNumber, transactions[i+1].transferAccountNumber) != 0) ||
                    (transactions[i].amount != transactions[i+1].amount))   {
                repeatedTransactionCount++;
                printRepeatedTransactions(transactions, i);
            }

        }
    }
    printf("Repeated Transactions:%d\n", repeatedTransactionCount);
    int firstDigit = 0;
    int benfordOne = 0;
    int benfordTwo = 0;
    int benfordThree = 0;
    int benfordFour = 0;
    int benfordFive = 0;
    int benfordSix = 0;
    int benfordSeven = 0;
    int benfordEight = 0;
    int benfordNine = 0;
    double exactFrequency = 0;
    double benfordDifference = 0;
    double expectedFrequency = 0;
    for(int j=0; j<=numTransactions; j++) {
        firstDigit = transactions[j].amount;
        while(firstDigit >= 10) {
            firstDigit = firstDigit / 10;
        }
        if(firstDigit == 1) {
            benfordOne++;
        }
        if(firstDigit == 2) {
            benfordTwo++;
        }
        if(firstDigit == 3) {
            benfordThree++;
        }
        if(firstDigit == 4) {
            benfordFour++;
        }
        if(firstDigit == 5) {
            benfordFive++;
        }
        if(firstDigit == 6) {
            benfordSix++;
        }
        if(firstDigit == 7) {
            benfordSeven++;
        }
        if(firstDigit == 8) {
            benfordEight++;
        }
        if(firstDigit == 9) {
            benfordNine++;
        }
    }
    int i = 1;
    printf("=========================\n");
    printf("Benford Analysis Report\n");
    printf("=========================\n");
    printf("Number  Count  Frequency  Expected    Difference\n");
    exactFrequency = (double)benfordOne / numTransactions;
    expectedFrequency = .301;
    benfordDifference = exactFrequency - expectedFrequency;
    printBenfordAnalysis(i, benfordOne, exactFrequency, expectedFrequency, benfordDifference);
    i++;

    exactFrequency = (double)benfordTwo / numTransactions;
    expectedFrequency = .176;
    benfordDifference = exactFrequency - expectedFrequency;
    printBenfordAnalysis(i, benfordTwo, exactFrequency, expectedFrequency, benfordDifference);
    i++;

    exactFrequency = (double)benfordThree / numTransactions;
    expectedFrequency = .125;
    benfordDifference = exactFrequency - expectedFrequency;
    printBenfordAnalysis(i, benfordThree, exactFrequency, expectedFrequency, benfordDifference);
    i++;

    exactFrequency = (double)benfordFour / numTransactions;
    expectedFrequency = .097;
    benfordDifference = exactFrequency - expectedFrequency;
    printBenfordAnalysis(i, benfordFour, exactFrequency, expectedFrequency, benfordDifference);
    i++;

    exactFrequency = (double)benfordFive / numTransactions;
    expectedFrequency = .079;
    benfordDifference = exactFrequency - expectedFrequency;
    printBenfordAnalysis(i, benfordFive, exactFrequency, expectedFrequency, benfordDifference);
    i++;

    exactFrequency = (double)benfordSix / numTransactions;
    expectedFrequency = .067;
    benfordDifference = exactFrequency - expectedFrequency;
    printBenfordAnalysis(i, benfordSix, exactFrequency, expectedFrequency, benfordDifference);
    i++;

    exactFrequency = (double)benfordSeven / numTransactions;
    expectedFrequency = .058;
    benfordDifference = exactFrequency - expectedFrequency;
    printBenfordAnalysis(i, benfordSeven, exactFrequency, expectedFrequency, benfordDifference);
    i++;

    exactFrequency = (double)benfordEight / numTransactions;
    expectedFrequency = .051;
    benfordDifference = exactFrequency - expectedFrequency;
    printBenfordAnalysis(i, benfordEight, exactFrequency, expectedFrequency, benfordDifference);
    i++;

    exactFrequency = (double)benfordNine / numTransactions;
    expectedFrequency = .046;
    benfordDifference = exactFrequency - expectedFrequency;
    printBenfordAnalysis(i, benfordNine, exactFrequency, expectedFrequency, benfordDifference);

    printf("=========================\n");
    printf("Database Snapshot Tampering Report\n");
    printf("=========================\n");

    int missingTransaction = 0;

    Transaction *secondData = loadFile(argv[2], &numTransactions);
    qsort(secondData, numTransactions, sizeof(Transaction), cmpByUUID);
    qsort(transactions, origNumTrans, sizeof(Transaction), cmpByUUID);

    for(int i=0; i<origNumTrans; i++) {

        Transaction key = {transactions[i].UUID};
        Transaction *needle = (Transaction *) bsearch(&key, secondData, numTransactions, sizeof(Transaction), cmpByUUID);
        if(needle == NULL) {
            missingTransaction++;
            printf("Missing Transaction: %s in Database A but not in B\n", transactions[i].UUID);
        }
        Transaction key1 = {secondData[i].UUID};
        Transaction *needle1 = (Transaction *) bsearch(&key1, transactions, origNumTrans, sizeof(Transaction), cmpByUUID);
        if(needle1 == NULL) {
            missingTransaction++;
            printf("Missing Transaction: %s in Database B but not in A\n", secondData[i].UUID);
        }
        if(strcmp(transactions[i].UUID, secondData[i].UUID) == 0 && (strcmp(transactions[i].accountNumber,
                secondData[i].accountNumber) != 0 || strcmp(transactions[i].type, secondData[i].type) != 0 ||
                strcmp(transactions[i].transferAccountNumber, secondData[i].transferAccountNumber) != 0 ||
                transactions[i].amount != secondData[i].amount ||
                transactions[i].beforeBalance != secondData[i].beforeBalance  ||
                transactions[i].afterBalance != secondData[i].afterBalance)) {
            printf("Inconsistent data:\n");
            printf("    A:");
            printRepeatedTransactions(transactions, i);
            printf("    B:");
            printRepeatedTransactions(secondData, i);
        }
    }



    for(int i=0; i<numTransactions; i++) {
        free(transactions[i].UUID);
        free(transactions[i].type);
        free(transactions[i].accountNumber);
        free(transactions[i].transferAccountNumber);
        free(secondData[i].UUID);
        free(secondData[i].type);
        free(secondData[i].accountNumber);
        free(secondData[i].transferAccountNumber);

    }
    free(transactions);
    free(secondData);
    return 0;

}





