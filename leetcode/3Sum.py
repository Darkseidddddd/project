def threeSum(nums):
    nums.sort()
    left, right, mid = 0, len(nums)-1, 1
    res = []
    while left < right - 1:
        #print(left,mid,right)
        while mid < right:
            #print(left, mid, right)
            sum = nums[left] + nums[mid] + nums[right]
            if sum > 0:
                right -= 1
                while nums[right] == nums[right+1] and right != mid:
                    right -= 1
                if right == mid and mid == left+1:
                    return res
                continue
            elif sum == 0:
                res.append([nums[left], nums[mid], nums[right]])
            mid += 1
            while nums[mid] == nums[mid-1] and mid != right:
                mid += 1
                
        left += 1
        while nums[left] == nums[left-1] and left < right:
            left += 1
        mid = left + 1
        right = len(nums)-1
    return res

def threeSum_(nums):
    dic = {}
    res = []
    for i in nums:
        dic[i] = dic.get(i, 0) + 1
    pos = [i for i in dic if i > 0]
    neg = [i for i in dic if i < 0]
    #neg.sort()
    
    if 0 in dic and dic[0] > 2:
        res.append([0,0,0])
        
    for i in pos:
        for j in neg:
            k = -i-j
            if k in dic:
                if (k == i or k == j) and dic[k] > 1:
                    res.append([j,k,i])
                elif j < k < i:
                    res.append([j,k,i])
    return res

if __name__ == '__main__':
    nums = [-1,0,1,2,-1,-4]
    print(threeSum_(nums))
    print(threeSum(nums))