def merge(arr, left, mid, right):
    n1 = mid - left + 1
    n2 = right - mid

    
    L = arr[left:left + n1]
    R = arr[mid + 1:mid + 1 + n2]

    i = j = 0
    k = left

    
    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    
    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1

    
    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1

def mergeSort(arr, left, right):
    if left < right:
        mid = (left + right) // 2

        
        mergeSort(arr, left, mid)
        mergeSort(arr, mid + 1, right)

        
        merge(arr, left, mid, right)


def printArray(arr):
    for i in arr:
        print(i, end=" ")
    print()

# Driver code
if __name__ == "__main__":
    
    arr = list(map(int, input().split()))

    printArray(arr)

    mergeSort(arr, 0, len(arr) - 1)

    printArray(arr)
