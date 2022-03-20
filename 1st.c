/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>


int arr[50];
int n;
int pos;

void create(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&arr[i]);
    }
}
void insert(){
    int ele,pos;
    scanf("%d %d",&ele,&pos);
    for(int i=(n);i>=pos;i--){
        arr[i+1]=arr[i];
    }
    arr[pos]=ele;
    n++;
}
void delete(){
    int pos;
    scanf("%d",&pos);
    for(int i=(pos);i<n;i++){
        arr[i]=arr[i+1];
    }
  //  arr[pos-1]=ele;
    n--;
}
void display(){
    for(int i=1;i<=n;++i){
        printf("%d\t",arr[i]);
    }
}

int main()
{
    int ch;
    while(1){
        printf("1-Create An Array\n");
        printf("2-Display Array\n");
        printf("3-Inserting element in Array\n");
        printf("4-Deleting element in Array\n");
        printf("5-Exit\n");
        scanf("%d",&ch);
        switch(ch){
        case 1: 
                create();
                break;
        case 2: display();
                break;
                
        case 3: insert();
                break;
        case 4: delete();
                break;
        case 5: return 0;
        
    }}

    return 0;
}
