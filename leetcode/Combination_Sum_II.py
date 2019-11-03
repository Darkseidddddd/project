def searchSum(candidates, target, total, res, res_):
    for index, i in enumerate(candidates):
        if index > 0 and i == candidates[index-1]:
            continue
        res_.append(i)
        sum_ = total + i
        if sum_ < target:
            searchSum(candidates[index+1:], target, sum_, res, res_)
        elif sum_ == target:
            res.append(res_[:])
        res_.pop()
        if sum_ >= target:
            break
def combinationSum2(candidates, target):
    res = []
    candidates.sort()
    searchSum(candidates, target, 0, res, [])
    return res

if __name__ == '__main__':
    candidates = [10,1,2,7,6,1,5]
    target = 8
    print(combinationSum2(candidates, target))