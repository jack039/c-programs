#include <stdio.h>

int main() {
    char oldPath[100], newPath[100];

    printf("Enter old file path: ");
    scanf("%s", oldPath);
    printf("Enter new file path: ");
    scanf("%s", newPath);

    if (rename(oldPath, newPath) == 0) {
        printf("File moved successfully.\n");
    } else {
        printf("Unable to move the file.\n");
    }

    return 0;
}
