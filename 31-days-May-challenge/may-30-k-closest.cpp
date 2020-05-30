//     K Closest Points to Origin
// We have a list of points on the plane.  Find the K closest points to the origin (0, 0).
// (Here, the distance between two points on a plane is the Euclidean distance.)
// You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        std::multimap<int, int> distance;
        for (int i = 0; i < points.size(); ++i) {
            distance.insert({points[i][0]*points[i][0] + points[i][1]*points[i][1], i});
        }
        
        std::vector<std::vector<int>> result;
        int count = 0;
        for (auto it = distance.cbegin(); count < K; ++it, ++count) {
            result.push_back(points[it->second]);
        }
        return result;
    }
};
