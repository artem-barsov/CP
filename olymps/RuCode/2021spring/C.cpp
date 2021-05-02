#include <iostream>
#include <string>

using namespace std;

int main() {
    unsigned answer  = 0;
    for (int i = 29; i >= 0; --i) {
        unsigned req = (1u << i);
        cout << "? " << req << endl;
        int b = 0; cin >> b;
        if (b <= 0) {
        	// case if bit true
            answer  |= req;
        }
    }
    cout << "! " << answer << endl;
}
