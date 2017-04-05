#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

#include "dataTypes.h"

using namespace std;

bool checkIfLineExists(empresa &e, unsigned int id);

void removeLine(empresa &e, unsigned int lineId){
	for (unsigned int i = 0; i < e.getLines().size(); i++) {
		if (e.getLines()[i].id == lineId) {
			e.removeLine(i);
		}
	}
}

void addLine(empresa &e) {
	unsigned int lineId;
	unsigned int freq;
	unsigned int stopsSize;
	vector<stop> stops;
	vector<unsigned int> intervals;
	
	do {
		cout << "Insira o id da linha: ";
		cin >> lineId;
	} while (checkIfLineExists(e, lineId));
	cout << endl << "Insira a frequencia de autocarros nessa linha (em minutos): ";
	cin >> freq;
	cout << endl << "Insira o numero de paragens da linha: ";
	cin >> stopsSize;
	for (unsigned int i = 0; i < stopsSize; i++) {
		stop s;
		cout << endl << "Insira o nome da paragem: " << i + 1 << ":";
		string name;
		getline(cin, name);
		s.name = name;
		s = e.addIfNotInStops(s);
		stops.push_back(s);
		getchar();
	}
	getchar();
	getchar();
	for (unsigned int i = 0; i < stopsSize - 1; i++) {
		unsigned int interval;
		cout << endl << "Insira o intervalo entre a " << i + 1 << "a e a " << i + 2 << "a paragens: ";
		cin >> interval;
		intervals.push_back(interval);
		getchar();
	}

	line l;
	l.id = lineId;
	l.freq = freq;
	l.route = stops;
	l.intervals = intervals;
	e.addLine(l);
	cout << endl << "Linha adicionada com sucesso!";
	getchar();
	getchar();
}


bool checkIfLineExists(empresa &e,unsigned int id) {
	bool lineAlreadyExists = false;
	for (unsigned int i = 0; i < e.getLines().size(); i++) {
		if (e.getLines()[i].id == id) {
			//LINE ALREADY EXISTS
			lineAlreadyExists = true;
		}
	}
	if (lineAlreadyExists) cout << endl << "Ja existe uma linha com esse id." << endl;
	return lineAlreadyExists;
}