def search(nums, target):
    if not nums:
        return -1
    n = len(nums)
    left, right = 0, n-1
    if target == nums[0]:
        return 0;
    if target == nums[n-1]:
        return n-1;
    if target >= nums[0]:
        while left <= right:
            mid = (left+right) // 2
            if nums[mid] == target:
                return mid
            if nums[mid] > target or (nums[mid] <= nums[n-1] and nums[n-1] < nums[0]):
                right = mid - 1
            else:
                left = mid + 1
    else:
        while left <= right:
            mid = (left+right) // 2
            if nums[mid] == target:
                return mid
            if nums[mid] < target or nums[mid] >= nums[0]:
                left = mid + 1
            else:
                right = mid - 1
    return -1

def search_(nums, target):
    n = len(nums)
    left, right = 0, n-1
    if n == 0:
        return -1
    if n == 1 and target != nums[0]:
        return -1
    while left < right:
        mid = (left+right) // 2
        if nums[mid] > nums[left]:
            left = mid
        else:
            right = mid
    if target >= nums[0] and target <= nums[left]:
        right = left
        left = 0
    elif target >= nums[left+1] and target <= nums[n-1]:
        right = n-1
        left += 1
    else:
        return -1
    while left <= right:
        mid = (left+right) // 2
        if nums[mid] == target:
            return mid
        if nums[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1

if __name__ == '__main__':
    nums = [5,6,7,8,0,1,2,3,4]
    target = 1
    print(search_(nums, target))