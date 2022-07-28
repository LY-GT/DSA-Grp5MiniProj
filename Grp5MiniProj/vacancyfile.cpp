#include "vacancyfile.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stack>
#include <list>
#include "SpStudent.h"


using namespace std;

Vacancies::Vacancies(string VacanciesInfo) {
	stringstream VacancyStream(VacanciesInfo);
	VacancyStream >> CCAName;
	VacancyStream >> CCAID;
	VacancyStream >> vacancies;
}

string Vacancies::getCCAName() 
{
	return CCAName;
}
char Vacancies::getCCAID() 
{
	return CCAID;
}
int Vacancies::getvacancies() 
{
	return vacancies;
}
//Reading the file
vacancieslist::vacancieslist(string pathtovacancies) {
	ifstream vacancypath(pathtovacancies);

	string vacancycontents;

	while (!vacancypath.eof()){
		getline(vacancypath, vacancycontents);

		Vacancies v(vacancycontents);
		ccavacancy.push_back(v); //storing vacancies.txt into vector
		//cout << ccavacancy.size() << endl;
	}
	vacancypath.close();
}

//Check winchoice