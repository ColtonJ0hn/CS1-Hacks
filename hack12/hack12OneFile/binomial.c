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

long chooseRecursive(int n, int k);
long chooseMemoization(int n, int k, long **table);

 
int main(int argc, char **argv) {
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);

    // long answer = choose( n, k);
    // printf("%ld\n", answer);
    // end = time(NULL);
    // int time = (end - start);
    // printf("Computation Time: %d seconds\n", time);


    long **table = (long **) malloc(sizeof(long *) * (n + 1));

    for(int i = 0; i <= n; i++){
        table[i] = (long *) malloc(sizeof(long) * (k + 1));
    }
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= k; j++){
            table[i][j] = 0;
            // printf("%ld\n", table[i][j]);
            
        }
    }
    table[0][0] = 1;
    table[1][0] = 1;
    table[1][1] = 1;
    table[2][0] = 1;
    table[2][1] = 2;
    table[2][2] = 1;
            
  long result = 0;
  result = chooseMemoization(n, k , table);
  //Printing all the table values
//   for (int i = 0; i <= n; i++){
//         for (int j = 0; j <= k; j++){
//             printf("%ld\n", table[i][j]);
//         }
//   }
  printf("%ld\n", result);

return 0;
}


long chooseMemoization(int n, int k, long **table){
    if(table[n][k] != 0){
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




// long chooseRecursive(int n, int k) {
//     if( n < k) {
//         printf("Incorrect input, n can't be less than k\n");
//         exit(1);
//     }
//     if( n == k || k == 0) {
//         return 1;
//     }
//     else {
//         return (chooseRecursive((n - 1),(k)) + chooseRecursive((n-1), (k-1)));

//     }

  //  return 0;
//}