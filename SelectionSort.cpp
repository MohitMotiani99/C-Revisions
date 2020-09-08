//SELECTION SORT

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=7;
    int arr[]={64, 34, 25, 12, 22, 11, 90};
    for(int i=0;i<n;i++){
        int minr=INT_MAX;
        int pos=i;
        for(int j=i;j<n;j++){
            if(minr>arr[j])
            {minr=arr[j];pos=j;}
        }
        swap(arr[i],arr[pos]);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
