#include<stdio.h>
int main(){
//Go Back N
int ws,fs;
printf("Enter the window size: ");
scanf("%d",&ws);
printf("Enter the Frame size: ");
scanf("%d",&fs);
int frame[fs];
printf("Enter the data into the frame: ");
for(int i=1;i<=fs;i++){
scanf("%d",&frame[i]);
}
int receiver[fs],i;
for(i=1;i<=fs;i++){
if(i%ws==0){
printf("%d",frame[i]);
printf("\n");
printf("Acknowledgement received \n");
}else{
printf("%d",frame[i]);
printf("\n");
}
}
printf("Final acknowledgement received \n");
return 0;
}
