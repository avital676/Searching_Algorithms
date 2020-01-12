//
// Created by avital on 12/01/2020.
//

class Point {
public:
    int x;
    int y;

    Point(int x, int y) {
        x = x;
        y = y;
    }

    bool equals(Point *p) {
        return (p->x == x) && (p->y == y);
    }
};