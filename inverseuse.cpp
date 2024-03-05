#include <iostream>

void inverseuse(int *a, int *b)
{
    int c{*a};
    *a = *b;
    *b = c;
}

int main()
{
    int a{3};
    int b{42};
    inverseuse(&a, &b);
    std::cout << a << std::endl;
}