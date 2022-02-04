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

vector<int> findAnagrams(string s, string p) {
    vector<int> res;
    if(p.length()>s.length()){
        return res;
    }

    map<char, int> m;
    int sum=0;
    for(char c: p){
        m[c]++;
        sum++;
    }
    int curr_sum=0;
    for(int i=0; i<p.length(); i++) {
        char c = s[i];
        if(m.find(c) != m.end()){
            m[c]--;
            if(m[c] >= 0)
                curr_sum += 1;
        }
    }
    if(curr_sum==sum) {
        res.push_back(0);
    }
    int i = 0;
    int j = p.length();
    while (i<s.length()-p.length()+1) {
        char l = s[i];
        if(m.find(l) != m.end()) {
            m[l]++;
            if(m[l]>0)
                curr_sum--;
        }
        i++;
        char r = s[j];
        if(m.find(r) != m.end()) {
            m[r]--;
            if(m[r]>=0)
                curr_sum++;
        }
        j++;
        if(curr_sum==sum) {
            res.push_back(i);
        }
    }
    return res;
}

vector<int> findAnagrams2(string s, string p) {
    vector<int> res;
    vector<int> hash(26,0), phash(26,0);
    if(p.length()>s.length()){
        return res;
    }
    int i=0, j=0;
    while(j<p.length()) {
        phash[p[j]-'a']+=1;
        hash[s[j++]-'a']+=1;
    }
    j--;
    while(j<s.length()) {
        if(phash == hash)
            res.push_back(i);
        j++;
        if(j!=s.length())
            hash[s[j]-'a']++;
        hash[s[i]-'a']--;
        i++;
    }
    
    return res;
}

int main() {
    vector<int> vec = findAnagrams("abab", "ab");
    for(vector<int>::iterator i=vec.begin();i!=vec.end();++i)
        cout<<*i<<endl;

    return 0;
}
