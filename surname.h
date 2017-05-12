/*
Yield the concatenated cartesian product of INITIALS and FINALS in
random order.
 */

enum surname_ops {surname_INIT, surname_NEXT, surname_FIN};

struct surname_state_vector {
  enum surname_ops state;
  int loop;
  int m;     // len of xl
  char sn[1024][5];
  int *xl;   // as array
  char value[5];
};

void surname_simple_gen(struct surname_state_vector *sv);

