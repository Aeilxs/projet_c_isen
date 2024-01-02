#ifndef MODS_FITFILE_H
#define MODS_FITFILE_H

#include "config.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

/**
 * @brief Header useful data for the project.
 */
typedef struct FitHeader {
    int bscale;
    int bzero;
    int naxis1;
    int naxis2;
    int bitpix;
    uint8_t raw[BYTES_PER_BLOCK];
} FitHeader;

/**
 * @brief FitFile struct with header, data and some utilities.
 * @param header FitHeader struct
 * @param data pixels array
 * @param bytesTot total bytes in HDU part
 * @param arrlen arrlen for data
 */
typedef struct FitFile {
    FitHeader header;
    int16_t *data;
    size_t bytesPdu;
    int arrlen;
} FitFile;

/**
 * @brief PRIM30: print formatted header to stdout.
 * @param rawHeader 2880 bytes char / uint8_t array.
 */
void printHeaderPrim30(uint8_t rawHeader[BYTES_PER_BLOCK]);

/**
 * @brief Extract FitFile - need to use freeFf() after to free ff->data & ffPtr.
 * @param file ptr to file
 */
FitFile *extract(FILE *file);

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
void dumpHeader(FitHeader *header, bool printRaw);

#endif
