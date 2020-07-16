class Solution {
private:
    string lettermap[10]=
    {
        " ",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    
    vector<string> res;
    
    
    void find(const string &digits,int index,const string &s)
    {
        if(index==digits.size())
       {
           res.push_back(s);
           return;
       }
        
        char c=digits[index];
        string letters=lettermap[c-'0'];
        for(int i=0;i<letters.size();i++)
        {
            find(digits,index+1,s+letters[i]);
        }
        return;
    }
public:
    /**
     * @param digits: A digital string
     * @return: all posible letter combinations
     */
    vector<string> letterCombinations(string &digits) {
        // write your code here
        if(digits=="")
        return res;
        find(digits,0,"");
        return res;
    }
};