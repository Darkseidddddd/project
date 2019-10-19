def searchRange(nums, target):
    n = len(nums)
    left, right = 0, n-1
    res = []
    while left <= right:
        mid = (left+right) // 2
        if nums[mid] == target:
            res = [mid, mid]
            break
        elif nums[mid] > target:
            right = mid - 1
        else:
            left = mid + 1
    if not res:
        return [-1, -1]
    left, right = 0, res[0]
    while left <= right:
        mid = (left+right) // 2
        if nums[mid] == target:
            res[0] = min(mid, res[0])
            right = mid - 1
        elif nums[mid] > target:
            right = mid - 1
        else:
            left = mid + 1
    left, right = res[1], n-1
    while left <= right:
        mid = (left+right) // 2
        if nums[mid] == target:
            res[1] = max(mid, res[1])
            left = mid + 1
        elif nums[mid] > target:
            right = mid - 1
        else:
            left = mid + 1
    return res

def searchRange_(nums, target):
    n = len(nums)
    if n == 0:
        return [-1, -1]
    left, right = 0, n-1
    while left < right:
        mid = (left+right) // 2
        if nums[mid] < target:
            left = mid + 1
        else:
            right = mid
    if nums[left] != target:
        return [-1, -1]
    res = [left]
    right = n-1
    while left < right:
        mid = (left+right+1) // 2
        if nums[mid] > target:
            right = mid - 1
        else:
            left = mid
    if nums[right] != target:
        return [res[0], res[0]]
    res.append(right)
    return res

if __name__ == '__main__':
    nums = [1,2,2,3,4,5,5,6]
    target = 5
    print(searchRange_(nums, target))