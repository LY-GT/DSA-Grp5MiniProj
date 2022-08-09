#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stack>
#include <list>
#include "SpStudent.h"
#include "vacancyfile.h"

using namespace std;

student_class::student_class(string studentinformation)
{
	stringstream studentin(studentinformation);
	studentin >> first_name;
	studentin >> last_name;
	studentin >> GPA;
	studentin >> choice1;
	studentin >> choice2;
	studentin >> choice3;
	studentin >> winchoice1;
	studentin >> winchoice2;
	studentin >> winchoice3;

}

string student_class::getFirst_name()
{
	return first_name;
}

string student_class::getLast_name()
{
	return last_name;
}

char student_class::getChoice1()
{
	return choice1;

}

char student_class::getChoice2()
{
	return choice2;

}

char student_class::getChoice3()
{
	return choice3;

}

char student_class::getWinchoice1()
{
	return winchoice1;
}

char student_class::getWinchoice2()
{
	return winchoice2;
}

char student_class::getWinchoice3()
{
	return winchoice3;
}


double student_class::getGPA()
{
	return GPA;
}


bool studentlist::check_same(student_class a, student_class b)
{
	if (a.getFirst_name() == b.getFirst_name() && a.getLast_name() == b.getLast_name())
		return true;
	else
		return false;

}





vector<student_class> studentlist::find1stClub(studentlist list, char club, int vacancy) {

	vector<student_class> x;

	for (student_class s : list.students)
	{
		if (s.getChoice1() == club)
		{
			x.push_back(s);
			
			

		}
	}

	while (x.size() > vacancy) { 
		x.pop_back();
	}

	return x;
}




void studentlist::remainding_vector(studentlist& studentlist,
	vector<student_class> firstPickandWins) 
{
	vector<student_class>::iterator it, student_it;


	for (student_it = firstPickandWins.begin(), it = studentlist.students.begin();
		it < studentlist.students.end(); it++)
	{
		if (check_same(*studentlist.students.begin(), *student_it))
		{
			studentlist.students.erase(studentlist.students.begin());
			it = studentlist.students.begin();
			if (student_it + 1 == firstPickandWins.end())
			{
				break;
			}
			else
			{
				student_it++;
			}

		}
		else if (check_same(*it, *student_it))
		{
			studentlist.students.erase(it);
			it = studentlist.students.begin();

			if (student_it + 1 == firstPickandWins.end())
			{
				break;
			}

			else
			{
				student_it++;

			}
		}

	}
}



vector<student_class> studentlist::find2ndClub(studentlist list, char club, int vacancy)
 {

	vector<student_class> x;

	for (student_class s : list.students)
	{
		if (s.getChoice2() == club)
		{
			x.push_back(s);

		}
	}

	while (x.size() > vacancy) { 
		x.pop_back();
	}

	return x;
}

void studentlist::remainding_vector2(studentlist& studentlist,
	vector<student_class> firstPickandWins) 
{
	vector<student_class>::iterator it, student_it;

	int count = 0;
	for (student_it = studentlist.students.begin(), it = firstPickandWins.begin();
		it < firstPickandWins.end() || studentlist.students.empty(); it++)
	{
		if (check_same(*firstPickandWins.begin(), *student_it))
		{
			studentlist.students.erase(student_it);
			it = firstPickandWins.begin();
			student_it = studentlist.students.begin();

			if (student_it + 1 + count == studentlist.students.end())
			{
				return;
			}
			else
			{
				student_it = student_it + count;
				student_it++;
				count++;
			}
		}

		else if (check_same(*it, *student_it))
		{
			studentlist.students.erase(student_it);
			it = firstPickandWins.begin();
			student_it = studentlist.students.begin();

			if (studentlist.students.empty())
			{
				return;

			}

		}
		else if (it == firstPickandWins.end() - 1 && student_it == studentlist.students.end() - 1)
		{
			break;
		}
		else if (it == firstPickandWins.end() - 1)

		{
			student_it++;
			it = firstPickandWins.begin();
		}
	}




}

void studentlist::remainding_vector3(vector<student_class> &studentlist,
	vector<student_class> &firstPickandWins) 
{
	vector<student_class>::iterator it, student_it;

	int count = 0;
	for (student_it = studentlist.begin(), it = firstPickandWins.begin();
		student_it < studentlist.end() || studentlist.empty(); student_it++)
	{
		if (check_same(*firstPickandWins.begin(), *student_it))
		{
			studentlist.erase(student_it);
			firstPickandWins.erase(it);
			it = firstPickandWins.begin();
			student_it = studentlist.begin();
			
			cout << "\n====REMOVED=====";
			

			if (student_it + 1 + count == studentlist.end() || firstPickandWins.empty())
			{	
				return;
			}
			else
			{
				student_it = student_it + count;
				student_it++;
				count++;
			}
		}

		else if (check_same(*it, *student_it))
		{
			studentlist.erase(student_it);
			firstPickandWins.erase(it);
			it = firstPickandWins.begin();
			student_it = studentlist.begin();
			
			cout << "\n====REMOVED====";
			

			if (studentlist.empty()|| firstPickandWins.empty())
			{
				return;

			}

		}
		else if (it == firstPickandWins.end() - 1 && student_it == studentlist.end() - 1)
		{
			break;
		}
		else if (student_it == studentlist.end() - 1)

		{
			student_it = studentlist.begin();
			it++;
		
		}
		
	}



}

vector<student_class> studentlist::find3rdClub(studentlist list, char club, int vacancy) {

	vector<student_class> x;

	for (student_class s : list.students)
	{
		if (s.getChoice3() == club)
		{
			x.push_back(s);
			


		}
	}

	while (x.size() > vacancy) { 
		x.pop_back();
	}

	return x;
}



studentlist::studentlist(string filepath)
{
	ifstream studentpath(filepath);

	string contents;

	while (!studentpath.eof())
	{
		getline(studentpath, contents);

		student_class s(contents);
		students.push_back(s); 

	}
	studentpath.close();

	
	sort(students.begin(), students.end(), [](student_class& s1, student_class& s2)
		{
			return s1.getGPA() > s2.getGPA();
		});

}

