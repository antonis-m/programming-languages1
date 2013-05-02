#include <stdio.h>
#include <stdlib.h>
#define max(x,y) (((x) > (y)) ? (x) : (y))
#define MAX 9999999999;
typedef struct {
    long long int upsos;  
    long long int tribe;   
} diad;

void swap (diad *x, diad *y);
long long int ch_pivot (long long int i, long long int j);
void quicksort_upsos (diad array[], long long int m, long long int n);


int main (int argc, char ** argv) {

FILE * fp;
long long N,K,i,j,counter,answer,temp;
diad * list;
long long  *check;
int flag_f, flag_b;
fp=fopen(argv[1],"r");
fscanf(fp,"%lld %lld",&N,&K);

list=malloc(N*sizeof(diad));
check=malloc(K*sizeof(long long));




for(i=0; i<N; i++) {
  fscanf(fp,"%lld",&list[i].tribe);
  fscanf(fp,"%lld",&list[i].upsos);
 }

for(i=0; i<K; i++) 
  check[i]=-1;


quicksort_upsos(list,0,N-1);

counter=K;
i=j=-1;
flag_f=1;
flag_b=0;
 
while ( i<=N ) {
  i++;
  if (check[list[i].tribe -1] == -1) {
    check[list[i].tribe-1]=list[i].upsos;
    counter--;
  } else {
     if(list[i].upsos > check[list[i].tribe-1])
       check[list[i].tribe-1]=list[i].upsos;
  }
  if (counter == 0 && (i<=N)) 
     flag_b=1; 
    
  
  while ((j<=i) && (flag_b==1)) {
    j++;
    if( check[list[j].tribe-1] !=list[j].upsos )
      ;  
    else {
      temp=list[i].upsos-list[j].upsos;
      if (temp<answer)
        answer= temp;
      check[list[j].tribe-1]=-1;
      counter++;
      flag_b=0;

//      printf("answer is %lld \n", answer);
    }

  }

}

printf("final answer is : %lld\n", answer);

//printf("i is %lld\n",i);
//for(j=0; j<K; j++)
//  printf("check[i] is : %lld\n",check[j]);

free(check);
free(list);
return 0;
}


void swap (diad * x, diad * y) {
   diad temp;
   temp = *x;
   *x = *y;
   *y = temp; 
}


long long int ch_pivot (long long int i, long long int j) {
    
    return (i+j)/2;
}


void quicksort_upsos (diad list[], long long int m, long long int n) {
long long int key,i,j,k;
   if( m < n)
   {
      k = ch_pivot(m,n);
      swap(&list[m],&list[k]);
      key = list[m].upsos;
      i = m+1;
      j = n;
      while(i <= j)
      {
         while((i <= n) && (list[i].upsos <= key))
                i++;
         while((j >= m) && (list[j].upsos > key))
                j--;
        if( i < j)
                swap(&list[i],&list[j]);
      }
      // swap two elements
      swap(&list[m],&list[j]);
      // recursively sort the lesser list
      quicksort_upsos(list,m,j-1);
      quicksort_upsos(list,j+1,n);

   }
}



