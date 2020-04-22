#include<iostream>
#include<array>
#include<numeric> // std::accumulate

enum Item{
    potions,
    torches,
    arrows
};

int countTotalItems(std::array<int, 3> arr)
{
    int total {0};
    for (int i : arr)
        total += i;

    return total;
}

// Their solution
enum ItemTypes{
    POTION,
    TORCH,
    ARROW,
    MAX_ITEMS
};

using inventory_type = std::array<int, ItemTypes::MAX_ITEMS>;

int countTotalItems2(inventory_type items)
{
    return std::accumulate(items.begin(), items.end(), 0);
}

int main()
{
    std::array <int, 3> my_array {2, 5, 10};
    std::cout << countTotalItems(my_array) << '\n';

    // Their solution
    
    inventory_type items {2, 5, 10};
    std::cout << "The player has " << countTotalItems2(items) << " item(s) in total.\n";

    // we can access individual items using the enumerators:
    
    std::cout << "The player has " << items[ItemTypes::TORCH] << " torch(es)\n";

    return 0;
}
