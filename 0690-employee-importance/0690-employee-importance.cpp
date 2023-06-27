/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    
    int dfs(vector<Employee*>& adj, int index, unordered_set<int>& visited, unordered_map<int,int>& mp) {
        visited.insert(adj[index]->id);
        
        int ans = adj[index]->importance;
        
        for(auto it : adj[index]->subordinates) {
            if(!visited.count(it)) {
                ans += dfs(adj, mp[it], visited, mp);
            }
        }
        
        return ans;
    }
    int getImportance(vector<Employee*> employees, int id) {
        unordered_set<int> visited;
        unordered_map<int, int> mp;
        
        for(int i = 0; i < employees.size(); i++) {
            mp[employees[i]->id] = i;
        }
        
        return dfs(employees, mp[id], visited, mp);
    }
};