#if !defined(WARD_ID)
#define WARD_ID

#define SVN 16

enum ward_id_ops {ward_id_INIT, ward_id_NEXT};

struct ward_id_state_vector {
  int operation;
  int i;
  char value[SVN];
};

void ward_id_gen(struct ward_id_state_vector *sv);

#endif
