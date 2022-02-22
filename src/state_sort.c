#include "libraris.h"

int main() {
    FILE *fbin = NULL;
    char path[260];
    int n;
    if (!readPath(path, &n) || (n != 0 && n != 1 && n != 2) || (fbin = openBin(path)) == NULL) {
        printf("n/a");
    } else {
        switch (n) {
            case 0:
                addBin(fbin);
            case 1:
            printf("sort start\n");
                sortBin(fbin);
                printf("sort good!\n");
                outputBin(fbin);
                break;
            case 2:
                outputBin(fbin);
                break;
        }
        closeBin(fbin);
    }
    // printf("%s\t%d", path, n);
    return 0;
}
