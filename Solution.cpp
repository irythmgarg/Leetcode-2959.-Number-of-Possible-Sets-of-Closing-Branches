class Solution {
public:
bool Floyd_warshall(unordered_map<int,vector<pair<int,int>>>&mp,int distance, vector<int>& nodes)
{
    int n = nodes.size();  // Use actual number of nodes in the current subset
    unordered_map<int, int> id;
    for (int i = 0; i < n; ++i) {
        id[nodes[i]] = i;
    }

    vector<vector<int>> ans(n, vector<int>(n, INT_MAX));
    
    auto it = mp.begin();
    while (it != mp.end()) {
        int from = id[it->first];
        for (auto a : it->second) {
            int to = id[a.first];
            int d = a.second;
            ans[from][to] = min(ans[from][to], d); // Use min to avoid overwriting with worse distance
        }
        it++;
    }

    for (int j = 0; j < n; j++) {
        ans[j][j] = 0;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (ans[i][k] < INT_MAX && ans[k][j] < INT_MAX) {
                    ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (distance < ans[i][j])
                return false;
        }
    }
    return true;
}

int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
    int ans = 0;
    for (int set = 0; set < (1 << n); set++) {
        vector<int> nodes;
        for (int i = 0; i < n; ++i) {
            if ((set >> i) & 1) nodes.push_back(i);
        }

        // Handle empty and single-node sets as valid
        if (nodes.size() <= 1) {
            ans++;
            continue;
        }

        int curset = set;
        unordered_map<int, vector<pair<int, int>>> mp;
        for (auto road : roads) {
            int u = road[0];
            int v = road[1];
            int distance = road[2];
            if (((curset >> u) & 1) && ((curset >> v) & 1)) {
                mp[u].push_back({v, distance});
                mp[v].push_back({u, distance});
            }
        }

        if (Floyd_warshall(mp, maxDistance, nodes)) {
            ans++;
        }
    }
    return ans;
}
};
