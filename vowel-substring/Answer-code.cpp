class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };
    long atMost(string &s, int goal) {
        int n=s.size();
        long cnt=0,left=0;
        unordered_map<char,int>mpp;
        for(int right=0;right<n;right++){
            if(!isVowel(s[right])){
                mpp.clear();
                left=right+1;
                continue;
            }
            mpp[s[right]]++;
            while(mpp.size()>goal){
                mpp[s[left]]-=1;
                if(mpp[s[left]]==0)
                mpp.erase(s[left]);
                left++;
            }

            cnt+=right-left+1;
        }
        return cnt;
    }
public:
    long countVowelSubstrings(string s) {
        return atMost(s, 5) - atMost(s, 4);
    }
};
