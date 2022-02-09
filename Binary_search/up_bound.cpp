#include<bits/stdc++.h>
using namespace std;

int Mindolit_up_bound_binary_search(int *array,int target, int start ,int end){
  //주어진 값보다 큰값이 나오는 인덱스를 리턴한다.
  while(start<end){
    int mid=(start+end)/2;
    if(array[mid]>target){
      end=mid;
    }
    else if(array[mid]<=target){
      start=mid+1;
    }
  }
  return end;
}

int main(){
  int array[11]={1,1,1,2,2,2,3,3,3,4,6};
  int target;
  cin>>target;
  cout<<Mindolit_up_bound_binary_search(array,target,0,sizeof(array)/sizeof(int));
  system("pause");
}