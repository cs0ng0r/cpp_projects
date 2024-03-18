#include <iostream>
#include <map>

using namespace std;

string simplifyCommand(string command) {
    map<char, int> counts;
    for (char letter : command) {
        counts[letter]++;
    }
    string simplifiedCommand;
    for (auto& pair : counts) {
        simplifiedCommand.append(pair.second, pair.first);
    }
    return simplifiedCommand;
}

string simplifyPath(string path) {
    string simplifiedPath;
    int x = 0, y = 0;
    for (char direction : path) {
        if (direction == 'E') y++;
        else if (direction == 'D') y--;
        else if (direction == 'K') x++;
        else if (direction == 'N') x--;
    }
    if (x > 0) simplifiedPath.append(x, 'K');
    else if (x < 0) simplifiedPath.append(-x, 'N');
    if (y > 0) simplifiedPath.append(y, 'E');
    else if (y < 0) simplifiedPath.append(-y, 'D');
    return simplifiedPath;
}

int main() {
    string path;
    cout << "Kerem a robot parancsait:: ";
    cin >> path;


    string simplifiedPath = simplifyPath(path);
    cout << "EgyszerűsItett parancs: " << simplifiedPath << endl;

    return 0;
}
