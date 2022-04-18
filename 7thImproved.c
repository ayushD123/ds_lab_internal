/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>

struct emp{
    char usn[10];
    char name[10];
    char sem[5];
    struct emp* link;
};

typedef struct emp nd;

nd* create(){
    nd* t=(nd*)malloc(sizeof(nd));
    printf("Enter usn name sem-\n ");
    
    scanf("%s %s %s",t->usn,t->name,t->sem);
    return t;
}
int count(nd* h){
    nd*t=h;
    int cnt=0;
    while(t!=NULL){
        cnt++;
        t=t->link;
    }
    return cnt;
}
void display(nd* h){
    nd*t=h;
    int cnt=0;
    while(t!=NULL){
        //cnt
        printf("%s %s %s\n",t->usn,t->name,t->sem);
        t=t->link;
    }
    //return cnt;
}

nd* insert_f(nd* h){
    nd* t=create();
    if(h==NULL){
        return t;
    }
    t->link=h;
    return t;
}

nd* insert_rear(nd* h){
    nd* t=create();
    if(h==NULL){
        return t;
    }
    nd* p=h;
    while(p->link!=NULL){
        p=p->link;
    }
    p->link=t;
    return h;
}

nd* delete_f(nd* h){
    if(h==NULL){
        printf("deletion not possible\n");
        return h;
    }
    nd* p=h;
    printf("deleted node-%s %s %s\n",h->usn,h->name,h->sem);
    h=p->link;
    p->link=NULL;
    free(p);
    return h;
}
nd* delete_r(nd* h){
    if(h==NULL){
        printf("deletion not possible\n");
        return h;
    }
    if(h->link==NULL){
        printf("%s %s %s\n",h->usn,h->name,h->sem);
        return NULL;
    }
    nd* p=h;
    while(p->link->link!=NULL){
        p=p->link;
    }
    
    printf("%s %s %s\n",p->link->usn,p->link->name,p->link->sem);
    
    p->link=NULL;
    
    return h;
}

int main()
{
    nd* h=NULL;
    while(1){
        printf("1-Insert Front\n");
        printf("2-Insert rear\n");
        printf("3-delete Front\n");
        printf("4-delete rear\n");
        printf("5-count\n");
        printf("6-display\n");
        int x;
        scanf("%d",&x);
        switch(x){
            case 1:h=insert_f(h);
            break;
            case 2:h=insert_rear(h);
            break;
            case 3:h=delete_f(h);
            break;
            case 4:h=delete_r(h);
            break;
            case 5:printf("%d",count(h));
            break;
            case 6:display(h);
        }
        
    }

    return 0;
}
