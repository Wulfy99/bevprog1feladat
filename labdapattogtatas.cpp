#include <iostream>
#include <cmath>
#include <conio.h>

using namespace std;

int write_x(int x,int y, string ball)
    {
    int xi,yi;

    for(xi=0; xi<x; xi++)
    {
     cout << "\n";
    }

    for(yi=0; yi<y; yi++)
    {
     cout << " ";
    }

     cout << ball;

return 0;
}

int main()
{

    int width = 90;
    int height = 25;
    int x=0,y=0;

    while(1)
    {
        system("cls");  // Windows
        write_x(abs(height - (x++ % (height * 2 ))), abs(width - (y++ % (width*2))), "X");
    }

    return 0;
}
© 2018 GitHub, Inc.
Terms
Privacy
Security
Status
Help
Contact GitHub
Pricing
API
Training
Blog
About
Press h to open a hovercard with more details.