#include<stdio.h>
int main(){
  int arr[20],i,n,count=0;
  printf("Enter the number of bits: \n");
  scanf("%d",&n);
  printf("Enter the data bits(only 0's and 1's are allowed) \n");
  for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  //printing after stuffing
  for(i=0;i<n;i++){
    if(arr[i]==1)
      count++;
    else
      count=0;
    //stuffing
    if(count==5){
    printf("0");
    count=0;}
  }
}
