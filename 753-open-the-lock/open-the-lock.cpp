class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set <string> deadend(deadends.begin(), deadends.end());
        if (deadend.count("0000")){
            return -1;
        }

        queue <pair <string, int>> q;
        q.push({"0000", 0});
        unordered_set <string> visited;
        visited.insert("0000");
        
        while(!q.empty()){
            auto cur = q.front();
            q.pop();

            string seq = cur.first;
            int moves = cur.second;

            if (seq == target) return moves;

            for (int i = 0; i < 4; i++){
                for (int d : {-1, 1}){
                    int newDigit = (seq[i] - '0' + d + 10) % 10;
                    string newSeq = seq;
                    newSeq[i] = '0' + newDigit;

                    if (visited.find(newSeq) == visited.end() && deadend.find(newSeq) == deadend.end()){
                        visited.insert(newSeq);
                        q.push({newSeq, moves+1});
                    }
                }
            }
        }
        return -1;
    }
};