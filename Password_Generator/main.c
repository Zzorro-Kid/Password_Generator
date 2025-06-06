#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_password(int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyz"
                           "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                           "0123456789"
                           "!@#$%^&*()-_=+[]{}";
    char password[100];

    for (int i = 0; i < length; i++) {
        int key = rand() % (sizeof(charset) -1);
        password[i] = charset[key];
    }

    password[length] = '\0';

    printf("Your password is: %s\n", password);
}

int main() {
    int length;

    srand(time(NULL));

    printf("Enter the password length (up to 99): ");
    scanf("%d", &length);

    if (length < 1 || length >= 100) {
        printf("Incorrect length. Try again\n");
        return 1;
    }

    generate_password(length);

    printf("\nPress Enter to exit...");
    getchar();
    getchar();

    return 0;
}