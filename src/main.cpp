#include <iostream>
#include "Board.h"

int main()
{
    queens::board b{10, 8, 8};
    b.add_queen(2,1);
    b.add_queen(6,5);
    b.print();
    return 0;
}
