#ifndef SRC_FUN_H_
#define SRC_FUN_H_

#include "fun.h"
#include <stdio.h>
#include "bin_fun.h"
#include "fun_for_search.h"
#include "fun_for_clean.h"

struct my_struct {
    int year;
    int month;
    int day;
    int hour;
    int minutes;
    int sec;
    int status;
    int code;
};

int readPath(char* path, int *n);
int addBin(FILE* fbin);
int sortBin(FILE* fbin);
int outputBin(FILE* fbin);
FILE* openBin(char* path);
int closeBin(FILE* fbin);

#endif  // SRC_FUN_H_
