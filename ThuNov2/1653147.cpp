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
	Student data;
	Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;
int numStudent = 0;
struct Student student;


void getStudent()
{
	cin.ignore();
	string temp;
	cout << "Enter the name of Student : ";
	getline(std::cin,temp);
	student.name = temp;
	cout << "Enter Student's country : ";
	getline(std::cin, temp);
	student.country = temp;
	int stdCode;
	cout << "Enter Student's Code : ";
	cin >> stdCode;
	student.code = stdCode;
}

void addStudent()
{
	struct Node *temp = new Node;
	temp->data = student;
	temp->next = NULL;
	if(front == NULL && rear == NULL)
	{
		front =  rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
	numStudent ++;
}

void deleteStudent()
{
	struct Node *temp = front;
	if(front == NULL)
	{
		return;
	}
	if(front == rear)
		rear = front = NULL;
	else
		front = front->next;
	delete[] temp;
	if(numStudent != 0)
		numStudent--;
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
	int back = 1;
	while(back == 1)
	{
		system("clear");
		int choose = menu();
		if (choose == 1)
		{
			getStudent();
			addStudent();
		}
		else if(choose == 2)
		{
			deleteStudent();
			cout << "You have deleted the first student in This list !!! " << endl;
		}
		else if(choose == 3)
		{
			cout << "Number of student in This list is : " << numStudent << endl;
		}
		else 
		{
			cout << "Your choice is not as same as my suggestion ... So I will set it is 0 " << endl;
			break;
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