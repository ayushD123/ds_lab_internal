
#include<ctype.h>
#include <stdio.h>
#include<stdlib.h>

float priority(char e,int op1,int op2){
    if(e=='+') return op1+op2;
    if(e=='-') return op1-op2;
    if(e=='*') return op1*op2;
    if(e=='/') return op1/op2;
    if(e=='%') return op1%op2;
    return 0;
}




int main()
{
    
    char exp[10];
    scanf("%s",exp);
    float st[10];
    int op1,op2;
    char e;
    int i=0;
    e=exp[i];
    char x;
    int top=-1;
    float res;
    
    while(e!='\0'){
        if(isalnum(e)){
            st[++top]=e-'0';
        }else {
            op2=st[top--];
            op1=st[top--];
            res=priority(e,op1,op2);
            st[++top]=res;
        }
        i++;
        e=exp[i];
        }
        
   
    {
        printf("%f",st[top--]);
    }
   
}
