#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

long long swaps;
long a[1000005];
long temp[1000005];
int main()
{
    long students;
    while(cin>>students){
           map<long,bool>vis;
           for(long i=0;i<students;i++)
           {
               cin>>a[i];
               temp[i]=a[i];
           }
         // we need to sort the array element to determine their correct places based on which comparisons will be made.
           sort(temp,temp+students);
           for(long i=0;i<students;i++)
           {
               //if a[i] or temp[i] has already been swapped or if they are same,nothing to do
               if(a[i]==temp[i] or vis[a[i]] or vis[temp[i]])continue;
               //otherwise mark temp[i] for being swapped and increment the count by 1
               vis[temp[i]]=true;
               swaps++;
           }
           cout<<swaps<<endl;
           swaps =0;
    }
}



void test(){
    long students;
    while(cin>>students){
        for(long i=0; i< students; i++){
            cin >> a[i];
        }
        bool visited[students] = {0};
        for(long i = 0; i < students; i++){
            if(visited[i] || a[i]==i){
                continue;
            }
            long cycle_size = 0;
            long j = i;
            while(!visited[j]){
                visited[j] = true;
                j = a[j]-1;
                cycle_size ++;
            }
            if(cycle_size>0){
                swaps += (cycle_size - 1);
            }
        }
        cout<<swaps<<endl;
        swaps =0;
    }


}
