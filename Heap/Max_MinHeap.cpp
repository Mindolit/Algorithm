#include<bits/stdc++.h>
using namespace std;
#define MAX 22

class Heap_{
  int heap[MAX];
  int min_heap[MAX];
  int min_heap_idx=1;
  int heap_idx=1;
public:
  void push(int data){
    heap[heap_idx++]=data; //data insert
    min_heap[min_heap_idx++]=data;
    int min_parent=(min_heap_idx-1)/2;
    int min_child=min_heap_idx-1;
    int parent=(heap_idx-1)/2; 
    int child=heap_idx-1;
    while(1<child){
      if (heap[child]<heap[parent]) break;
      else { //자식이 부모노드보다 크다면
        swap(heap[child],heap[parent]); //자식노드와  부모노드 스왑
        child=parent;
        parent=child/2;
      }
    }
    while(1<min_child){
      if(min_heap[min_child]>=min_heap[min_parent]) break;
      else{ //자식이 부모노드보다 작다면 
        swap(min_heap[min_child],min_heap[min_parent]);
        min_child=min_parent;
        min_parent=min_child/2;
      }
    }
  }

  void print_top(){
    cout<<"MAX_HEAL_TOP:"<<heap[1]<<'\n';
    cout<<"MIN_HEAP_TOP:"<<min_heap[1]<<'\n';
  }
};

int main(){
  Heap_ a;
  a.push(3);
  a.push(4);
  a.push(1);
  a.push(11);
  a.push(13);
  a.print_top();
  system("pause");
}