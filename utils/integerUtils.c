//
// Created by Nylander on 07-05-2021.
//

#include "integerUtils.h"

int getNumDigits(int number, int base){
	int numDigits = 0;
	do {
		numDigits++;
		number /= base;
	} while(number != 0);
	return numDigits;
}

int getNumDecDigits(int number){
	return getNumDigits(number, 10);
}