#ifndef UTILS_STRING_H
#define UTILS_STRING_H

/**
 * @brief Remove char from string :
 * https://www.geeksforgeeks.org/remove-spaces-from-a-given-string/
 * @param str input string
 * @param removed char to trim
 */
void trim(char *str, char removed);
/**
 * @brief Return 2D array of strings containing paths.
 */
char **getPaths(char *path, int count);
/**
 * @brief Print all paths in stdout.
 */
void printPaths();

char **getAllPaths();
/**
 * @brief Ask user for two paths.
 */
char **get2path();

#endif