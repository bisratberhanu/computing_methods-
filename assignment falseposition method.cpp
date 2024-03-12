#include<iostream>
#include<cmath>
// Define function  to be solved
#define f(x) cos(x) - x * exp(x)
using namespace std;

float falsePosition(float x0, float x1, float e){
	float x, f, f1, f0;
	f1=f(x1);
	f0=f(x0);
	int counter=1;
	
	do{
		
	    x = (x0*f1 - x1*f0)/(f1 - f0);
		f = f(x);

		cout<<"Iteration-"<< counter<<":\t x = "<< x<<" and f(x) = "<< f(x)<< endl;

		if( f0 * f < 0){
			x1 = x;
			f1 = f;
		}	else{
			x0 = x;
			f0 = f;
		}
	   counter+= 1;

	 }while( fabs(f(x1)) > e);
	 cout<<endl<<"the number of iteration is "<<counter-1<<endl;
	 
	return x;
}

int main(){
		float x0, x1, e, f0, f1;
		cout<<"   the false postion method  "<<endl;

     
    while(true){
	
	cout<<"Enter first guess: "<<endl;
    cin>>x0;
    cout<<"Enter second guess: ";
    cin>>x1;
    cout<<"Enter tolerable error: ";
    cin>>e;
    
    f0 = f(x0);
	f1 = f(x1); 
    if( f0 * f1 > 0.0){
		cout<<"Incorrect Initial Guesses."<< endl;}
	else{
		break;}
	
	}
	cout<<endl<<"the two values are f(0)= "<<f0<<" and f(1)= "<<f1<<endl;
	
	 cout<< endl<<"answer  is: "<< falsePosition(x0,x1,e)<<endl;

	return 0;
}
