#include "fun.h"
#include <stdio.h>
#include "bin_fun.h"
#include "fun_for_search.h"
#include "fun_for_clean.h"

int main() {
    FILE *fbin = NULL;
    char path[260];
    int n;
    if (!readPath(path, &n) || (n != 0 && n != 1 && n != 2) || (fbin = openBin(path)) == NULL) {
        printf("n/a");
    } else {
        switch (n) {
            case 2:
                if (!addBin(fbin)) { printf("n/a"); break; }
            case 1:
                sortBin(fbin);
            case 0:
                outputBin(fbin);
        }
        closeBin(fbin);
    }
    return 0;
}
