
def searchSum(candidates, target):
    if not candidates:
        return None
    res = []
    for index, i in enumerate(candidates):
        if not(target - i):
            res.append([target])
            continue
        j = i
        while target-j >= 0:
            if target-j == 0:
                res.append([i for x in range(j//i)])
            l = searchSum(candidates[index+1:], target-j)
            if l:
                temp = [i for x in range(j//i)]
                for k in l:
                    res.append(temp+k)
                    # print(res)
            j += i
    return res
def combinationSum(candidates, target):
    return searchSum(candidates, target)

def searchSum_(candidates, target, sum, res, res_):
    for i in range(len(candidates)):
        num = candidates[i]
        sum_ = sum + num
        res_.append(num)
        if sum_ < target:
            searchSum_(candidates[i:], target, sum_, res, res_)
        elif sum_ - target == 0:
            res.append(res_[:])
            # print(res)
        res_.pop()
        if sum_ >= target:
            break

def combinationSum_(candidates, target):
    candidates.sort()
    res = []
    searchSum_(candidates, target, 0, res, [])
    return res

if __name__ == '__main__':
    candidates = [10,1,2,7,6,5]
    target = 8
    print(combinationSum_(candidates, target))