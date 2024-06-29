#include <fstream>
#include <iostream>
#include <fstream>
#include <string>   
#include <vector>
using namespace std;

//Operator ovewrload 
///////////////////////////////////////////////////////////////////
class Point {
public:
    int x, y;

    Point(int x, int y) : x(x), y(y) {}

    bool operator!=(const Point& p2) const {
        return this->x * this->y != p2.x * p2.y;
    }

    bool operator<(const Point& p2) const {
        return this->x * this->y < p2.x * p2.y;
    }

    bool operator>(const Point& p2) const {
        return this->x * this->y > p2.x * p2.y;
    }

    bool operator<=(const Point& p2) const {
        return this->x * this->y <= p2.x * p2.y;
    }

    bool operator>=(const Point& p2) const {
        return this->x * this->y >= p2.x * p2.y;
    }
};
///////////////////////////////////////////////////////////////////

int main() {
    setlocale(0, "ru");
    vector<Point> points;


    ///////////////////////////////////////////////////////////////////
    //Create 10 random cor points
    for (int i = 0; i < 10; ++i) {
        points.push_back(Point(rand() % 101, rand() % 101));
    }
    ///////////////////////////////////////////////////////////////////



    ///////////////////////////////////////////////////////////////////
    //Output on screen
    for (const Point& point : points) {
        cout << "Точки: (" << point.x << ", " << point.y << ")" << endl;
    }
    ///////////////////////////////////////////////////////////////////



    ///////////////////////////////////////////////////////////////////
    //Search of the biggest point
    Point maxPoint = points[0];
    for (const Point& point : points) {
        if (point > maxPoint) {
            maxPoint = point;
        }
    }
    cout << "Точка с максимальными координатами: (" << maxPoint.x << ", " << maxPoint.y << ")" << endl;
    ///////////////////////////////////////////////////////////////////



    ///////////////////////////////////////////////////////////////////
    //Search the smallest point
    Point minPoint = points[0];
    for (const Point& point : points) {
        if (point < minPoint) {
            minPoint = point;
        }
    }
    cout << "Точка с минимальными координатами: (" << minPoint.x << ", " << minPoint.y << ")" << endl;
    ///////////////////////////////////////////////////////////////////



    ///////////////////////////////////////////////////////////////////
    //Search the same cor points
    for (int i = 0; i < points.size(); ++i) {
        for (int j = i + 1; j < points.size(); ++j) {
            if (points[i] != points[j]) {
                cout << "Точки с одинаковыми координатами: (" << points[i].x << ", " << points[i].y << ") и (" << points[j].x << ", " << points[j].y << ")" << endl;
            }
        }
    }
    ///////////////////////////////////////////////////////////////////

    return 0;
}
