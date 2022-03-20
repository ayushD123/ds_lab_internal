/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* llink;
    struct node* rlink;
    
};
typedef struct node nd;

nd* insert(nd* h){
    int key;
    scanf("%d",&key);
    nd* t=(nd*)malloc(sizeof(nd));
    t->data=key;
    nd* prev=0;
    nd* curr=h;
    if(h==NULL) return t;
    
    while(curr){
        prev=curr;
        if(t->data<curr->data){
            curr=curr->llink;
        }else{
            curr=curr->rlink;
        }
    }
    if(key<prev->data){
        prev->llink=t;
    }else{
        prev->rlink=t;
    }
    return h;
}

void inorder(nd* h){
    if(h){
        inorder(h->llink);
        printf("%d",h->data);
        inorder(h->rlink);
    }
}

void search(nd* h,int key){
    if(h==NULL){
        printf("unsucess search");
        return;
    }
    if(h->data==key){
        printf("search success");
        return;
    }
    if(h->data>key){
        return search(h->llink,key);
    }else{
        return search(h->rlink,key);
    }
    //printf("search unsucess");
    
}

int main()
{
    nd* h=NULL;
    
    h=insert(h);
    h=insert(h);
    h=insert(h);
    h=insert(h);
    h=insert(h);
    inorder(h);
    search(h,6);
    search(h,99);

    return 0;
}
