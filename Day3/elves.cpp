#include <vector>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

void readFileIntoArray(vector<vector<char>>& myArray) {
    ifstream file("input.txt");
    if (!file.is_open()) {
        cout << "File unable to open" << endl;
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
    // cout << "isNum: " << input << endl;
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
    cout << "isSymbol called" << endl;
    return (!isNum(input) && (input != '.'));
}

int collectFullNumber(vector<vector<char>>& myArray, vector<vector<bool>>& checkedArray, unsigned int row, unsigned int found) {
    cout << "Starting collectFullNumber()" << endl;
    cout << "hehe xd: " << myArray[row][found] << endl;

    /*
    bool lefting = true;
    while (lefting) {
        if (found == 0) {
            lefting = false; 
            break; 
        }
        if (isNum(myArray[row][found - 1])) { found--; }
        else { lefting = false; }
    }
    */
    while (found > 0 && isNum(myArray[row][found - 1])) {
        found--;
    }

    cout << "hoho: " << myArray[row][found] << endl;
    /*
    bool righting = true;
    string myNum = "";
    while (righting) {
        // TODO: Check out of bounds
        myNum += myArray[row][found];
        checkedArray[row][found] = true;
        if (found ++ > myArray[0].size() - 1) {
            righting = false;
            break;
        }
        if (isNum(myArray[row][found++])) { found ++; }
        else { righting = false; }
    }
    */
    string myNum = "";
    while (found < myArray[row].size() && isNum(myArray[row][found])) {
        myNum += myArray[row][found];
        checkedArray[row][found] = true;
        found++;
    }
    cout << "Row: " << row << endl;
    cout << "Column: " << found << endl;
    cout << "Number Found: " << myNum << endl;
    int myResult = stoi(myNum);
    return myResult;
}


int solve_elves() {
    // create array of characters from text
    vector<vector<char>> myArray;
    readFileIntoArray(myArray);

    vector<vector<bool>> checkedArray;
    createBoolArray(checkedArray, myArray);

    int length = myArray.size();
    int width = myArray[0].size();

    int sum = 0;
    cout << "Starting iterating" << endl;
    for (int y = 0; y < length; y++) {
         for (int x = 0; x < width; x++) {
            char currentChar = myArray[y][x];
            if (isSymbol(currentChar)) {
                cout << "Symbol found" << endl;
                // Check one character radius around symbol now
                // 0, 0 is the symbol so skip
                bool leftClear = false;
                bool rightClear = false;
                bool topClear = false;
                bool botClear = false;
                if (x != 0) {
                    leftClear = true;
                }
                if (x < width - 1) {
                    rightClear = true;
                }
                if (y != 0) {
                    topClear = true;
                }
                if ( y < length - 1) {
                    botClear = true;
                }
                // Check Left of symbol
                if (leftClear) {
                    if (isNum(myArray[y][x - 1]) && !checkedArray[y][x - 1]) {
                        cout << "Collecting to the left" << endl;
                        sum += collectFullNumber(myArray, checkedArray, y, x - 1);
                    }
                    // Check Top Left of symbol
                    if (topClear) {
                        if (isNum(myArray[y - 1][x - 1]) && !checkedArray[y - 1][x - 1]) {
                            cout << "Collecting to the top left" << endl;
                            sum += collectFullNumber(myArray, checkedArray, y - 1, x - 1);
                        }
                    }
                    // Check Bot Left of symbol
                    if (botClear) {
                        if (isNum(myArray[y + 1][x - 1]) && !checkedArray[y + 1][x - 1]) {
                            cout << "Collecting to the bottom left" << endl;
                            sum += collectFullNumber(myArray, checkedArray, y + 1, x - 1);
                        }
                    }
                }
                
                // Check Right of symbol
                if (rightClear) {
                    if (isNum(myArray[y][x + 1]) && !checkedArray[y][x + 1]) {
                        cout << "Collecting to the right" << endl;
                        sum += collectFullNumber(myArray, checkedArray, y, x + 1);
                    }
                    // Check Top Right of symbol
                    if (topClear) {
                        if (isNum(myArray[y - 1][x + 1]) && !checkedArray[y - 1][x + 1]) {
                            cout << "Collecting to the top right" << endl;
                            sum += collectFullNumber(myArray, checkedArray, y - 1, x + 1);
                        }
                    }
                    // Check Bot Right of symbol
                    if (botClear) {
                        if (isNum(myArray[y + 1][x + 1]) && !checkedArray[y + 1][x + 1]) {
                            cout << "Collecting to the bottom right" << endl;
                            sum += collectFullNumber(myArray, checkedArray, y + 1, x + 1);
                        }
                    }
                }
                
                // Check Top of symbol
                if (topClear) {
                    if (isNum(myArray[y - 1][x]) && !checkedArray[y - 1][x]) {
                        cout << "Collecting to the top" << endl;
                        sum += collectFullNumber(myArray, checkedArray, y - 1, x);
                    }
                }

                // Check Bot of symbol
                if (botClear) {
                    if (isNum(myArray[y + 1][x]) && !checkedArray[y + 1][x]) {
                        cout << "Collecting to the bottom" << endl;
                        sum += collectFullNumber(myArray, checkedArray, y + 1, x);
                    }
                }

            }
            cout << "Running total: " << sum << endl;
        }
    }
    cout << "Here is the result: " << sum << endl;
    return 0;
}




int main() {
    solve_elves();
}