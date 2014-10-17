#include <stdio.h>
#include <stdlib.h>
#include "p18f4520.h"
#include "flash.h"

void PGD_high(){
	PGD = 1;
}

void PGD_low(){
	PGD = 0;
}

void PGC_high(){
	PGC = 1;
}

void PGC_low(){
	PGC = 0;
}