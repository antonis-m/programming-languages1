#include <stdio.h>
#include <stdlib.h>
#define max(x,y) (((x) > (y)) ? (x) : (y))

typedef struct {
    long long int upsos;  
    long long int tribe;   
} diad;

void swap (diad *x, diad *y);
long long int ch_pivot (long long int i, long long int j);
void quicksort_upsos (diad array[], long long int m, long long int n);
void quicksort_tribe (diad array[], long long int m, long long int n);


int main (int argc, char ** argv) {

FILE * fp;
long long N,K,i;
diad * list;
fp=fopen(argv[1],"r");
fscanf(fp,"%lld %lld",&N,&K);

list=malloc(N*sizeof(diad));

for(i=0; i<N; i++) {
  fscanf(fp,"%lld",&list[i].tribe);
  fscanf(fp,"%lld",&list[i].upsos);
}

quicksort_upsos(list,0,N-1);
for (i=0; i<N; i++)
  printf("%lld ", list[i].upsos);

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


void quicksort_tribe (diad list[], long long int m, long long int n) {
long long int key,i,j,k;
   if( m < n)
   {
      k = ch_pivot(m,n);
      swap(&list[m],&list[k]);
      key = list[m].tribe;
      i = m+1;
      j = n;
      while(i <= j)
      {
         while((i <= n) && (list[i].tribe <= key))
                i++;
         while((j >= m) && (list[j].tribe > key))
                j--;
        if( i < j)
                swap(&list[i],&list[j]);
      }
      // swap two elements
      swap(&list[m],&list[j]);
      // recursively sort the lesser list
      quicksort_tribe(list,m,j-1);
      quicksort_tribe(list,j+1,n);

   }
}

