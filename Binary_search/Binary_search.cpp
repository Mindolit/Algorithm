#include<bits/stdc++.h>
using namespace std;

int binary_search(int *arr,int target,int start,int end){
  /*
  param 
  arr   : 오름차순으로 정렬된 배열
  target: 찾을려하는 값
  start : 이진탐색 시작점
  end   : 이진탐색 끝점    */
  
  //이진탐색의 종료시점은 start>=end인경우
  if(start>=end){ //target이 주어진 배열안에 없는경우
    return -1;
  }
  else{
    int mid=(start+end)/2;
    if(arr[mid]==target){
      return mid;
    }
    else{
      if(arr[mid]>target){ // target보다 큰경우 
        return Mindolit_binary_search(arr,target,start,mid);
      }
      else if(arr[mid<target]){
        return Mindolit_binary_search(arr,target,mid,end);
      }
    }
  }
  
}

int main(){
  int sorted_array[11]={10,11,13,15,16,17,92,100,132,133,155};
  int target;
  cout<<"INPUT TARGET:";
  cin>>target;
  cout<<"TARGET INDEX:"<<binary_search(sorted_array,target,0,11);
  system("pause");
}
