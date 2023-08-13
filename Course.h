#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include"CLO.h"
using namespace std;

class Course
{
private:

	string code;
	string name;
	vector<CLO>* clo;
	int clocount;
public:
	Course()
	{
		code = "";
		name = "";
		clo = new vector<CLO>;
		clocount = 0;
	}
	Course(string code, string name)
	{
		this->code = code;
		this->name = name;
		clo = new vector<CLO>;
		clocount = 0;
	}
	void setcode(string code)
	{
		this->code = code;
	}
	void setname(string name)
	{
		this->name = name;
	}
	string getcode()
	{
		return code;
	}
	string getname()
	{
		return name;
	}
	void inputCwithoutCLo()
	{
		cout << "Enter the code of the course: ";
		cin >> code;
		cout << "Enter the name of the course: ";
		cin >> name;
	}
private:void inputCourse()
{
	cout << "Enter course code: ";
	cin >> code;
	cout << "Enter course name: ";
	cin >> name;
	cout << "No of CLOs : ";
	cin >> clocount;
}
public:
	void addCourse()
	{
		inputCourse();

		if (searchCourse(code) == true)
		{
			cout << "Course with the given code already exist \n";
		}
		else {
			ofstream fout;
			ifstream test;
			test.open("Courses.txt");
			fout.open("Courses.txt", ios::app);

			if (test.peek() != EOF) {

				fout << endl;
			}
			fout << code << endl;
			fout << name << endl;
			fout << clocount;
			if (clocount != 0)
			{
				fout << endl;
			}

			CLO c;
			for (int i = 0; i < clocount; i++)
			{
				c.inputCLO();
				clo->push_back(c);
				fout << c.getCode() << endl;
				fout << c.getName();
				if (i < clocount - 1)
				{
					fout << endl;
				}

			}
			fout.close();
			cout << "Course Added Successfully" << endl;
		}

	}
	void addCLOToC(CLO c)
	{
		clo->push_back(c);
		clocount++;
	}
	bool comparestring(string s1, string s2)
	{
		if (s1.length() != s2.length())
		{
			return false;
		}
		for (int i = 0; i < s1.length(); i++)
		{
			if (s1[i] != s2[i])
			{
				return false;
			}
		}
		return true;
	}
	bool searchCourse(string  c)
	{
		ifstream fin;
		fin.open("Courses.txt");
		if (fin.peek() == EOF)
		{
			cout << "No content in the file" << endl;
			return false;
		}
		else {
			string s;
			while (!fin.eof())
			{
				getline(fin, s);
				if (comparestring(s, c))
				{
					return true;
				}
			}
			return false;
		}
	}
	void RemoveCourse(string codek)
	{
		bool flag = searchCourse(codek);
		if (flag == true) {
			ifstream fin;
			fin.open("Courses.txt");
			if (fin.peek() == EOF)
			{
				cout << "No content in the file" << endl;
			}
			else {
				ofstream fout;
				fout.open("tempq.txt");
				string c;
				string n;
				int count;
				while (!fin.eof())
				{
					fin >> c;
					fin >> n;
					fin >> count;

					if (comparestring(c, codek) == false)
					{
						fout << c << endl;
						fout << n << endl;
						fout << count;
						if (count == 0 && fin.peek() == EOF)
						{
							break;
						}
						fout << endl;
						for (int i = 0; i < count; i++)
						{
							fin >> c;
							fin >> n;
							fout << c << endl;
							fout << n;
							if (fin.peek() != EOF)
							{
								fout << endl;
							}
						}
					}
					else
					{
						CLO cle;

						for (int i = 0; i < count; i++)
						{
							fin >> c;
							cle.removeCLO(c);
							fin >> n;
						}
					}
				}
				fin.close();
				fout.close();
				remove("Courses.txt");
				rename("tempq.txt", "Courses.txt");
			}
			cout << "Course Removed Successfully" << endl;
		}
		else
		{
			cout << "Course not found" << endl;
		}

	}
	void UpdateCourse(string code)
	{
		bool flag = searchCourse(code);
		if (flag == true) {
			ifstream fin;
			fin.open("Courses.txt");
			if (fin.peek() == EOF)
			{
				cout << "No content in the file" << endl;
			}
			else {
				ofstream fout;
				fout.open("tempw.txt");
				string c;
				string n;
				int count;
				while (!fin.eof())
				{
					fin >> c;
					fin >> n;
					fin >> count;
					if (comparestring(c, code) == false)
					{
						fout << c << endl;
						fout << n << endl;
						fout << count;
						if (count == 0 && fin.peek() == EOF)
						{
							break;
						}
						fout << endl;
						for (int i = 0; i < count; i++)
						{
							fin >> c;
							fin >> n;
							fout << c << endl;
							fout << n;
							if (fin.peek() != EOF)
							{
								fout << endl;
							}
						}
					}
					else
					{
						for (int i = 0; i < count; i++) //skipping the clos of prev course in the file
						{
							fin >> c;
							fin >> n;
						}
						cout << "Enter new course code: ";
						cin >> c;
						cout << "Enter new course name: ";
						cin >> n;
						cout << "Enter new no of CLOs: ";
						cin >> count;
						fout << c << endl;
						fout << n << endl;
						fout << count;
						if (count == 0 && fin.peek() == EOF)
						{
							break;
						}
						fout << endl;
						CLO cl;
						int i = 0;
						for (; i < count; i++)
						{
							cl.inputCLO();
							fout << cl.getCode() << endl;
							fout << cl.getName();
							if (fin.peek() != EOF)
							{
								fout << endl;
							}

						}

					}
				}
				fin.close();
				fout.close();
				remove("Courses.txt");
				rename("tempw.txt", "Courses.txt");
			}
			cout << "Course Updated Successfully" << endl;
		}
		else
		{
			cout << "Course not found" << endl;
		}

	}
	void DisplayAllCourses()
	{
		ifstream fin;
		fin.open("Courses.txt");
		if (fin.peek() == EOF)
		{
			cout << "No content in the file" << endl;
		}
		else {
			string c;
			string n;
			int count;
			while (!fin.eof())
			{
				fin >> c;
				fin >> n;
				fin >> count;
				cout << "Course code: " << c << endl;
				cout << "Course name: " << n << endl;
				cout << "No of CLOs: " << count << endl;
				for (int i = 0; i < count; i++)
				{
					fin >> c;
					fin >> n;
					cout << "CLO code : " << c << endl;
					cout << "CLO name : " << n << endl;
				}
			}
			fin.close();
		}
	}
	void DisplayCourseByCode(string code)
	{
		ifstream fin;
		fin.open("Courses.txt");
		if (fin.peek() == EOF)
		{
			cout << "No content in the file" << endl;
		}
		else {
			string c;
			string n;
			int count;
			while (!fin.eof())
			{
				fin >> c;
				fin >> n;
				fin >> count;
				if (comparestring(c, code))
				{
					cout << "Course code: " << c << endl;
					cout << "Course name: " << n << endl;
					cout << "No of CLOs: " << count << endl;
					for (int i = 0; i < count; i++)
					{
						fin >> c;
						fin >> n;
						cout << "CLO code: " << c << endl;
						cout << "CLO name: " << n << endl;
					}
				}
				else
				{
					for (int i = 0; i < count; i++)
					{
						fin >> c;
						fin >> n;
					}
				}
			}
			fin.close();
		}
	}



	~Course()
	{
		//delete[]clo;

	}
};