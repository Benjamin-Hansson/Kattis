#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string line;
    int n;
    int m;
    int casenumber = 1;
    while(getline(cin,line) && !line.empty()){
        n = stoi(line);
        vector<int> numbers;
        for(int i = 0; i<n; i++){
            getline(cin, line);
            numbers.push_back(stoi(line));
        }
        getline(cin, line);
        m = stoi(line);
        int query;
        cout<<"Case "<<casenumber<<":"<<endl;

        for(int i = 0; i<m; i++){
            getline(cin, line);
            query = stoi(line);
            int championSum = numbers[0]+numbers[1];
            int sum;
            for(int i=0; i < numbers.size(); i++){
                for(int j = i+1; j < numbers.size(); j++){
                    sum = numbers[i] + numbers[j];
                    if(abs(query-sum) < abs(query-championSum)){
                        championSum = sum;
                    }
                }
            }
            cout<<"Closest sum to "<<query<<" is "<<championSum<<"."<<endl;
        }
        casenumber++;
    }
}
