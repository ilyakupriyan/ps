#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <conio.h>

using namespace std;

int main() {

    map <string, int> mymap;
    string line, word;

    cout << "String: ";

    getline(cin, line);

    int pos = line.find(' ');
    while (pos != string::npos) {
        word = line;
        word.erase(pos);
        if (mymap.find(word) == mymap.end())
        {
            mymap.insert(pair<string, int> (word, 1));
        }
        else
        {
            mymap[word]++;
        }
        line.erase(0, pos+1);
        pos = line.find(' ');
    }

    map <string, int>::iterator it = mymap.begin();

    for (int i = 0; it != mymap.end(); it++, i++)
    {
        cout << i << "  " << it->first << ": " << it->second << endl;
    }
    _getch();
    return 0;
}