#include <vector>
#include <unordered_set>

using namespace std;

int checkForWinners(vector<int> winners, vector<int> chosen) {
    int result = 0;
    unordered_set<int> winnerSet(winners.begin(), winners.end());

    for (int num : chosen) {
        if (winnerSet.find(num) != winnerSet.end()) {
            result++;
        }
    }

    return result;
}

vector<int> readWinners() {

}

vector<int> readChosen() {

}

void solveDay4() {
    vector<int> winners;
    vector<int> chosen;
}



int main() {
    // Line by line:
        // Read up to ':'
        // then collect the next 10 1-2 digit numbers, we will call these "winners"
        // then collect the chosen numbers "chosen"
        // Iterate over chosen numbers and see if they appear in the winners list
    solveDay4();
    

}