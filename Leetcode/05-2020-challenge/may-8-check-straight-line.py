'''
  Check If It Is a Straight Line
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point.
Check if these points make a straight line in the XY plane.
'''

class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        # check if the same slope
        if len(coordinates) <= 2:
            return True

        # adjacent difference
        slope = [coordinates[1][0]-coordinates[0][0], coordinates[1][1]-coordinates[0][1]]

        horizontal = slope[1] == 0
        vertical = slope[0] == 0
        line = not vertical and not horizontal

        for prev, current in zip(coordinates[1:], coordinates[2:]):
            tmp_slope = [current[0] - prev[0], current[1] - prev[1]]
            if horizontal and tmp_slope[1] != 0:
                    return False
            elif vertical and tmp_slope[0] != 0:
                    return False
            elif line:
                if slope[0] != tmp_slope[0] or slope[1] != tmp_slope[1]:
                    if 0 in [slope[0], slope[1], tmp_slope[0], tmp_slope[1]] or abs(slope[1]//slope[0]) != abs(tmp_slope[1]//tmp_slope[0]):
                        return False
        return True
