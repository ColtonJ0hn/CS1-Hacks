/**
 * Author: Luke Whipple and Colton Johnson and David Dubchakov
 *
 * Date: 2020/11/6
 *
 * A program that uses memoization to calculate how many options you can pick from using Pascals rule
 * Tests binomial.c
 *
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "binomial.h"

int main(int argc, char **argv) {
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);

    long **table = (long **) malloc(sizeof(long *) * (n + 1));

    for(int i = 0; i <= n; i++) {
        table[i] = (long *) malloc(sizeof(long) * (k + 1));
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            table[i][j] = 0;

        }
    }


    long long result = 0;
    result = chooseMemoization(n, k, table);
    printf("%lld\n", result);

    return 0;
}