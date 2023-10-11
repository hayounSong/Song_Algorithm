#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
vector<int> num;
int tr;
using namespace std;
int answer = 0;
void bfs(){
    int startx=0;
    int value=0;
    
    queue<pair<int,int>> q;
    
    q.push({startx,value});
    
    while(!q.empty()){
        int fx=q.front().first;
        int fv=q.front().second;
        
        q.pop();
        if(fx==num.size()){
            if(fv==tr){
                answer++;
                continue;
            }
            else{
                continue;
            }
        }
        else{
            q.push({fx+1,fv+num[fx]});
            q.push({fx+1,fv-num[fx]});
        }
        
    }
}

int solution(vector<int> numbers, int target) {

    tr=target;
    num=numbers;
    bfs();
    return answer;
}