#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include"Question.h"
using namespace std;
class Evaluation
{
private:
	string code;
	string type;
public:
	Evaluation()
	{
		code = "";
		type = "";
	}
	Evaluation(string code, string name)
	{
		this->code = code;
		this->type = name;
	}
	string getCode()
	{
		return code;
	}
	string getType()
	{
		return type;
	}
	void setcode(string c)
	{
		code = c;
	}
	void settype(string name)
	{
		this->type = name;
	}
	virtual int getcount() {
		return 0;
	};
	virtual void input()
	{
		cout << "Enter the code of the evaluation: ";
		cin >> code;
		cout << "Enter the type of the evaluation: ";
		cin >> type;
	}
	virtual void display()
	{
		cout << "Code : " << code << endl;
		cout << "Type : " << type << endl;
	}
	void add()
	{
		input();
		if (searchevaluation(code) == true)
		{
			cout << "Evaluation already exists" << endl;
		}
		else
		{

			ifstream fin;
			fin.open("Evaluation.txt");
			ofstream fout;
			fout.open("Evaluation.txt", ios::app);
			if (fin.peek() != EOF)
			{
				fout << endl;
			}
			fout << code << " ";
			fout << type;
			fin.close();
			fout.close();
			cout << "Evaluations added successfully" << endl;
		}
	}
	bool comparestrings(string s1, string s2)
	{
		int i = 0;
		while (s1[i] != '\0' && s2[i] != '\0')
		{
			if (s1[i] != s2[i])
			{
				return false;
			}
			i++;
		}
		if (s1[i] == '\0' && s2[i] == '\0')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool searchevaluation(string s)
	{
		ifstream fin;
		fin.open("Evaluation.txt");
		string code;
		string type;
		while (!fin.eof())
		{
			fin >> code;
			fin >> type;
			if (comparestrings(code,s)==true)
			{
				return true;
			}
		}
		return false;
	}
	void Update(string s)
	{
		ifstream fin;
		fin.open("Evaluation.txt");
		ofstream fout;
		fout.open("temp3.txt");
		if (fin.peek() == EOF)
		{
			cout << "File is empty " << endl;
		}
		else {
			if (searchevaluation(s) == true) {
				string code;
				string type;
				while (!fin.eof())
				{
					fin >> code;
					fin >> type;
					if (comparestrings(code, s) == true)
					{
						cout << "Enter the new code of the evaluation: ";
						cin >> code;
						cout << "Enter the new type of the evaluation: ";
						cin >> type;
					}
					fout << code << " ";
					fout << type;
					if (fin.peek() != EOF)
					{
						fout << endl;
					}
				}
				fin.close();
				fout.close();
				remove("Evaluation.txt");
				rename("temp3.txt", "Evaluation.txt");
				cout << "Evaluations updated successfull y " << endl;
			}
			else {
				{
					cout << "Evaluation not found   " << endl;
				}
			}
		}
	}
	void Remove(string c)
	{
		ifstream fin;
		fin.open("Evaluation.txt");
		ofstream fout;
		fout.open("temp31.txt");
		if (fin.peek() == EOF)
		{
			cout << "File is empty   " << endl;
		}
		else {
			if (searchevaluation(c) == true) {
				string code;
				string type;
				while (!fin.eof())
				{
					fin >> code;
					fin >> type;
					if (comparestrings(code, c) == true)
					{
						continue;
					}
					else
					{
						fout << code << " ";
						fout << type;
						if (fin.peek() != EOF)
						{
							fout << endl;
						}
					}
					
					
				}
				fin.close();
				fout.close();
				remove("Evaluation.txt");
				rename("temp31.txt", "Evaluation.txt");
				cout << "Evaluations removed successfull y  " << endl;
			}
			else
			{
				cout << "Evaluation not found : " << endl;
			} 
			
		}
	}
};
class Quiz : public Evaluation
{
private:
	int count;
	vector<Question>* questions;
public:
	Quiz()
	{
		count = 0;
		questions = new vector<Question>;
	}
	Quiz(string code, string name) : Evaluation(code, name)
	{
		count = 0;
		questions = new vector<Question>;
	}
	void input()
	{
		Evaluation::input();
		cout << "Enter the number of questions: ";
		cin >> count;
		for (int i = 0; i < count; i++)
		{
			Question q;
			q.input();
			questions->push_back(q);
		}
	}
	void display()
	{
		Evaluation::display();
		cout << "Number of questions: " << count << endl;
		for (int i = 0; i < count; i++)
		{
			questions->at(i).display();
		}
	}
	int getcount()
	{
		return count;
	}
};
	

class Assignment : public Evaluation
{
private:
	int count;
	vector<Question>* questions;
public:
	Assignment()
	{
		count = 0;
		questions = new vector<Question>;
	}
	Assignment(string code, string name) : Evaluation(code, name)
	{
		count = 0;
		questions = new vector<Question>;
	}
	void input()
	{
		Evaluation::input();
		cout << "Enter the number of questions: ";
		cin >> count;
		for (int i = 0; i < count; i++)
		{
			Question q;
			q.input();
			questions->push_back(q);
		}
	}
	void display()
	{
		Evaluation::display();
		cout << "Number of questions: " << count << endl;
		for (int i = 0; i < count; i++)
		{
			questions->at(i).display();
		}
	}
	int getcount()
	{
		return count;
	}
};

class Exam : public Evaluation
{
private:
	int count;
	vector<Question>* questions;
public:
	Exam()
	{
		count = 0;
		questions = new vector<Question>;
	}
	Exam(string code, string name) : Evaluation(code, name)
	{
		count = 0;
		questions = new vector<Question>;
	}
	void input()
	{
		Evaluation::input();
		cout << "Enter the number of questions: ";
		cin >> count;
		for (int i = 0; i < count; i++)
		{
			Question q;
			q.input();
			questions->push_back(q);
		}
	}
	void display()
	{
		Evaluation::display();
		cout << "Number of questions: " << count << endl;
		for (int i = 0; i < count; i++)
		{
			questions->at(i).display();
		}
	}
	int getcount()
	{
		return count;
	}
};

	
	
	