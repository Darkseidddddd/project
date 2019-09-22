def maxArea(height):
    i, j = 0, len(height)-1
    vol = min(height[0], height[-1])*(j-i)
    while i < j:
        if height[i] < height[j]:
            i += 1
        else:
            j -= 1
        vol = max(vol,min(height[i],height[j])*(j-i))
    return vol

if __name__ == '__main__':
    height = [4,2,3,1,9,10,5,7]
    print(maxArea(height))      