def low_bound(arr,target,start,end,cur=0):
  #target과 같거나 큰 idx가 처음으로 나오는 위치를 return  
  if start>=end:
    return cur
  else:
    mid=int((start+end)/2)
    if arr[mid]<target:
      return low_bound(arr,target,mid+1,end,cur)
    elif arr[mid]>=target:
      cur=mid
      return low_bound(arr,target,start,mid,cur)

if __name__=='__main__':
  sorted_array=[10, 10, 10, 13, 20, 20 ,20]
  print(low_bound(sorted_array,20,0,len(sorted_array)))
