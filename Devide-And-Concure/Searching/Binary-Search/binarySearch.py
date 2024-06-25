def binarySearch(arr,low,high,x):
    if low<=high:
        mid = low + (high-low)//2
        if arr[mid] == x:
            return mid+1
        if arr[mid] > x:
            return binarySearch(arr,low,mid-1,x)
        return binarySearch(arr,mid+1,high,x)
    return -1
def printArray(arr):
    for i in arr:
        print(i, end=" ")
    print()
def printpos(pos,x):
    if pos == -1:
        print(f" no element as {x}\n")
    else:
        print(f"{x} found at position {pos}. \n")

if __name__=="__main__":
    arr = list(map(int, input().split()))
    search = int(input("Enter element to search : "))
    printArray(arr)
    arr.sort()
    print(" after sorted :\n")
    printArray(arr)
    printpos(binarySearch(arr,0,len(arr),search),search)

