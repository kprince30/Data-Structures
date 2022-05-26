#include<bits/stdc++.h>
using namespace std;

struct Stack{
    int size;
    int top;
    int *A;
};
void Create(struct Stack *st){
    cout <<"Enter size of stack";
    cin >> st->size;
    st->top=-1;
    st->A= new int[st->size];
}

void Display(struct Stack st){
    int i;
    for(i=st.top; i>=0; i--){
        cout << st.A[i];
        cout << "\t";
    }
}

void Push(struct Stack *st, int x){
    if(st->top == st->size-1){
        cout << "Stack Overflow" << endl;
    }
    else{
        st->top++;
        st->A[st->top]=x;
    }
}

int Pop(struct Stack *st){
    int x=-1;
    if(st->top == -1){
        cout << "Stack Underflow" <<endl;
    }
    else{
        x=st->A[st->top];
        st->top--;
    }
    return x;
}

int main(){
    struct Stack  st;
    Create(&st);

    Push(&st,4);
    Push(&st,5);
    Push(&st,6);
    Push(&st,9);
    Push(&st,9);
    Push(&st,9);
    Pop(&st);
    Pop(&st);
    Pop(&st);
    Pop(&st);
    Pop(&st);
    Pop(&st);
    Display(st);
    return 0;
}