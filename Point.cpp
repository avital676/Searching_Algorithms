//
// Created by avital on 12/01/2020.
//

class Point {
public:
    int x;
    int y;

    Point(int x1, int y1) {
        x = x1;
        y = y1;
    }

    bool equals(Point *p) {
        return (p->x == x) && (p->y == y);
    }
};