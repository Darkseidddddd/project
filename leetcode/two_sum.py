def twoSum(nums, target):
    head, tail = 0, len(nums)-1
    sorted_nums = sorted(enumerate(nums), key=lambda x: x[1])
    while head < tail:
        total = sorted_nums[head][1] + sorted_nums[tail][1]
        if total == target:
            return [sorted_nums[head][0], sorted_nums[tail][0]]
        elif total < target:
            head += 1
        else:
            tail -= 1
    return None
def twoSum_(nums, target):
    dic = {}
    for index, value in enumerate(nums):
        other_num = target - value
        if other_num in dic:
            return [dic[other_num], index]
        dic[value] = index
    return None

if __name__ == '__main__':
    nums = [4,3,9,1,5]
    target = 10
    print(twoSum(nums, target))