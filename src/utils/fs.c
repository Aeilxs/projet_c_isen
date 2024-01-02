#include "utils/fs.h"
#include "mods/extractor.h"
#include "mods/log.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

FILE *open(const char *path, const char *opts) {
    FILE *f = fopen(path, opts);
    if (f == NULL) {
        log_fatal("Can't open: %s with options: %s", path, opts);
        exit(EXIT_FAILURE);
    }

    return f;
}

int16_t swapEndian16(int16_t val);
int16_t swapEndian16(int16_t value) { return (value >> 8) | (value << 8); }
void writeCsvPrim40(FILE *outFile, FitFile *ff) {
    log_info("Writing CSV...");
    for (int i = 0; i < ff->arrlen; i++) {
        int16_t swapped = swapEndian16(ff->data[i]);
        uint16_t realValue =
            (uint16_t)ff->header.bscale * swapped + ff->header.bzero;
        fprintf(
            outFile,
            "%hx;%s",
            realValue,
            (i + 1) % ff->header.naxis1 ? "" : "\n"
        );
    }
}

void writeFit(FILE *outFile, FitFile *ff) {
    log_info("Writing fit...");
    fseek(outFile, 0, SEEK_SET);
    fwrite(ff->header.raw, BYTES_PER_BLOCK, 1, outFile);
    fwrite(ff->data, ff->bytesPdu, 1, outFile);
}

int flushStdin() {
    int chr, count = 0;
    while ((chr = getchar()) != '\n' && chr != EOF) {
        ++count;
    }
    return count;
}