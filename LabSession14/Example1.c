#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *username = "newuser";

    char command[100];
    snprintf(command, sizeof(command), "sudo useradd %s", username);

    // Execute the command
    int status = system(command);

    // Check status
    if (status == 0) {
        printf("User %s created successfully with home directory.\n", username);
    } else {
        fprintf(stderr, "Error creating user %s.\n", username);
    }

    return 0;
}
