#ifndef FUN_H
#define FUN_H

#include "libraris.h"

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
int get_file_size_in_bytes(FILE *pfile);
int get_records_count_in_file(FILE *pfile);
struct my_struct read_record_from_file(FILE *pfile, int index);
void quick_sort(FILE* fbin, int first, int last);
// int count = 0;


#endif  // FUN_H
