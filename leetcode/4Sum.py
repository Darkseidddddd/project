def fourSum(nums, target):
    n = len(nums)
    if n < 4:
        return []
    nums.sort()
    res = []   
    for i in range(n-3):
        if i > 0 and nums[i] == nums[i-1]:
            continue
        if nums[i] + nums[n-1] + nums[n-2] + nums[n-3] < target:
            continue
        if nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target:
            break
        for j in range(i+1, n-2):
            if j > i+1 and nums[j] == nums[j-1]:
                continue
            if nums[i] + nums[j] + nums[n-1] + nums[n-2] < target:
                continue
            if nums[i] + nums[j] + nums[j+1] + nums[j+2] > target:
                break
            l, r = j+1, n-1
            while l < r:
                if nums[i] + nums[j] + nums[l] + nums[r] == target:
                    res.append([nums[i], nums[j], nums[l], nums[r]])
                    l += 1
                    while l < r and nums[l] == nums[l-1]:
                        l += 1
                    r -= 1
                    while l < r and nums[r] == nums[r+1]:
                        r -= 1
                elif nums[i] + nums[j] + nums[l] + nums[r] < target:
                    l += 1
                else:
                    r -= 1
    return res

if __name__ == '__main__':
    nums = [-4,-1,-1,0,1,2]
    target = -1
    print(fourSum(nums, target))