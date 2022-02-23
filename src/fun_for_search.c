#ifndef FUN_FOR_SEARCH_C
#define FUN_FOR_SEARCH_C

#include "fun.h"
#include <stdio.h>
#include "bin_fun.h"
#include "fun_for_search.h"
#include "fun_for_clean.h"

int readSPath(char* path, int* date) {
    char c, c1, c2, c3;
    c = getchar();
    path[0] = '.';
    path[1] = '.';
    path[2] = '/';
    for (int i = 3; c != EOF && c != '\n'; i++) {
        path[i] = c;
        c = getchar();
    }
    // c = getchar();
    // for (int i = 0; c != EOF && c != '\n'; i++) {
    //     if (i > 9) return 0;
    //     dateChar[i] = c;
    //     if ((i == 2 || i == 5) && dateChar[i] != '.') return 0;
    //     c = getchar();
    // }
    // for (int i = 0; i < 10; i++) {
    //     if ((i != 2 && i != 5) && )
    // }
    if (scanf("%d%c%d%c%d%c", &date[0], &c1, &date[1], &c2, &date[2], &c3)
        != 6 && c1 != '.' && c2 != '.' && c3 != '\n') return 0;
    return 1;
}

int outputBinCode(FILE* fbin, int *date) {
    int count_write = get_records_count_in_file(fbin), count = 0;
    struct my_struct stract;
    for (int i = 0; i < count_write; i++) {
        stract = read_record_from_file(fbin, i);
        if (stract.day == date[0] && stract.month == date[1] && stract.year == date[2]) {
            printf("%d", stract.code); count++; break;
        }
    }
    if (count == 0) return 0;
    return 1;
}

#endif  // FUN_FOR_SEARCH_C
