#include <iostream>
using namespace std;

int main()
{
    uint32_t i = 1;
    uint32_t k = 0xFFFF;
    uint32_t j = i & 0xFFFF;
    cout << k << endl;

    return 0;
}
