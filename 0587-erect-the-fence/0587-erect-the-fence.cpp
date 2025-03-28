class Solution {
public:
    struct Point {
        int x, y;
        Point() {}
        Point(int a, int b) : x(a), y(b) {}
    };
    bool isCCW(Point p, Point q, Point r) {
        double cross = (double)(r.x - q.x) * (p.y - q.y) - (double)(r.y - q.y) * (p.x - q.x);
        return (cross > 0) || (fabs(cross - 0.0) < DBL_EPSILON);
    }

    bool comp(Point a, Point b) {
        if(fabs(a.x - b.x) < DBL_EPSILON) return a.y < b.y;
        return a.x < b.x;
    }

    vector<Point> convexHullAMC(vector<Point> pnts) {
        vector<Point> hull;
        int n = pnts.size();
        if (n <= 3) return pnts; // Special case

        sort(pnts.begin(), pnts.end(), [](Point a, Point b) {
            if(fabs(a.x - b.x) < DBL_EPSILON) return a.y < b.y;
            return a.x < b.x;
        });

        // Construct bottom part of hull
        for(int i = 0; i < n; i++) {
            //int size = hull.size();
            while(hull.size() >= 2 && !isCCW(hull[hull.size()-2], hull[hull.size()-1], pnts[i]))
                hull.pop_back();
            hull.push_back(pnts[i]);
        }

        // Construct top part of hull
        int l = hull.size() + 1;
        for(int i = n-1; i >= 0; i--) {
            //int size = hull.size();
            while(hull.size() >= l && !isCCW(hull[hull.size()-2], hull[hull.size()-1], pnts[i]))
                hull.pop_back();
            hull.push_back(pnts[i]);
        }
        return hull;
    }
    
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = (int)trees.size();
        vector<Point> points(n);
        for (int i = 0; i < n; i++) {
            points[i].x = trees[i][0];
            points[i].y = trees[i][1];
        }
        
        vector<Point> hull = convexHullAMC(points);
        set<pair<int, int>> mp;
        for (int i = 0; i < (int)hull.size(); i++) mp.insert({hull[i].x, hull[i].y});

        vector<vector<int>> ret;
        for (auto p : mp) ret.push_back({p.first, p.second});
        
        return ret;
    }
};