#include<bits/stdc++.h>
#include<string>
using namespace std;

int main(){
    string s1;
    getline(cin,s1);
    cout << s1 << endl;

    string s2="abc";
    cout << s2 << endl;

    cout << s2.compare(s1) << endl;
    cout << s1.empty() << endl;
    cout << s1.erase(2,4) << endl;
    cout << s1.insert(1," love") << endl;
    cout << s1.size() << endl;

    reverse(s2.begin(), s2.end());
    cout << s2 << endl;
}
