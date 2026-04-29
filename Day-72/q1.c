#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int visited[26] = {0};  // for 'a' to 'z'

    for (int i = 0; i < strlen(s); i++) {
        int index = s[i] - 'a';

        if (visited[index] == 1) {
            printf("%c\n", s[i]);
            return 0;
        }

        visited[index] = 1;
    }

    // If no repeated character
    printf("-1\n");

    return 0;
}