
/* Using Boost Threads */
/* Listing 10.2: Concurrent tasks as threads */
#include <iostream>
#include <string>
#include <vector>

#include <boost/thread.hpp>

typedef std::vector<std::string> strvec;
void printGreets(const strvec& greets)
{
    for (const auto& greet : greets){
        std::cout << greet << '\n';
    }
}

int main()
{
    strvec angloSaxon{
        "Guten Morgen!",
        "Godmorgen!",
        "Good morning!",
        "Goedemorgen"
    };

    strvec romance{
        "Buenos dias!",
        "Bonjour!",
        "Bom dia!",
        "Buongiorno!"
    };

    boost::thread t1(printGreets, romance);
    boost::thread t2(printGreets, angloSaxon);

    t1.join();
    t2.join();
    return 0;
}
