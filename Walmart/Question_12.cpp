int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int idx[n];
        for(int i=0;i<n;i++){
            idx[i]=i;
        }
        sort(idx,idx+n,[&efficiency](int a,int b){
            return efficiency[a]<efficiency[b];
        });
        long suff[n];
        priority_queue<int> pq;
        long sum=0;
        for(int i=n-1;i>=0;i--){
            suff[i]=sum;
            pq.push(-speed[idx[i]]);
            sum+=speed[idx[i]];
            if(pq.size()>k-1){
                sum+=pq.top();
                pq.pop();
            }
        }
        long ans=0;
        for(int i=n-1;i>=0;i--){
            ans=max(ans,efficiency[idx[i]]*(suff[i]+speed[idx[i]]));
        }
        int MOD=1e9+7;
        return ans%MOD;
    }