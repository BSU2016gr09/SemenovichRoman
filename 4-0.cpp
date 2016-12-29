//график функции sin(2x)/x
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void drawGraph();

int main(){
   drawGraph();
}

void drawGraph() {
    float x = -6, y;
    while (x <= 6){
        if (x == 0) y = 60;
        else y = ((sin(2*x)/x) * 30);//Ничего, что тебе просто повезло, что из-зп округления, тв не "попал" в х=0
        cout << setw(15 + (y)) << setfill(' ') << '*' << "\n";
        x += 0.1;
    }
}
