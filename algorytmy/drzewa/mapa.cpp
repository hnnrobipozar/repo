#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;

int main(){

    map<char, int> mapa1;

    string s1 = "0123456789ABCDEFGHIJKLMNOP!@#$%^&*()QRSTUVWXYZ";

    for(int i = 0; i < s1.size(); i++){
        mapa1[s1[i]] = s1.size()-1-i;
    }

    for(auto it = mapa1.begin(); it != mapa1.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
   

    return 0;
}