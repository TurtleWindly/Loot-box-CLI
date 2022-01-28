#include <iostream>
#include <string>
#include <iterator>
#include "random.hpp"

using Random = effolkronium::random_static;

struct Item
{
    std::string_view name{};
    std::string_view rareType{};
};

std::string rareType[5]{"common", "rare", "epic", "legendary", "mythic"};
enum rareType
{
    common,
    rare,
    epic,
    legendary,
    mythic,
};

constexpr int maxItemList {10};
Item itemList[maxItemList]{
    {"excarlibur", rareType[legendary]}, 
    {"shit", rareType[common]}, 
    {"dragon shield", rareType[epic]}, 
    {"magic sword", rareType[rare]},
    {"gun", rareType[mythic]},
    {"duckymomo", rareType[epic]},
    {"normal shooes", rareType[common]}
};

constexpr int maxSlot {10};
Item balo[maxSlot]{itemList[0], itemList[1]};

void generateToBalo(Item balo[], Item itemList[])
{
    if (!(balo[maxSlot - 1].name.empty())) return;
    for (int i = 0; i < maxSlot; i++)
    {
        if (balo[i].name.empty())
        {
            balo[i] = itemList[Random::get(0, maxItemList - 1)];
            if (balo[i].name.empty())
            {
                std::cout << "You get nothing\n";
            }
            return;
        }
        
    }
    
}


void printBalo(Item balo[])
{
    for(int i = 0; i < maxSlot; ++i)
    {
        std::cout << i + 1 << '.' << balo[i].name << ' ' << balo[i].rareType << '\n';
    }
}

int main()
{
    bool running {true};
    char input {};

    std::cout << "Lucky number machine!\n";
    while (running)
    {
        std::cout << "[L]loot   [W]watch items  [Q]quit: ";
        std::cin >> input;
        switch (input)
        {
        case 'L':
        case 'l':
            generateToBalo(balo, itemList);
            break;
        case 'W':
        case 'w':
            printBalo(balo);
            break;
        case 'Q':
        case 'q':
            running = false;
            break;
        
        default:
            std::cout << "Invalid input\n";
            break;
        }
    }
    


    return 0;
}
