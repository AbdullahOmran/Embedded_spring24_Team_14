
#include <stdio.h>
#include <math.h>

int main() {
    int n, c, k = 1;
    char output[255];

    printf("Enter number of rows: ");
    scanf("%d", &n);
    n = (n + 1) / 2;

    for (k = 0; k <= n; k++) {
        int index = 0;
        for (c = 1; c <= n - k; c++)
            output[index++] = ' ';

        for (c = 1; c <= 2 * k - 1; c++)
            output[index++] = '*';

        output[index++] = '\n';

        output[index] = '\0';
        printf("%s", output);
    }

    for (k = 1; k < n; k++) {
        int index = 0;

        for (c = 1; c <= k; c++)
            output[index++] = ' ';

        for (c = 1; c < 2 * (n - k); c++)
            output[index++] = '*';

        output[index++] = '\n';

        // Print the constructed line
        output[index] = '\0';
        printf("%s", output);
    }

    return 0;
}