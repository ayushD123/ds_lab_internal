

#include <stdio.h>
const int max=10;

int n;
int st[10];

int top=-1;
int cnt=0;


void palin(){
    int rev[10];
    int num[10];
    int i,t;
    
    for(i=0,t=top;t>=0;i++,t--){
        num[i]=rev[t]=st[i];
    }
    for(i=0;i<cnt;i++){
        if(num[i]!=rev[i])
        break;
    }
    if(i==cnt){
        printf("its a palindrome\n");
    }else{
        printf("its not a palindrome\n");
    }
}

void push(){
    // if(cnt==max){
    //     printf("stack overflowed\n");
    //     return;
    // }
    int ele;
    printf("Enter element to push\n");
    scanf("%d",&ele);
    st[++top]=ele;
    cnt++;
}

void pop(){
    if(cnt==0){
        printf("stack underflowed\n");
        return;
    }
    printf("poppped element-%d",st[top]);
    top--;
    cnt--;
}
void display(){
    if(cnt==0){
        printf("stack empty\n");
        return;
    }
    for(int i=0;i<cnt;i++){
        printf("%d\t",st[i]);
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
            case 5:
                palin();
        }
        
    }

    return 0;
}
