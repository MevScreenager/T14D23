#ifndef SRC_FUN_FOR_CLEAN_H_
#define SRC_FUN_FOR_CLEAN_H_

#include "fun.h"
#include <stdio.h>
#include "bin_fun.h"
#include "fun_for_search.h"
#include "fun_for_clean.h"

int readCPath(char* path, int* dateFrom, int* dateTo);
int popDate(FILE* fbin, int* dateFrom, int* dateTo);
int position(FILE* fbin, int* posStart, int* posEnd, int *dateFrom, int* dateTo);

#endif  // SRC_FUN_FOR_CLEAN_H_
