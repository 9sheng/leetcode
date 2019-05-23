#include "testharness.h"
#include <map>
#include <set>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if (points.size() < 3) return points.size();

        map<Line, set<size_t>> lineMap;
        size_t max = 0;

        for (size_t i = 0; i < points.size(); i++) {
            for (size_t j = i + 1; j < points.size(); j++) {
                Line l = getLine(points[i], points[j]);
                //cout << l.type << "," << l.k << "," << l.m << "\t\t\t" << lineMap.size() << "|" << lineMap[l].size() << endl;
                lineMap[l].insert(i);
                lineMap[l].insert(j);

                if (max < lineMap[l].size())
                    max = lineMap[l].size();
            }
        }

        return max;
    }

protected:
    struct Line {
        int type;
        double k;
        double m;

        Line() : type(0), k(0.0), m(0.0) {}
        Line(double a, double b, int c) : type(c), k(a), m(b) {}

        bool operator<(const Line& rhs) const {
            if (type != rhs.type) return type < rhs.type;

            if (k < rhs.k) return true;
            if (k > rhs.k) return false;

            return m < rhs.m;
        }
    };

    Line getLine(Point& p1, Point& p2) {
        int x  = p1.x - p2.x;
        int y = p1.y - p2.y;

        int type = 0;
        double k = 0.0;
        double m = 0.0;

        if (x == 0) {
            if (y == 0) {
                type = 1;
                k = p1.x;
                m = p1.y;
            } else {
                type = 2;
                k = p1.x;
            }
        } else {
            if (y == 0) {
                type = 3;
                k = p1.y;
            } else {
                type = 4;
                k = double(y) / x;
                m = double (p2.y * p1.x - p1.y * p2.x) / x;
            }
        }

        return Line(k, m, type);
    }
};

TEST(Solution, test) {
    ASSERT_EQ(2, 1+1);
}
