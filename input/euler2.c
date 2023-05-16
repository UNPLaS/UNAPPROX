#include <stdio.h>
//#include <stdlib.h>



#define ITER 6 //Precisse 12 
 
unsigned fact(int x) {
    unsigned p=1;
    unsigned i;
    for (i=1; i<=x; i++) {
        p=p*i;        
    }
    return p;
}
    
 
int main(void) {
    
   double e=1.0;
  
    //unsigned i;
    for (int i=1; i<ITER; i++) {
        e=e+(1.0/(double)fact(i));
    }
    
    printf("%1.9f \n", e) ;
	//2.718281828 45904523536
 //  return e;
  }
