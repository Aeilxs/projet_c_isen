#ifndef UTILS_MEM_H
#define UTILS_MEM_H

#include "mods/extractor.h"
#include <stddef.h>

/**
 * @brief malloc & check if nullptr
 * @param size size to allocate
 */
void *imalloc(size_t size);
/**
 * @brief Free FitFile struct.
 * @param ff FitFile ptr
 */
void freeFf(FitFile *ff);
/**
 * @brief Free 2D array string.
 * @param paths or 2D array of string
 * @param count number of strings inside the array
 */
void freePaths(char **paths, int count);

#endif