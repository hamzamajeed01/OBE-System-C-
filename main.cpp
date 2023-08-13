#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include"Course.h"
#include"Evaluation.h"
#include"Question.h"
#include"User.h"
#include"PLO.h"
using namespace std;
int choose;
void login_signup()
{
	cout << "\n****************** WELCOME TO OBE SUPPORT SYSTEM *************************" << endl << endl;
	User* u = new AO();
	
	do
	{
		cout << "1-Login" << endl;
		cout << "2-Signup" << endl;
		cout << "3-Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choose;
		if (choose == 1)
		{
			if (u->Login() == true)
			{
				cout << "You are logged in" << endl;
				break;
			}
			else
			{
				cout << "You are not logged in" << endl;
				cout << "The Username or Password is Incorrect! Try Again" << endl;
			}
		}
		else if (choose == 2)
		{
			u->signup();
			cout << " Congoratulation! Your Account Has Been Created" << endl;
			break;
		}
		else if (choose == 3)
		{
			cout << "Thank you for using our system" << endl;
		}
		else
		{
			cout << "Invalid choice" << endl;
		}
	} while (choose != 3);

}
int main()
{

	login_signup();
	if (choose != 3)
	{
		int choice;
		do
		{
			cout << "\n****************** OBE SUPPORT SYSTEM *************************" << endl << endl;
			cout << "1-Add Course" << endl;
			cout << "2-Remove Course" << endl;
			cout << "3-Update Course" << endl;
			cout << "4-Add CLO" << endl;
			cout << "5-Remove CLO" << endl;
			cout << "6-Update CLO" << endl;
			cout << "7-Add Evaluation" << endl;
			cout << "8-Remove Evaluation" << endl;
			cout << "9-Update Evaluation" << endl;
			cout << "10-Add Question" << endl;
			cout << "11-Remove Question" << endl;
			cout << "12-Update Question" << endl;
			cout << "13-Check CLO has been tested or not" << endl;
			cout << "14-Generate the list of all the courses for a given PLO" << endl;
			cout << "15-Exit" << endl;
			cout << "Enter your choice: ";
			cin >> choice;
			if (choice == 1)
			{
				Course c;
				c.addCourse();
			}
			else if (choice == 2)
			{
				string code;
				cout << "Enter the course code : ";
				cin >> code;
				Course c;
				c.RemoveCourse(code);
			}
			else if (choice == 3)
			{
				Course c;
				string code;
				cout << "Enter the course code : ";
				cin >> code;
				c.UpdateCourse(code);
			}
			else if (choice == 4)
			{
				CLO c;
				c.addCLO();
			}
			else if (choice == 5)
			{
				string code;
				cout << "Enter the CLO code: ";
				cin >> code;
				CLO c;
				c.removeCLO(code);
			}
			else if (choice == 6)
			{
				CLO c;
				string code;
				cout << "Enter the CLO code: ";
				cin >> code;
				c.UpdateCLO(code);
			}
			else if (choice == 7)
			{
				Evaluation e;
				e.add();
			}
			else if (choice == 8)
			{
				string code;
				cout << "Enter the Evaluation code: ";
				cin >> code;
				Evaluation e1;
				e1.Remove(code);
			}
			else if (choice == 9)
			{
				Evaluation e1;
				string code;
				cout << "Enter the Evaluation code: ";
				cin >> code;
				e1.Update(code);
			}
			else if (choice == 10)
			{
				Question q1;
				q1.addQuestion();
			}
			else if (choice == 11)
			{
				string code;
				Question q1;
				q1.removeQuestion();
			}
			else if (choice == 12)
			{
				Question q1;
				string code;
				q1.updateQuestion();
			}
			else if (choice == 13)
			{
				CLO c;
				Evaluation* e1[3];
				e1[0] = new Quiz();
				e1[1] = new Assignment();
				e1[2] = new Exam();
				e1[0]->input();
				e1[1]->input();
				e1[2]->input();
				c.addEvaluation(e1[0]);
				c.addEvaluation(e1[1]);
				c.addEvaluation(e1[2]);
				c.CLOhasTested();
				
			}
			else if (choice == 14)
			{
				Course c1;
				Course c2;
				Course c3;
				Course c4;
				c1.inputCwithoutCLo();
				c2.inputCwithoutCLo();
				c3.inputCwithoutCLo();
				c4.inputCwithoutCLo();
				PLO p1;
				p1.inputPLO();
				p1.addCourse(c1);
				p1.addCourse(c2);
				p1.addCourse(c3);
				p1.addCourse(c4);
				p1.displayAllCoursesofaplo();
				
			}
			else if (choice == 15)
			{
				cout << "Thank you for using our system" << endl;
			}
			else
			{
				cout << "Invalid choice" << endl;
			}
			} while (choice != 15);
		
	}

	
	return 0;
}

