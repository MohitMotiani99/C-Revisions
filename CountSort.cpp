//COUNT SORT

#include<bits/stdc++.h>
using namespace std;
void countSort(int *arr,int n){
    int ans[n];
    //memset(ans,0,sizeof(ans));
    map<int,int> m;// use an array till max
    for(int i=0;i<n;i++){
        if(m.find(arr[i])==m.end())
        m.insert({arr[i],1});
        else
        m[arr[i]]++;
    }
    auto it=m.begin();
    it++;
    auto it1=m.begin();
    for(;it!=m.end();it++){
        it->second=it1->second+it->second;
        it1=it;
    }
    for(int i=0;i<n;i++){
        //cout<<m[arr[i]]-1<<endl;
        ans[m[arr[i]]-1]=arr[i];
        m[arr[i]]--;
    }
    for(int i=0;i<n;i++)
    arr[i]=ans[i];
}
int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    
    countSort(arr,n);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    
}
