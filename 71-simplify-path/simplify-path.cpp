class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string temp;
        int i = 1;
        int n = path.size();
        while (i < n) {
            while (i < n && path[i] == '/') {
                i++;
            }
            while (i < n && path[i] != '/') {
                temp += path[i++];
            }
            if (temp == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            } else if (temp != "" && temp != "." && temp != "..") {
                st.push(temp);
            }
            temp.clear();
        }
        vector<string> vec;
        while (!st.empty()) {
            vec.push_back(st.top());
            st.pop();
        }
        temp = "";
        for (int i = vec.size() - 1; i >= 0; i--) {
            temp += "/" + vec[i];
        }
        if (temp == "") {
            temp = "/";
        }
        return temp;
    }
};