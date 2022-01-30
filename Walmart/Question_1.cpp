vector<vector<pair<int,double>>> graph(n,vector<pair<int,double>>());
    
    for(int i=0;i<edges.size();i++){
        graph[edges[i][0]].push_back({edges[i][1],succProb[i]});
        graph[edges[i][1]].push_back({edges[i][0],succProb[i]});
    }
    
    priority_queue<pair<double,int>> maxheap;
            
    double prob[n];
    
    for(int i=0;i<n;i++)
        prob[i]=(double)0.0;
    
    prob[start]=(double)1.0;
    
    maxheap.push({prob[start],start});
    
    while(!maxheap.empty()){
        
        auto p=maxheap.top();
        
        maxheap.pop();
                
        for(auto i:graph[p.second]){
            if(prob[i.first]<prob[p.second]*i.second){
                prob[i.first]=prob[p.second]*i.second;
                maxheap.push({prob[i.first],i.first});
            }
        }
    }
    
    return prob[end];
}
