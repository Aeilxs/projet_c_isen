#include "utils/fs.h"
#include "mods/log.h"
#include <stdio.h>
#include <stdlib.h>

FILE* open(const char* path, const char* opts) {
    FILE* f = fopen(path, opts);
    if (f == NULL) {
        log_fatal("Can't open: %s with options: %s", path, opts);
        exit(EXIT_FAILURE);
    }

    return f;
}
