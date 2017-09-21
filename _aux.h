/******************************************************************************
 *                                                                            *
 *                   MAC0422 - Sistemas Operacionais - EP1                    *
 *                                                                            *
 *                             Auxiliar functions                             *
 *                                                                            *
 *                      Pedro Pereira     - NUSP 9778794                      *
 *                      Raphael R. Gusmao - NUSP 9778561                      *
 *                                                                            *
 ******************************************************************************/

#ifndef __AUX_H__
#define __AUX_H__

#define bool char
#define true 1
#define false 0
#define MAX_LENGTH_CONSTANT 2048
#include <time.h>

typedef struct {
    int size;
    char **data;
} string_vector;

/**
 * Just like python's split: splits the string into a vector of instances  before
 * and after the divisor.
 * @param to_split The string to be splitted.
 * @param divisors The divisors of the string
 * @GUARANTEE No memory leaks possible
 * @return_example split("abc=d;e", "=.;") => string_vector { size: 3, data: ["abc", "d", "e"] }
 */
const string_vector __split(const char *to_split, char* divisor);

/**
 * changes first '\n' to '\0'.
 * @param to_strip string to be stripped
 */
char *__chomp(char *to_chomp);

/**
 * Frees a string_vector.
 * @GUARANTEE no memory leaks possible.
 */
void free_vector(string_vector to_free);

/**
 * Constructs a timespec representing the time in seconds
 * based on a positive float
 * @param  dt the time, in seconds
 * @return    the same time, in a struct timespec
 */
struct timespec ftots(float dt);

/**
 * Inverse function of ftots
 * @param  dt the time, in tv_sec and tv_nsec
 * @return    the float representing the time
 */
float tstof(struct timespec dt);

#endif
