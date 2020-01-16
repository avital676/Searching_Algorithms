//
// Created by avital on 12/01/2020.
//
//we use point to knew the actual place of the state inside the matrix.
class Point {
public:
    int x;
    int y;

    Point(int x1, int y1) {
        x = x1;
        y = y1;
    }
//check if the 2 points aer equals.
    bool equals(Point *p) {
        return (p->x == x) && (p->y == y);
    }
};