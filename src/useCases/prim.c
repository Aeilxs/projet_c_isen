#include "useCases/prim.h"
#include "config.h"
#include "mods/dataTreatment.h"
#include "mods/extractor.h"
#include "utils/fs.h"
#include "utils/mem.h"
#include "utils/strings.h"

void sumAllPrim50() {
    FILE *fitOut = open(OUT_FIT_PATH, "wb");
    FILE *csvOut = open(OUT_CSV_PATH, "wb");
    char **paths = getAllPaths();

    FitFile *ff = processFiles(TOTAL_FILE_COUNT, paths, processSumCb);
    freePaths(paths, TOTAL_FILE_COUNT);

    writeCsvPrim40(csvOut, ff);
    writeFit(fitOut, ff);

    freeFf(ff);
    fclose(fitOut);
    fclose(csvOut);
}

void avgAllPrim60() {
    FILE *fitOut = open(OUT_FIT_PATH, "wb");
    FILE *csvOut = open(OUT_CSV_PATH, "wb");
    char **paths = getAllPaths();

    FitFile *ff = processFiles(TOTAL_FILE_COUNT, paths, processSumCb);
    freePaths(paths, TOTAL_FILE_COUNT);

    for (int i = 0; i < ff->arrlen; i++) {
        ff->data[i] /= TOTAL_FILE_COUNT;
    }

    writeCsvPrim40(csvOut, ff);
    writeFit(fitOut, ff);

    freeFf(ff);
    fclose(fitOut);
    fclose(csvOut);
}

void substract2Prim70() {
    FILE *fitOut = open(OUT_FIT_PATH, "wb");
    FILE *csvOut = open(OUT_CSV_PATH, "wb");
    char **paths = get2path();

    FitFile *ff = processFiles(2, paths, processSubstractCb);
    freePaths(paths, 2);

    writeCsvPrim40(csvOut, ff);
    writeFit(fitOut, ff);

    freeFf(ff);
    fclose(fitOut);
    fclose(csvOut);
}

void divide2Prim80() {
    FILE *fitOut = open(OUT_FIT_PATH, "wb");
    FILE *csvOut = open(OUT_CSV_PATH, "wb");
    char **paths = get2path();

    FitFile *ff = processFiles(2, paths, processSubstractCb);
    freePaths(paths, 2);

    writeCsvPrim40(csvOut, ff);
    writeFit(fitOut, ff);

    freeFf(ff);
    fclose(fitOut);
    fclose(csvOut);
}

// assets/fits/lights/r_lights_00024.fit
// assets/fits/lights/r_lights_00025.fit
// assets/fits/darks/darks_00006.fit