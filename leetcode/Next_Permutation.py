def numsSort(nums, start):
    n = len(nums)
    for i in range(start, n):
        j = i+1
        while j < n:
            if nums[j] < nums[i]:
                nums[i], nums[j] = nums[j], nums[i]
            j += 1
def nextPermutation(nums):
    """
    Do not return anything, modify nums in-place instead.
    """
    n = len(nums)
    for i in range(n-1)[::-1]:
        j = n-1
        while j > i:
            if nums[i] < nums[j]:
                nums[i], nums[j] = nums[j], nums[i]
                numsSort(nums, i+1)
                return
            j -= 1
        
    nums.sort()

def reverseNums(nums, i, j):
    while i < j:
        nums[i], nums[j] = nums[j], nums[i]
        i += 1
        j -= 1
def nextPermutation_(nums):
    """
    Do not return anything, modify nums in-place instead.
    """
    n = len(nums)
    i = n-1
    while i > 0:
        if nums[i] > nums[i-1]:
            break
        i -= 1
    else:
        reverseNums(nums, 0, n-1)
        return
    i -= 1
    j = n-1
    while j > i:
        if nums[j] > nums[i]:
            nums[i], nums[j] = nums[j], nums[i]
            reverseNums(nums, i+1, n-1)
            return
        j -= 1
    
if __name__ == '__main__':
    nums = [1,3,2,0,2,0]
    nextPermutation_(nums)
    print(nums)