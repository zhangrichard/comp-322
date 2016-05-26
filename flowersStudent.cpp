#include "flowers.h"
#include <math.h>
int spitSqrt8(int index){

	if (index ==0) {
		return 2;
	}
	else if ((index -1)%2 ==0) {
		return 1;
	}
	else {
		return 4;
	}
}
ContinuedFraction fractionalPart(ContinuedFraction &f){
	f.fixedPart[0]=0;
	return f;
}



unsigned int spitEulerSquare(unsigned int index) {
	// TODO : add code here
	if (index ==0) {
		return 7;
	}
	if (index ==1) return 2;
	if (index % 5 ==2||index % 5 ==3) return 1;
	if (index % 5 == 4) return (index/5+1)*3;
	if(index % 5 == 0) return (index/5-1)*12+18;
	if (index % 5 ==1)return (index/5-1)*3+5;

	//	7 2 1 1 3 18 5 1 1 6 30 8 1 1 9 42 11 1
	//	0 1 2 3 4 5  6 7 1 6 30 8 1 1 9 42 11 1

}

Fraction getApproximation(ContinuedFraction &fr, unsigned int n){
	//    // TODO : add code here
	auto k = fr.fixedPart.size();
	auto m = fr.periodicPart.size();
	Fraction f;
	Fraction fp;
	if (n<=k){
		fp.numerator = fr.fixedPart[n];
	}else{
		fp.numerator = fr.periodicPart[(n-k)%m];
	}
	fp.denominator = 1;
	for (int i = n-2; i>=0; i--) {
		int h;
		if (i<k){
			h = fr.fixedPart[i];
		}
		else {
			h = fr.periodicPart[(n-i)%m];
		}
		f.numerator=h*fp.numerator+fp.denominator;
		f.denominator= fp.numerator;
		fp = f;
	}
	return fp;

}


double getAngle(ContinuedFraction &theta, int k) {
	// TODO : add code here
	ContinuedFraction *newCf = new ContinuedFraction;
	*newCf = theta;
	ContinuedFraction fractTheta = fractionalPart(*newCf);
	auto n = getApproximation(fractTheta,7);
	n.numerator = n.numerator*k % n.denominator;
	double result = 2*M_PI*n.numerator/n.denominator;
	return result;
}

Seed getSeed(ContinuedFraction &theta, int k) {
	// TODO : add code here
	Seed result;
	result.x = sqrt(k/M_PI)*cos(getAngle(theta,k));
	result.y = sqrt(k/M_PI)*sin(getAngle(theta,k));
	return result;

}

void pushSeed(std::list<Seed> &flower, ContinuedFraction &theta) {
	static int k = 0;
	// TODO : add code here
	flower.push_back(getSeed(theta,k));
	k++;
}

int spitNextMagicBox(MagicBox &box) {
	// TODO : add code here
	int x = box.indexInBoxedFraction;

	if(box.k == 0 && box.l ==0){
		return -1;
	}
	else if ((box.k!=0&& box.l!=0)&&(box.i/box.k) == (box.j/box.l)){
		int q = (box.i/box.k);
		MagicBox newBox;
		newBox = box;
		newBox.i = box.k;
		newBox.j = box.l;
		newBox.k = box.i - box.k * q;
		newBox.l = box.j - box.l*q;
		box = newBox;
		return q;
	}
	else{
		int n = box.boxedFraction.fixedPart.size();
		int m = box.boxedFraction.periodicPart.size();
		int p  =  x<=n-1 ? box.boxedFraction.fixedPart[x]:box.boxedFraction.periodicPart[(x-n)%m];
		MagicBox newBox ;
		newBox = box;
		newBox.i = box.j;
		newBox.j = box.i+box.j*p;
		newBox.k = box.l;
		newBox.l = box.k + box.l*p;
		newBox.indexInBoxedFraction = x+1;
		box = newBox;

		if (box.boxedFraction.periodicPart.empty()&&box.indexInBoxedFraction>=box.boxedFraction.fixedPart.size())
		{
			box.i = box.j;
			box.k = box.l;
			return spitNextMagicBox(box);
		}
		else {
			return spitNextMagicBox(box);
		}
	}

}

ContinuedFraction getCFUsingMB(ContinuedFraction &f, int a, int b, int length) {
	// TODO : add code here
	MagicBox box ;
	box.boxedFraction = f;
	box.i = a;
	box.j = b;
	box.k = 1;
	box.l = 0;
	box.indexInBoxedFraction = 0;
	ContinuedFraction cf;
	int x = 0;
	int k=spitNextMagicBox(box);
	while(x<length&&k!=-1){
		cf.fixedPart.push_back(k);
		k = spitNextMagicBox(box);
		x++;
	}
	return cf;
}
