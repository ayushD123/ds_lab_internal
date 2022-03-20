
#include<ctype.h>
#include <stdio.h>
#include<stdlib.h>

struct node{
    char usn[10];
    char name[10];
    char branch[10];
    char phno[10];
    char sem[10];
    struct node* link;
};

typedef struct node nd;


int count(nd* h){
    nd* p=h;
    
    int cnt=0;
    while(p!=NULL){
        p=p->link;
        cnt++;
    }
    return cnt;
}

void display(nd* h){
    nd* p=h;
    if(p==NULL){
        printf("List empty\n");
        return;
        
    }
    
    
    while(p!=NULL){
        printf("%s %s %s %s %s\t",p->name,p->usn,p->branch,p->sem,p->phno);
        p=p->link;
        
    }
    
}
nd* create(){
    nd* t=(nd*)malloc(sizeof(nd));
    t->link=NULL;
    printf("enter name usn branch sem phno\n");
    scanf("%s %s %s %s %s",t->name,t->usn,t->branch,t->sem,t->phno);
    
    return t;
}
void pop(){
    
}

nd* insert_f(nd* r){
    
    nd* t=create();
    if(r==NULL){
        return t;
    }
    t->link=r;
    return t;
}

nd* insert_r(nd* r){
    
    
    nd* t=create();
    nd* p=r;
    while(p->link!=NULL){
        p=p->link;
    }
    p->link=t;
    
    return r;
}

nd* delete_f(nd* r){
    if(r==NULL){
        printf("Delteion not possible\n");
        return r;
    }
    nd* p=r;
    printf("delted item %s %s %s %s %s\t",p->name,p->usn,p->branch,p->sem,p->phno);
    r=p->link;
    p->link=NULL;
    free(p);
    return r;
}
nd* delete_r(nd* r){
    if(r==NULL){
        printf("Delteion not possible\n");
        return r;
    }
    if(r->link==NULL){
        printf("delted item %s %s %s %s %s\t",r->name,r->usn,r->branch,r->sem,r->phno);
        return NULL;
    }
    nd* p=r;
    nd* q;
    int i=1;
    while(i<count(r)-1){
        p=p->link;
        i++;
    }
    if(p->link!=NULL){
    q=p->link;
    printf("delted item %s %s %s %s %s\t",q->name,q->usn,q->branch,q->sem,q->phno);
    p->link=NULL;
    } 
    return r;
}




int main()
{
    
    int ch;
    nd* h=NULL;
    
    while(1){
        printf("\n1-Push\n");
        printf("2-Pop\n");
        printf("3-display\n");
        printf("4-delete f\n");
        printf("5-delete r\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                h=insert_f(h);
                break;
            case 2:
                h=insert_r(h);
                break;
            case 3:
                display(h);
                break;
            case 4:
                h=delete_f(h);
                break;
            case 5:
                h=delete_r(h);
                break;
                
            
        }
        
    }

    return 0;
    
    
   
}
