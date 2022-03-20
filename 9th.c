#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
    int cf;
    int ex,ey,ez;
    struct node* link;
};

typedef struct node nd;

nd* insert(nd *r,int exx,int eyy,int ezz,int cff){
    nd*t=(nd*)malloc(sizeof(nd));
    (t->cf=cff);
    (t->ex=exx);
    (t->ey=eyy);
    (t->ez=ezz);
    if(r==NULL){
        t->link=t;
        return t;
    }
    t->link=r->link;
    r->link=t;
    return t;
}
// void eval(nd* h){
//     nd *t=h;
//     int x,y,z;
//     scanf("%d%d%d",&x,&y,&z);
//     int sum=0;
//     do{
//         sum=sum+(t->cf)((pow(x,t->ex))(pow(y,t->ex))*(pow(z,t->ez)));
//         t=t->link;
//     }while(t!=h->link);
//     printf("%d",sum);
// }
void display(nd* t){
    if(t==NULL) return;
    nd*  p=t->link;
    do{
        printf("%d %d %d %d",p->ex,p->ey,p->ez,p->cf);
        printf("\n");
        p=p->link;
    }while(p!=t->link);
}

void eval1(nd *h)
{
  int x,y,z;
  double sum=0;
  printf("Accept the values of x,y ,z\n");
  scanf("%d%d%d",&x,&y,&z);
  nd *t=h->link;
 do
  {
   sum=sum+(t->cf)*pow(x,(t->ex))*pow(y,(t->ey))*pow(z,(t->ez));
   t=t->link;
  }while(t!=h->link);
  printf("%lf",sum);
}

nd* add(nd* h1,nd* h2){
    nd* p1=h1->link;
    nd* p2=h2->link;
    nd* h3=NULL;
    do{
        if(p1->ex==p2->ex && p1->ey==p2->ey && p1->ez==p2->ez){
            h3=insert(h3,p1->ex,p1->ey,p1->ez,p1->cf+p2->cf);
            p1=p1->link;
            p2=p2->link;
        }else if((p1->ex)>(p2->ex)){
             h3=insert(h3,p1->ex,p1->ey,p1->ez,p1->cf);
             p1=p1->link;
        }else{
            h3=insert(h3,p2->ex,p2->ey,p2->ez,p2->cf);
            p2=p2->link;
        }
    }while(p1!=h1->link && p2!=h2->link);
    while(p1!=h1->link){
        h3=insert(h3,p1->ex,p1->ey,p1->ez,p1->cf);
        p1=p1->link;
    }
     while(p2!=h2->link){
        h3=insert(h3,p2->ex,p2->ey,p2->ez,p2->cf);
        p2=p2->link;
    }
    return h3;
}

int main()
{
   nd* head1=NULL;
   nd* head2=NULL;
   nd* head3=NULL;
   int n1;
   printf("Enter Number Of Nodes \n");
   scanf("%d",&n1);
   for(int i=0;i<n1;i++){
       int exx,eyy,ezz,cff;
       scanf("%d%d%d%d",&exx,&eyy,&ezz,&cff);
       head1=insert(head1,exx,eyy,ezz,cff);
   }
   display(head1);
   eval1(head1);
   int n2;
   printf("Enter Number Of Nodes \n");
   scanf("%d",&n2);
   for(int i=0;i<n2;i++){
       int exx,eyy,ezz,cff;
       scanf("%d%d%d%d",&exx,&eyy,&ezz,&cff);
       head2=insert(head2,exx,eyy,ezz,cff);
   }
   display(head2);
   eval1(head2);
   head3=add(head1,head2);
   printf("Resultant Poly-\n");
   display(head3);

    return 0;
}