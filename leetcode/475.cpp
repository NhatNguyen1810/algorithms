//https://leetcode.com/problems/heaters/


class Solution {
public:
    void in_range(int left, int right, set<int>& houses, set<int>& house_index){
        for(auto x: houses){
            if(x >= left && x <= right){
                house_index.insert(x); 
            }
        }
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int left = 0; 
        int right = 1E9; 
        int final_radius = INT_MAX; 
        sort(heaters.begin(), heaters.end()); 
        sort(houses.begin(), houses.end()); 
        while(left <= right){
            int radius = (left + right)/2; 
            cout << left << " " << right << " " << radius << endl; 
            bool accepted_radius = false; 
            set<int> house_index; 
            int i = 0; 
            int j = 0; 
            while(i < houses.size() && j < heaters.size()){
                if(abs(heaters[j] - houses[i]) <= radius){
                    i++;
                }
                else{
                    j++; 
                }
            } 
            if(i == houses.size() && j <= heaters.size()){
                final_radius = min(final_radius, radius); 
                right = radius - 1; 
            }
            else{
                left = radius + 1; 
            }
        }
        return final_radius; 
    }
};