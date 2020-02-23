#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <set>
#include <queue>
#include <stack>

using namespace std;

class person{
public:
    int id;
    int owes;
    vector<int> friends;

    bool operator==(const person& o) const{
        return id==o.id;
    }
};


int calcSum(person* p, person* persons[], vector<person*>& visited){
    int tempSum = p->owes;
    visited.push_back(p);
    for(int i=0; i < p->friends.size(); i++){
        person* temp = persons[p->friends[i]];
        if(find(visited.begin(), visited.end(), temp) == visited.end()){
            tempSum += calcSum(persons[p->friends[i]], persons, visited);
        }
    }
    return tempSum;
}


int main()
{
    int n, m;
    cin >>n>>m;
    person* persons[n];

    for(int i =0; i< n; i++){
        person* p = new person;
        cin>>p->owes;
        persons[i]=p;
        p->id=i;
    }

    int friend1, friend2;
    for(int i =0; i<m; i++){
        cin>>friend1>>friend2;
        persons[friend1]->friends.push_back(friend2);
        persons[friend2]->friends.push_back(friend1);

    }

    //summan i varje friendship-cirkel måste vara 0
    vector<person*> visited;
    bool broken = false;
    for(int i=0; i<n; i++){
        person* p = persons[i];
        if(find(visited.begin(), visited.end(), p) != visited.end()) continue;
        int sum = calcSum(p, persons, visited);
        if(sum != 0){
            cout<<"IMPOSSIBLE"<<endl;
            broken = true;
            break;
        }
        if(visited.size()==n) break;

    }
    if(!broken){
        cout<<"POSSIBLE"<<endl;
    }

}




