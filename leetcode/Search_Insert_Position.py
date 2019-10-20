def searchInsert(nums, target):
    if not nums:
        return 0
    n = len(nums)
    left, right = 0, n-1
    while left <= right:
        mid = (left+right) // 2
        if nums[mid] == target:
            return mid
        if nums[mid] > target:
            right = mid - 1
        else:
            left = mid + 1
    return left

def searchInsert_(nums, target):
    if target in nums:
        return nums.index(target)
    else:
        nums.append(target)
        nums.sort()
        return nums.index(target)

if __name__ == '__main__':
    nums = [1,2,4,5,6]
    target = 7
    print(searchInsert_(nums, target))