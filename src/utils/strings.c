#include "utils/strings.h"
#include "mods/log.h"
#include "utils/mem.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>

void trim(char *str, char removed) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] != removed) str[count++] = str[i];
    }
    str[count] = '\0';
}

char **getPaths(char *path, int count) {
    // 10 => 000XX.fit + \0
    size_t pathlen = strlen(path) + 10 * sizeof(char);
    char **paths = (char **)imalloc(count * sizeof(char *));
    for (int i = 0; i < count; i++) {
        paths[i] = (char *)imalloc(pathlen);
    }

    for (int i = 0; i < count; i++) {
        strcpy(paths[i], path);
        sprintf(paths[i] + strlen(path), "%05d.fit", i + 1);
    }
    return paths;
}

char **getAllPaths() {
    char **darks = getPaths(DARK_FILE_PATH, DARK_FILE_COUNT);
    char **flats = getPaths(FLAT_FILE_PATH, FLAT_FILE_COUNT);
    char **lights = getPaths(LIGHT_FILE_PATH, LIGHT_FILE_COUNT);
    char **offsets = getPaths(OFFSET_FILE_PATH, OFFSET_FILE_COUNT);

    char **paths = (char **)imalloc(TOTAL_FILE_COUNT * sizeof(char *));

    int index = 0;

    for (int i = 0; i < DARK_FILE_COUNT; i++) {
        size_t length = strlen(darks[i]) + 1;
        paths[index] = (char *)imalloc(length * sizeof(char));
        strcpy(paths[index], darks[i]);
        index++;
    }

    for (int i = 0; i < FLAT_FILE_COUNT; i++) {
        size_t length = strlen(flats[i]) + 1;
        paths[index] = (char *)imalloc(length * sizeof(char));
        strcpy(paths[index], flats[i]);
        index++;
    }

    for (int i = 0; i < LIGHT_FILE_COUNT; i++) {
        size_t length = strlen(lights[i]) + 1;
        paths[index] = (char *)imalloc(length * sizeof(char));
        strcpy(paths[index], lights[i]);
        index++;
    }

    for (int i = 0; i < OFFSET_FILE_COUNT; i++) {
        size_t length = strlen(offsets[i]) + 1;
        paths[index] = (char *)imalloc(length * sizeof(char));
        strcpy(paths[index], offsets[i]);
        index++;
    }

    freePaths(darks, DARK_FILE_COUNT);
    freePaths(flats, FLAT_FILE_COUNT);
    freePaths(lights, LIGHT_FILE_COUNT);
    freePaths(offsets, OFFSET_FILE_COUNT);

    return paths;
}

char **get2path() {
    char **paths = (char **)imalloc(2 * sizeof(char *));
    paths[0] = (char *)imalloc(200 * sizeof(char));
    paths[1] = (char *)imalloc(200 * sizeof(char));

    printf("Please provide 2 paths (use space as separator)\n:");
    scanf("%199s %199s", paths[0], paths[1]);
    return paths;
}

static void display(char **paths, int count);
static void display(char **paths, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s\n", paths[i]);
    }
    printf("\n");
}

void printPaths() {
    char **darks = getPaths(DARK_FILE_PATH, DARK_FILE_COUNT);
    char **flats = getPaths(FLAT_FILE_PATH, FLAT_FILE_COUNT);
    char **lights = getPaths(LIGHT_FILE_PATH, LIGHT_FILE_COUNT);
    char **offsets = getPaths(OFFSET_FILE_PATH, OFFSET_FILE_COUNT);

    log_info("Paths :\n");
    display(darks, DARK_FILE_COUNT);
    freePaths(darks, DARK_FILE_COUNT);
    display(flats, FLAT_FILE_COUNT);
    freePaths(flats, FLAT_FILE_COUNT);
    display(lights, LIGHT_FILE_COUNT);
    freePaths(lights, LIGHT_FILE_COUNT);
    display(offsets, OFFSET_FILE_COUNT);
    freePaths(offsets, OFFSET_FILE_COUNT);
}