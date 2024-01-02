#ifndef MODS_DATA_TREATMENT_H
#define MODS_DATA_TREATMENT_H

#include "mods/extractor.h"
#include <stdbool.h>
#include <stdio.h>

typedef void (*processFilesCb)(FitFile *ff, FitFile *ffToProcess);
FitFile *processFiles(int fCount, char **paths, processFilesCb processFilesCb);

/**
 * @brief Calculate pixel data. If overflow, return min or max value for int16t
 * type.
 * @param a
 * @param b
 * @param char must be + or -
 */
int16_t calculate(int16_t a, char op, int16_t b);
/**
 * @brief Callback function to use in processFiles.
 * @param ff
 * @param ffToProcess
 */
void processSumCb(FitFile *ff, FitFile *ffToProcess);
/**
 * @brief Callback function to use in processFiles.
 * @param ff
 * @param ffToProcess
 */
void processSubstractCb(FitFile *ff, FitFile *ffToProcess);
/**
 * @brief Callback function to use in processFiles, do avg on all.
 * @param ff
 * @param ffToProcess
 */
void processDivideCb(FitFile *ff, FitFile *ffToProcess);

#endif
