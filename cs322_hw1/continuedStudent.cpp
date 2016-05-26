#include "continued.h"
//

ContinuedFraction *getCFlargerThanOne(unsigned int b, unsigned int a) {
  // your code here
	if (a==0){
		return nullptr;
	}
	int q = b/a;
	int r = b%a;
	struct ContinuedFraction *cf = new ContinuedFraction;
	(*cf).head = q;
	(*cf).tail= getCFlargerThanOne(a,r);
	return cf;
 }
ContinuedFraction *getCF(unsigned int b, unsigned int a) {
	if (b>a)
	{	
		return getCFlargerThanOne(b,a);
	}
	else
	{
		ContinuedFraction *fr;
		fr = new ContinuedFraction;
		fr -> head = 0;
		fr -> tail = getCFlargerThanOne(a,b);
		return fr;
	}

}

ContinuedFraction *getCF(unsigned int head, ContinuedFraction *fixed, ContinuedFraction *period) {
	ContinuedFraction *toRet = new ContinuedFraction;
	toRet->head = head;
	toRet->tail= new ContinuedFraction;
	ContinuedFraction *last = toRet->tail;
	//initial
	last->head = fixed->head;
	while ( fixed->tail != nullptr) {
			last->tail = new ContinuedFraction;
			last = last->tail;
			//see next fixed tail
			fixed = fixed->tail;
			//
			last->head = fixed->head;
		}
	last->tail = new ContinuedFraction;
	last->tail = period;
	// go the last and append period back 
	while (last->tail !=nullptr){
		last = last->tail;
	}
 	last->tail = period;
	return toRet;
}

Fraction getApproximation(ContinuedFraction *fr, unsigned int n) {
  // your code here
	if (n==1) {
		Fraction f;
		f.numerator=fr->head;
		f.denominator= 1;

		return f;
	}
	int h =fr->head;
	//previous
	n--;
	Fraction fp = getApproximation(fr->tail,n);
	Fraction f;
	f.numerator = h*fp.numerator+fp.denominator;
	f.denominator = fp.numerator;
	return f;
}
//q1
unsigned int gcd(unsigned int a,unsigned int b)
{
	if (a == 0){
	    	return b;
	    }
    if (a>b) {
       return gcd(b,a);
    }
    else
    {
       int r = b%a;
       return gcd(r,a);
    }

}
//q2
unsigned int gcdFaster(unsigned int a, unsigned int b){
	if(a==1||b==1){
    	return 1;
    }
	if (a%2==0&&b%2==0){
		return 2*gcdFaster(a/2,b/2);
	}
	else if(a%2==0&&b%2==1){
		return gcdFaster(a/2,b);
	}
	else if(a>b&&(a%2==1&&b%2==1)){
			return gcdFaster(((a-1)/2-(b-1)/2),b);
	}
	else{
		return gcdFaster(b,a);
	}

}

