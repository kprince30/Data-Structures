#include<iostream>
#include<array>
#include<bits/stdc++.h>
using namespace std;

void Create(int A[], int n){
    cout << "Enter the array elements : " ;
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    // cout << "The Array A is : ";
    // for(int j=0; j<n; j++){
    //     cout << A[j] << " " ; 
        
    // }
} 

void Display(int A[], int n){
    for(int j=0; j<n; j++){
         cout << A[j] << " " ; 
    }
    cout<<endl;

}

void Insert(int n, int x, int pos, int A[]){
    for (int i=n; i>pos; i--){
         A[i]=A[i-1];
    }
    A[pos]=x;
    
}

void Delete(int n, int y, int A[]){
    int val;
    val = A[y];
    for(int i=y; i<n-1; i++){
        A[i]=A[i+1];
    }
    n--; 
}

int LinearSearch(int A[], int n, int z){
    for(int i=0; i<n; i++){
        if(z==A[i])
            return i;
    }
    return -1;
}

int BinarySearch(int A[], int n, int w){
    int l,h,mid;
    l=0;
    h=n-1;

    while(l<=h)
    {
    mid=(l+h)/2;
    if(w == A[mid]){
        return mid;
    }
    else if (w < A[mid])
    {
        h=mid-1;
    }
    else if (w > A[mid]){
        l=mid+1;
    }      
    }
    return -1;
}

int MaxMin(int A[],int n){
    int max=A[0];
    int min;
    for(int i=0; i<n; i++){
        if(A[i]>max){
            max=A[i];
        }
    }
    cout << "Maximum element of array is: " << max << endl << endl ;
   
    for(int j=0; j<n;j++){
        if(A[j]<min){    
            min=A[j]; 
        }
    }
    cout << "Minimum element of array is: " << min << endl << endl;
}

int SumofEle(int A[], int n){
   int sum=0;
   for(int i=0; i<n; i++){
       sum = sum + A[i];
   }
   return sum;
}

int Average(int A[], int n){
    int avg;
    int sum = SumofEle(A,n);
    avg= sum/n;
    return avg;
}

void LeftShift(int A[], int n, int v){
    for(int j=0; j<v; j++){
        for(int i=0; i<n; i++){
        A[i]=A[i+1];
    }
    A[n-1]=0;
}
}

void RotateRight(int A[], int n, int k){
    int temp;
    for(int i=0; i < k%n; i++){
        temp=A[0];
        for(int j=0; j<n-1; j++){
        A[j]=A[j+1];
      }
      A[n-1]=temp;
    }
}

void Reverse(int A[], int low, int high){
    int temp;
    while(low < high)
    {
       temp= A[low];
       A[low]=A[high];
       A[high]=temp;
       low++;
       high--;
    }
    
}

void RotateRight2(int A[], int n, int r){
     r=r%n;
     Reverse(A,0,n-r-1);
     Reverse(A,n-r,n-1);
     Reverse(A,0,n-1);
     cout<<"Rotated array is: " << endl;
     for(int j=0; j<n; j++){
         cout << A[j] << " " ; 
    }
    cout<<endl;
}

int Merge(int A[], int B[], int n, int m){
    int i=0,j=0;
    int k=0;
    int C[n+m];

    while(i<n && j<m){
        if(A[i]<B[j]){
            C[k++]=A[i++];
        }
        else
          C[k++]=B[j++];
    }
    while(i<n){
         C[k++]=A[i++];
    }
    while (j<m)
    {
       C[k++]=B[j++];
    }
    cout << "Array after merging is: " ;
    Display(C,m+n);
}

int main()
{
    int n,m;
    cout << "Enter the size of array: " ;
    cin >> n;
    int A[100];
    int B[50];
    Create(A,n);
    cout << "The Array A is : " << endl ;
    Display(A,n);

    cout << "Enter the size of array B: " ;
    cin >> m;
    cout << "Enter the array elements : " ;
    for(int i=0; i<m; i++){
        cin >> B[i];
    }
    cout << "The Array B is : " << endl ;
    Display(B,m);

    int pos,x;
    cout << "Enter the value to be inserted and position of it in array: ";
    cin >> x >> pos;
    // int len= sizeof(A)/sizeof(A[0]);
    Insert(n,x,pos,A);
    n=n+1;
    cout << "Array after insertion" << endl ;
    Display(A,n);

    int y;
    cout << "Enter the position of element to delete it from array: ";
    cin >> y;
    Delete(n,y,A);
    n=n-1;
    cout << "Array after deletion" << endl;
    Display(A,n);

    int z;
    cout << "Enter the value to be searched: ";
    cin >> z;
    int index = LinearSearch(A,n,z);
    cout << "Element inserted is found at: " << index << endl << endl;
   
    int w;
    cout << "Enter the value to be searched: ";
    cin >> w;
    int index1 = BinarySearch(A,n,w);
    cout << "Element inserted is found at: " << index1 << endl << endl;

    MaxMin(A,n);

    int sum = SumofEle(A,n);
    cout << "Sum of all elements of Array is: " << sum << endl << endl ;

    int avg = Average(A,n);
    cout <<"Average of all elements of Array is: " << avg << endl << endl;

    // int v;
    // cout << "How much left shifting you wants in array: ";
    // cin >> v;
    // LeftShift(A,n,v);
    // cout << "Array after shifting : " << endl;
    // Display(A,n);

    int k;
    cout << "Enter how much time you have to rotate array: " ;
    cin >> k;
    RotateRight(A,n,k);
    cout << "Rotated Array: " << endl;
    Display(A,n);
    
    int r;
    cout << "Enter how much time you have to rotate array: ";
    cin >> r;
    RotateRight2(A,n,r);
    cout << "Rotated Array: " << endl;
    Display(A,n);

    Merge(A,B,n,m);
}