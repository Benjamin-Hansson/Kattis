#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{

    int frontSprockets, rearSprockets;
    while(cin>>frontSprockets && frontSprockets != 0 && cin>>rearSprockets){
        vector<int> frontGears, rearGears;
        int temp;
        for(int i=0; i<frontSprockets; i++){
            cin>>temp;
            frontGears.push_back(temp);
        }
        for(int i=0; i<rearSprockets; i++){
            cin>>temp;
            rearGears.push_back(temp);
        }
        vector<double> ratios;
        for(int frontTeeth : frontGears){
            for(int rearTeeth : rearGears){
                ratios.push_back(double(rearTeeth)/double(frontTeeth));
            }
        }
        sort(ratios.begin(), ratios.end());
        double champion = 0;
        double tempSpread;
        for(int i=0;i<ratios.size()-1; i++){
            tempSpread = ratios[i+1]/ratios[i];
            if(tempSpread>champion) champion=tempSpread;
        }
        printf("%.2f\n", champion);
    }
}
