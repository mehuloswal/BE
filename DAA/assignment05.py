#design based on divide and conquer
# RANDOMIZED -> Random Pivot Selection. It follows that the expected running time of RandomizedQuicksort is O(n log n). It is unlikely that this algorithm will choose a terribly unbalanced
                # partition each time, so the performance is very good almost all the time. 


#DETEREMINED
#WORSTCASE : The Worst-Case complexity is still O ( N^2 ). The worst-case behavior for quicksort occurs on an input of length n when partitioning
             #produces just one subproblem with n-1 elements and one subproblem with 0 elements.
#BESTCASE : If partition produces two subproblems that are roughly of the same size, then the recurrence of the running time is 




import random


def quicksort(arr, start, stop, randomized):
    if start < stop:
        if randomized:
            pivotindex = partitionrand(arr, start, stop)
        else:
            pivotindex = partition(arr, start, stop)
        quicksort(arr, start, pivotindex - 1, randomized)
        quicksort(arr, pivotindex + 1, stop, randomized)


def partitionrand(arr, start, stop):
    randpivot = random.randrange(start, stop)
    arr[start], arr[randpivot] = arr[randpivot], arr[start]
    return partition(arr, start, stop)


def partition(arr, start, stop):
    pivot = start
    i = start + 1
    for j in range(start + 1, stop + 1):
        if arr[j] <= arr[pivot]:
            arr[i], arr[j] = arr[j], arr[i]
            i = i + 1     
    arr[pivot], arr[i - 1] = arr[i - 1], arr[pivot]
    pivot = i - 1
    return pivot


array = []
print("Enter number of elements to sort")
size = int(input())

print("Enter input numbers:")
for i in range(size):
    s = int(input())
    array.append(s)

randomized = input("Randomized / Not randomized (1/0)")

print("Unsorted Array")
print(array)
quicksort(array, 0, size - 1, randomized == "1")
print(array)