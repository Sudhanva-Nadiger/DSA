class Solution {
public:
    void process(queue<int>& q,int snack,bool& ok){
        if(q.size() == 0){
            ok = false;
            return;
        }
        
        int x = q.front();
        if(x == snack){
            ok = true;
            return;
        }
        
        q.pop();
        process(q,snack,ok);
        q.push(x);
        
    }
    int countStudents(vector<int>& students, vector<int>& s) {
        queue<int> q;
        for(int i = 0;i<students.size();++i){
            q.push(students[i]);
        }
        
        int i = 0;
        
        while(i<s.size()){
            int front = q.front();
            if(front != s[i]){
                bool ok = 0;
                process(q,s[i],ok);
                if(!ok){
                    return q.size();
                }
            }
            else{
                q.pop();
                i++;
            }
        }
        
        return 0;
    }
};