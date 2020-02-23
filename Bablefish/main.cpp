#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
using namespace std;
int main()
{
    string line, englishWord, foreignWord;
    map<string, string> dictionary;
    while(getline(cin, line) && !line.empty()){
         englishWord = line.substr(0,line.find(" "));
         foreignWord = line.substr(line.find(" ")+1, line.back());
         dictionary[foreignWord] = englishWord;
    }
    while(getline(cin, foreignWord) && !foreignWord.empty()){
        if(dictionary[foreignWord].empty()){
            cout<<"eh"<<endl;
        }
        else{
            cout<<dictionary[foreignWord]<<endl;
        }
    }
}
