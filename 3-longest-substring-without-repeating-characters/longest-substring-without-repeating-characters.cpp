class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int map[256];
    fill(map, map + 256, -1);
    int l=0;
    int r=0;
    int maxL=0;
    while(r<n){
        if(map[s[r]]!=-1){
            //present in the map
            if(map[s[r]]>=l){
                l=map[s[r]]+1;
            }
        }

        int len=r-l+1;
        maxL=max(maxL,len);
        map[s[r]]=r;
        r++;
    }
    return maxL;
    }
};