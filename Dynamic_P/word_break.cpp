class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<vector<int> > travel(s.size()+1);
        
        // prepare travel map between indexes
        for(int i=0; i<wordDict.size(); i++) {
            int pos=s.find(wordDict[i]);
            while (pos!=string::npos) {
                travel[pos].push_back(pos+wordDict[i].size());
                pos=s.find(wordDict[i],pos+1);
            }
        }
        
        int target=s.size();
        vector<int> got(s.size()+1, 0);
        got[0]=1;
        
        // go through accesable indexes, and check that s.size() is accesable
        for(int i=0; i<got.size(); i++)
            if(got[i])
                for(int j=0; j<travel[i].size(); j++)
                    got[travel[i][j]]=1;
            
        return bool(got[s.size()]);
    }
};