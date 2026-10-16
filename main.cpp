#include <iostream>
#include "math.h"
#include <random>

int montecarlo(int numPoints){
    //Defining our Square boundry
    int CoordSpace[4][2] = {
        {-1, -1},
        {-1, 1},
        {1, 1},
        {1, -1}
    };

    int Radius = 1; 
    int pointsInCircle = 0;
    double x = 0;
    double y = 0;
    double sumOfSq = 0;

    std::random_device random;
    std::mt19937 gen(random());
    std::uniform_real_distribution<double> distro(-1.0,1.0);

    for(int i = 0; i < numPoints; i++){
        x = distro(gen);
        y = distro(gen);
        sumOfSq = x*x + y*y;
        
        if(sumOfSq <= Radius){
            pointsInCircle++;
        }
    }

    return pointsInCircle;
}

int main(){
    int generatePts = 100; // THe number of points we ask our simulation to sample.
    int numPts = 0; //Num of pts inside our circle from our sampling simulation. 
    double ourPi = 0; //Our pi approximation 

    numPts = montecarlo(generatePts);
    ourPi = ((double)numPts / generatePts) * 4;
    std::cout << ourPi; 
}
