#include<iostream>
using namespace std;
int main(){
	int m,rem,r;
	int q=0;
	cin>>m;
	if(m>=10){
		q+=m/10;
		rem=m%10;
		if(rem>=5){
			q+=rem/5;
			r=rem%5;
			q+=r;
			cout<<q;
		}
		else{
			q+=rem;
			cout<<q;
		}
	}
	else if(m>=5 && m<10){
		cout<<1+(m%5);
	}
	else{
		cout<<m;
	}
return 0;
}
			
