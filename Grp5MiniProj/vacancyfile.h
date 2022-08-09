#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stack>
#include <list>

using namespace std;


class Vacancies {
public:
	Vacancies(string VacanciesInfo);
	string getCCAName();
	int getvacancies();
	char getCCAID();
private:
	string CCAName;
	int vacancies;
	char CCAID;
};

class vacancieslist {
public:

	vacancieslist(string pathtovacancies);

	vector<Vacancies> ccavacancy;

};