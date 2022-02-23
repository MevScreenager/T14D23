#ifndef FUN_C
#define FUN_C

#include "fun.h"
#include <stdio.h>
#include "bin_fun.h"
#include "fun_for_search.h"
#include "fun_for_clean.h"

int readPath(char* path, int *n) {
    char c;
    c = getchar();
    path[0] = '.';
    path[1] = '.';
    path[2] = '/';
    for (int i = 3; c != EOF && c != '\n'; i++) {
        path[i] = c;
        c = getchar();
    }
    if (!scanf("%d", n))
        return 0;
    return 1;
}

int addBin(FILE* fbin) {
    struct my_struct stract;
    char c1, c2, c3, c4, c5, c6, c7, c8;
    int index = get_records_count_in_file(fbin),
        scan = scanf("%d%c%d%c%d%c%d%c%d%c%d%c%d%c%d%c", &stract.year, &c1, &stract.month, &c2, &stract.day,
            &c3, &stract.hour, &c4, &stract.minutes, &c5, &stract.sec, &c6, &stract.status, &c7, &stract.code,
            &c8);
    if (scan != 16 || (c1 != ' ' && c2 != ' ' && c3 != ' ' && c4 != ' '
        && c5 != ' ' && c6 != ' ' && c7 != ' ' && c8 != '\n')) return 0;
    write_record_in_file(fbin, &stract, index);
    return 1;
}

int sortBin(FILE* fbin) {
    int n = get_records_count_in_file(fbin);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            struct my_struct stractJ = read_record_from_file(fbin, j);
            struct my_struct stractJ_1 = read_record_from_file(fbin, j + 1);
            if (stractJ.year > stractJ_1.year) {
                swap_records_in_file(fbin, j, j + 1);
            } else if (stractJ.year == stractJ_1.year && stractJ.month > stractJ_1.month) {
                swap_records_in_file(fbin, j, j + 1);
            } else if (stractJ.year == stractJ_1.year && stractJ.month == stractJ_1.month
                        && stractJ.day > stractJ_1.day) {
                swap_records_in_file(fbin, j, j + 1);
            } else if (stractJ.year == stractJ_1.year && stractJ.month == stractJ_1.month
                        && stractJ.day == stractJ_1.day &&
                        stractJ.hour > stractJ_1.hour) {
                swap_records_in_file(fbin, j, j + 1);
            } else if (stractJ.year == stractJ_1.year && stractJ.month == stractJ_1.month &&
                        stractJ.day == stractJ_1.day &&
                        stractJ.hour == stractJ_1.hour && stractJ.minutes > stractJ_1.minutes) {
                swap_records_in_file(fbin, j, j + 1);
            } else if (stractJ.year == stractJ_1.year && stractJ.month == stractJ_1.month &&
                        stractJ.day == stractJ_1.day &&
                        stractJ.hour == stractJ_1.hour && stractJ.minutes == stractJ_1.minutes
                        && stractJ.sec > stractJ_1.sec) {
                swap_records_in_file(fbin, j, j + 1);
            } else if (stractJ.year == stractJ_1.year && stractJ.month == stractJ_1.month &&
                        stractJ.day == stractJ_1.day &&
                        stractJ.hour == stractJ_1.hour && stractJ.minutes == stractJ_1.minutes
                        && stractJ.sec == stractJ_1.sec &&
                        stractJ.status > stractJ_1.status) {
                swap_records_in_file(fbin, j, j + 1);
            } else if (stractJ.year == stractJ_1.year && stractJ.month == stractJ_1.month &&
                        stractJ.day == stractJ_1.day &&
                        stractJ.hour == stractJ_1.hour && stractJ.minutes == stractJ_1.minutes
                        && stractJ.sec == stractJ_1.sec &&
                        stractJ.status == stractJ_1.status && stractJ.code > stractJ_1.code) {
                swap_records_in_file(fbin, j, j + 1);
            }
        }
    }
    return 1;
}

int outputBin(FILE* fbin) {
    int count_write = get_records_count_in_file(fbin);
    struct my_struct stract;
    for (int i = 0; i < count_write; i++) {
        stract = read_record_from_file(fbin, i);
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", stract.year, stract.month, stract.day,
        stract.hour, stract.minutes, stract.sec, stract.status, stract.code);
    }
    return 1;
}

FILE* openBin(char* path) {
    return fopen(path, "r+b");
}

int closeBin(FILE* fbin) {
    fclose(fbin);
    return 1;
}

#endif  // FUN_C
