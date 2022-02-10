#include<bits/stdc++.h>
using namespace std;

int low_bound_binary_search(int *arr, int target, int start ,int end){
  while(start<end)
  { 
    int mid=(start+end)/2; 
    if(arr[mid]<target){
      start=mid+1;
    }
    else if(arr[mid]>=target){
      end=mid;
    }
  }
  return end;
}

int main(){
  int array[11]={1,1,1,2,2,2,3,3,3,4,6};
  int target;
  cin>>target;
  cout<<low_bound_binary_search(array,target,0,sizeof(array)/sizeof(int)-1);
  system("pause");
}
