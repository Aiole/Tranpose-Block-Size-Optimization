#include"transform.h"
#include <stdio.h>


//-------------------- default transpose function -------------------//
void transpose(int *dest, int *source, int dims) {
  int i,j;

  for(i=0;i<dims;i++){
    for(j=0;j<dims;j++){
      dest[j*dims + i] = source[i*dims + j];
    }
  }
  
  //printf("(%d)", dest[0]); //checking...
  //printf("(%d)", dest[10]);
  //printf("(%d)", dest[98765]);
  //printf("(%d)", dest[100000000]);

  
}

 
//---------------------- optimized transpose ---------------------//
void transpose_O(int *dest, int *source, int dims) {
  #define MIN(x, y) (((x) < (y)) ? (x) : (y))
  int i,j,x,y;
  int block = 16;
  
  /*  
limit = dims *dims
  for(int n = 0; n < limit; n++) { //compact
        i = n/dims;
        j = n%dims;
	dest[j*dims + i] = source[i*dims +j];
}
  */

  // block size 16 is 370~, 8 is 382~, 4 is 428~, 32 is uhh ohh, 64 is uhh ohh
  // sticking with 16 block size
 for(i = 0; i < dims; i+=block){
    for(j = 0; j < dims; j+=block){
        for(x = i; x < i + block; ++x){
            for(y = j; y < j + block; ++y){
                dest[y*dims + x] = source[x*dims + y];
            }
        }
    }
}
   

 
  //printf("(%d)", dest[0]); //checking...
  //printf("(%d)", dest[10]);
  // printf("(%d)", dest[98765]);
  // printf("(%d)", dest[100000000]);

  
}
