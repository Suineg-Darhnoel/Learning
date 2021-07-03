#include <boost/filesystem.hpp>
#include <iostream>
namespace fs = boost::filesystem;

int main()
{
    fs::path cwd = fs::current_path();
    std::cout << "generic: " << cwd.generic_string() << '\n';
    std::cout << "native: " << cwd.string() << '\n';
    std::cout << "quoted: " << cwd << '\n';

    std::cout << "Components: \n";
    for (const auto& dir : cwd){
        std::cout << '[' << dir.string() << ']';
    }
    std::cout << '\n';

    return 0;
}
