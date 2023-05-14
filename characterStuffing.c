#include<stdio.h>
#include<string.h>
int main(){
    char input[100],stuffed[200];
    char flag='d';
    int i,j=0;
    printf("Enter the string \n");
    gets(input);
    stuffed[j++]=flag; //Addng flag bit at the begining
    
    /* stuffed[j++]=flag works as follows
        stuffed[j]=flag;
        j=j+1;  */
        
    for(i=0;i<strlen(input);i++){
        if(input[i]==flag){
            stuffed[j++]=flag;
            
  /*  If input character is a flag character, add another flag character
             stuffed[j] = flag;
              j = j + 1;
              */
        }
        stuffed[j++]=input[i];
    }
    //Adding the flag at the end and incrementing j
    stuffed[j++]=flag;
    stuffed[j]="\0";
    printf("The stuffed string is %s \n",stuffed);
}
