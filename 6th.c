
#include<ctype.h>
#include <stdio.h>
#include<stdlib.h>

#define max 5

int q[5];
int r=-1;
int f=0;
int cnt=0;


void push(){
    if(cnt==max){
        printf("overflow");
        return;
    }
    int ele;
    scanf("%d",&ele);
    r=(r+1)%max;
    q[r]=ele;
    cnt++;
}
void pop(){
    if(cnt==0){
        printf("underflow");
        return;
    }
    int ele;
    printf("%d",q[f]);
    f=(f+1)%max;
    
    cnt--;
}
void display(){
    if(cnt==0){
        printf("underflow");
        return;
    }
    int i,j;
    for(i=f,j=0;j<cnt;j++){
        printf("%d\t",q[i]);
        i=(i+1)%max;
    }
    
    
}






int main()
{
    
    int ch;
    
    while(1){
        printf("\n1-Push\n");
        printf("2-Pop\n");
        printf("3-display\n");
        printf("4-exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            
        }
        
    }

    return 0;
    
    
   
}
