#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "ward_id.h"
#include "person_type.h"
#include "surname.h"
#include "hyphen.h"

int
main (int argc, char *argv[argc+1]) {
  struct timeval tv;  
  gettimeofday(&tv, NULL);
  srand(tv.tv_usec); // seed the random generator
  
  struct ward_id_state_vector sv;
  sv.operation = ward_id_INIT;
  ward_id_gen(&sv);
  
  struct surname_state_vector ssv;
  ssv.state = surname_INIT;
  surname_simple_gen(&ssv);
  
  struct hyphen_state hsv;
  hsv.state = hyphen_INIT;
  hyphen_gen(&hsv);
  
  for (size_t j=1; j<36; j++) {
    sv.operation = ward_id_NEXT;
    ward_id_gen(&sv);
    // group several records per ward_id:
    for (size_t k=0; k<3; k++) {
      ssv.state = surname_NEXT;
      surname_simple_gen(&ssv);
      hyphen_gen(&hsv);
      printf("%s|%d|%s|%s\n", sv.value, person_type_choose(), ssv.value, hsv.value);
    };
  };
  return EXIT_SUCCESS;
};
