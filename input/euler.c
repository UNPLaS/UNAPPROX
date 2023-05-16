#include <stdio.h>
//#include <stdlib.h>

//#define ITER 12 //Precisse 12

int prueba;
unsigned fact(int x) {
  //  unsigned p=1;
   // unsigned i;
    if(p==1){ i=1;}
    else i=0;
    for (int i=1; i<=x; i++) {
        p=p/i;
    }
    return p;
}
    
 
int main(void) {
    
   unsigned e=100000000;
  //  float eu=0;
  //  unsigned i;
  //  unsigned long euler;
    for (int i=1; i<ITER; i++) {
        e=e+(100000000/fact(i));
        
    }
    
   // ed=10000000000000*e;
//     eu=(float)(ed);
  //  euler = (unsigned long)(ed);
//   float *myPointer;
//    myPointer = &e;
   printf("%d \n", e) ;
   return e;
  }
