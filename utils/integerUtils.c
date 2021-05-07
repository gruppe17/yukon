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

unsigned long numDigitsInRange(int start, int end, int base){
	unsigned long numDigits = 0;
	for (int i = start; i < end; ++i) {
		numDigits += getNumDigits(i, base);
	}
	/*
	if (start != 0) return numDigitsInRange(0, end, base) - numDigitsInRange(0, start, base);
	int numDigits = 1;
	while (end > 0){
		numDigits += end;
		end -= base;
	}
	 */
	return numDigits;
}