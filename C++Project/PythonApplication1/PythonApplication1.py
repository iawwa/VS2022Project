import copy
import random
def mergeSort(arr,low,high):
    print(arr)
    if low<high:
        mid=low+(high-low)>>1 
        print("s=")
        print((high-low)>>1)
        mergeSort(arr,low,mid)
        mergeSort(arr,mid+1,high)
        #merge(arr,low,mid,high)
        merge(arr,a,mid,b)
    else:
        return arr
helper=list()
def merge(arr,low,mid,high):
    #先将A中的数据拷贝到helper中
    print(low)
    print(high)
    helper=copy.deepcopy(arr[low:high])
    print(helper)
    print("helper",helper)
    left=low    #左侧队列的头部指针
    right=mid+1     #右侧队列的头部指针
    p=0       #整个队列的指针
    while left<mid and right<high:
        if helper[left]<=helper[right]:
            arr[p]=helper[left]
            left=left+1
            p = p + 1
        else:
            arr[p]=helper[right]
            right=right+1
            p = p + 1
    while left<=mid:
        arr[p]=helper[left]
        p=p+1
        left=left+1
    while right<=high:
        arr[p]=helper[right]
        p=p+1
        right=right+1
        
test=[random.randint(1,100) for i in range(10)]
mergeSort(test,0,9)
print(test)