def removeDuplicates(nums):
    l = None
    for i in nums[::-1]:
        if i == l:
            nums.remove(i)
        else:
            l = i
    return len(nums)

def removeDuplicates_(nums):
    n = 0
    for i in range(1,len(nums)):
        if nums[i] != nums[n]:
            n += 1
            nums[n] = nums[i]
    return n+1

if __name__ == '__main__':
    nums = [1,1,2,2,3,4,5]
    for i in range(removeDuplicates_(nums)):
        print(nums[i], end=' ')
    print('')