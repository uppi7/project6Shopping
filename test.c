#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000 // 10^4 items

// Function to generate random integers in a given range
int generateRandom(int lower, int upper) {
    return lower + rand() % (upper - lower + 1);
}

int main() {
    FILE *outputFile = fopen("test_input.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Unable to create test file.\n");
        return 1;
    }

    srand(time(0)); // Seed for random number generation

    // Generate a random amount of money between 1 and 10^6
    int D = generateRandom(1, 1000000);

    // Write N and D to the file
    fprintf(outputFile, "%d %d\n", N, D);

    // Generate N random prices for items (between 1,000 and 1,000,000)
    for (int i = 0; i < N; i++) {
        int price = generateRandom(1000, 1000000);
        fprintf(outputFile, "%d ", price);
    }
    fprintf(outputFile, "\n");

    // Generate N random values for coupons (between 1 and 999)
    for (int i = 0; i < N; i++) {
        int coupon = generateRandom(1, 999);
        fprintf(outputFile, "%d ", coupon);
    }
    fprintf(outputFile, "\n");

    fclose(outputFile);

    printf("Test input generated in 'test_input.txt'.\n");
    return 0;
}
