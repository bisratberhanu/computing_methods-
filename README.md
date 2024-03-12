# Computing Methods

## secant method for finding roots of a function
``` c++ 
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
```
The main function starts by printing a title, then prompts the user to input a tolerable error, maximum number of iterations, and two initial guesses.

These inputs are then passed to the secant function.

In the secant function, a loop begins which will continue until either the absolute value of f(x2) is less than the tolerable error e, or the number of iterations exceeds N.

In each iteration, the function f(x) (which is defined as x^3 - 2^x - 5) is evaluated at x0 and x1, and these values are stored in f0 and f1 respectively.

If f0 and f1 are equal, an error message is printed and the loop is broken.

Otherwise, a new guess x2 is calculated using the formula for the Secant Method, and f(x2) is calculated.

The values of x0, f0, x1, and f1 are updated for the next iteration, and the counter is incremented.

If the number of iterations exceeds N, a message is printed and the function returns.

Once the loop ends (either due to convergence or reaching the maximum number of iterations), the function prints the number of iterations and the final estimate for the root.

The main function then ends and returns 0.


``` c++
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
```

This C++ code is implementing the False Position (or Regula Falsi) method, which is a root-finding algorithm that uses a succession of roots of secant lines combined with the bisection method to approximate the roots of a function.

Here's a step-by-step breakdown:

The main function starts by printing a title, then enters a loop where it prompts the user to input two initial guesses and a tolerable error.

It calculates the function values at the initial guesses. If the product of these two function values is greater than 0, it means the initial guesses do not bracket a root, so it prints an error message and asks for new guesses. This continues until valid initial guesses are provided.

Once valid initial guesses are obtained, it prints the function values at these points and then calls the falsePosition function with these guesses and the tolerable error.

In the falsePosition function, a loop begins which will continue until the absolute value of the function at x1 is less than the tolerable error.

In each iteration, it calculates a new guess x using the formula for the False Position method, and calculates the function value at this point.

If the product of the function value at x0 and the function value at x is less than 0, it means the root lies between x0 and x, so it updates x1 and f1. Otherwise, it updates x0 and f0.

The counter is incremented in each iteration.

Once the loop ends, it prints the number of iterations and returns the final estimate for the root.

The main function then prints this root and ends.





## Contributing

If you want to contribute to this project and make it better with new ideas, your pull request is very welcomed. If you find any issue just put it in the repository issue section or contact the owner at bisratbnegus@gmail.com

