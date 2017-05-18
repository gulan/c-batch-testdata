#if !defined(SURNAME)
#define SURNAME

/*
Yield the concatenated cartesian product of INITIALS and FINALS in
random order.
 */

enum surname_ops {surname_INIT, surname_NEXT, surname_FIN};

struct surname_state_vector {
  enum surname_ops state;
  size_t loop;
  size_t m;     // len of xl
  char sn[1024][5];
  size_t *xl;   // as array
  char value[5];
};

/*
The state vector holds all of the locate state of `surname_simple_gen`
that persists between calls. Any number of these 'generators' may be
used independently, as long as each has its own state vector instance.

The user is expected to first call with INIT, then any number calls
with NEXT, and finally a call with FIN.

Only calls with NEXT return a value in surname_state_vector.value.
 */

void surname_simple_gen(struct surname_state_vector *sv);

#endif
