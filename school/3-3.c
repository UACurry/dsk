#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    int n,i=1;
    scanf("%d",&n);
    while(i++){
        if((int)pow(2,i)%n==1){
            printf("2^%d mod %d=1",i,n);
            break;
        }
    }

    while (1) {
        getchar();
    }
    return 0;
}
