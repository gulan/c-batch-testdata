#if !defined(HYPHEN)
#define HYPHEN

#include "surname.h"

/*
Generate hyphenated surnames by using two instances of the surname
generator.
 */

enum hyphen_op {hyphen_INIT, hyphen_NEXT, hyphen_FIN};

struct hyphen_state {
  enum hyphen_op state;
  struct surname_state_vector sv1;
  struct surname_state_vector sv2;
  char value[10];
};

void hyphen_structured_demo(void);
void hyphen_gen(struct hyphen_state *hst);
void hyphen_gen_demo();

#endif
