#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct LL{
    struct node *head;
    struct node *tail;
    size_t _size;
};
struct node* newNode(int value){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Memory allocation failed\n"); return NULL;
    }
    newnode->data=value;
    newnode->next=NULL;
    return newnode;
}
struct LL* newLL(){
    struct LL  *l1=(struct LL*) malloc(sizeof(struct LL));
    if(l1==NULL){
        printf("Memory allocation failed\n");
        return NULL;
    }
    l1->head=NULL;
    l1->tail=NULL;
    l1->_size=0;
    return l1;
}
int isempty(struct LL *l1){
    if(!l1->head){
        return 1;
    }
    return 0;
}
void display(struct LL *l1){
    struct node *temp;
    if(isempty(l1)){
        printf("The linked list is empty\n");
        return;
    }
    temp=l1->head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
void insertatbegin(struct LL *l1,int val){
    struct node *temp=newNode(val); 
    if(temp==NULL){return;}
    if(isempty(l1)){
        l1->tail=temp;
    }
    temp->next=l1->head;
    l1->head=temp;
    (l1->_size)++;
    return;
}
void insertatend(struct LL *l1, int val){
    struct node *temp = newNode(val);
    if(temp==NULL){return;}
    if(isempty(l1)){
        insertatbegin(l1,val);
        return;
    }
    l1->tail->next=temp;
    l1->tail=temp;
    (l1->_size)++;
    return;
}
void insertbeforek(struct LL *l1,int k,int val){
    if(isempty(l1)){
        printf("list is empty\n");
        return;}
    struct node *itr=l1->head;
    if(l1!=NULL && l1->head->data==k){ 
        insertatbegin(l1,val);
        return;
    }         //insert in begin  
    while(itr->next!=NULL && itr->next->data!=k ){ 
        itr=itr->next;
    }         //find node before k
    if(itr->next==NULL){
        printf("%d is not present in list\n",k);
        return;
    }         //not present
    struct node *temp = newNode(val);
    if(temp==NULL){return;}
    temp->next=itr->next;
    itr->next=temp;
    (l1->_size)++;
    return;
}
void insertafterk(struct LL *l1,int k,int val){
    if(isempty(l1)){
        printf("list is empty\n");
        return;}
    struct node *itr=l1->head;
    if(l1!=NULL && l1->tail->data==k){ 
        insertatend(l1,val);
        return;
    }         //insert in end
    while(itr!=NULL && itr->data!=k ){ 
        itr=itr->next;
    }         //find node before k
    if(itr==NULL){
        printf("%d is not present in list\n",k);
        return;
    }         //not present
    struct node *temp = newNode(val);
    if(temp==NULL){return;}
    temp->next=itr->next;
    itr->next=temp;
    (l1->_size)++;
    return;
}
void insertati(struct LL *l1,int i,int val){
    if(i<1 || i>l1->_size+1){
        printf("Invalid Position\n");
        return;
    }
    if (i==1){
        insertatbegin(l1,val);
        return;
    }
    if(i==(l1->_size)+1){
        insertatend(l1,val);
        return;
    }
    struct node* itr=l1->head;
    struct node *temp = newNode(val);
    if(temp==NULL){return;}
    for(int count=1;count<i-1;count++){
      itr=itr->next;
    }
    temp->next=itr->next;
    itr->next=temp;
    l1->_size++;
    return;
}

void deletefrombegin(struct LL *l1){
    if(isempty(l1)){
    printf("Linked list is empty\n");
    return;
    }
    struct node* temp=l1->head;
    if(temp==NULL){return;}
    l1->head=l1->head->next;
    free(temp);
    l1->_size--;
    printf("Element removed successfully\n");
    return;
}

void deletefromend(struct LL *l1){
    if(l1->head==NULL){
    printf("Linked list is empty\n");
    return;
    }
    struct node* itr=l1->head;
    while(itr->next!=l1->tail){
        itr=itr->next;
    }
    l1->tail=itr;
    l1->tail->next=NULL;
    itr=itr->next;
    free(itr);
    l1->_size--;
    printf("Value deleted successfully\n" );
    return;
}
void deletionofk(struct LL *l1, int val){
    if(isempty(l1)){
    printf("Linked list is empty\n");
    return;
    }
    struct node * itr=l1->head;
    if(l1->head->data==val){
        deletefrombegin(l1);
        return;
    }
    if(l1->tail->data==val){
        deletefromend(l1);
        return;
    }
    while(itr->next->data!=val){
        itr=itr->next;
    }
    struct node * temp=itr->next;
    itr->next=temp->next;
    free(temp);
    l1->_size--; 
    return;
}
void deleteati(struct LL *l1,int i){
    struct node* itr=l1->head;
    for(int count=1;count<i-1;count++){
            itr=itr->next;
    }
    struct node* temp=itr->next;
    itr->next=temp->next;
    free(temp);
    l1->_size--; 
    return;
}
int main(){
struct LL *l1=newLL();
int n,k,val;
while(1){
printf("Enter the number corresponding to the operation you want to perform:\n");
printf("1.Insert value at beginning\n2.Insert at end\n3.Insert before k\n4.Insert after k\n5.Insert at position i\n");
printf("6.Delete value at beginning\n7.Delete at end\n8.Delete k\n9.Delete at position i\n10.Display the list\n11.Exit\n");
scanf("%d",&n); 
switch(n){
    case 1:{
        printf("Enter value:\n");
        scanf("%d",&val);
        insertatbegin(l1,val);
        break;
    };
    case 2:{
        printf("Enter value:\n");
        scanf("%d",&val);
        insertatend(l1,val);
        break;
    };
    case 3:{
        printf("Enter the value of k:\n");
        scanf("%d",&k);
        printf("Enter element to be inserted:\n");
        scanf("%d",&val);
        insertbeforek(l1,k,val);
        break;
   
};
    case 4:{
        printf("Enter the value of k:\n");
        scanf("%d",&k);
        printf("Enter element to be inserted:\n");
        scanf("%d",&val);
        insertafterk(l1,k,val);
        break;
    };
    case 5:{
        printf("Enter index:\n");
        scanf("%d",&k);
        printf("Enter element to be inserted:\n");
        scanf("%d",&val);
        insertati(l1,k,val);
        break;
    };
    case 6:{
        deletefrombegin(l1);
        break;
    };
    case 7:{
        deletefromend(l1);
        break;
    };
    case 8:{
        printf("Enter the value of k:\n");
        scanf("%d",&k);
        deletionofk(l1,k);
        break;
    };
    case 9:{
        printf("Enter the index:\n");
        scanf("%d",&k);
        deleteati(l1,k);
        break;
    };
    case 10:{
        display(l1);
        break;
    };
    case 11: {
        exit(1);
    };
    default: {
        printf("Invalid input\n");
    };
};
}
    return 0;}