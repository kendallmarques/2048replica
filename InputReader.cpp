// credit: Yunhan Huang

#include "InputReader.h"
using namespace std;
char InputReader::read() {
    char input;
    cin >> input;
    if (input == 'w' || input == 's' || input == 'a' || input == 'd') {
        return input;
    }
    cout << "enter lower case letter 'w', 'a', 's', 'd' " << endl;
    return read();
}
