class Solution {
public:
    vector<vector<int>> vf;
    void mvf(vector<int> &p,int idx,vector<int> &nums){
        int n=nums.size();
        if(p.size()==n) {vf.push_back(p);return;}
        for(int i=0;i<n;i++){
            bool f=false;
            for(int j=0;j<p.size();j++){
                if(p[j]==nums[(i+idx)%n]) f=true;
            }
            if(f) continue;
            p.push_back(nums[(i+idx)%n]);
            mvf(p,idx+1,nums);
            p.pop_back();
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v;
        mvf(v,0,nums);
        return vf;
    }
};
