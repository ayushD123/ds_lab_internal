
#include<ctype.h>
#include <stdio.h>
#include<stdlib.h>

int priority(char e){
    if(e=='+' || e=='-') return 1;
    if(e=='*' || e=='/') return 2;
    if(e=='^' || e=='%') return 3;
    return 0;
}




int main()
{
    
    char exp[10];
    scanf("%s",exp);
    char st[10];
    char e;
    int i=0;
    e=exp[i];
    char x;
    int top=-1;
    
    while(e!='\0'){
        if(isalnum(e)){
            printf("%c",e);
        }else if(e=='('){
            st[++top]=e;
        }else if(e==')'){
            while((x=st[top--])!='('){
                printf("%c",x);
            }
        }else{
            while(priority(e)<=priority(st[top])){
                printf("%c",st[top--]);
            }
            st[++top]=e;
        }
        i++;
        e=exp[i];
    }
    while(top!=-1){
        printf("%c",st[top--]);
    }
   
}
