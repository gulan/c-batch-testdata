#if !defined(WARD_ID)
#define WARD_ID

#define SVN 4

enum ward_id_ops {ward_id_INIT, ward_id_NEXT};

struct ward_id_state_vector {
  size_t operation;
  size_t i;
  char value[SVN];
};

void ward_id_gen(struct ward_id_state_vector *sv);

#endif
