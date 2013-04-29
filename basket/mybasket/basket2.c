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
long long N,K,i,min,max,track,counter;
diad left,right;
diad * list;
long long * team;
int flagl, flagr;
counter=0;

fp=fopen(argv[1],"r");
fscanf(fp,"%lld %lld",&N,&K);

list=malloc(N*sizeof(diad));
team=calloc(K,sizeof(long long));

min=0; max=0; track=0;


for(i=0; i<N; i++) {
  fscanf(fp,"%lld",&list[i].tribe);
  fscanf(fp,"%lld",&list[i].upsos);
 
}


quicksort_upsos(list,0,N-1);

for (i=0; i<N; i++)
  printf("%lld ", list[i].upsos);
printf("\n");
for(i=0; i<N; i++)
  printf("%lld ",list[i].tribe);
printf("\n");

/*team[list[0].tribe-1]=list[0].upsos;
tribes=list[0].tribe;
i=1;
while (tribes==list[0].tribe) {
 team[list[0].tribe-1]=list[i].upsos ;
 tribes=list[i].tribe;
 i++;
}
*/

left=right=list[0];
i=0;

while(counter<K) {
 right=list[i];
 if (team[right.tribe-1]==0){
   team[right.tribe-1]=1;
   counter++;
 }
 i++;
}
track=i;
for (i=0; i<K; i++)
 team[i]=0;





free(team);
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

