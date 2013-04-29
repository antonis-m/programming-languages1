#include <stdio.h>
#include <stdlib.h>
#define max(x,y) (((x) > (y)) ? (x) : (y))
#define abs(x,y) (((x) >= (y)) ? (x-y) : (y-x))

typedef struct {
    long long int upsos;  
    long long int tribe;   
} diad;

void swap (diad *x, diad *y);
int main (int argc, char ** argv) {
void partition (diad list[], long long, long long,long long,long long);

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


partition(list,K,N,0,N-1);


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


void partition(diad list[], long long K,long long N, long long left, long long right) {

long long counter,avg,diff,i,pivot,key,j,min,max;
int flag_left, flag_right;
counter=K;
max=list[0].upsos;
min=list[0].upsos;

for (i=0; i<N; i++) {
  if (list[i].upsos>max)
    max=list[i].upsos;
  if (list[i].upsos<min)
    min=list[i].upsos;
}

 avg=(max-min)/2;
 diff=abs(list[0].upsos,avg);
 pivot=0;
 for(i=0; i<N; i++) {
   if (abs(list[i].upsos,avg)<diff) {
     diff=abs(list[i].upsos,avg);
     pivot=i;
    } 
 }

printf("pivot : %lld \n",list[pivot].upsos);

min=left;
max=right;



if( min < max)
 {

//    printf("%lld %lld \n",min,max);  
    swap(&list[min],&list[pivot]);
      key = list[min].upsos;
      i = min+1;
      j = max;
//      printf("%lld %lld \n",i,j);
      while(i <= j)
      {
         while((i <= max) && (list[i].upsos <= key))
                i++;
         while((j >= min) && (list[j].upsos > key))
                j--;
        if( i < j)
                swap(&list[i],&list[j]);
      }
      // swap two elements
      swap(&list[min],&list[j]);
      
   }

for (i=0; i<N; i++)
  printf("%lld\n",list[i].upsos);

}
