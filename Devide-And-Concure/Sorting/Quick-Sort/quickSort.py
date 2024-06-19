def positioningPivot(arr,low,high):
    pivot = arr[high]
    i = low -1

    for j in range(low,high):
        if arr[j]<=pivot :
            i +=1
            arr[i],arr[j] = arr[j],arr[i]
    arr[i+1],arr[high] = arr[high],arr[i+1]
    return i+1
def quickSort(arr,low,high):
    if low<high :
        pivot = positioningPivot(arr,low,high)

        quickSort(arr,low,pivot-1)
        quickSort(arr,pivot+1,high)
def printArray(arr):
    for i in arr:
        print(i, end=" ")
    print()
if __name__ == "__main__":
    
    arr = list(map(int, input().split()))

    printArray(arr)

    quickSort(arr, 0, len(arr) - 1)

    printArray(arr)