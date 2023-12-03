#include <vector>
#include <fstream>
#include <string>

using namespace std;

void readFileIntoArray(vector<vector<char>>& myArray) {
    ifstream file("input.txt");
    if (!file.is_open()) {
        // File is unable to open
    }

    string line;
    while (getline(file, line)) {
        vector<char> charLine(line.begin(), line.end());
        myArray.push_back(charLine);
    }
    file.close();
}

void createBoolArray(vector<vector<bool>>& checkedArray,  vector<vector<char>>& myArray) {
    checkedArray.reserve(myArray.size());

    for (const auto& row : myArray) {
        vector<bool> boolRow(row.size(), false);
        checkedArray.push_back(boolRow);
    }
}

bool isNum(char input) {
    return (input == '0' ||
            input == '1' ||
            input == '2' ||
            input == '3' ||
            input == '4' ||
            input == '5' ||
            input == '6' ||
            input == '7' ||
            input == '8' ||
            input == '9' );
}

bool isSymbol(char input) {
    return (!isNum(input) && !(input == '.'));
}


int solve_elves() {
    // create array of characters from text
    vector<vector<char>> myArray;
    readFileIntoArray(myArray);

    vector<vector<bool>> checkedArray;
    createBoolArray(checkedArray, myArray);

    int length = myArray.size();
    int width = myArray[0].size();

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < length; y++) {
            char currentChar = myArray[y][x];
        }
    }
}




int main() {
    // solve_elves();
}