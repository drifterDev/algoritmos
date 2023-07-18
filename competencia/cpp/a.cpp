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
    int N;
    cin >> N;

    set<string> candidates;
    vector<string> votes(N);
    for (int i = 0; i < N; i++) {
        cin >> votes[i];
        candidates.insert(votes[i]);
    }

    vector<int> voteCounts(candidates.size());
    for (int i = 0; i < N; i++) {
        voteCounts[distance(candidates.begin(), candidates.find(votes[i]))]++;
    }

    int majorityThreshold = N / 2 + 1;
    set<string> eliminatedCandidates;
    while (true) {
        int minVotes = *min_element(voteCounts.begin(), voteCounts.end());
        if (minVotes >= majorityThreshold) {
            break;
        }

        auto minVotesIndex = min_element(voteCounts.begin(), voteCounts.end()) - voteCounts.begin();
        voteCounts[minVotesIndex] = INT_MAX;
        eliminatedCandidates.insert(*next(candidates.begin(), minVotesIndex));

        for (int i = 0; i < N; i++) {
            if (votes[i] == *next(candidates.begin(), minVotesIndex)) {
                for (int j = 0; j < candidates.size(); j++) {
                    if (votes[i] == *next(candidates.begin(), j)) {
                        voteCounts[j]++;
                        break;
                    }
                }
            }
        }
    }

    cout << eliminatedCandidates.size() << endl;
    for (const auto& candidate : eliminatedCandidates) {
        cout << candidate << endl;
    }

    return 0;
}
