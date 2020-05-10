#include <iostream>

class Something
{
    public:
        static int s_var;
};

int Something::s_var {2};

class Sth
{
    private:
        static int s_idGenerator;
        int m_id;
    public:
        Sth() { m_id = s_idGenerator++; }
        int getID() const { return m_id; }
};

int Sth::s_idGenerator = 1;

int main()
{
    Something first;
    Something second;

    std::cout << first.s_var << '\n';
    std::cout << second.s_var << '\n';

    // note: we're not instantiating any objects of type something
    Something::s_var = 4;
    std::cout << Something::s_var << '\n';

    Sth fst;
    Sth snd;
    Sth thd;

    std::cout << fst.getID() << '\n';
    std::cout << snd.getID() << '\n';
    std::cout << thd.getID() << '\n';

    return 0;
}
