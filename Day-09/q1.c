/*A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that 
its characters appear in the opposite order.*/

#include <stdio.h>
#include <string.h>

// Recursive function to print string in reverse
void mirror(char str[], int index) {
    // Base case
    if (index < 0)
        return;

    // Print current character
    printf("%c", str[index]);

    // Recursive call
    mirror(str, index - 1);
}

int main() {
    char str[100];

    // Input
    scanf("%s", str);

    int len = strlen(str);

    // Output (mirror)
    mirror(str, len - 1);

    return 0;
}