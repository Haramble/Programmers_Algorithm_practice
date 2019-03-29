#include <string>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer[n+1], index=0;
    vector<int> map[n+1];
    bool visit[n+1];
    //초기화 부분
    for(int i=0; i<n+1; i++){
        answer[i] = 0;
        visit[i] = false;
    }
    //간선들로 map을 만듬.
    for(int i=0; i<edge.size(); i++){
        map[edge[i][0]].push_back(edge[i][1]);
        map[edge[i][1]].push_back(edge[i][0]);
    }
    
    //bfs
    queue<pair<int, int> > q; //queue에 pair값을 넣는데 first는 노드의 번호, second는 간선을 몇번 거쳐서 왔는지 나타낸다.
    q.push({1,0});
    visit[1] = true;
    while(!q.empty()){
        int cur = q.front().first;
        int eg = q.front().second;
        if(index < eg) index = eg; //최대 간선길이 갱신
        q.pop();

        for(vector<int>::iterator it=map[cur].begin(); it<map[cur].end(); it++){
            int next = *it;
            if(!visit[next]){
                visit[next] = true;
                q.push({next, eg+1});
                answer[eg+1]++;
            }
        }
    }
    return answer[index];
}
