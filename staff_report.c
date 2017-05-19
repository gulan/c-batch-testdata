#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person_type.h"

// gcc -Wall -std=c99 staff_report.c -o staff_report
// ./hosp_td |./staff_report

struct hosp_rec {
  char ward_id[4];
  // unsigned ptype;
  enum PERSONTYPE ptype;
  char surname[16];
};

int
read_hosp(struct hosp_rec *hr) {
  hr->ward_id[0] = 0;
  hr->ptype = 0;
  hr->surname[0] = 0;
  return scanf("%3c|%u|%*[a-z]|%s ", hr->ward_id, &hr->ptype, hr->surname);
};

int
main(int argc, char *argv[argc+1]) {
  unsigned total,count;
  int rc;
  char save_ward_id[4];
  struct hosp_rec hr;
  
  printf("HEADING\n");
  total = 0;
  rc = read_hosp(&hr);
  while (rc != EOF) {
    strcpy(save_ward_id, hr.ward_id);
    count = 0;
    while (rc != EOF && strcmp(save_ward_id, hr.ward_id) == 0) {
      // printf("    %s|%u|%s\n", hr.ward_id, hr.ptype, hr.surname);
      if (hr.ptype == STAFF)
	count++;
      rc = read_hosp(&hr);
    }
    printf("%s COUNT %u\n", save_ward_id, count);
    total += count;
  }
  printf("TOTAL %d\n", total);
  return EXIT_SUCCESS;
}
