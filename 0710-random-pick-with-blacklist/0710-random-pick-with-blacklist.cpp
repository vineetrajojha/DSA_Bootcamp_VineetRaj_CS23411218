class Solution {
    private:
        int m_lim;
        unordered_set<int> m_bl;
        unordered_map<int, int> m_map;
        std::mt19937 m_e1; 
        std::minstd_rand m_e2; 
        std::uniform_int_distribution<int> uniformDistribution;


public:
    Solution(int n, vector<int>& blacklist) :
        m_lim(n-(int)blacklist.size()),m_e2(std::random_device{}())
        ,uniformDistribution(0, n-1-(int)blacklist.size())
        {
            for (auto &v : blacklist) m_map.insert({v,-1});

            int ilim = m_lim;
            for (auto &v : blacklist){
                if ( v >= m_lim) continue;
                for(; m_map.contains(ilim); ++ilim) {}
                m_map[v] = ilim;
                ++ilim;
            }
        }
    int pick() {
        int rnd = uniformDistribution(m_e2);
        return m_map.contains(rnd) ? m_map[rnd] : rnd;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */