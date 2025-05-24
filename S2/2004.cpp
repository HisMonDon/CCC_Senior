#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

struct Yodeller {
    int id;
    int score;
    int worst_rank;

    Yodeller(int id) : id(id), score(0), worst_rank(1) {}
};

bool compareYodellers(const Yodeller& a, const Yodeller& b) {
    if (a.score != b.score) {
        return a.score > b.score;
    }
    return a.id < b.id;
}

int calculate_rank(const vector<Yodeller>& yodellers, int yodeller_index) {
    int rank = 1;
    for (size_t i = 0; i < yodellers.size(); ++i) {
        if (i != yodeller_index && yodellers[i].score > yodellers[yodeller_index].score) {
            rank++;
        }
    }
    return rank;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<Yodeller> yodellers;
    for (int i = 1; i <= n; ++i) {
        yodellers.emplace_back(i);
    }

    for (int round = 0; round < k; ++round) {
        vector<int> round_scores(n);
        for (int i = 0; i < n; ++i) {
            cin >> round_scores[i];
            yodellers[i].score += round_scores[i];
        }

        for (int i = 0; i < n; ++i) {
            int current_rank = calculate_rank(yodellers, i);
            yodellers[i].worst_rank = max(yodellers[i].worst_rank, current_rank);
        }
    }

    sort(yodellers.begin(), yodellers.end(), compareYodellers);

    int top_score = yodellers[0].score;
    for (const auto& y : yodellers) {
        if (y.score == top_score) {
            cout << "Yodeller " << y.id << " is the TopYodeller: score " << y.score << ", worst rank " << y.worst_rank << endl;
        } else {
            break;
        }
    }

    return 0;
}
