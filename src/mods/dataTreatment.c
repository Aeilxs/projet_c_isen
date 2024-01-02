#include "mods/dataTreatment.h"
#include "mods/log.h"
#include "utils/fs.h"
#include "utils/mem.h"
#include <stdio.h>
#include <stdlib.h>

FitFile *processFiles(int fileCount, char **paths, processFilesCb callback) {
    FILE *fileOne = open(paths[0], "rb");
    FitFile *ff = extract(fileOne);
    fclose(fileOne);

    for (int i = 1; i < fileCount; i++) {
        system("tput cuu1"); // delete last line in terminal
        log_info("Processing file %s n° %d / %d", paths[i], i + 1, fileCount);
        FILE *curF = open(paths[i], "rb");
        FitFile *curFf = extract(curF);
        fclose(curF);
        callback(ff, curFf);
        freeFf(curFf);
    }
    return ff;
}

void processSumCb(FitFile *ff, FitFile *ffToProcess) {
    for (int i = 0; i < ff->arrlen; i++) {
        // ff->data[i] = calculate(ff->data[i], '+', ffToProcess->data[i]);
        ff->data[i] += ffToProcess->data[i];
    }
}

void processSubstractCb(FitFile *ff, FitFile *ffToProcess) {
    for (int i = 0; i < ff->arrlen; i++) {
        ff->data[i] -= ffToProcess->data[i];
        // ff->data[i] = calculate(ff->data[i], '-', ffToProcess->data[i]);
    }
}

void processDivideCb(FitFile *ff, FitFile *ffToProcess) {
    for (int i = 0; i < ff->arrlen; i++) {
        ff->data[i] /= ffToProcess->data[i];
    }
}

// int16_t calculate(int16_t a, char op, int16_t b) {
//     int result = op == '+' ? a + b : a - b;
//     return result;
// }

int16_t calculate(int16_t a, char op, int16_t b) {
    if (op != '+' && op != '-') {
        log_fatal("Calculate not used properly in app.c");
        exit(EXIT_FAILURE);
    }
    int result = op == '+' ? a + b : a - b;
    if (result > INT16_MAX) {
        // log_debug("overflow MAX");
        return INT16_MAX;
    }
    if (result < INT16_MIN) {
        // log_debug("overflow MIN");
        return INT16_MIN;
    }
    return (int16_t)result;
}