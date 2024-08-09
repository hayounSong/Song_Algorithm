#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> q;
    
    for(int i=0;i<scoville.size();i++){
        q.push(scoville[i]);
    }
    
    while(q.top()<K&&q.size()>=2){
     int small=q.top();
     q.pop();
     int big=q.top();
     q.pop();
        
    int new1=small+big*2;
    q.push(new1);
    answer++;
    }
    if(q.top()<K&&q.size()<2){
        answer=-1;
    }
    return answer;
}