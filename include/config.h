#ifndef CONFIG_H
#define CONFIG_H

/**
 * FILE SYSTEM CONSTANTS
 */

#define DARK_FILE_COUNT   26
#define FLAT_FILE_COUNT   17
#define LIGHT_FILE_COUNT  50
#define OFFSET_FILE_COUNT 10
#define TOTAL_FILES       103

#define DARK_FILE_PATH   "assets/fits/darks/darks_"
#define FLAT_FILE_PATH   "assets/fits/flats/flats_"
#define OFFSET_FILE_PATH "assets/fits/offsets/offsets_"
#define LIGHT_FILE_PATH  "assets/fits/lights/r_lights_"

#define OUT_FIT "build/out.fit"
#define OUT_CSV "build/out.csv"

/**
 * FIT FILE CONSTANTS
 */

#define FIT_HEADER_LINE_LENGTH 80
#define FIT_HEADER_LINE_TOT    36
#define BYTES_PER_BLOCK        2880

#endif