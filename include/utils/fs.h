#ifndef FS_H
#define FS_H

#include "mods/extractor.h"
#include <stdio.h>

/**
 * @brief fopen & check if nullptr
 * @param path
 * @param opts i. e. rb
 */
FILE *open(const char *path, const char *opts);
/**
 * @brief Write HDU part in CSV format.
 * @param outFile file ptr
 * @param ff FitFile struct
 */
void writeCsvPrim40(FILE *outFile, FitFile *ff);

void writeFit(FILE *outFile, FitFile *ff);

int flushStdin();

#endif