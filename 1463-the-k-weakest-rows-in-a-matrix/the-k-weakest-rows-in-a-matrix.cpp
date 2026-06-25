class Solution {
public:
    class Row {
    public:
        int SoldierCount;
        int idx;
        Row(int SoldierCount, int idx) {
            this->SoldierCount = SoldierCount;
            this->idx = idx;
        }
        bool operator<(const Row& obj) const {
            if (this->SoldierCount == obj.SoldierCount) {
                return this->idx > obj.idx;
            }
            return this->SoldierCount > obj.SoldierCount;
        }
    };
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<Row> rows;
        for (int i = 0; i < mat.size(); i++) {
            int count = 0;
            for (int j = 0; j < mat[i].size() && mat[i][j] == 1; j++) {
                count++;
            }
            rows.push_back(Row(count, i));
        }
        priority_queue<Row> pq(rows.begin(), rows.end());
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(pq.top().idx);
            pq.pop();
        }
        return ans;
    }
};