#include <iostream>
#include <string>
#include <sstream>


using namespace std;


int main () {

    string s("1.0 1.1 1.2 1.3\n \
              2.0 2.1 2.2 2.3\n" );
    istringstream iss(s);
    cout << "s: " << s << endl;
    double t = 0;
    int count = 5;
    while(iss >> t){
        cout << t << endl;
    }
    return 0;
}

