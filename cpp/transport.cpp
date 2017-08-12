#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct Transport

{
    void* buf;
    int length;
    Transport() : length(0), buf(nullptr) {};
    Transport(int len) : length(len) {
        if(len>0) {
            buf = new int [len];
        }
        else
            buf =nullptr;
    }
    ~Transport() {
        if (buf)
            delete [] static_cast<int*> (buf);
    }
};

/**/
int main() {
    vector<Transport> ships_v;
    vector<Transport> vans_v;

    cout << "please input the load of every ship, (seperate by space, finish by new line) :" << endl;
    string ships;
    getline(cin, ships);

    stringstream ss{ships};
    int load;
    try {
        while (!ss.eof()) {
            ss >> load;
            cout << load << endl;
            if (load >= 0) {
                ships_v.emplace_back(Transport(load));
            } else {
                cout << "input error, load of ship should be non negative" << endl;
                return 0;
            }
        }
    } catch (exception& ex) {
        cout << ex.what() << endl;
        return 0;
    }

    cout << "please input the load of every van, (seperate by space, finish by new line) :" << endl;
    string vans;
    getline(cin, vans);
    ss = stringstream{vans};
    try {
        while (!ss.eof()) {
            ss >> load;
            if (load >= 0) {
                vans_v.emplace_back(Transport(load));
            } else {
                cout << "input error, load of ship should be non negative" << endl;
                return 0;
            }
        }
    } catch (exception& ex) {
        cout << ex.what() << endl;
        return 0;
    }

    /* check if ok */
    int total_ships_load = 0;
    for (auto &x : ships_v) {
        total_ships_load += x.length;
    }

    int total_vans_load = 0;
    for (auto &x : vans_v) {
        total_vans_load += x.length;
    }

    if (total_vans_load >= total_ships_load) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }
}
