/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>

#define sz 3

FILE* fp;

struct emp{
    char name[5];
    int empno;
    char sal[5];
};
typedef struct emp EMP;

struct hashtable{
    int key;
    long int addr;
};
typedef struct hashtable ht;

int hashval(int n){
    return (n%sz);
}

ht h[sz];

void insert(int n){
    EMP a;
    int hindex,ct;
    for(int i=0;i<n;++i){
        scanf("%s %d %s",a.name,&a.empno,a.sal);
        hindex=hashval(a.empno);
        ct=hindex;
        while(h[hindex].key!=-1){
            hindex=(hindex+1)%sz;
            if(hindex==ct){
                printf("insertion not possible\n");
                return;
            }
        }
        h[hindex].key=a.empno;
        fseek(fp,0,SEEK_END);
        h[hindex].addr=ftell(fp);
        
        fprintf(fp,"%s %d %s\n",a.name,a.empno,a.sal);
        printf("insertion success\n");
    }
}

void search(){
    EMP a;
    int x;
    scanf("%d",&x);
    int hindex=hashval(x);
    int ct=hindex;
    while(h[hindex].key!=x){
        hindex=(hindex+1)%sz;
            if(hindex==ct){
                printf("search not possible\n");
                return;
            }
    }
    printf("Search Success\n");
    fseek(fp,h[hindex].addr,SEEK_SET);
    fscanf(fp,"%s %d %s",a.name,&a.empno,a.sal);
    printf("%s %d %s",a.name,a.empno,a.sal);
}

void display(){
    EMP a;
    
    for(int i=0;i<sz;i++){
        if(h[i].key!=-1){
            printf("hast table %d %ld |",h[i].key,h[i].addr);
            fseek(fp,h[i].addr,SEEK_SET);
            fscanf(fp,"%s %d %s",a.name,&a.empno,a.sal);
        printf("%s %d %s\n",a.name,a.empno,a.sal);
}
        }
    }


int main()
{
    int n;
    fp=fopen("emp.txt","w+");
    for(int j=0;j<sz;j++){
        h[j].key=-1;
    }
    int ch;
    while(1){
        printf("1-Insert\n");
        printf("2-Search\n");
        printf("3-Display\n");
        printf("4-exit\n");
        scanf("%d",&ch);
        switch(ch){
        case 1:
                printf("enter number of employee-\n");
                scanf("%d",&n);
                insert(n);
                break;
        case 2: search();
                break;
        case 3: display();
                break;
        case 4: return 0;
        }
    }

    return 0;
}
