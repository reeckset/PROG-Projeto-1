#include <iostream>
#include <string>
#include <stdio.h>

#include "Protos.h"

using namespace std;

int main() {

	empresa semprarrolar;
	semprarrolar.readLines("linhas.txt");
	semprarrolar.readDrivers("condutores.txt");
	showMenu(semprarrolar);
	getchar();
	getchar();

	return 0;
}