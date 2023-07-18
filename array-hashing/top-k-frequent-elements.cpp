#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9+7;
int dirx[4] = {0,-1,1,0};
int diry[4] = {-1,0,0,1};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
return 0;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> dic;
        int n=nums.size();
        for (int i=0;i<n;i++){
            try{
                dic[nums[i]]+=1;
            }
            catch(const std::exception& e){
                dic[nums[i]]=1;
            }
            
        }
        priority_queue<pair<int,int>> cola;
        for (auto it = dic.begin(); it != dic.end(); ++it) {
            cola.push(make_pair(it->second, it->first));
        }
        vector<int> array;
        for (int j=0;j<k;j++){
            pair<int,int> actual=cola.top();
            array.push_back(actual.second);
            cola.pop();
        }
        return array;
    }
};