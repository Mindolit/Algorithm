def binary_serach(arr,target,start,end):
  size=len(arr)
  if start>=end:
    return -1
  else:
    mid=int((start+end)/2)
    if(arr[mid]==target):
      return mid
    elif(arr[mid]<target):
      return binary_serach(arr,target,mid,end)
    elif(arr[mid]>target):
      return binary_serach(arr,target,start,mid)


if __name__=='__main__':
  sorted_array=[10,11,12,13,14,15,16,17,18,19,20]
  print(binary_serach(sorted_array,12,0,len(sorted_array)-1))
