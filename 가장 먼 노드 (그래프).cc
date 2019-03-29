#include <string>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer[n+1], index=0;
    vector<int> map[n+1];
    bool visit[n+1];
    for(int i=0; i<n+1; i++){
        answer[i] = 0;
        visit[i] = false;
    }
    for(int i=0; i<edge.size(); i++){
        map[edge[i][0]].push_back(edge[i][1]);
        map[edge[i][1]].push_back(edge[i][0]);
    }
    queue<pair<int, int> > q;
    q.push({1,0});
    visit[1] = true;
    while(!q.empty()){
        int cur = q.front().first;
        int eg = q.front().second;
        if(index < eg) index = eg;
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
