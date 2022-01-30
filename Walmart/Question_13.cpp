class Solution {
public:
    
    static bool cmp(string a, string b){
        if(a.size() == b.size()){
            for(int i = 0; i<a.size(); i++){
                if(a[i] == b[i]){
                    continue;
                }
                
                return a[i] < b[i];
            }
        }
        
        return a.size() < b.size();
    }
    
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        return nums[nums.size()-k];
    }
};