#include "config.h"
#include "mods/extractor.h"
#include "mods/log.h"
#include "utils/fs.h"
#include "utils/mem.h"
#include <stdint.h>
#include <stdio.h>

int main() {
    FILE* rlight1 = open("assets/fits/lights/r_lights_00001.fit", "rb");
    FitFile* ff = extract(rlight1);
    dumpHeader(&ff->header, 0);
    fclose(rlight1);

    for (int i = 0; i < ff->bytesTot; i++) {
        printf("--- val : [%hd] ---", ff->data[i]);
    }

    freeFf(ff);

    return 0;
}
