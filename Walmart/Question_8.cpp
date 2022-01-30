class Solution{
public:
    int height(int N){
        // code here
        int ans = (-1 + sqrt(1 + (8*N))) / 2;
        return ans;
    }
};