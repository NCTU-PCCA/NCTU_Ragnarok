#define eid w
void _EulerCircuit(int x){
	for(int i=0;i<(int)vc[x].size();i++){
		Edge e = vc[x][i];
		if(vis[e.eid]) continue;
		vis[e.eid] = 1;
		_EulerCircuit(e.to);
		eulercircuit.push_back(e.eid);
	}
}
bool EulerCircuit(){ // undirected
	if(!Connected()) return false;
	vis = vector<int>(M+1, 0);
	for(int i=0;i<N;i++){
		if(vc[i].size()&1)
			return false;
		//sort
		sort(vc[i].begin(), vc[i].end());
	}
	eulercircuit.clear();
	_EulerCircuit(0);
	//sort
	reverse(eulercircuit.begin(), eulercircuit.end());
	return true;
}

