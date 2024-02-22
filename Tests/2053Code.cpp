#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<math.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<string> DistArr;
    
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> V;
        for (int i = 0; i < arr.size(); i++) {
            V[arr[i]]++;
        }
        vector<string> DistV;
        for (int i = 0; i < arr.size(); i++) {

            if (!isPresent(arr[i])) {
                DistArr.push_back(arr[i]);
            }
            
        }

        /*for (int i = 0; i < DistArr.size(); i++) {
            cout << DistArr[i] << " ";
        }
        cout << endl;*/

        for (int i = 0; i < DistArr.size(); i++) {
            if (!isMoreThanOne(DistArr[i], arr)) {
                DistV.push_back(DistArr[i]);
            }
        }

        /*for (int i = 0; i < DistV.size(); i++) {
            cout << DistV[i] << " ";
        }
        cout << endl;*/

        if (k > DistV.size()) {
            //cout << "BLANK" << endl;
            return "";
        }
        else {
            return DistV[k-1];
        }
    }

    bool isMoreThanOne(string V,vector<string>& arr) {
        int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (V == arr[i]) {
                count++;
            }
        }
        if (count >=2) {
            return true;
        }
        return false;
    }

    bool isPresent(string V) {
        for (int i = 0; i < DistArr.size(); i++) {
            if (V == (DistArr[i])) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution S;
    vector<string> V = { "a","b","a" };
    cout << S.kthDistinct(V, 3) << endl;
}