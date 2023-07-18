class Solution:
    def findMin(self, nums: list[int]) -> int:
        nums.sort()
        n = len(nums)
        der = n - 1
        izq = 0
        while der != izq and der - 1 != izq:
            mid = izq + (der - izq) // 2
            if nums[der] > nums[izq]:
                der = mid
            elif nums[izq] > nums[der]:
                izq = mid
        return min(nums[izq], nums[der])
