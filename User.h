#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
class User
{
public:
	virtual bool Login() = 0;
	virtual void signup() = 0;
	virtual void inputUser() = 0;
};
class AO:public User
{
	private:
	string username;
	string password;
public:
	AO()
	{
		username = "";
		password = "";
	}
	AO(string username, string password)
	{
		this->username = username;
		this->password = password;
	}
	void setusername(string username)
	{
		this->username = username;
	}
	void setpassword(string password)
	{
		this->password = password;
	}
	string getusername()
	{
		return username;
	}
	string getpassword()
	{
		return password;
	}
	void inputUser()
	{
		cout << "Enter username: ";
		cin >> username;
		cout << "Enter password: ";
		cin >> password;
	}
	virtual void signup()
	{
		inputUser();
		
		ofstream file;
		file.open("User.txt", ios::app);
		file << username << endl;
		file << password << endl;
		file.close();
	}
	virtual bool Login()
	{
		inputUser();
		ifstream file;
		file.open("User.txt");
		string line;
		while (getline(file, line))
		{
			if (line == username)
			{
				getline(file, line);
				if (line == password)
				{
					return true;
				}
			}
		}
		return false;
	}
	~AO()
	{
		
	}
};

