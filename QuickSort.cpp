//QUICK SORT

#include<bits/stdc++.h>
using namespace std;
int partition(int *arr,int low,int high){
    int pivot =arr[high];
    int i=low-1;
    for(int j=low;j<=high-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return (i+1);
}
void qsort(int *arr,int low,int high){
    if(low<high){
        int p=partition(arr,low,high);
        //cout<<"H"<<endl;
        qsort(arr,low,p-1);
        qsort(arr,p+1,high);
    }
}
int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    qsort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
