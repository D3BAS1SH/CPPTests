#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> myVals;

        for (int i = 0; i < nums.size()-1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    myVals.push_back(i);
                    myVals.push_back(j);
                    break;
                }
            }
        }

        return myVals;
    }
};

int main() {
    Solution S;
    vector<int> myNum = { 3,2,4};
    vector<int> myR=S.twoSum(myNum, 6);
    for (int i = 0; i < myR.size(); i++) {
        cout << myR[i] << endl;
    }
    return 0;
}