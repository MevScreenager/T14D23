#include "fun.h"
#include <stdio.h>
#include "bin_fun.h"
#include "fun_for_search.h"
#include "fun_for_clean.h"

int main() {
    FILE *fbin = NULL;
    char path[260];
    int date[3];
    if (!readSPath(path, date) || (fbin = openBin(path)) == NULL) {
        printf("n/a");
    } else {
        if (!outputBinCode(fbin, date)) printf("n/a");
        closeBin(fbin);
    }
    return 0;
}
