#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void Create(int A[], int n){
    struct Node *t, *last;
    first=new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1; i<n; i++){
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *p){
    cout << "The elements of Linked List are: ";
    while(p!=NULL){
        cout << p->data << " ";
        p=p->next;
    }
    cout << endl;
}

 int CountNodes(struct Node*p){
    int c=0;
    while(p){
        c++;
        p=p->next;
    }
    cout << "The number of Nodes in Linked list are : "  << c;
    cout << endl;
    return c;
}

void SumofEle(struct Node *p){
    int sum=0;
    while(p){
        sum=sum + p->data;
        p=p->next;
    }
    cout << "The sum of elelments of LL is : "  << sum;
    cout << endl;
}

void Max(struct Node *p){
    int max=INT16_MIN;
    while(p){
        if(max < p->data){
            max=p->data;
        }
        else 
          p=p->next;
    } 
    cout << "The maximum element of the linked list is: " << max << endl;
}

int RMax(struct Node *p){
    int x=INT16_MIN;
    if(p==0){
       return x;
    }
    else{
        x=RMax(p->next);
        if(x > p->data)
          return x;
        else 
        return p->data;
    }
}

void Search(struct Node *p, int key){
    int node=1;         
    while(p){
        if(key == p->data){
            cout << "Key found at: " << node << endl;
            break;
        }
        node++;                                                  //node ++ yha aayega
        p=p->next;
    }
    if(node>5){
        cout << "Element not Found" << endl;
    }
}
int Insertion(struct Node *p, int ikey, int index){
    struct Node *temp;
    temp=new Node;
    // if (index < 0 || index > CountNodes(p)){
    //     return (-1);
    // }
    // else{
    if(index==1){
        temp->data=ikey;
        temp->next=first;
        first=temp;
    }
    else if(index>1){
        for(int i=1; i<index; i++){  //agar insertion index wali position se pehle 
        //krna h to loop "index-1" tak chalao verna "index" tak 
            p=p->next;
        }
        temp->data=ikey;
        temp->next=p->next;
        p->next=temp;
    }
    // }
}

int Delete(struct Node *p, int dindex){
    int x;
    struct Node *q=NULL;
    if (dindex < 0 || dindex > CountNodes(p)){
        return (-1);
    }
    else {
        if(dindex==1){
            x=first->data;
            q=first;
            first=first->next;
            delete q;
        }
        else 
            for(int i=0; i<dindex-1;i++){
                q=p;
                p=p->next;
            }
            q->next=p->next;
            x=p->data;
            delete p;
    }
    return x;
}

int IsSorted(struct Node *p){
    int x=INT16_MIN;
    while(p){
        if(p->data<x){return 0;}
        x=p->data;
        p=p->next;
    }
    return 1;
}

void RemDuplicates(struct Node *p){
    struct Node *q;
    p=first;
    q=first->next;
    while(q){
        if(p->data != q->data){
            p=q;
            q=q->next;
        }
        else
           p->next=q->next;
           delete q;
           q=p->next;
    }
}

void ReverseE(struct Node *p, int n){
    int A[n],i=0;
    while(p){
        A[i]=p->data;
        p=p->next;
        i++;
    }
    p=first;
    i--;
    while(p){
        p->data=A[i];
        i--;
        p=p->next;
    }
}

void ReverseL(struct Node *p){
    struct Node *q=NULL, *r=NULL;
    p=first;
    while(p){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    cout << endl;
    Display(p);
}



int main(){
    int n;
    cout << "Enter the size of linked list: " ;
    cin >> n;
    int A[n];
    cout << "Enter Linked List elements: " ;
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    Create(A,n);
    Display(first);
    // CountNodes(first);
    // SumofEle(first);
    // Max(first);
    // cout << "The Maximum element is : " << RMax(first) << endl;
    // int key;
    // cout << "Enter the element to find in LL: ";
    // cin >> key; 
    // Search(first,key);
    // int ikey,index;
    // cout << "Enter the element and position to insert in LL: ";
    // cin >> ikey >> index; 
    // Insertion(first,ikey,index);
    // Display(first);
    // int dindex;
    // cout << "Enter the position of element to delete: ";
    // cin >>  dindex;
    // Delete(first,dindex);
    // Display(first);
    // int res=IsSorted(first);
    // if(res==0){cout << "Linked List is not sorted" << endl;}
    // if(res==1){cout << "Linked List is sorted" << endl;}
    RemDuplicates(first);
    Display(first);
    // ReverseE(first,n);
    // ReverseL(first);


}