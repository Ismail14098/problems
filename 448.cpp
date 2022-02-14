#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
//    vector<int> findDisappearedNumbers(vector<int>& nums) {
//        set<int> s;
//        for (int i=0; i<nums.size(); i++) {
//            s.insert(nums[i]);
//        }
//        int n = 1;
//        vector<int> result;
//        for (int i=0; i<nums.size(); i++) {
//            if (s.count(n) == 0) result.push_back(n);
//            n++;
//        }
//        return result;
//    }
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
            nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1]);
        
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > 0) res.push_back(i+1);
        
        return res;
    }
};

void rec(vector<int>::iterator begin, vector<int>::iterator end) {
    for (auto i=begin; i!=end; i++) {
        cout<<*i<<endl;
    }
}

int main() {
    vector<int> nums = {4,3,2,7,8,2,3,1};
//    vector<int> nums = {1,1};
    Solution s;
    nums = s.findDisappearedNumbers(nums);
    rec(nums.begin(), nums.end());
}

//int main() {
//    vector<int> nums = {1,2,3,4,5,6};
//    rec(nums.begin(), nums.end());
//}
