#include <iostream>

// don't use default parameters
class Ball
{
    private:
        std::string m_color { "black" };
        double m_radius { 10.0 };
    public:
        Ball() = default;
        
        Ball(const std::string color)
        {
            m_color = color;
        }

        Ball(const double radius)
        {
            m_radius = radius;
        }

        Ball(const std::string color, const double radius)
        {
            m_color = color;
            m_radius = radius;
        }

        void print()
        {
            std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
        }
};

// use default parameters
class Ball2
{
    private:
        std::string m_color {};
        double m_radius {};
    public:
        Ball2(const double radius)
        {
            m_color = "black";
            m_radius = radius;
        }
        Ball2(const std::string& color="black", const double radius=10.0)
        {
            m_color = color;
            m_radius = radius;
        }

        void print()
        {
            std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
        }
};

int main()
{
    Ball def{};
    def.print();

    Ball blue{ "blue" };
    blue.print();

    Ball twenty{ 20.0 };
    twenty.print();

    Ball blueTwenty { "blue", 20.0 };
    blueTwenty.print();

    Ball2 def2{};
    def2.print();

    Ball2 blue2{ "blue" };
    blue2.print();

    Ball2 twenty2{ 20.0 };
    twenty2.print();

    Ball2 blueTwenty2 { "blue", 20.0 };
    blueTwenty2.print();
    return 0;
}
