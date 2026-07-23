/*  Name: Tanvi Gupta
    Problem Statement: Write a program to swap first and last element of a array using call by reference
 
*/
void swap(int *a,int *b);
#include<stdio.h>
int main(){
    int n,i;
    printf("Enter number of elements in array:\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
swap(&a[0],&a[n-1]);
   for(i=0;i<n;i++){
        printf("%d",a[i]);
    }
return 0;
}
void swap(int *a,int *b){
int k;
k=*a;
*a=*b;
*b=k;
}