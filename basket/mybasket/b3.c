#include <stdio.h>
#include <stdlib.h>
#define max(x,y) (((x) > (y)) ? (x) : (y))
#define abs(x,y) (((x) >= (y)) ? (x-y) : (y-x))
#define MAX 9999999999    //na diorthwthei katalilla

typedef struct {
    long long int upsos;  
    long long int tribe;   
} diad;

long long int answer=MAX;

void swap (diad *x, diad *y);
int main (int argc, char ** argv) {
void partition (diad list[], long long team[], long long, long long,long long,long long);

FILE * fp;
long long N,K,i;
diad * list;
long long * team;


fp=fopen(argv[1],"r");
fscanf(fp,"%lld %lld",&N,&K);

list=malloc(N*sizeof(diad));
team=calloc(K,sizeof(long long));
for(i=0; i<N; i++) {
  fscanf(fp,"%lld",&list[i].tribe);
  fscanf(fp,"%lld",&list[i].upsos);
}


partition(list,team,K,N,0,N);    // ekana to N-1, N
printf("%lld \n",answer);
//free(team);
free(list);
return 0;
}


void swap (diad * x, diad * y) {
   diad temp;
   temp = *x;
   *x = *y;
   *y = temp; 
}


void partition(diad list[],long long team[], long long K,long long N, long long left, long long right) {

long long counter,avg,diff,i,pivot,key,j,min,max,track,temp;
int flag_left, flag_right;
for(i=0; i<K; i++)
  team[i]=0;

counter=K;
flag_left=0;
flag_right=0;
max=0;
min=MAX ;   
//printf("entering partition, print list for first time\n");
//for(i=left; i<right; i++){  //check ekana allagi se sxesi me panw
//  printf("%lld ",list[i].upsos);
//}
//printf("\n");
//printf("left, right : %lld %lld",left,right);
for (i=left; i<right; i++) {  //for (i=0; i<N; i++) {
if (list[i].upsos < min ) 
  min =list[i].upsos;
if (list[i].upsos > max)
  max =list[i].upsos;
}


avg = (max/2) +(min/2);
//printf("max min avg : %lld %lld %lld \n",max,min,avg);

 diff=abs(list[left].upsos,avg);   ///0
 pivot=left;   ///0 
for(i=left; i<right; i++){  
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
//printf("j is: %lld",j);
//printf("\nprinting list 2nd time after partitin\n");

//for(i=left;i<right; i++)//for(i=0; i<N; i++)
//  printf("%lld ",list[i].upsos);
//printf("\n");



track=left;
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

track=right-1;   //-1
//printf("check here j %lld:\n",j);
//printf("right = %lld \n",right);
while(track>j) {
// printf("check track and j : %lld %lld \n",track, j );
 if(team[list[track].tribe-1]==0) {
   team[list[track].tribe-1]=1;
   counter--;
   track--;
 } else
   track--;
}
//printf("check here for counter : %lld \n",counter);
if(counter==0)
  flag_right=1;


//printf("%d %d \n",flag_right,flag_left);

for(i=0; i<K; i++) {
  team[i]=MAX;
}

//vres lisi me sukrisi diaforwn gia ti mesaia periptwsi-pithanws provlimatiko.
for(i=left; i<right; i++) {  
  track=list[i].upsos;
  diff= key-track;
  if (abs(diff,0) < abs(team[list[i].tribe-1],0))
    team[list[i].tribe-1]=diff;
}



for(i=0; i<K; i++) {
  team[i]+=key;
}

min=max=team[0];
for(i=0; i<K; i++) {
  if(team[i]<min)
     min=team[i];
  if(team[i]>max)
     max=team[i];  
}
temp = max-min;
if (temp < answer)
  answer=temp;
//printf("answer : %lld\n",answer);

//printf("flags %d %d",flag_left, flag_right);
//free(team);

if (flag_right==1 && flag_left==1 && N>K ) { 
// printf("case 1 starts\n");
 partition(list,team,K,j+1-left, left, j+1);              
 partition(list,team,K,right-(j+1),j+1,right);             
 
 
} else if (flag_right==1 && flag_left==0 && N>K  ) {
// printf("case 2 starts K, j , right :%lld, %lld, %lld \n",K, j,right);
 partition(list,team,K,right-(j+1),j+1,right);
 
} else if (flag_right==0 && flag_left==1 && N >K ){
// printf("case 3 starts\n");
 partition(list,team,K,j+1-left,left,j+1);  

}/* else  exit(0);*/  

}
