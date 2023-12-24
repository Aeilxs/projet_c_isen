#include "config.h"
#include "mods/extractor.h"
#include "mods/log.h"
#include "utils/fs.h"
#include <stdint.h>
#include <stdio.h>

int main() {
    FILE* rdark1 = open("assets/fits/darks/darks_00001.fit", "rb");
    uint8_t header[BYTES_PER_BLOCK];
    fread(header, BYTES_PER_BLOCK, 1, rdark1);

    FitHeader h = getHeader(header);
    dumpHeader(&h, 1);

    fclose(rdark1);
    return 0;
}
