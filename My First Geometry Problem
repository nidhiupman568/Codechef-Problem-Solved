#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    string s;
	    cin >> s;
	    
	    int onecount = 0;
	    
	    for(int i = 0;i<4;i++){
	        if(s[i]=='1')onecount++;
	    }
	    
	    if(onecount == 1){
	        cout << 11 << endl;
	    }
	    else if(onecount == 2){
	        if((s[0] == '1' && s[1] == '1') || (s[2] == '1' && s[3] == '1')){
	            cout << 21 << endl;
	        }
	        else{
	            cout << 121 << endl;
	        }
	    }
	    else if(onecount == 3){
	        cout << 231 << endl;
	    }
	    else{
	        cout << 441 << endl;
	    }
	}

}
