/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>


void hanoi(int n,char s,char t,char d){
    if(n==0){
        return;
    }
    hanoi(n-1,s,d,t);
    printf("%d disk moved from %c to %c\n",n,s,d);
    hanoi(n-1,t,s,d);
}

int main()
{
    int n;
    printf("Enter number of disks\n");
    scanf("%d",&n);
    hanoi(n,'A','B','C');

    return 0;
}
