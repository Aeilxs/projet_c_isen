#include "utils/mem.h"
#include "mods/log.h"
#include <stdlib.h>

void* imalloc(size_t s) {
    void* ptr = malloc(s);
    if (ptr == NULL) {
        log_fatal("Error during malloc");
        exit(EXIT_FAILURE);
    }
    return ptr;
}
