class Point {
public:
    int x;
    int y;

    Point(int x1, int y1) {
        x = x1;
        y = y1;
    }
//check if the 2 points are equals.
    bool equals(Point *p) {
        return (p->x == x) && (p->y == y);
    }
};