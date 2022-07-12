// 3:30까지 20분

#include<bits/stdc++.h>
using namespace std;

int T,N,M;
vector<int> adj[501]{};
int deg[501]{};
bool vi[501][501]{};
bool tvi[501]{};
vector<int> ord;

int topology() {
	queue<int> q;
	for (int i = 1; i <= N; i++){
		if (deg[i] == 0) { 
			q.push(i);
		}
	}
    
	for (int i = 1; i <= N; i++) {
        if(q.size()==0) return -1;
        if(q.size()!=1) return 0;
		int cn = q.front();
		q.pop();
        ord.push_back(cn);

		for (auto nn : adj[cn]) {
			if (--deg[nn] == 0) {
				q.push(nn);
			}
		}
	}
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tmp,a,b;
    cin>>T;
    while(T--){
        cin>>N;
        for(int i=1; i<=N; i++) adj[i].clear();
        memset(deg,0,sizeof(deg));
        memset(vi,0,sizeof(vi));
        memset(tvi,0,sizeof(tvi));
        ord.clear();
        vector<int> trank;
        for(int i=1; i<=N; i++){
            cin>>tmp;
            trank.push_back(tmp);
        }

        cin>>M;
        for(int i=0; i<M; i++){
            cin>>a>>b;
            vi[a][b] = true;
            vi[b][a] = true;
        }
        
        for(int k=0; k<trank.size(); k++){
            int i = trank[k];
            tvi[i] = true;
            for(int j=1; j<=N; j++){
                if(tvi[j]) continue;
                if(!vi[i][j]) {
                    adj[i].push_back(j);
                    deg[j]++;
                } else {
                    adj[j].push_back(i);
                    deg[i]++;
                }
            }
        }

        int res = topology();
        if(res==-1) cout<<"IMPOSSIBLE\n";
        else if(res==0) cout<<"?\n";
        else {
            for(int i=0; i<ord.size(); i++){
                cout<<ord[i]<<' ';
            }
            cout<<'\n';
        }
    }
}