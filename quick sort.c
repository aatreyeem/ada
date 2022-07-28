#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void quicksort(int number[],int first,int last){
   int i, j, pivot, temp;
   if(first<last){
      pivot=first;
      i=first;
      j=last;
      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
         i++;
         while(number[j]>number[pivot])
         j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }
      
      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);
   }
}
int main(){

   clock_t start, end;
   int i, n;
   printf("Enter number of elements ");
   scanf("%d",&n);
   int arr[n];
//   printf("Enter the elements of the array\n");
//   for(int i=0;i<n;i++){
//       scanf("%d",&arr[i]);
//   }
   
  for(int i=0;i<n;i++){
      arr[i]=rand();
  }
   
   start=clock();
   quicksort(arr,0,n-1);
   end=clock();
   
//   printf("Order of Sorted elements: ");
//   for(i=0;i<n;i++)
//   printf(" %d",arr[i]);
   printf("\ntime taken: %f ",difftime(end,start)/CLOCKS_PER_SEC);
   return 0;
}