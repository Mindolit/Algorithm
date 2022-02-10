#include<bits/stdc++.h>
using namespace std;

void Merge(int arr[],int left, int mid,int right){
  int tmp_arr[right]; //VLA G++, No MSVC.
  int l_ptr=left,r_ptr=mid+1;
  int check=left;
  while(true){
    if(l_ptr==mid+1 &&r_ptr==right+1){
      break;
    }
    if(l_ptr!=mid+1 &&r_ptr!=right+1 ){
      if(arr[l_ptr]<=arr[r_ptr]){
        tmp_arr[check]=arr[l_ptr];
        l_ptr++;
      }
      else{
        tmp_arr[check]=arr[r_ptr];
        r_ptr++;
      }
      check++;
      }
    if(l_ptr==mid+1 && r_ptr!=right+1){
      //왼쪽배열은 다 사용해고 오른쪽 배열만 남아있을 때
      tmp_arr[check]=arr[r_ptr];
      r_ptr++;
      check++;
    }else if(l_ptr!=mid+1 && r_ptr==right+1){
      //오른쪽 배열은 다 사용했고 왼쪽 배열만 남아있을 때
      tmp_arr[check]=arr[l_ptr];
      l_ptr++;
      check++;
    }
  }
  
  for(int i=left; i<=right; i++){
    arr[i]=tmp_arr[i];
  }

}

void Mergesort(int un_arr[],int left,int right){
  if(left==right){
    return;
  } 
  int mid=(left+right)/2;
  Mergesort(un_arr,left,mid);
  Mergesort(un_arr,mid+1,right);
  Merge(un_arr,left,mid,right);
}

int main(){
  int unsorted_arr[10]={10,9,2,4,3,1,11,16,0,-1};
  Mergesort(unsorted_arr,0,9);
  for(auto i:unsorted_arr)
  {
    cout<<i<<" ";
  }
  system("pause");
}