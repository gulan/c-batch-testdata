#include <stdlib.h>
#include <sys/time.h>
#include "person_type.h"

static enum PERSONTYPE ptmap[3] = {PATIENT,PATIENT,STAFF};

enum PERSONTYPE
person_type_choose(void) {
  return ptmap[rand()%3];
};


void person_type_demo (void) {
  struct timeval tv;  
  gettimeofday(&tv, NULL);
  srand(tv.tv_usec); // seed the random generator
  person_type_choose();
};


