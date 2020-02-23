#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <set>
using namespace std;


int main()
{
    int numstones, numoptions;

    while(cin>>numstones>>numoptions){
        bool youWinning[numstones+1] = {false};

        int options[numoptions+1];
        for(int i=0; i<numoptions; i++) cin>>options[i];
        youWinning[0] = false;
        youWinning[1]= true;
        for(int i=1; i <= numstones; i++){
            //cout<<"i: "<<i<<endl;
            for(int j=0; j<numoptions; j++){
                //cout<<"options[j] = "<<options[j]<<endl;
                if((i-options[j])>=0 && !youWinning[i-options[j]]){
                    //cout<<"hej"<<endl;
                    youWinning[i] = true;
                }
            }
        }
        if(youWinning[numstones]){
            cout<<"Stan wins"<<endl;
        }else{
            cout<<"Ollie wins"<<endl;
        }

    }



}
