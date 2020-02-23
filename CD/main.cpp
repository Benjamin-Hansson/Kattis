#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int jacksNum, jillsNum;
    while(cin >> jacksNum >>jillsNum){
        if(jacksNum== 0 && jillsNum==0){
            break;
        }
        vector<int> jack;
        vector<int> jill;
        int catalogNum;
        for(int i=0; i< jacksNum ; i++){
            cin>> catalogNum;
            jack.push_back(catalogNum);
        }
        for(int i=0; i< jillsNum; i++){
            cin>>catalogNum;
            jill.push_back(catalogNum);
        }
        vector<int> intersections;
        set_intersection(jack.begin(), jack.end(),
                         jill.begin(), jill.end(),
                         inserter(intersections, intersections.begin()));
        cout<<intersections.size()<<endl;
    }
}



