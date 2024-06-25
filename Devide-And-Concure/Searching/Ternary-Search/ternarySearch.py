def ternarySearch(arr,low,high,search):
    if low<=high:
        mid1 = low+(high-low)//2
        mid2 = high-(high-low)//2

        if arr[mid1] == search :
            return mid1 +1
        if arr[mid2] == search :
            return mid2 +1
        if arr[mid1>search]:
            return ternarySearch(arr,low,mid1-1,search)
        elif arr[mid2]<search :
            return ternarySearch(arr,mid2+1,high,search)
        else :
            return ternarySearch(arr,mid1+1,mid2-1,search)
        
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

if __name__ == "__main__":
    arr = list(map(int, input().split()))
    search = int(input("Enter element to search : "))
    printArray(arr)
    arr.sort()
    print(" after sorted :\n")
    printArray(arr)
    printpos(ternarySearch(arr,0,len(arr),search),search)