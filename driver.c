#include"archtools.h"
#include"transform.h"
#include<stdlib.h>
#include<stdio.h>

// set N for NxN matrix
#define TEST_DIM 10000

int main(void) {

  int *s,*d;
  char msg[255];
  unsigned int fselect;
  Stopwatch sw;
  void (*transfuncs[2])(int *, int *, int) = {transpose, transpose_O};


  printf(" Choose transpose (0=original, 1=optimized)\n");
  scanf("%d",&fselect);

  if (fselect > 1 ) {
    puts("Invalid transpose function");
    return(-1);
  }

  // initialize data`
  s = random_ints(((TEST_DIM) * (TEST_DIM)), RANDOM_M_SEED, 4);
  d = (int *)malloc(sizeof(int) * ((TEST_DIM) * (TEST_DIM)));
  sw = new_stopwatch();
  if (d == NULL || s == NULL || sw == NULL) return -1;

  // performance test given transpose
  stopwatch_start(sw);
  transfuncs[fselect](d,s,TEST_DIM);
  stopwatch_stop(sw);

  snprintf(msg, 255, "%s transform: %li ms\n", 
      (fselect) ? "Optimized" : "Original", stopwatch_milliseconds(sw));
  puts(msg);

  // superfluous memory deallocation activities
  free(s);
  free(d);
  destroy_stopwatch(sw);

  return 0;
}
