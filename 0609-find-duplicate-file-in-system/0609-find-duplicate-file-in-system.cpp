class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        int n = paths.size();

        unordered_map<string, vector<string>> mp;

        for (string& path : paths) {
            stringstream ss(path);
            string dir;
            ss >> dir;

            string file;
            while (ss >> file) {
                int open = file.find('(');
                int close = file.find(')');

                string fileName = file.substr(0, open);
                string content = file.substr(open, close - open + 1);

                string fullPath = dir + "/" + fileName;
                mp[content].push_back(fullPath);
            }
        }

        vector<vector<string>> ans;
        for (auto& pair : mp) {
            if (pair.second.size() > 1) {
                ans.push_back(pair.second);
            }
        }
        return ans;
    }
};