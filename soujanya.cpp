#include <iostream>
#include <ctime>
using namespace std;
#define MAX_VALUE 10
#define MIN_VALUE 5
float getRandom()
{
    auto lhs = MIN_VALUE + rand() % ((MAX_VALUE + 1) - MIN_VALUE);
    auto dec = MIN_VALUE + rand() % ((MAX_VALUE + 1) - MIN_VALUE);
    float val = lhs +  dec / 10.0;
    return val;
};
float getY(float x,int i)
{
    float w = getRandom();
    float b = getRandom();
    std::cout << “w” << i<< “:” << w << “, b” << i <<“:” << b << std::endl;
    return (x * w) + b;
}
int main(void) {
    std::srand(unsigned(std::time(nullptr)));
    std::string x;
    while (true)
    {
        std::cout << “Give x:“;
        std::cin >> x;
        if (x == “q”)
        {
            std::cout << “EXITTING!!!” << std::endl;
            break;
        }
        else
        {
            float xinfloat=std::stof(x);
            float y1=getY(xinfloat,1);
            float y2=getY(xinfloat,2);
            std::cout << “y1: ” << y1<< “, y2: “<< y2 << std::endl;
            float y3=getY(y1,3);
            float y4=getY(y2,4);
            std::cout << “y3: ” << y3<< “, y4: “<< y4 << std::endl;
            float y5=y3+y4;
            std::cout << “y5: ” << y5<< std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}
