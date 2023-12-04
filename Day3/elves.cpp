#include <vector>
#include <fstream>
#include <string>
#include <iostream>

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

int collectFullNumber(vector<vector<char>>& myArray, vector<vector<bool>>& checkedArray, int row, int found) {
    string myNum;
    // get leftest
    bool lefting = true;
    while (lefting) {
        if (found == 0) {
            lefting = false; 
            break; 
        }
        if (isNum(myArray[row][found--])) { found --; }
    }

    bool righting = true;
    while (righting) {
        if (isNum(myArray[row][found])) {
            myNum += myArray[row][found];
            found ++;
            checkedArray[row][found] = true;
        }
        else {
            righting = false;
        }
    }
    cout << "Number Found: " << myNum << endl;
    return stoi(myNum);
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
            if (isNum(currentChar)) {
                if (!checkedArray[y][x]) {
                    int myNum = collectFullNumber(myArray, checkedArray, y, x);
                    cout << "My number: " << myNum << endl;
                }
            }
        }
    }

    return 0;
}




int main() {
    // solve_elves();
}