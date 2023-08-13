#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include"Course.h"

using namespace std;
class PLO
{

private:
	string code;
	string name;
	vector<Course>* course;
	int coursecount;
public:
	PLO()
	{
		code = "";
		name = "";
		course = new vector<Course>;
		coursecount = 0;
	}
	PLO(string code, string name)
	{
		this->code = code;
		this->name = name;
		course = new vector<Course>;
		coursecount = 0;
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
	void inputPLO()
	{
		cout << "Enter PLO code: ";
		cin >> code;
		cout << "Enter PLO name: ";
		cin >> name;
	}
	void addCourse(Course c)
	{
		course->push_back(c);
		coursecount++;
	}
	void addPLO()
	{
		inputPLO();
		if (searchPLOfromFile(code) == true)
		{
			cout << "PLO already exists" << endl;
		}
		else
		{
			ofstream fout;
			fout.open("PLO.txt", ios::app);
			fout << code << " " << name << endl;
			fout.close();
		}
	}
	bool searchPLOfromFile(string code)
	{
		ifstream fin;
		fin.open("PLO.txt");
		string c, n;
		while (!fin.eof())
		{
			fin >> c >> n;
			if (c == code)
			{
				return true;
			}
		}
		fin.close();
		return false;
	}
	void displayAllCoursesofaplo()
	{
		cout << "Plo code : " << code << endl;
		cout << "Plo name :   " << name << endl;
		//iterate the vector 
		for (int i = 0; i < course->size(); i++)
		{
			cout <<"Course Code = "<<course->at(i).getcode() << " Course Name = " << course->at(i).getname() << endl;
		}
	}
	bool comparestrings(string s1,string s2)
	{
		if (s1.length() != s2.length())
		{
			return false;
		}
		else
		{
			for (int i = 0; i < s1.length(); i++)
			{
				if (s1[i] != s2[i])
				{
					return false;
				}
			}
			return true;
		}
	}
	void displayPLO()
	{
		ifstream fin;
		fin.open("PLO.txt");
		string c, n;
		while (!fin.eof())
		{
			fin >> c >> n;
			cout << c << " " << n << endl;
		}
		fin.close();
	}
	void displayPLO(string code)
	{
		ifstream fin;
		fin.open("PLO.txt");
		string c, n;
		while (!fin.eof())
		{
			fin >> c >> n;
			if (comparestrings(c,code)==true)
			{
				cout << c << " " << n << endl;
			}
		}
		fin.close();
	}
	void displayPLOwithCourse()
	{
		ifstream fin;
		fin.open("PLO.txt");
		string c, n;
		while (!fin.eof())
		{
			fin >> c >> n;
			cout << c << " " << n << endl;
			for (int i = 0; i < coursecount; i++)
			{
				cout << course->at(i).getcode() << " " << course->at(i).getname() << endl;
			}
		}
		fin.close();
	}
	void displayPLOwithCourse(string code)
	{
		ifstream fin;
		fin.open("PLO.txt");
		string c, n;
		while (!fin.eof())
		{
			fin >> c >> n;
			if (comparestrings(c, code) == true)
			{
				cout << c << " " << n << endl;
				for (int i = 0; i < coursecount; i++)
				{
					cout << course->at(i).getcode() << " " << course->at(i).getname() << endl;
				}
			}
		}
		fin.close();
	}
	void updatePLO(string code)
	{
		ifstream fin;
		fin.open("PLO.txt");
		string c, n;
		vector<string> v;
		while (!fin.eof())
		{
			fin >> c >> n;
			if (comparestrings(c, code) == true)
			{
				cout << "Enter new PLO name: ";
				cin >> n;
			}
			v.push_back(c + " " + n);
		}
		fin.close();
		ofstream fout;
		fout.open("PLO.txt");
		for (int i = 0; i < v.size(); i++)
		{
			fout << v[i] << endl;
		}
		fout.close();
	}

	void deletePLO(string code)
	{
		ifstream fin;
		fin.open("PLO.txt");
		string c, n;
		vector<string> v;
		while (!fin.eof())
		{
			fin >> c >> n;
			if (comparestrings(c, code) == true)
			{
				v.push_back(c + " " + n);
			}
		}
		fin.close();
		ofstream fout;
		fout.open("PLO.txt");
		for (int i = 0; i < v.size(); i++)
		{
			fout << v[i] << endl;
		}
		fout.close();
	}
};
	
	
