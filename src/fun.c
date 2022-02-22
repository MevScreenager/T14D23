#ifndef FUN_C
#define FUN_C

#include "libraris.h"

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
    return 1;
}

int sortBin(FILE* fbin) {
    printf("sortBin\n");
    // struct my_struct stractFist, stractTwo;
    // int count_write = get_records_count_in_file(fbin);
    // printf("count_write: \t%d", count_write);
    quick_sort(fbin, 0, 1100);
    printf("quick_sort");
    // for (int i = 0; i < count_write; i++) {
    //     stractFist = read_record_from_file(fbin, i);
    //     for (int j = i; j < count_write; j++) {
    //         stractTwo = read_record_from_file(fbin, j);
    //         struct my_struct stractTime;
    //         if (stractFist.year > stractTwo.year) {
    //             stractTime = stra
    //         }
    //         else if (stractFist.year < stractTwo.year) {}
    //     }
    // }
    return 1;
}
// last -1
void quick_sort(FILE* fbin, int first, int last) {
    // printf("count:\t%d", count++);
    if (first < last) {
        int left = first, right = last;
        struct my_struct stractMiddle = read_record_from_file(fbin, (left + right) / 2);
        do {
            struct my_struct stractLeft = read_record_from_file(fbin, left);
            while (stractLeft.year < stractMiddle.year)
                left++;
            struct my_struct stractRight = read_record_from_file(fbin, right);
            while (stractRight.year > stractMiddle.year)
                right--;
            if (left <= right) {
                swap_records_in_file(fbin, left, right);
                left++;
                right--;
            }
        } while (left <= right);
        quick_sort(fbin, first, right);
        quick_sort(fbin, left, last);
    }
}

int outputBin(FILE* fbin) {
    int count_write = get_records_count_in_file(fbin);
    struct my_struct stract;
    for (int i = 0; i < count_write; i++) {
        stract = read_record_from_file(fbin, i);
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", stract.year, stract.month, stract.day,
        stract.hour, stract.minutes, stract.sec, stract.status, stract.code);
    }
    printf("count_write: %d", count_write);
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
