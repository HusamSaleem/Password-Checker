#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// returns 1 if found, 0 if not
int checkPasswordAgainstDatabase(const char password[32]) {
    FILE *fp;
    char buffer[32];
    fp = fopen("./passwordList.txt", "r");

    if (fp) {
        while (fgets(buffer, sizeof(buffer), fp)) {
            //printf("%s\n", buffer); // Commented out to save time

            if (strcmp(password, buffer) == 0) {
                fclose(fp);
                return 1;
            }
        }
    }

    fclose(fp);
    return 0;
}

int main(void) {
    char passwordInput[32];
    printf("Enter your password to be checked against 10M other passwords. You will also get the strength level of this password: ");
    fgets(passwordInput, 32, stdin);

    int found = checkPasswordAgainstDatabase(passwordInput);

    if (found == 1) {
        printf("Your password was found in the common list of passwords. Immediately change your password!");
    } else {
        printf("Your password was not found in the common list of passwords. Good job!");
    }

    return 0;
}