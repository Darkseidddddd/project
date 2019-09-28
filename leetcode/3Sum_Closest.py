def threeSumClosest(nums, target):
    res = nums[0] + nums[1] + nums[2]
    nums.sort()
    for i in range(len(nums)):
        if i > 0 and nums[i] == nums[i-1]:
            continue
        left = i + 1
        right = len(nums) - 1
        while left < right:
            res_ = nums[i] + nums[left] + nums[right]
            if res_ - target < 0:
                left += 1
                while left < right and nums[left] == nums[left-1]:
                    left += 1
            elif res_ - target > 0:
                right -= 1
                while right > left and nums[right] == nums[right+1]:
                    right -= 1
            else:
                return res_
            if abs(res_-target) < abs(res-target):
                res = res_
    return res

if __name__ == '__main__':
    nums = [-1,-3,2,5,7,11]
    target = 19
    print(threeSumClosest(nums,target))