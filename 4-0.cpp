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
        y = ((sin(2*x)/x) * 30);
        cout << setw(15 + (y)) << setfill(' ') << '*' << "\n";
        x += 0.1;
    }
}
