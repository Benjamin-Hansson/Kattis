#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <map>
#include <queue>
#include <stack>

using namespace std;
int main()
{

    string commandNum;
    bool stk;
    bool que;
    bool pque;
    while(true){
        bool broken = false;
        stk = true;
        que = true;
        pque = true;
        queue<int> q;
        priority_queue<int> p;
        stack<int> s;
        int size =0;
        getline(cin, commandNum);
        if(commandNum.empty()) break;

        int commnum = stoi(commandNum);
        int command, value, i;
        for(i=0; i<commnum; i++){
            cin >> command >> value;
            if(command == 1){
                q.push(value);
                p.push(value);
                s.push(value);
                size ++;

            }else{
                if(size <1){
                    cout<<"impossible"<<endl;
                    broken =true;
                    break;
                }
                if(q.front() != value) que = false;
                if(p.top() != value) pque = false;
                if(s.top() != value) stk = false;

                q.pop();
                p.pop();
                s.pop();
                size --;

            }
        }
        if(broken){
            i+=1;
            for(i; i<commnum; i++){
                cin>> command >> value;
            }
            cin.ignore();
            continue;
        }
        int numOfTrue =0;
        if(stk){
            numOfTrue ++;
        }
        if(que){
            numOfTrue ++;
        }
        if(pque){
            numOfTrue ++;
        }


        if(numOfTrue > 1){
            cout<<"not sure"<< endl;
        }
        if(numOfTrue == 0){
            cout<<"impossible"<<endl;
        }
        if(numOfTrue == 1){
            if(stk){
                cout<<"stack"<<endl;
            }
            if(que){
                cout<<"queue"<<endl;
            }
            if(pque){
                cout<<"priority queue"<<endl;
            }
        }
        cin.ignore();
    }

}
