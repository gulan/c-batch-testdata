#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "surname.h"

static const char *INITIALS[] = {"b","bl","br","c","ch","cr","d","dr","f","fl","fr","g","gl","gr","h","j","k","kr","l","m","n","p","pr","pl","r","s","sr","sl","st","sh","t","th",NULL};

static const char *FINALS[] = {"a","ai","ao","au","e","ee","ea","ei","i","ia","ie","io","iu","o","oo","oa","oe","oi","ou","u","ua","ui","ay","ey","oy","uy",NULL};

void
surname_simple_gen(struct surname_state_vector *sv) {
  int i,j,k,r,s;
  int *xl;
  char buf[5];

  switch (sv->state) {

  case surname_INIT:
    // fill_namebuf();
    k = 0;i = 0;
    while (INITIALS[i]) {
      j = 0;
      while (FINALS[j]) {
	sprintf(buf, "%s%s", INITIALS[i], FINALS[j]);
	strcpy(sv->sn[k],buf);
	k++; j++;
      };
      i++;
    };
    sv->m = k;
    // shuffle remapping vector
    xl = (int *)malloc(sv->m * sizeof(int));
    for (int i=0; i < sv->m; i++)
      xl[i] = i;
    s = sv->m - 1;
    while (s > 0) {
      r = rand() % s;
      int t = xl[s];
      xl[s] = xl[r];
      xl[r] = t;
      s--;
    }
    sv->state = surname_NEXT;
    sv->value[0] = '\0';
    sv->loop = 0;
    sv->xl = xl;
    break;

  case surname_NEXT:
    if (sv->loop < sv->m) {
      int p = sv->xl[sv->loop];
      strcpy((char *)sv->value, (char *)sv->sn[p]);
      sv->loop++;
      sv->state = surname_NEXT;
    } else
      sv->state = surname_FIN;
    break;
    
  case surname_FIN:
    free(sv->xl);
    break;
  };
};

void
surname_demo(void) {
  struct timeval tv;  
  gettimeofday(&tv, NULL);
  srand(tv.tv_usec); // seed the random generator
  struct surname_state_vector sv;
  sv.state = surname_INIT;
  surname_simple_gen(&sv);
  while (sv.state == surname_NEXT) {
    printf("%s ", sv.value);
    surname_simple_gen(&sv);
  }
  putchar('\n');
  surname_simple_gen(&sv);
}

// int main (int argc, char *argv[]) {demo();}

