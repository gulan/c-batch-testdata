#if !defined(PERSON_TYPE)
#define PERSON_TYPE

/*
A person is either 'staff' or 'patient'. WE want the chance of
choosing a patient to be twice as likely as choosing staff.

I expect duplicate choices, so there is no need to create a
permutation by shuffling.

The next state does not depend on the previous state (seemingly, since
the mechanics of rand() are hidden from us), so we can use a simple
function instead of a coroutine.
*/

enum PERSONTYPE {PATIENT,STAFF};
enum PERSONTYPE person_type_choose(void);

#endif
