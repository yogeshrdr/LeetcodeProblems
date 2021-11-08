class Solution {
void calculate(int n, int pos, vector<bool>& visited, int& count){
    if(pos > n) count++;
    for(int i = 1; i <= n; ++i){
        if(!visited[i] && (pos % i == 0 || i%pos == 0)){
            visited[i] = true;
            calculate(n, pos+1, visited, count);
            visited[i] = false;
        }
    }
}
public:
    int countArrangement(int n) {
        vector<bool> visited(n+1, false);
        int count = 0;
        calculate(n, 1, visited, count);
        return count;
    }
};