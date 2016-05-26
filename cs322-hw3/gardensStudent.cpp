#include "gardens.h"
#include <stack>
#include <iostream>
#include <math.h>

 /* 0-credit */
Fraction ContinuedFraction::getApproximation(unsigned int k) const {
    //TODO
}


// TODO : RationalCF::RationalCF(Fraction f) ...

RationalCF::~RationalCF() {
    //TODO
}

/* QUESTION 3*/

cf_int PeriodicCF::next() const {
    //TODO
}

bool PeriodicCF::hasNoMore() const {
    //TODO
}

void PeriodicCF::resetIterator() const {
    //TODO
}

PeriodicCF::~PeriodicCF() {
    //TODO
}



/* QUESTION 4*/

//TODO : MagicBoxCF::MagicBoxCF(ContinuedFraction const* f, unsigned long aParam, unsigned long bParam) ...

cf_int MagicBoxCF::next() const {
    //TODO
}

bool MagicBoxCF::hasNoMore() const {
    //TODO
}

void MagicBoxCF::resetIterator() const {
    //TODO
}

MagicBoxCF::~MagicBoxCF() {
    //TODO
}



/* QUESTION 5*/

ostream &operator<<(ostream& outs, const ContinuedFraction &cf) {
    //TODO
}


/* QUESTION 6 */

float Flower::getAngle(unsigned int k) const {
    //TODO
}

//TODO : Flower::Flower(const ContinuedFraction *f, unsigned int apxLengthParam) ...

Seed Flower::getSeed(unsigned int k) const {
    //TODO
}

vector<Seed> Flower::getSeeds(unsigned int k) const {
    //TODO
}


Flower::~Flower() {
    //TODO
}

/* QUESTION 7*/

void Flower::writeMVGPicture(ostream &out, unsigned int k, unsigned int scale_x, unsigned int scale_y) const {
    //TODO
}





