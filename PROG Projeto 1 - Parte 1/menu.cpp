#include <iostream>
#include <string>
#include <stdlib.h>

#include "Protos.h"

using namespace std;

void showMenu(empresa &e) {
	while (1) {
		system("cls");
		cout << "1 - Gestao de Linhas\n\n";
		cout << "2 - Gestao de Condutores\n\n";
		cout << "3 - Visualização da Informacao\n\n";
		int selectedItem;
		cin >> selectedItem;
		system("cls");
		if (selectedItem > 0 && selectedItem <= 3) {
			switch (selectedItem) {
			case 1:
				manageLines(e);
				break;
			case 2:
				break;
			case 3:
				showInfo(e);
				break;
			}
		}
	}
}

void manageLines(empresa &e) {
	cout << "Bem vindo ao gestor de linhas. Escolha a sua opcao" << endl << endl;
	cout << "1 - Adicionar linha" << endl;
	cout << "2 - Remover linha" << endl;
	int selectedItem;
	cin >> selectedItem;
	system("cls");
	if (selectedItem > 0 && selectedItem <= 2) {
		switch (selectedItem) {
		case 1:
			addLine(e);
			break;
		case 2:
			break;
		}
	}
	getchar();
	getchar();
}

void showInfo(empresa &e) {
	vector<line> lines = e.getLines();
	vector<driver> drivers = e.getDrivers();
	vector<stop> stops = e.getStops();

	cout << "LINHAS (" << lines.size() << ")"<< endl; ///////////////// SHOW LINES
	for (unsigned int l = 0; l < lines.size(); l++) {
		cout << endl << "Linha " << lines[l].id << endl;
		cout << " " << lines[l].route[0].name;
		for (unsigned int s = 1; s < lines[l].route.size(); s++) {
			cout << " -> " << lines[l].route[s].name;
		}
		cout << endl;
	}


	cout << endl << "PARAGENS" << endl << stops[0].name;  ///////////// SHOW STOPS
	for (unsigned int s = 1; s < stops.size(); s++) {
		cout << ", " << stops[s].name;
	}
	cout << endl;

	getchar();
	getchar();
}