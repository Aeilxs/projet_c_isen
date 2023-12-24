#ifndef UTILS_MEM_H
#define UTILS_MEM_H

#include "mods/extractor.h"
#include <stddef.h>

void* imalloc(size_t s);
void freeFf(FitFile* ff);

#endif