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
#include <unordered_map>
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
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int length = 0;
        ListNode* curr = head;
        while (curr != NULL) {
            curr = curr->next;
            length++;
        }
        
        int mid = length / 2;
        int i = 0;
        ListNode* left = head;
        curr = head;
        ListNode* right = nullptr;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while (curr != NULL) {
            if (i<mid) {
                prev = curr;
                curr = curr->next;
                i++;
          } else {
              next = curr->next;
              curr->next = prev;
              prev = curr;
              curr = next;
          }
        }
        right = prev;
        i=0;
        while(i<mid) {
            if(right->val != left->val) {
                right->next = nullptr;
                left->next = nullptr;
                return false;
            }
            right = right->next;
            left = left->next;
            i++;
        }
        right->next = nullptr;
        left->next = nullptr;
        return true;
    }
};

void rec(vector<int>::iterator begin, vector<int>::iterator end) {
    for (auto i=begin; i!=end; i++) {
        cout<<*i<<endl;
    }
}

int main() {
    ListNode l1;
    l1.val = 1;
    ListNode l2;
    l2.val = 2;
    ListNode l3;
    l3.val = 5;
    ListNode l4;
    l4.val = 2;
    ListNode l5;
    l5.val = 1;
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    Solution s;
    cout<<s.isPalindrome(&l1);
//    rec(nums.begin(), nums.end());
}

//int main() {
//    vector<int> nums = {1,2,3,4,5,6};
//    rec(nums.begin(), nums.end());
//}
