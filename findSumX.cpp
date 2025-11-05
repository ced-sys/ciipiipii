#include <bits/stdc++.h>
using namespace std;

struct Cmp {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        if (a.first != b.first) return a.first < b.first;   // smaller freq first
        return a.second < b.second;                         // smaller value first
    }
};

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        map<int,int> freq;
        multiset<pair<int,int>, Cmp> top, rest;
        long long top_sum = 0;
        vector<long long> ans;

        auto balance = [&]() {
            while ((int)top.size() < x && !rest.empty()) {
                auto it = prev(rest.end());
                top.insert(*it);
                top_sum += 1LL * it->first * it->second;
                rest.erase(it);
            }
            while ((int)top.size() > x) {
                auto it = top.begin();
                top_sum -= 1LL * it->first * it->second;
                rest.insert(*it);
                top.erase(it);
            }
            while (!rest.empty() && !top.empty()) {
                auto it1 = prev(rest.end());
                auto it2 = top.begin();
                if (*it1 > *it2) {
                    top_sum += 1LL * it1->first * it1->second - 1LL * it2->first * it2->second;
                    top.insert(*it1);
                    rest.insert(*it2);
                    rest.erase(it1);
                    top.erase(it2);
                } else break;
            }
        };

        auto add = [&](int num) {
            pair<int,int> old = {freq[num], num};
            if (freq[num] > 0) {
                if (top.find(old) != top.end()) {
                    top_sum -= 1LL * old.first * old.second;
                    top.erase(top.find(old));
                } else rest.erase(rest.find(old));
            }
            freq[num]++;
            rest.insert({freq[num], num});
            balance();
        };

        auto remove = [&](int num) {
            pair<int,int> old = {freq[num], num};
            if (top.find(old) != top.end()) {
                top_sum -= 1LL * old.first * old.second;
                top.erase(top.find(old));
            } else rest.erase(rest.find(old));
            freq[num]--;
            if (freq[num] > 0) rest.insert({freq[num], num});
            else freq.erase(num);
            balance();
        };

        for (int i = 0; i < k; ++i) add(nums[i]);
        ans.push_back(top_sum);

        for (int i = k; i < (int)nums.size(); ++i) {
            remove(nums[i - k]);
            add(nums[i]);
            ans.push_back(top_sum);
        }

        return ans;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1,2,2,3,3,3};
    int k = 4, x = 2;
    auto res = sol.findXSum(nums, k, x);
    for (auto v : res) cout << v << " ";
}