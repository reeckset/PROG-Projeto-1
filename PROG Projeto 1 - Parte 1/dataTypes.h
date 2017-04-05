#pragma once

#include <vector>
#include <string>
#include <iostream>

using namespace std;



struct stop {
	unsigned int id; //INDEX OF THE STOP IN THE STOPS ARRAY OF THE COMPANY
	string name;
};

struct line {
	unsigned int id;
	unsigned int freq; //frequencia de autocarros na linha
	vector<stop> route; //Sequencia de paragens
	vector<unsigned int> intervals; //tempos entre as paragens
};

struct driver {
	string name;
	unsigned int id;
	unsigned int maxHoursPerShift; //Máximo número de horas que um turno pode ter
	unsigned int maxHoursPerWeek; //Máximo número de horas semanais que um condutor pode trabalhar
	unsigned int minHoursOfRest; //Minimo número de horas de descanso entre turnos
};

class empresa{
	vector<line> lines;
	vector<stop> stops;
	vector<driver> drivers;

	public:
	void readLines(string filepath);
	void readDrivers(string filepath);
	vector<driver> getDrivers() { return drivers; }
	vector<line> getLines() { return lines; }
	vector<stop> getStops() { return stops; }

	stop addIfNotInStops(stop curStop);
	void removeLine(unsigned int i) { lines.erase(lines.begin() + i); }
	void addLine(line l) { lines.push_back(l); std::cout << "added line. Total of lines: " << lines.size() << endl; }
};