#include <stdio.h>

unsigned char rotate_right(unsigned char x, int n) {
    return (x >> n) | (x << (8 - n));
}

unsigned char rotate_left(unsigned char x, int n) {
    return (x << n) | (x >> (8 - n));
}

int main() {
    unsigned char x;
    int n;
    char option;

    printf("Enter an 8-bit number: ");
    scanf("%hhu", &x);

    printf("Enter the number of rotate cycles: ");
    scanf("%d", &n);

    printf("Enter the rotate option (r for right, l for left): ");
    scanf(" %c", &option);

    if (option == 'r') {
        printf("Rotate right %d times: %hhu\n", n, rotate_right(x, n));
    } else if (option == 'l') {
        printf("Rotate left %d times: %hhu\n", n, rotate_left(x, n));
    } else {
        printf("Invalid option\n");
    }

    return 0;
}