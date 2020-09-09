//RADIX SORT

#include<bits/stdc++.h>
using namespace std;
void countSort(int *arr,int n,int exp){
    int ans[n];
    int count[10]={0};
    
    for(int i=0;i<n;i++){
        count[(arr[i]/exp)%10]++;
    }
    for(int i=1;i<10;i++)
        count[i]+=count[i-1];
    
    for(int i=n-1;i>=0;i--){
        ans[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++)
    {arr[i]=ans[i];
    /*cout<<arr[i]<<" ";*/}
    cout<<endl;
}
void radixSort(int *arr,int n){
    int m=INT_MIN;
    for(int i=0;i<n;i++)
    m=max(m,arr[i]);
    
    for(int exp=1;m/exp>0;exp*=10){
        countSort(arr,n,exp);
    }
}
int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    
    radixSort(arr,n);
    
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    
}
