/*  Name: Tanvi Gupta
    Problem Statement: Write a program to find sum of elements of array(without arguments,with return type)
*/
int Sum();
#include<stdio.h>
int main(){
    int sum;
sum=Sum();
        printf(" Sum:%d",sum);
return 0;
}
int Sum(){
int n,i,sum=0;
    printf("Enter number of elements in array:\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
for(i=0;i<n;i++){
        sum+=a[i];
    }
    return sum;
}