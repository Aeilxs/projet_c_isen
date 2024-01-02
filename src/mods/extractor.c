#include "mods/extractor.h"
#include "mods/log.h"
#include "utils/mem.h"
#include "utils/strings.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// clang-format off
void to_matrix(uint8_t rawHeader[BYTES_PER_BLOCK], char buffer[FIT_HEADER_LINE_TOT][FIT_HEADER_LINE_LEN + 2]);
void insertKeys(FitHeader *header, char key[8], char val[73]);
bool isValidKey(char key[8]);
// clang-format on

FitFile *extract(FILE *file) {
    FitFile *ff = (FitFile *)imalloc(sizeof(FitFile));
    uint8_t hBuffer[BYTES_PER_BLOCK];
    fread(hBuffer, BYTES_PER_BLOCK, 1, file);
    ff->header = getHeader(hBuffer);

    fseek(file, 0, SEEK_END);
    ff->bytesPdu = ftell(file) - BYTES_PER_BLOCK;
    fseek(file, BYTES_PER_BLOCK, SEEK_SET);

    ff->arrlen = ff->bytesPdu / 2;
    ff->data = (int16_t *)imalloc(ff->bytesPdu);
    fread(ff->data, ff->bytesPdu, 1, file);
    return ff;
}

FitHeader getHeader(uint8_t rawHeader[BYTES_PER_BLOCK]) {
    FitHeader header;
    header.bitpix = 0;
    header.bscale = 0;
    header.bzero = 0;
    header.naxis1 = 0;
    header.naxis2 = 0;
    char buffer[FIT_HEADER_LINE_TOT][FIT_HEADER_LINE_LEN + 2];
    to_matrix(rawHeader, buffer);
    char key[9], val[73];

    for (int i = 0; i < FIT_HEADER_LINE_TOT; i++) {
        sscanf(buffer[i], "%8s %[^\n]s", key, val);
        if (!strcmp(key, "END")) break;
        insertKeys(&header, key, val);
    }

    for (int i = 0; i < BYTES_PER_BLOCK; i++) {
        header.raw[i] = rawHeader[i];
    }

    return header;
}

void insertKeys(FitHeader *header, char key[8], char val[73]) {
    if (!isValidKey(key)) return;
    trim(val, ' ');
    trim(val, '=');
    if (!strcmp(key, "NAXIS1")) {
        header->naxis1 = atoi(val);
        return;
    } else if (!strcmp(key, "NAXIS2")) {
        header->naxis2 = atoi(val);
        return;
    } else if (!strcmp(key, "BSCALE")) {
        header->bscale = atoi(val);
        return;
    } else if (!strcmp(key, "BZERO")) {
        header->bzero = atoi(val);
        return;
    } else if (!strcmp(key, "BITPIX")) {
        header->bitpix = atoi(val);
        return;
    }
}

bool isValidKey(char key[8]) {
    const int validKeysLength = 5;
    const char *validKeys[] = {"NAXIS1", "NAXIS2", "BSCALE", "BZERO", "BITPIX"};
    for (int i = 0; i < validKeysLength; i++) {
        if (!strcmp(key, validKeys[i])) return true;
    }
    return false;
}

void to_matrix(
    uint8_t rawHeader[BYTES_PER_BLOCK],
    char buffer[FIT_HEADER_LINE_TOT][FIT_HEADER_LINE_LEN + 2]
) {
    int index = 0;
    for (int y = 0; y < FIT_HEADER_LINE_TOT; y++) {
        for (int x = 0; x < FIT_HEADER_LINE_LEN; x++) {
            buffer[y][x] = rawHeader[index++];
        }
        buffer[y][FIT_HEADER_LINE_LEN - 1] = '\n';
        buffer[y][FIT_HEADER_LINE_LEN] = '\0';
    }
}

void printHeaderPrim30(uint8_t header[BYTES_PER_BLOCK]) {
    log_info("");
    for (int i = 0; i < BYTES_PER_BLOCK; i++) {
        printf("%c", header[i]);
        printf("%s", (i + 1) % 80 ? "" : "\n");
    }
}

void dumpHeader(FitHeader *header, bool printRaw) {
    log_debug("Header dump:\n\n");
    printf("naxis1: %d\n", header->naxis1);
    printf("naxis2: %d\n", header->naxis2);
    printf("bscale: %d\n", header->bscale);
    printf("bzero: %d\n", header->bzero);
    printf("bitpix: %d\n\n", header->bitpix);

    // can't use %s bcs no null char
    if (printRaw) {
        log_debug("Raw print: \n");
        for (int i = 0; i < BYTES_PER_BLOCK; i++) {
            printf("%c", header->raw[i]);
        }
    }
}
