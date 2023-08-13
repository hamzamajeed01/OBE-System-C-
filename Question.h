#pragma once
#include<iostream>
#include<string>
using namespace std;
class Question
{
private:
	int marks;
	string question;
public:
	Question()
	{
		marks = 0;
		question = "";
	}
	Question(int marks, string question)
	{
		this->marks = marks;
		this->question = question;
	}
	int getmarks()
	{
		return marks;
	}
	string getquestion()
	{
		return question;
	}
	void setmarks(int marks)
	{
		this->marks = marks;
	}
	void setquestion(string question)
	{
		this->question = question;
	}
	void input()
	{
		cout << "Enter the marks of the question: ";
		cin >> marks;
		cout << "Enter the question: ";
		getline(cin, question);
	}
	void display()
	{
		cout << "Marks : " << marks << endl;
		cout << "Question : " << question << endl;
	}
	void addQuestion()
	{
		input();
		if (searchquestion(question) == true)
		{
			cout << "Question already exists" << endl;
		}
		else
		{


			ifstream fin;
			fin.open("Questions.txt");
			ofstream fout;
			fout.open("Questions.txt", ios::app);
			if (fin.peek() != EOF)
			{
				fout << endl;
			}
			fout << marks << endl;
			fout << question;
			fin.close();
			fout.close();
			cout << "Question added successfully" << endl;
		}
		
	}
	bool comparestrings(string s1, string s2)
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
	bool searchquestion(string q)
	{
		ifstream fin;
		fin.open("Questions.txt");
		string ques;
		while (!fin.eof())
		{
			getline(fin, ques);
			if (comparestrings(ques,q)==true)
			{
				fin.close();
				return true;
			}
		}
		fin.close();
		return false;
		
	}
	void removeQuestion()
	{
		string q;
		cout << "Enter the question to be removed: ";
		getline(cin, q);
		ifstream fin;
		fin.open("Questions.txt");
		ofstream fout;
		fout.open("temp4.txt");
		if (fin.peek() == EOF)
		{
			cout << "File is empty" << endl;
			return;
		}
		if (searchquestion(q) == true)
		{
			int c;
			string ques;
			while (!fin.eof())
			{
				fin >> c;
				fin >> ques;
				if (comparestrings(ques, q) == true)
				{
					continue;
				}
				else
				{
					fout << c << endl;
					fout << ques;
					if (fin.peek() != EOF)
					{
						fout << endl;
					}
				}
			}
			fin.close();
			fout.close();
			remove("Questions.txt");
			rename("temp4.txt", "Questions.txt");
			
			cout << "Question removed successfully" << endl;
			
		}
		else {
			{
				cout << "Question not found" << endl;
			}
		}
		
		
	}
	void updateQuestion()
	{
		string q;
		cout << "Enter the question to be updated: ";
		cin >> q;
		ifstream fin;
		fin.open("Questions.txt");
		ofstream fout;
		fout.open("tempc.txt");
		if (fin.peek() == EOF)
		{
			cout << "File is empty" << endl;
			return;
		}
		if (searchquestion(q) == true)
		{
			int c;
			string ques;
			while (!fin.eof())
			{
				fin >> c;
				fin >> ques;
				if (comparestrings(ques, q) == true)
				{
					cout << "Enter the new marks: ";
					cin >> c;
					cout << "Enter the new question: ";
					getline(cin, ques);
					fout << c << endl;
					fout << ques;
					if (fin.peek() != EOF)
					{
						fout << endl;
					}
				}
				else
				{
					fout << c << endl;
					fout << ques;
					if (fin.peek() != EOF)
					{
						fout << endl;
					}
				}
			}
			fin.close();
			fout.close();
			remove("Questions.txt");
			rename("tempc.txt", "Questions.txt");
			cout << "Question updated successfully" << endl;
		}
		else
		{
			cout << "Question not found" << endl;
		}
	}
	~Question()
	{

	}
	
};