def Merge(unsorted,start,mid,end):
  tmp=[0 for i in range(end+1)] 
  tmp_index=start 
  start_index=start
  end_index=mid+1
  while(True):
    if(start_index==mid+1 and end_index==end+1):
      break
    if(start_index !=mid+1 and end_index!=end+1):
      if(unsorted[start_index]<=unsorted[end_index]):
        tmp[tmp_index]=unsorted[start_index]
        start_index+=1
        tmp_index+=1
      elif(unsorted[start_index]>unsorted[end_index]):
        tmp[tmp_index]=unsorted[end_index]
        end_index+=1
        tmp_index+=1
    #오른쪽 리스트를 다사용하고 왼쪽리스트만 남았을때
    if(start_index !=mid+1 and end_index==end+1):
      tmp[tmp_index]=unsorted[start_index]
      start_index+=1
      tmp_index+=1
    #왼쪽 리스트를 다사용하고 오른쪽 리스트만 남았을때
    elif(start_index==mid+1 and end_index!=end+1):
      tmp[tmp_index]=unsorted[end_index]
      end_index+=1
      tmp_index+=1
  
  for i in range(start,end+1):
    unsorted[i]=tmp[i]
  


def Mergesort(list,start,end):
  if(start==end): return None
  mid=int((start+end)/2)
  Mergesort(list,start,mid)
  Mergesort(list,mid+1,end)
  Merge(list,start,mid,end)



if __name__ == '__main__':
  unsorted_list=[10,9,2,4,3,1,11,16,0,-1,-1]
  Mergesort(unsorted_list,0,len(unsorted_list)-1)
  for i in unsorted_list:
    print(i,end=" ")
