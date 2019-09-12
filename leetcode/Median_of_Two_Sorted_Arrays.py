def findMedianSortedArrays(nums1, nums2):
    m, n = len(nums1), len(nums2)
    k = (m+n) // 2
    if (m+n)%2 == 0:
        return (findkth(nums1, nums2, k) + findkth(nums1,nums2, k+1))/2
    else:
        return findkth(nums1, nums2, k+1)/1
    
def findkth(nums1, nums2, k):
    m, n = len(nums1), len(nums2)
    if m > n:
        return findkth(nums2, nums1, k)
    print(nums1, nums2, k)
    if m == 0:
        return nums2[k-1]
    if k == 1:
        return min(nums1[0], nums2[0])
    k1 = min(k//2, m)
    k2 = k-k1
    if nums1[k1-1] >= nums2[k2-1]:
        return findkth(nums1, nums2[k2:], k-k2)
    else:
        return findkth(nums1[k1:], nums2, k-k1)

def findMedianSortedArrays_(nums1, nums2):
    m, n = len(nums1), len(nums2)
    if m > n:
        nums1, nums2, m, n = nums2[:], nums1[:], n, m
    low, high = 0, m
    #print(m, n)
    while low <= high:
        i = (high+low) // 2
        j = (m+n+1)//2 - i
        right1 = nums1[i] if i < m else float('inf')
        left1 = nums1[i-1] if i > 0 else float('-inf')
        right2 = nums2[j] if j < n else float('inf')
        left2 = nums2[j-1] if j > 0 else float('-inf')
        #print('low=%d, high=%d' %(low,high))
        #print('left1=%d, right1=%d'%(left1, right1))
        #print('left2=%d, right2=%d'%(left2, right2))
        if right1 >= left2 and left1 <= right2:
            if (m+n) % 2 == 0:
                return (max(left1, left2)+min(right1, right2)) / 2
            else:
                return max(left1, left2) / 1
        if left1 > right2:
            high = i-1
        else:
            low = i+1

if __name__ == '__main__':
    nums1 = [1,3,5,7,8,12]
    nums2 = [2,4,6,9,10,11]
    print(findMedianSortedArrays_(nums1, nums2))