#include<stdio.h>
int main(){
    int n,i,j,k;
    printf("Enter the no of nodes: \n");
    scanf("%d",&n);
    int a[n][n],b[n][n];
    printf("Enter the cost matrix: \n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("The resultant matrix is: \n");
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(a[i][j]>a[i][k]+a[k][j]) 
                    a[i][j]=a[i][k]+a[k][j];
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            b[i][j]=a[i][j];
            if(i==j){
                b[i][j]=0;
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    return 0;
}
