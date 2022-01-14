bool check(int color, int node, vector <int> &vc, bool graph[101][101]){
    for(int i=0;i<vc.size();i++){
        if(graph[i][node] && vc[i]==color) return false;
    }
    return true;
}

bool solve(int node, bool graph[101][101], int m, int V, vector <int> &vc){
    if(node>=V){
        return true;
    }
    for(int i=0;i<m;i++){
        if(check(i,node,vc, graph)){
            vc[node] = i;
            if(solve(node+1, graph, m, V, vc)) return true;
            vc[node] = -1;
        }
    }
    return false;
}




bool graphColoring(bool graph[101][101], int m, int V)
{
    vector <int> vc (V, -1);
    bool a =  solve(0, graph, m, V, vc);
    for(auto b:vc) cout<<b<<" ";
    cout<<endl;
    return a;
}