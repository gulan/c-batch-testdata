#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "ward_id.h"

void
ward_id_gen(struct ward_id_state_vector *sv) {
  switch (sv->operation ) {

  case ward_id_INIT:
    for (int j=0; j<SVN; j++)
      sv->value[j] = '\0';
    sv->i = 1;
    break;;

  case ward_id_NEXT:
    sprintf(sv->value, "%3.3d", sv->i);
    sv->i++;
    break;
  }
};

void ward_id_demo (void) {
  int j;
  struct ward_id_state_vector sv;
  sv.operation = ward_id_INIT;
  ward_id_gen(&sv);
  j = 1;
  while (j < 12) {
    sv.operation = ward_id_NEXT;
    ward_id_gen(&sv);
    j += 1;
  };
};
