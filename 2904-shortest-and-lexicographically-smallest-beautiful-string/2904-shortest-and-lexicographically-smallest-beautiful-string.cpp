class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int l = 0;
        int ones = 0;

        string res = "";

        for(int r = 0; r < s.length(); r++){

            if(s[r] == '1')
                ones++;

            while(ones > k){

                if(s[l] == '1')
                    ones--;

                l++;
            }

            if(ones == k){

                while(l < r && s[l] == '0')
                    l++;

                string cur = s.substr(l, r - l + 1);

                if(res.empty() ||
                   cur.length() < res.length() ||
                   (cur.length() == res.length() && cur < res)){

                    res = cur;
                }
            }
        }

        return res;
    }
};