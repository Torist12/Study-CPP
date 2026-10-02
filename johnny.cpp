#include <iostream>
#include <cmath>
using namespace std;

int main(){
	double a, b, c, x1, x2, delta;

	cout<<"a, b, c?"<<endl;
	cin>>b>>c, 
	
	delta = b*b-4*a*c; 
	
	x1=(-b+sqrt(delta))/(2*a);
	
	x2=(-b-sqrt(delta))/(2*a);
	cout<<"\n \t delta="<<delta<<"\n\t x1="<<x1<<"e x2="<<x2<<endl;

return 0;
}

	
