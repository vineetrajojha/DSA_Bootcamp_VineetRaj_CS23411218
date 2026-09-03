class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        vector<string> a;
        stringstream s(sentence);
        string w;
        while(s>>w) a.push_back(w);
        for(string i:dictionary){
            for(int j=0;j<a.size();j++){
                string to=a[j].substr(0,i.size());
                if(to==i) a[j]=i;}}
        string res;
        for(string i:a){
            res+=i;
            res.push_back(' ');}
        res.pop_back();
        return res;}};