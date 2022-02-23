#include "fun.h"
#include <stdio.h>
#include "bin_fun.h"
#include "fun_for_search.h"
#include "fun_for_clean.h"

int main() {
    FILE *fbin = NULL;  // , *newfbin = NULL;
    char path[260];
    int dateFrom[3], dateTo[3];  // , countH = 0;
    // char pathH[264];
    // for (int i = 0; i < 264; i++) {
    //     if (i < 260) pathH[i] = path[i];
    //     if (!path[i] && countH < 3) { pathH[i] = 'H'; countH++; }
    // }
    // newfbin = fopen(pathH, "ab");
    if (!readCPath(path, dateFrom, dateTo) || (fbin = openBin(path)) == NULL) {
        printf("n/a");
    } else {
        // outputBin(fbin);
        if (!popDate(fbin, dateFrom, dateTo)) {
            printf("n/a");
        } else {
            // outputBin(newfbin);
        }
        closeBin(fbin);
    }
    // closeBin(newfbin);
    // remove(pathH);
    return 0;
}
