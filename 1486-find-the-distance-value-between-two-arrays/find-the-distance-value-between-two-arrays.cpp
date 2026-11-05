class Solution {
public:
    bool isValid(vector <int>& arr2, int d, int i){
        for (int n : arr2){
            if (abs(n - i) <= d) return false;
        }
        return true;
    }
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int c = 0;
        for (int i : arr1){
            if(isValid(arr2, d, i)){
                c++;
            }
        }
        return c;
    }
};