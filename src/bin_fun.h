#ifndef BIN_FUN_H
#define BIN_FUN_H

#include "libraris.h"

int get_file_size_in_bytes(FILE *pfile);
int get_records_count_in_file(FILE *pfile);
struct my_struct read_record_from_file(FILE *pfile, int index);
void write_record_in_file(FILE *pfile, const struct my_struct *record_to_write, int index);
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2);

#endif  // BIN_FUN_H