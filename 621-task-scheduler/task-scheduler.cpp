class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }
        priority_queue<int> pq;
        for (int f : freq) {
            if (f > 0) {
                pq.push(f);
            }
        }
        queue<pair<int, int>>
            cooldown; // stores remaining frequency and available time
        int time = 0;
        while (!pq.empty() || !cooldown.empty()) {
            time++;

            if (!pq.empty()) {
                int cnt = pq.top();
                pq.pop();
                cnt--;

                if (cnt > 0) {
                    cooldown.push({cnt, time + n});
                }
            }
            if (!cooldown.empty() && cooldown.front().second == time) {
                pq.push(cooldown.front().first);
                cooldown.pop();
            }
        }
        return time;
    }
};