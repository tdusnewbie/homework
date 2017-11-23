#include <iostream>
#include <string>

using namespace std;

struct Student
{
	string name;
	string country;
	int code;
};

struct Node 
{
	Student info;
	Node *link;
};

class List
{
private:
	Node *front ;
	Node *rear ;
	static int numStudent;
public:
	List()
	{
		front = NULL;
		rear = NULL;
	}
	~List()
	{}
	void addStudent();
	void deleteStudent();
	static int takeNumStudent();
	bool checkNumStudent();
};

int List::numStudent;

void List::addStudent()
{
	Student student;
	string flag;
	cin.ignore();
	cout << "Please enter name of this student : ";
	getline(std::cin,flag);
	student.name = flag;
	cout << "After that ... Please enter His/Her country : ";
	getline(std::cin,flag);
	cout << "OK ... Now enter His/Her code : ";
	cin >> student.code;
	student.country = flag;
	Node *temp =new Node;
	temp->info = student;
	temp->link = NULL;
	if (front == NULL && rear == NULL )
	{
		front = rear = temp;
		return;
	}
	rear->link = temp;
	rear = temp;
	numStudent ++;
}

void List::deleteStudent()
{
	Node *temp = front;
	if(front == NULL)
		return;
	if(front == rear)
		rear = front = NULL;
	else 
		front = front->link;
	delete[] temp;
	if(numStudent != 0)
		numStudent--;
}

bool List::checkNumStudent()
{
	if (numStudent == 0 || numStudent % 2 == 0)
		return true;
	else 
		return false;
}
int List::takeNumStudent()
{
	return numStudent;
}

int menu()
{
	int choose;
	cout << "=========== Main menu===========" <<endl;
	cout << "1. Add New Student (The end of list) " <<endl;
	cout << "2. Delete Student (The first of list) " <<endl;
	cout << "3. Number of Student " <<endl;
	cout << "---------------------------------" <<endl;
	cout << "Your choice : ";
	cin >> choose;
	return choose;
}

int main()
{
	List odd, even;
	int back = 1;
	while(back == 1)
	{
		system("clear");
		int choose = menu();
		if (choose == 1)
		{
			if(odd.checkNumStudent() == true)
				odd.addStudent();
			else
				even.addStudent();
		}
		else if(choose == 2)
		{
			cout << "Please choose one list : " << endl;
			cout << "1. Odd List (students who has odd number " << endl;
			cout << "2. Even List (student who has evenn number " << endl;
			cout << "---------------------------------------------" <<  endl;
			cout << "Your choise : " ;
			cin >>choose;
			if(choose == 1)
				odd.deleteStudent();
			else 
				even.deleteStudent(); 
			cout << "You have deleted the first student in This list !!! " << endl;
		}
		else if(choose == 3)
		{
			cout << "Number of student in This list is : " << odd.takeNumStudent << endl;
		}
		else 
		{
			cout << "Your choice is not as same as my suggestion ... So I will set it is 3 " << endl;
			cout << "Number of student in This list is : " << odd.takeNumStudent << endl;
		}
		cout << endl;
		cout << "Do you wanna continue (1:Yes/0:No) : ";
		cin >> back;
		if (back == 0)
		{
			cout << "OK .. Fine ... If this is your choice !!!! " <<endl;
		}
	}
}