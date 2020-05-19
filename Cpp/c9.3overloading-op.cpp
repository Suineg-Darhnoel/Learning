#include <iostream>
#include <ostream>

class Point
{
    private:
        int m_x {0};
        int m_y {0};
    public:
        Point(int x=0, int y=0): m_x {x}, m_y {y} {}

        /* for output */
        friend std::ostream& operator<<(std::ostream &out, const Point &p);

        /* for input */
        /* note that no "const" before Point &p */
        friend std::istream& operator>>(std::istream &inp, Point &p);
};

std::ostream& operator<<(std::ostream &out, const Point &p)
{
    out << "Point(" << p.m_x << ", " << p.m_y << ")";
    return out;
}

std::istream& operator>>(std::istream &inp, Point &p)
{
    inp >> p.m_x;
    inp >> p.m_y;
    return inp;
}

int main()
{
    std::cout << Point(1,2) << '\n';

    Point P1;
    std::cin >> P1;
    std::cout << P1 << '\n';
    return 0;
}
