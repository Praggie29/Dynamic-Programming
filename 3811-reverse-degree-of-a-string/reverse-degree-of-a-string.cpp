class Solution {
public:
    int reverseDegree(string s) {
        int n=s.size();
        int ans=0;
        int arr[26]={0};
        for(int i=0;i<26;i++){
            arr[i]=26-i;
        }
        for(int i=0;i<n;i++){
            int val=arr[s[i]-'a'];
            ans+=val*(i+1);

        }
        return ans;
    }
};