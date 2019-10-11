def removeElement(nums, val):
    i = 0
    while i < len(nums):
        if nums[i] == val:
            nums.remove(val)
        else:
            i += 1
    return len(nums)

if __name__ == '__main__':
    nums = [1,2,2,3,4,5,2]
    val = 2
    for i in range(removeElement(nums,val)):
        print(nums[i], end=' ')