#include "config.h"
#include "mods/extractor.h"
#include "mods/log.h"
#include "mods/menu.h"
#include "useCases/prim.h"
#include "utils/fs.h"
#include "utils/mem.h"
#include "utils/strings.h"
#include <stdint.h>
#include <stdio.h>

int main() {
    while (1) {
        char choice;
        switch (choice = menu()) {

        case '1': // Sum All
            sumAllPrim50();
            break;

        case '2': // Average All
            avgAllPrim60();
            break;

        case '3': // Substract two
            substract2Prim70();
            break;

        case '4': // Divide two
            // divideTwoPrim80();
            break;

        case '5': // Divide two
            log_info("master");
            break;

        case 'p': // Print paths
            printPaths();
            break;

        case 'q': // Divide two
            log_info("Bye.");
            return 0;

        default:
            log_error("Choix invalide");
            break;
        }
    }

    return 1;
}

// FILE *rlight1 = open("assets/fits/lights/r_lights_00001.fit", "rb");
// FitFile *ff = extract(rlight1);
// fclose(rlight1);

// FILE *outCsv = open(OUT_CSV, "wb");
// writeCsvPrim40(outCsv, ff);
// fclose(outCsv);

// char **paths = getPaths(DARK_FILE_PATH, DARK_FILE_COUNT);

// freePaths(paths, DARK_FILE_COUNT);
// freeFf(ff);