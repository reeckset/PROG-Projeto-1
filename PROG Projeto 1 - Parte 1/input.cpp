#include <fstream>
#include <string>
#include <vector>
#include <iostream>

#include "dataTypes.h"

using namespace std;

void empresa::readLines(string filepath) {
	ifstream file;
	file.open(filepath);
	string curLine;
	while (getline(file, curLine)) {

		line l;

		//Get line id
		unsigned int id = stoi(curLine.substr(0, curLine.find_first_of(';')));
		curLine.erase(0, curLine.find_first_of(';') + 1);

		//Get line freq
		unsigned int freq = stoi(curLine.substr(0, curLine.find_first_of(';')));
		curLine.erase(0, curLine.find_first_of(';') + 1);

		//Get line route
		vector<stop> route;
		string routeSrc = curLine.substr(0, curLine.find_first_of(';'));
		curLine.erase(0, curLine.find_first_of(';') + 1);
		while (1) {
			stop p;
			p.name = routeSrc.substr(routeSrc.find_first_not_of(' '), routeSrc.find_first_of(',') - 1);
			p = addIfNotInStops(p);
			route.push_back(p);
			cout << endl;
			if (routeSrc.find(',') == routeSrc.npos) break;
			else routeSrc.erase(0, routeSrc.find_first_of(',') + 1);
		}
		//Get times
		vector<unsigned int> intervals;
		while(1) {
			intervals.push_back(stoi(curLine.substr(curLine.find_first_not_of(' '), curLine.find_first_of(',') - 1)));
			if (curLine.find(',') == routeSrc.npos) break;
			else curLine.erase(0, curLine.find_first_of(',') + 1);
		}

		l.id = id;
		l.freq = freq;
		l.route = route;
		l.intervals = intervals;
		lines.push_back(l);
	}
}

void empresa::readDrivers(string filepath) {
	ifstream file;
	file.open(filepath);
	string curLine;
	while (getline(file, curLine)) {

		driver d;

		//Get line id
		unsigned int id = stoi(curLine.substr(0, curLine.find_first_of(';')));
		curLine.erase(0, curLine.find_first_of(';') + 1);

		//Get line freq
		string name = curLine.substr(0, curLine.find_first_of(';'));
		curLine.erase(0, curLine.find_first_of(';') + 1);

		//Get driver's maximum work hours per shift
		unsigned int maxHoursPerShift = stoi(curLine.substr(0, curLine.find_first_of(';')));
		curLine.erase(0, curLine.find_first_of(';') + 1);

		//Get driver's maximum work hours per week
		unsigned int maxHoursPerWeek = stoi(curLine.substr(0, curLine.find_first_of(';')));
		curLine.erase(0, curLine.find_first_of(';') + 1);

		//Get driver's minimum rest hours
		unsigned int minHoursOfRest = stoi(curLine);

		d.id = id;
		d.name = name;
		d.maxHoursPerShift = maxHoursPerShift;
		d.maxHoursPerWeek = maxHoursPerWeek;
		d.minHoursOfRest = minHoursOfRest;

		drivers.push_back(d);
		
	}
}


stop empresa::addIfNotInStops(stop curStop) {
	for (unsigned int i = 0; i < stops.size(); i++) { //FOR EACH STOP ALREADY IN STOPS
		if (stops[i].name == curStop.name) return stops[i];
	}
	curStop.id = stops.size();
	stops.push_back(curStop);
	return curStop;
}