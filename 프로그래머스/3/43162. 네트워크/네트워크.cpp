#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
vector<int> v[201];
int visited[201]={0};
int N;
void bfs(int start){
    
    queue<int> q;
    q.push(start);
    visited[start]=1;
    while(!q.empty()){    
        int fx=q.front();
        q.pop();

        for(int i=0;i<v[fx].size();i++){
            if(visited[v[fx][i]]==0){
                visited[v[fx][i]]=1;
                        
                q.push(v[fx][i]);
            }
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    N=n;
    for(int i=0;i<computers.size();i++){
        for(int j=0;j<n;j++){
            if(computers[i][j]==1){

                v[i+1].push_back(j+1);
                v[j+1].push_back(i+1);
            }
        }
    }
    for(int i=1;i<=N;i++){
        if(visited[i]==0){
            answer++;
            bfs(i);
        }
    }
    
    
    return answer;
}