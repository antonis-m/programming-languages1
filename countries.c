#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap (long long *x, long long *y);
long long int ch_pivot (long long int i, long long int j);
void quicksort (long long array[], long long int m, long long int n);
long long  BinarySearch(long long array[], long long);

int main (int argc, char ** argv) {

FILE * fp;
long long int N,i,k;
long long int * list;
long long int answer,exclusions,val;
fp=fopen(argv[1],"r");
fscanf(fp,"%lld", &N);
list =(long long *)calloc(N,sizeof(long long int));
for (i=0; i<N; i++) 
  fscanf(fp,"%lld", &list[i]);

quicksort(list,0,N-1);
/*for (i=0; i<N; i++) 
   printf("%lld ",list[i]);
   printf("\n");*/
answer=BinarySearch(list,N);
i=0;
for (k=(answer-1); k<N; k++) {
  if (list[k]%2==0)
     val=list[k]/2;
  else 
     val=list[k]/2+1;
 if(list[i]<val)
   i++;
 else {
   exclusions=k;
   i++;
 }

}

exclusions=N-1-exclusions;
printf("%lld %lld\n",answer,exclusions);
free(list);
return 0;
}



void swap (long long * x, long long * y) {
   long long temp;
   temp = *x;
   *x = *y;
   *y = temp; 
}


long long int ch_pivot (long long int i, long long int j) {
    
    return (i+j)/2;
}


void quicksort (long long list[], long long int m, long long int n) {
long long int key,i,j,k;
   if( m < n)
   {
      k = ch_pivot(m,n);
      swap(&list[m],&list[k]);
      key = list[m];
      i = m+1;
      j = n;
      while(i <= j)
      {
         while((i <= n) && (list[i] <= key))
                i++;
         while((j >= m) && (list[j] > key))
                j--;
        if( i < j)
                swap(&list[i],&list[j]);
      }
      // swap two elements
      swap(&list[m],&list[j]);
      // recursively sort the lesser list
      quicksort(list,m,j-1);
      quicksort(list,j+1,n);

   }
}


long long BinarySearch(long long int list[], long long int N) {
  long long int i=0;
  long long int up,down;
  long long int k,temp,failed,answer,val;
  int flag=0;
  temp= N/2;

  answer=1; 
  up=N;
  down=1;

 while(down<=up) {

 //printf("%lld %lld %lld %lld %d\n",answer,up,down,temp,flag); 
 i=0;
  for(k=(temp-1); k<N; k++) {   //parathuro metakinisis
    if (list[k]%2==0)
       val=list[k]/2;
    else 
       val=list[k]/2+1;
    if (list[i]<val) {
      flag=0;
      i++; 
    } else {
     flag=1;
     break;
    }
  }

 if (flag==0){ 
   up=temp-1;
   failed=temp;

     if ((failed+answer)%2==0)  //answer or temp
     	temp=(failed+answer)/2;
     else temp=((failed+answer)/2)+1;

}   

 else if (flag==1){

  down=temp+1;
  answer=temp;
 
  if(temp%2==0)
    temp=(temp+N)/2;
  else temp=((temp+N)/2) +1 ;
//    if (temp==N)
//      break;

}



}
return answer;
}
