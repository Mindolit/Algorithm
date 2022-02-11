def partition(arr,start,end):
  pivot=arr[start]
  low=start+1
  high=end
  while(low<=high):
    while(arr[low]<=pivot and low<=end):
      low+=1
    while(arr[high]>=pivot and high>=start+1):
      high-=1
    if(low<=high):
      tmp=arr[low]
      arr[low]=arr[high]
      arr[high]=tmp

  tmp=arr[high]
  arr[high]=pivot
  arr[start]=tmp
  return high

def Quick_sort(arr,start,end):
  if(start<end):
    pivot=partition(arr,start,end)
    Quick_sort(arr,start,pivot-1)
    Quick_sort(arr,pivot+1,end)


if __name__ =='__main__':
  unsorted=[3,8,2,4,1,5,6,9]
  Quick_sort(unsorted,0,len(unsorted)-1)
  for i in range(len(unsorted)):
    print(unsorted[i],end=" ")