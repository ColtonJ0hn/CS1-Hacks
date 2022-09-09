/**
 * Author: Luke Whipple and Colton Johnson and David Dubchakov
 *
 * Date: 2020/11/6
 *
 * A program that uses memoization to calculate how many options you can pick from using Pascals rule
 *
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>



long chooseMemoization(int n, int k, long **table) {
    if(table[n][k] != 0) {
        return table[n][k];
    }
    else if(k <= 0 || n == k) {
        table[n][k] = 1;
        return table[n][k];
    }
    else {
        long result = chooseMemoization((n - 1), (k), table) + chooseMemoization((n - 1), (k - 1), table);
        table[n][k] = result;
        return result;
    }

}

