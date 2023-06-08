def merge_lists(nums1, n1, nums2, n2):
    p1=n1-1
    p2=n2-1
    p=len(nums1)-1

    while p1>=0 and p2>=0:
        if nums1[p1]<nums2[p2]:
            nums1[p]=nums2[p2]
            p2-=1
        else:
            nums1[p]=nums1[p1]
            p1-=1
        p-=1
    if n1!=n2:
        nums1[:p2+1]=nums2[:p2+1]
    return nums1