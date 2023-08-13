#pragma once
#include"Evaluation.h"
#include <iostream>
#include <fstream>
#include "Course.h"
#include <string>
#include <vector>
using namespace std;
class Course;
class CLO
{
private:
	string code;
	string name;
	vector<Evaluation*>* eval;
	int evalcount;
public:
	CLO()
	{
		code = "";
		name = "";
		eval = new vector<Evaluation*>;
		evalcount = 0;
	}
	CLO(string code, string name)
	{
		this->code = code;
		this->name = name;
		eval = new vector<Evaluation*>;
		evalcount = 0;
	}
	
	string getCode()
	{
		return code;
	}
	string getName()
	{
		return name;
	}


	void inputCLO()
	{
		cout << "Enter CLO code: ";
		cin >> code;
		cout << "Enter CLO name: ";
		cin >> name;
	}
	
	void addEvaluation(Evaluation *e)
	{
		
		eval->push_back(e);
		evalcount++;
	}
	void addCLO()
	{
		inputCLO();
		if (searchCLOfromFile(code) == true)
		{
			cout << "CLO already exists" << endl;
		}
		else
		{
			ifstream fin;
			fin.open("CLO.txt");
			ofstream fout;
			fout.open("CLO.txt", ios::app);
			if (fin.peek() != EOF)
			{
				fout << endl;
			}
			fout << code << " " << name << " ";
			Evaluation* e = new Evaluation();
			cout << "Enter number of evaluations: ";
			cin >> evalcount;
			fout << evalcount;
			if (evalcount != 0)
			{
				fout << " ";
			}
			for (int i = 0; i < evalcount; i++)
			{
				e->input();
				eval->push_back(e);
				fout << e->getCode() << " " << e->getType();
				if (i < evalcount - 1)
				{
					fout << " ";
				}
			}
			fout.close();
			cout << "CLO Added Successfully" << endl;

		}
	}
	bool SearchCLO(string c)
	{
		ifstream fin;
		fin.open("CLO.txt");
		if (fin.peek() == EOF)
		{
			cout << "File is empty" << endl;
			return false;
		}
		string code;
		string name;
		int evalcount;
		while (!fin.eof())
		{
			fin >> code;
			fin >> name;
			fin >> evalcount;
			if (code == c)
			{
				cout << "CLO Code: " << code << endl;
				cout << "CLO Name: " << name << endl;
				cout << "Number of Evaluations: " << evalcount << endl;
				Evaluation* e = new Evaluation();
				for (int i = 0; i < evalcount; i++)
				{
					fin >> code;
					fin >> name;
					e->setcode(code);
					e->settype(name);
					e->display();
				}
				return true;
			}
			else
			{
				Evaluation *e=new Evaluation();
				for (int i = 0; i < evalcount; i++)
				{
					fin >> code;
					fin >> name;
				}
			}
		}
	}
	bool searchCLOfromFile(string c)
	{
		ifstream fin;
		fin.open("CLO.txt");
		if (fin.peek() == EOF)
		{
			cout << "File is empty" << endl;
			return false;
		}
		string code;
		string name;
		int evalcount;
		while (!fin.eof())
		{
			fin >> code;
			fin >> name;
			fin >> evalcount;
			if (code == c)
			{
				return true;
			}
			else
			{
				Evaluation *e = new Evaluation();
				for (int i = 0; i < evalcount; i++)
				{
					fin >> code;
					fin >> name;
				}
			}
		}
		return false;
	}
	void DisplayAllClos()
	{
		ifstream fin;
		fin.open("CLO.txt");
		if (fin.peek() == EOF)
		{
			cout << "File is empty" << endl;
			return;
		}
		string code;
		string name;
		int evalcount;
		while (!fin.eof())
		{
			fin >> code;
			fin >> name;
			fin >> evalcount;
			cout << "CLO Code: " << code << endl;
			cout << "CLO Name: " << name << endl;
			cout << "Number of Evaluations: " << evalcount << endl;
			Evaluation* e = new Evaluation();
			for (int i = 0; i < evalcount; i++)
			{
				fin >> code;
				fin >> name;
				e->setcode(code);
				e->settype(name);
				e->display();
			}
		}
	}
	bool comparestrings(string s1, string s2)
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
	void removeCLO(string c)
	{
		ifstream fin;
		fin.open("CLO.txt");
		if (fin.peek() == EOF)
		{
			cout << "File is empty" << endl;
			return;
		}
		if(searchCLOfromFile(c)==true)
		{ 
		string code;
		string name;
		int evalcount;
		ofstream fout;
		fout.open("temp2.txt");
		while (!fin.eof())
		{
			fin >> code;
			fin >> name;
			fin >> evalcount;
			
			if (comparestrings(code,c)==true)
			{
				Evaluation* e = new Evaluation();
				for (int i = 0; i < evalcount; i++)
				{
					fin >> code;
					e->Remove(code);
					fin >> name;
				}
			}
			else
			{
				fout << code << " " << name << " " << evalcount;
				Evaluation *e = new Evaluation();
				for (int i = 0; i < evalcount; i++)
				{
					fin >> code;
					fin >> name;
					fout << " " << code << " " << name;
				}
				if (fin.peek() != EOF)
				{
					fout << endl;
				}
				
			}
			
		}
		fin.close();
		fout.close();
		remove("CLO.txt");
		rename("temp2.txt", "CLO.txt");
		cout << "CLO removed Successfully " << endl;
	}
		else
		{
			cout << "CLO not found" << endl;
		}
	}
	void UpdateCLO(string c)
	{
		ifstream fin;
		fin.open("CLO.txt");
		if (fin.peek() == EOF)
		{
			cout << "File is empty" << endl;
			return;
		}
		if (searchCLOfromFile(c) == true)
		{
			string code;
			string name;
			int evalcount;
			ofstream fout;
			fout.open("tempr.txt");
			while (!fin.eof())
			{
				fin >> code;
				fin >> name;
				fin >> evalcount;

				if (comparestrings(code, c) == true)
				{
					cout << "Enter new CLO Code: ";
					cin >> code;
					cout << "Enter new CLO name: ";
					cin >> name;
					
					fout << code << " " << name << " " << evalcount;
					Evaluation *e = new Evaluation();
					for (int i = 0; i < evalcount; i++)
					{
						fin >> code;
						fin >> name;
						fout << " " << code << " " << name;
					}
					if (fin.peek() != EOF)
					{
						fout << endl;
					}
				}
				else
				{
					fout << code << " " << name << " " << evalcount;
					Evaluation *e = new Evaluation();
					for (int i = 0; i < evalcount; i++)
					{
						fin >> code;
						fin >> name;
						fout << " " << code << " " << name;
					}
					if (fin.peek() != EOF)
					{
						fout << endl;
					}

				}

			}
			fin.close();
			fout.close();
			remove("CLO.txt");
			rename("tempr.txt", "CLO.txt");
			cout << "CLO Updated Successfully   " << endl;
		}
		else
		{
			cout << "CLO not found" << endl;
		}
	}
	void simpledisplay()
	{
		cout << "CLO code is : " << code << endl;
		cout << "CLO name is :   " << name << endl;
		cout << "Number of Evaluations: " << evalcount << endl;
		for (int i = 0; i < evalcount; i++)
		{
			eval->at(i)->display();
		}
		
	}
	void CLOhasTested()
	{
		int c = 0;
		for (int i = 0; i < evalcount; i++)
		{
			c+=eval->at(i)->getcount();
			
		}
		if (c > 2)
		{
			cout << "All the evaluations of given CLO are tested" << endl;
		}
		else
		{
			cout << "All the evaluations of given CLO are not tested " << endl;
		}
	}
	~CLO()
	{
		delete eval;
	}
};