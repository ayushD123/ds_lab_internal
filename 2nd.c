/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
char str[20],pat[10],rep[10],fin[20];


int strlenn(char *a){
    int len=0;
    for(;a[len]!='\0';len++);
    return len;
}

void repp(){
    int s=strlenn(str);
    int l=0;
    int q=0;
    int z=0;
    int r=strlenn(pat);
    int max=s-r+1;
    int k=0;
    for(;k<=max;){
        for(l=0;l<r;l++){
            if(pat[l]!=str[k+l])
            break;
        }
        if(l==r){
            for(z=0;z<strlenn(rep);z++){
                fin[q++]=rep[z];
                k=k+r;
            }
        }else{
            fin[q++]=str[k++];
        }
        fin[q]='\0';
    }
    
}

int main()
{
    scanf("%s",str);
    scanf("%s",pat);
    scanf("%s",rep);
    // str={"abababa"};
   // pat={"ba"};
   // rep="BA";
    repp();
    printf("%s",fin);
    

    return 0;
}
