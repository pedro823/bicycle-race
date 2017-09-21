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

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "error_handler.h"
#include "_aux.h"
#include <time.h>
#include <math.h>

// Converts a positive time described in a float to a timespec
struct timespec ftots(float dt) {
    add_to_stack("scheduler_methods->ftots");
    struct timespec t;
    t.tv_sec = (long) floorf(dt);
    t.tv_nsec = (long) floorf((dt - floorf(dt)) * 1000000000);
    pop_stack();
    return t;
}

// Converts a struct timespec to a float
float tstof(struct timespec dt) {
    add_to_stack("scheduler_methods->tstof");
    float t = (float) dt.tv_sec;
    t += (float) dt.tv_nsec / 1000000000;
    pop_stack();
    return t;
}


const string_vector __split(const char *to_split, char *divisors) {
    add_to_stack("aux->split");
    int divisor_count = 0;
    // Counts how many divisors are there
    int len_divisors = strlen(divisors);
    int len_to_split = strlen(to_split);
    for (int j = 0; j < len_divisors; j++) {
        char divisor = divisors[j];
        for (int i = 0; i < len_to_split; i++) {
            if (to_split[i] == divisor) {
                divisor_count++;
            }
        }
    }
    // Adds the space for the last string
    divisor_count++;
    string_vector v;
    v.size = divisor_count;
    v.data = emalloc(divisor_count * sizeof(char *));

    char *runner = strdup(to_split);
    // So that it can free runner
    char *start = runner;
    char *splitted_string;
    int counter = 0;

    while (runner != NULL) {
        splitted_string = strdup(strsep(&runner, divisors));
        if (strcmp(splitted_string, "") == 0) {
            v.data[counter++] = strdup("");
        }
        else {
            v.data[counter++] = splitted_string;
        }
    }
    free(start);
    pop_stack();
    return v;
}

char *__chomp(char *to_chomp) {
    int size = strlen(to_chomp);
    for (int i = 0; i < size; i++) {
        if (to_chomp[i] == '\n') {
            to_chomp[i] = '\0';
            break;
        }
    }
    return to_chomp;
}

void free_vector(string_vector to_free) {
    add_to_stack("aux->free_vector");
    for (int i = 0; i < to_free.size; i++) {
        free(to_free.data[i]);
    }
    free(to_free.data);
    pop_stack();
}
