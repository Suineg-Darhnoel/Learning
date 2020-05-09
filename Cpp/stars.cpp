#include <iostream>
#include <vector>

void lrstars_loop(int max_stars, bool r=false)
{
    if (r != true)
        for (int i {0}; i < max_stars; i++)
        {
            for (int stars {i}; stars >= 0; stars--)
                std::cout << '*';
            for (int spaces {max_stars-i}; spaces >=0; spaces--)
                std::cout << ' ';
            std::cout << '\n';
        }
    else
        for (int i {0}; i < max_stars; i++)
        {
            for (int stars {max_stars-i}; stars > 0; stars--)
                std::cout << '*';
            for (int spaces {i}; spaces >=0; spaces--)
                std::cout << ' ';
            std::cout << '\n';
        }
}

void rlstars_loop(int max_stars, bool r=false)
{
    if (r != true)
        for (int i {0}; i < max_stars; i++)
        {
            for (int spaces {max_stars-i}; spaces >0; spaces--)
                std::cout << ' ';
            for (int stars {i}; stars > 0; stars--)
                std::cout << '*';
            std::cout << '\n';
        }
    else
        for (int i {0}; i < max_stars; i++)
        {
            for (int spaces {i}; spaces >0; spaces--)
                std::cout << ' ';
            for (int stars {max_stars-i}; stars > 0; stars--)
                std::cout << '*';
            std::cout << '\n';
        }
}

class Point
{
    private:
        int m_x {1};
        int m_y {1};
    public:
        Point(): m_x {1}, m_y {1} {};
        Point(int X, int Y=1): m_x {X}, m_y {Y}{}
        
        std::vector<Point> getPoint(){
            std::vector<Point> v;
            v.push_back(m_x);
            v.push_back(m_y);
            return v;
        }

        void showPoint()
        {
            std::cout << "(" << m_x << ", " << m_y << ")" << std::endl;
        }
};

/* void pixel_stars(int width, int height, std::vector<Point>& point) */
/* { */
/*     for (int h {height}; h > 0; h--) */
/*     { */
/*         for (int w {width}; w > 0; w--){ */
/*             auto v {point.getPoint()}; */
/*             if (w == point.x && h == point.y) */
/*                 std::cout << ' '; */
/*             else */
/*                 std::cout << '*'; */
/*         } */
/*         std::cout << '\n'; */
/*     } */
/*     std::cout << '\n'; */
/* } */

int main()
{
    Point p1 {};
    p1.showPoint();

    Point p2 {0};
    p2.showPoint();

    Point p3 {2, 4};
    p3.showPoint();

    int i {};
    i += 1;

    std::cout << typeid(i).name() << '\n';

    return 0;
}
