#ifndef FUN_FOR_CLEAN_C
#define FUN_FOR_CLEAN_C

#include "fun.h"
#include <stdio.h>
#include "bin_fun.h"
#include "fun_for_search.h"
#include "fun_for_clean.h"

int readCPath(char* path, int* dateFrom, int* dateTo) {
    char c, c1, c2, c3;
    c = getchar();
    path[0] = '.';
    path[1] = '.';
    path[2] = '/';
    for (int i = 3; c != EOF && c != '\n'; i++) {
        path[i] = c;
        c = getchar();
    }
    if (scanf("%d%c%d%c%d%c", &dateFrom[0], &c1, &dateFrom[1], &c2, &dateFrom[2], &c3)
        != 6 && c1 != '.' && c2 != '.' && c3 != '\n') return 0;
    if (scanf("%d%c%d%c%d%c", &dateTo[0], &c1, &dateTo[1], &c2, &dateTo[2], &c3)
        != 6 && c1 != '.' && c2 != '.' && c3 != '\n') return 0;
    return 1;
}

int popDate(FILE* fbin, int *dateFrom, int* dateTo) {
    int count_write = get_records_count_in_file(fbin), posStart, posEnd, j = 0;
    struct my_struct stract;
    if (!position(fbin, &posStart, &posEnd, dateFrom, dateTo)) return 0;
    rewind(fbin);
    for (int i = 0; i < count_write; i++) {
        if (i < posStart || i > posEnd) {
            stract = read_record_from_file(fbin, i);
            // write_record_in_file(newfbin, &stract, i);
            printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", stract.year, stract.month, stract.day,
                stract.hour, stract.minutes, stract.sec, stract.status, stract.code);
            j++;
        }
    }
    return 1;
}

int position(FILE* fbin, int* posStart, int* posEnd, int *dateFrom, int* dateTo) {
    int count_write = get_records_count_in_file(fbin);
    struct my_struct stract;
    for (int i = 0; i < count_write; i++) {
        stract = read_record_from_file(fbin, i);
        if (stract.day == dateFrom[0] && stract.month == dateFrom[1] && stract.year == dateFrom[2]) {
            *posStart = i;
            for (int j = count_write - 1; j > 0 && j > i; j--) {
                stract = read_record_from_file(fbin, j);
                if (stract.day == dateTo[0] && stract.month == dateTo[1] && stract.year == dateTo[2]) {
                    *posEnd = j;
                    return 1;
                }
            }
        }
    }
    return 0;
}

#endif  // FUN_FOR_CLEAN_C




// if (stract.day == dateFrom[0] && stract.month == dateFrom[1] && stract.year == dateFrom[2]) {
//             for (int j = i; j < count_write; j++) {
//                 stract = read_record_from_file(fbin, j);
//                 if (stract.day == dateTo[0] && stract.month == dateTo[1] && stract.year == dateTo[2]) {
//                     write_record_in_file(fbin, &stractSpace, j);
//                     break;
//                 } else {
//                     write_record_in_file(fbin, &stractSpace, j);
//                 }
//             }
//         }
