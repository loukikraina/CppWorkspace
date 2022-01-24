#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t>0){
	    int a[3],b[3],totala = 0,totalb = 0;
	    for(int i=0;i<3;i++) {
	        cin>>a[i];
	        totala += a[i];
	    }
	    for(int i=0;i<3;i++){
	        cin>>b[i];
	        totalb += b[i];
	    }
	    int i;
	    if(totala>totalb){
	        cout<<"DRAGON\n";
	    }
	    else if(totala<totalb) cout<<"SLOTH\n";
	    else{
	        for(i=0;i<3;i++){
	            if(a[i]==b[i]) continue;
	            else if(a[i]<b[i]) cout<<"SLOTH\n";
	            else cout<<"DRAGON\n";
	            break;
	        }
	        if(i==3) cout<<"TIE\n";
	    }
	    t--;
	}
	return 0;
}
