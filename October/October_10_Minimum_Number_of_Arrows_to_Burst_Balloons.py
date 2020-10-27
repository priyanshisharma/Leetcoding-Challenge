class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key = lambda a:(a[0],-a[1]))
        # print(points)
        count = 0
        if not points:
            return 0
        end = points[0][1]
        count+=1
        for i in range(1,len(points)):
            if points[i][0] > end:
                count+=1
                end = points[i][1]
            end = min(end,points[i][1])
        
        return count
            
