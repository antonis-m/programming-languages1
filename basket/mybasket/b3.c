#include <stdio.h>
#include <stdlib.h>
#define max(x,y) (((x) > (y)) ? (x) : (y))
#define abs(x,y) (((x) >= (y)) ? (x-y) : (y-x))
#define MAX 1000000    //na diorthwthei katalilla
typedef struct {
    long long int upsos;  
    long long int tribe;   
} diad;

long long int answer;

void swap (diad *x, diad *y);
int main (int argc, char ** argv) {
void partition (diad list[], long long, long long,long long,long long);

FILE * fp;
long long N,K,i,counter;
diad * list;
counter=0;

fp=fopen(argv[1],"r");
fscanf(fp,"%lld %lld",&N,&K);

list=malloc(N*sizeof(diad));

for(i=0; i<N; i++) {
  fscanf(fp,"%lld",&list[i].tribe);
  fscanf(fp,"%lld",&list[i].upsos);
}


partition(list,K,N,0,N-1);


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

long long counter,avg,diff,i,pivot,key,j,min,max,track;
int flag_left, flag_right;
long long * team;
team=calloc(K,sizeof(long long));
counter=K;
//max=list[0].upsos;
//min=list[0].upsos;
flag_left=0;
flag_right=0;
max=0;
for (i=0; i<N; i++) {
 max+=list[i].upsos;
//  if (list[i].upsos>max)
//    max=list[i].upsos;
//  if (list[i].upsos<min)
//    min=list[i].upsos;
}

 avg= max/N;  //(max-min)/2;
// printf("avg : %lld",avg);
 diff=abs(list[0].upsos,avg);
 pivot=0;
 for(i=0; i<N; i++) {
   if (abs(list[i].upsos,avg)<diff) {
     diff=abs(list[i].upsos,avg);
     pivot=i;
    } 
 }

//printf("pivot : %lld \n",list[pivot].upsos);

min=left;
max=right;
track=list[pivot].upsos;


if( min < max)
 {  
    swap(&list[min],&list[pivot]);
      key = list[min].upsos;
      i = min+1;
      j = max;

      while(i <= j)
      {
         while((i <= max) && (list[i].upsos <= key))
                i++;
         while((j >= min) && (list[j].upsos > key))
                j--;
        if( i < j)
                swap(&list[i],&list[j]);
      }

      swap(&list[min],&list[j]);
      
   }


for(i=0; i<N; i++)
  printf("%lld ",list[i].upsos);
printf("\n");
track=0;
while(track<=j) {
  if (team[list[track].tribe-1]==0) {
    team[list[track].tribe-1]=1;
    counter--;
    track++;
  } else
    track++;
}
if (counter==0)
  flag_left=1;

counter=K;
for(i=0; i<K; i++)
  team[i]=0;

track=right;
while(track>j) {
 if(team[list[track].tribe-1]==0) {
   team[list[track].tribe-1]=1;
   counter--;
   track--;
 } else
   track--;
}

if(counter==0)
  flag_right=1;

//printf("%d %d \n",flag_right,flag_left);
//printf("K: %lld\n", K);
for(i=0; i<K; i++) {
  team[i]=MAX;
//  printf("heeloooc %lld ",team[i]);
  
}
//vres lisi me sukrisi diaforwn gia ti mesaia periptwsi
for(i=0; i<N; i++) {
  track=list[i].upsos;
  diff= key-track;
  if (abs(diff,0) < abs(team[list[i].tribe-1],0))
    team[list[i].tribe-1]=diff;
}

//printf("key %lld\n",key);
//printf("\n");
for(i=0; i<K; i++) {
//  printf("team[i] arxika : %lld ",team[i]);
//  printf("\n key %lld \n",key);
  team[i]+=key;
//  printf("%lld ", team[i]);
}

min=max=team[0];
for(i=0; i<K; i++) {
  if(team[i]<min)
     min=team[i];
  if(team[i]>max)
     max=team[i];  
}
answer = max-min;
printf("answer : %lld\n",answer);
free(team);


if (flag_right==1 && flag_left==1) { 
 printf("case 1 starts\n");
 partition(list,K,j/*+1*/,0,j);
 partition(list,K,N-j-1,j+1,N-1);
} else if (flag_right==1 && flag_left==0) {
 printf("case 2 starts\n");
 partition(list,K,N-j-1,j+1,N-1);
 
}  else if (flag_right==0 && flag_left==0){
 printf("case 3 starts\n");
 partition(list,K,j+1,0,j);

}


}
