#include <iostream>
#include<cmath>
// function is defined below
#define   f(x)  x*x*x - pow(2,x) - 5
using namespace std;

void secant(float x0, float x1, float e, int N){
	float f0, f1, x2,f2;
	
	int counter=1;
	do{
	    f0 = f(x0);
		f1 = f(x1);
		if(f0 == f1){
			cout<<" Error f(0) and f(1) has the same value.";
			break;
		}

		x2 = x1 - (x1 - x0) * f1/(f1-f0);
		f2 = f(x2);

		cout<<"Iteration-"<< counter <<":     x2 = "<< x2<<" and f(x2) = "<< f(x2)<< endl;

		x0 = x1;
		f0 = f1;
		x1 = x2;
		f1 = f2;
		counter+=1;
		if(counter > N){
			cout<<"doesn't converge on given amount of iteration"<<endl;
			return ;// return statment used to break out of the loop
			
		}
	}while(fabs(f2)>e);
	 cout<<endl<< " number of iteration is "<<counter-1<<endl;
	 
	cout<< endl<<"the answer  is: "<< x2<<endl; // the value of x2 is returned so it can be printed as the answer in the main function
}
int main() {
	int N;  // the number of iteration is defined here
	float x0, x1, e; // two intitial values and tolerance are defined here 
	cout<<endl<<"           the secant method         "<<endl;
	cout<<"Enter tolerable error: ";
	 cin>>e;
	 cout<<"Enter maximum iteration: ";
	 cin>>N;
	  cout<<"Enter initial guess: ";
	 cin>>x0;
	 cout<<"Enter second guess: ";
	 cin>>x1;
	 
	 
	secant(x0,x1,e,N);
	 
	return 0;
	
}
