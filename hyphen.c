#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "hyphen.h"

/*
The hyphen_structured_demo and hyphen_gen_demo produce the same
output. The routines differing only in coding style.
 */

void
hyphen_structured_demo(void) {
  struct surname_state_vector sv1;
  struct surname_state_vector sv2;
  
  sv1.state = surname_INIT;
  sv2.state = surname_INIT;
  surname_simple_gen(&sv1);
  surname_simple_gen(&sv2);
  while (sv1.state == surname_NEXT) {
    surname_simple_gen(&sv1);
    surname_simple_gen(&sv2);
    printf("%s-%s ", sv1.value, sv2.value);
  }
  putchar('\n');
  surname_simple_gen(&sv1);
  surname_simple_gen(&sv2);
}

void
hyphen_gen(struct hyphen_state *hst) {
  char buf[10];
  switch (hst->state) {

  case hyphen_INIT:
    hst->sv1.state = surname_INIT;
    hst->sv2.state = surname_INIT;
    surname_simple_gen(&hst->sv1);
    surname_simple_gen(&hst->sv2);
    hst->state = hyphen_NEXT;
    break;
    
  case hyphen_NEXT:
    if (hst->sv1.state == surname_NEXT) {
      surname_simple_gen(&hst->sv1);
      surname_simple_gen(&hst->sv2);
      sprintf(buf, "%s-%s", hst->sv1.value, hst->sv2.value);
      strcpy(hst->value, buf);
    } else
      hst->state = hyphen_FIN;
    break;
    
  case hyphen_FIN:
    surname_simple_gen(&hst->sv1);
    surname_simple_gen(&hst->sv2);
    break;
  };
}

void
hyphen_gen_demo() {
  struct hyphen_state hst;
  
  hst.state = hyphen_INIT;
  hyphen_gen(&hst);
  while (hst.state == hyphen_NEXT) {
    hyphen_gen(&hst);
    printf("%s ", hst.value);
  }
  putchar('\n');
  hyphen_gen(&hst);
};

/*
int
main(int argc, char *argv[]) {
  struct timeval tv;  
  gettimeofday(&tv, NULL);
  srand(tv.tv_usec); // seed the random generator
  hyphen_gen_demo();
}
*/
