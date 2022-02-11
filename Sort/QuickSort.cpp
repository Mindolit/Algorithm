#include<bits/stdc++.h>
using namespace std;

void QuickSort(int [],int,int);

int main(){
  int unsorted_arr[9]={5,3,8,4,9,1,6,2,7};
  QuickSort(unsorted_arr,0,9);
  for(int i:unsorted_arr){
    cout<<i<<" ";
  }
  system("pause");
}

void QuickSort(int arr[],int start,int end){
  int pivot=arr[start];
  int low=start+1;
  int high=end;
  while(low<=high){
    while(arr[low]<=pivot && low<=end){
      low++;
    }

    while(arr[high]>=pivot && start+1<=high){
      high--;
    }
    
    if(low<=high){
      int tmp=arr[low];
      arr[low]=arr[high];
      arr[high]=tmp;
    }
  }
  if(start<end){
  int tmp=arr[high];
  arr[high]=pivot;
  arr[start]=tmp;
  QuickSort(arr,start,high-1);
  QuickSort(arr,high+1,end);
  }
}