#include "mods/menu.h"
#include "mods/log.h"
#include "utils/fs.h"

char menu() {
    log_info("\n\n--- Menu ---\n\n");

    printf("[p] Print paths (useful to copy paste)\n\n");
    printf("[1] Sum all                  [2] Average all\n");
    printf("[3] Subtract two             [4] Divide two\n");
    printf("[5] Gen master               [6] Divide two\n");

    printf("\n[q] Exit\n");
    char choice;
    scanf("%c", &choice);
    flushStdin();
    return choice;
}