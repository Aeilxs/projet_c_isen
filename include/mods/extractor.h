#ifndef MODS_FITFILE_H
#define MODS_FITFILE_H

#include "config.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

typedef struct FitHeader {
    int bscale;
    int bzero;
    int naxis1;
    int naxis2;
    int bitpix;
    uint8_t raw[BYTES_PER_BLOCK];
} FitHeader;

typedef struct FitFile {
    FitHeader header;
    uint16_t* data;
} FitFile;

/**
 * @brief PRIM30: print formatted header to stdout.
 * @param rawHeader 2880 bytes char / uint8_t array.
 */
void printHeaderPrim30(uint8_t rawHeader[BYTES_PER_BLOCK]);

/**
 * @brief Extract FitFile
 * @param file ptr to file
 */
FitFile extract(FILE* file);

/**
 * @brief Process the HDU (Header Data Unit) and stock in FitHeader required
 * values for the project.
 * @param rawHeader 2880 bytes char / uint8_t array.
 */
FitHeader getHeader(uint8_t rawHeader[BYTES_PER_BLOCK]);

/**
 * @brief Debug function. Print Fitheader properties on stdout.
 * @param header header ptr
 * @param printRaw boolean, true= print false= no print
 */
void dumpHeader(FitHeader* header, bool printRaw);

#endif
