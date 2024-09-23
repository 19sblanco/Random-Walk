#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
This program calculates the placement of a pointer and the number of times that 
pointer crosses 0 on a random walk

for a random walk a pointer starts at 0 on the number line and there is a 50% chance that
pointer will either go left or right on the number line

This program also lets you adjust the 50% chance to any percent you like 
*/
int probability(double n) {
    double p = (double)rand() / (double)RAND_MAX;
    if (p > n) {
      return 0;
    }
    else {
      return 1;
    }
}

int main() {
    clock_t s = clock();
    srand(time(NULL));

    int itr;
    printf("Enter the number of iterations\n");
    scanf("%d", &itr);
    double n;
    printf("Enter the probability (a number between 0 and 1) that the pointer will go right\n");
    scanf("%le", &n);

    int crosses_0 = 0;
    int pointer = 0;
    for (int i = 0; i < itr; i++) {
      int result = probability(n);
      if (result == 1) {
        pointer++;
      }
      else {
        pointer--;
      }
      if (pointer == 0) {
        crosses_0++;
      }
    }
    clock_t e = clock();
    double time_spent = (double)(e - s) / CLOCKS_PER_SEC;
    printf("time spent: %f\n", time_spent);
    printf("pointer: %d\n", pointer);
    printf("crosses 0: %d\n", crosses_0);

    return 0;
}

