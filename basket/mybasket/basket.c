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
long long N,K,i,min,max,track, left, right;
diad * list;
long long * team1,* team2, *check;
int flagl, flagr;
fp=fopen(argv[1],"r");
fscanf(fp,"%lld %lld",&N,&K);

list=malloc(N*sizeof(diad));
team1=calloc(K,sizeof(long long));
team2=calloc(K,sizeof(long long));
check=calloc(K,sizeof(long long));

min=0; max=N-1; flagl=flagr=1;


for(i=0; i<N; i++) {
  fscanf(fp,"%lld",&list[i].tribe);
  fscanf(fp,"%lld",&list[i].upsos);
  team1[list[i].tribe-1]+=1;
  team2[list[i].tribe-1]+=1;  
}


quicksort_upsos(list,0,N-1);

/*for (i=0; i<N; i++)
  printf("%lld ", list[i].upsos);
printf("\n");
for(i=0; i<N; i++)
  printf("%lld ",list[i].tribe);
printf("\n");
*/

while ((min <= N-1) && (flagl==1)){
 track=list[min].tribe;
 team1[track-1]-=1;
 if (team1[track-1]==0)
   flagl=0;
 else
   min++;

}

track=list[min].tribe;
team2[track-1]=-10;
free(team1);

while ((max >= 0) && (flagr==1)){
 track=list[max].tribe;
 team2[track-1]-=1;
 if (team2[track-1]==0)
   flagr=0;
 else
   max--;

}
free(team2);


left=min;
right=max;

diad * left_list,* right_list;
left_list=malloc(left*sizeof(diad));
right_list=malloc((N-right-1)*sizeof(diad));

for(i=0; i<left; i++) {
  left_list[i].upsos=list[i].upsos;
  left_list[i].tribe=list[i].tribe;
}

for(i=right+1; i<N; i++) {
  right_list[i-right-1].upsos=list[i].upsos;
  right_list[i-right-1].tribe=list[i].tribe;
}

for(i=min; i<=max;i++)
  check[list[i].tribe-1]=1;

quicksort_tribe(left_list,0,left-1);
quicksort_tribe(right_list,0,N-right-2);

/*for (i=0; i<left; i++ ){
  printf("%lld %lld \n", left_list[i].tribe,left_list[i].upsos);

}
printf("\n");
for(i=0;i<N-right-1; i++)
  printf("%lld %lld \n", right_list[i].tribe,right_list[i].upsos);
*/

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

