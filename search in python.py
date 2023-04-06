A = [-10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100]

left = 0
right = len(A) - 1
mid = (left + right) // 2

x = 71 # search for x

while left <= right:
    if A[mid] == x:
        print("Found at", mid)
        break
    elif x > A[mid]:
        left = mid + 1
    else:
        right = mid - 1
    mid = (left + right) // 2
print("Not found")


