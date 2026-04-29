//Given integers a and b, compute a^b using recursion without using pow() function.

#include <stdio.h>

// Recursive function to calculate a^b
long long power(int a, int b) {
    // Base case
    if (b == 0)
        return 1;

    // Recursive case
    return a * power(a, b - 1);
}

int main() {
    int a, b;

    // Input
    scanf("%d %d", &a, &b);

    // Output
    printf("%lld\n", power(a, b));

    return 0;
}