#include<stdio.h>
 
int main(){
    
    int a,b,result;
    1<=a<=10;
    scanf("%d",&a);
    
        for(int i=1; i<=a; i++){
        scanf("%d",&b);
        if(i == 1){result = b;}
        if(i>1 &&result <= b){result = b;}
    }
    printf("%d",result);
    return 0;
    
}
