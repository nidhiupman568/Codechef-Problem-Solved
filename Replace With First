#include <bits/stdc++.h>
using namespace std;

bool checkPossible(string s1, string s2) {
    int fromLeft = 0;
    int fromRight = 0;
    for(int i=0;i<s1.length() && i < s2.length();i++) {
        if(s1[i] == s2[i]) {
            fromLeft++;
        }   
        else {
            break;
        }
    }
    
    int j = s1.length()-1;
    for(int i=s2.length()-1;i>=0; i--) {
        if(s1[j] == s2[i]) {
            fromRight++;   
        }
        else {
            break;
        }
        j--;
    }

    if(fromLeft+fromRight >= s2.length()) {
        return true;        
    }

    return false;
}

int main() {
    int t;
    cin>>t;
    int len1, len2;
    string s1, s2;
    while(t--) {
        cin>>len1>>len2;
        cin>>s1>>s2;
        if(s1[0] != s2[0]) {
           cout<<-1<<endl;
           continue;
        }
        if(s1 == s2) {
            cout<<0<<endl;
            continue;
        }

        if(s1.length() > s2.length()) {
            if(checkPossible(s1,s2)) {
                cout<<1<<endl;
                continue;
            }
        }
        else if(s2.length() > s1.length()) {
            if(checkPossible(s2, s1)) {
                cout<<1<<endl;
                continue;
            }
        }
        cout<<2<<endl;
    }
    return 0;
}
