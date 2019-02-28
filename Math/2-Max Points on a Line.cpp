
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
 */

struct Point {
    int x;
    int y;
    Point(): x(0), y(0) {}
    Point(int a, int b): x(a), y(b) {}
};

class Solution {
public:
    /**
     * We start from a specific point p, and compute all the slopes of the lines between p and the remaining points. 
     * Then those with the same slopes will be the same line. 
     * We can find out the maximum number of points fall on a line containing p. 
     * We exhaust all possible p's and record the largest number we have seen. This number is just answer.
     * There are two special cases to handle:
     * 1. Duplicate points: a pair of duplicate points give no determined line, 
     * so we just count the number of duplicates and add them to the result.
     * 2. Vertical lines: the slope of these lines is infinity mathematically. 
     * We simply set it to be INT_MAX in the following code.
     * We use an unordered_map<float, int> slopes to record how many points fall in the line of a specific slope and containing points[i].
     */ 
    int maxPoints(vector<Point>& points) {
        unordered_map<long double, int> slopes;
        int n = points.size(), maxp = 0;
        for(int i = 0; i < n; i++) {
            slopes.clear();
            int duplicate = 1;
            for(int j = i + 1; j < n; j++) {
                if(points[j].x == points[i].x && points[j].y == points[i].y) {
                    duplicate++;
                    continue;
                }
                long double slope = (points[j].x == points[i].x) ? INT_MAX : (long double)(points[j].y - points[i].y) / (points[j].x - points[i].x);
                slopes[slope]++;
            }
            maxp = max(maxp, duplicate);
            for(auto slope : slopes) {
                if(slope.second + duplicate > maxp) {
                    maxp = slope.second + duplicate;
                }
            }
        }
        return maxp;
    }
};
