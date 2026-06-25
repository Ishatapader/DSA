class Point{
public:
    int idx;
    int distSquare;
    Point(int idx, int distSquare){
        this -> idx = idx;
        this -> distSquare = distSquare;
    }
    bool operator < (const Point &obj) const{
        return this -> distSquare > obj.distSquare; //min heap
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
         vector<Point> p;

    for(int i = 0; i < points.size(); i++){ 
        int distSquare = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
        p.push_back(Point(i, distSquare));
    }
    priority_queue<Point> pq(p.begin(), p.end()); 
    vector<vector<int>>ans;
    for(int i = 0; i < k ; i++){ 
        ans.push_back(points[pq.top().idx]);
        pq.pop(); 
    }
    return ans;
    }
};