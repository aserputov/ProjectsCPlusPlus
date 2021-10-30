#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

class Student
{
	int studentId;
	char* fullName;
	float* grades;
	int numOfGrades;
public:
	Student();
	Student(const char* name, const float* Sgrades, int numGrades,int id);
	~Student();
	void display() const;
	Student(const Student& obj1);
	Student& operator=(const Student& s2);
	Student operator+=(float w);	
//ToDo: overload += operator. Operator should take floating value and return the reference to a current object
};

Student::Student()
{
	studentId = 0;
	fullName = nullptr;
	grades = nullptr;
	numOfGrades = 0;
}

Student::Student(const char* name, const float* Sgrades, int numGrades,int id)
{
	bool valid = name != nullptr && strlen(name) > 0 && Sgrades != nullptr && numGrades >= 0;
	if (valid) {
		for (int i = 0; i < numGrades && valid; i++)
			valid = Sgrades[i] >= 0.0f && Sgrades[i] <= 100.0f;
	}
		
	if(valid){
		studentId = id;
		numOfGrades = numGrades;
		fullName = new char[strlen(name) + 1];
		strcpy(fullName, name);
		grades = new float[numOfGrades];
		if (numOfGrades > 0) {
			for (int i = 0; i < numOfGrades; i++) {
				grades[i] = Sgrades[i];
			}
		}
		else {
			grades = nullptr;
		}
	}
	else {
		grades = nullptr;
		*this = Student();
	}
}

Student::~Student()
{
	delete[] fullName;
	delete[] grades;
}

void Student::display() const
{
	if (numOfGrades > 0) {
		cout << "Full Name: " << fullName  << " " << "Student ID: " << studentId << endl;
		cout.setf(ios::fixed);
		cout.precision(2);
		for (int i = 0; i < numOfGrades; i++) {
			cout << grades[i] << endl;
		}
		cout.unsetf(ios::fixed);
		cout.precision(6);
	}
	else {
		cout << "no data available" << endl;
	}
}


Student& Student::operator=(const Student& s2)
{
	if (this != &s2) {
		studentId = s2.studentId;
		numOfGrades = s2.numOfGrades;
		delete[] fullName;
		delete[] grades;
		if (s2.grades != nullptr) {
			grades = new float[numOfGrades];
			for (int i = 0; i < numOfGrades; i++) {
				grades[i] = s2.grades[i];
			}
			fullName = new char[strlen(s2.fullName) + 1];
			strcpy(fullName, s2.fullName);
		}
		else {
			fullName = nullptr;
			grades = nullptr;
		}
	}
	return *this;
}

Student Student::operator+=(float *w){
	float *t;
	for(int i=0;i<numOfGrades;i++){
		t[i] = grades[i]+=w[i];
	
	return t;
}
}

// ToDo: overload += operator. Operator should take floating value and return the reference to a current object 
// Definition: Here 






Student::Student(const Student& obj1)
{
	// Shallow copy
	studentId = obj1.studentId;
	numOfGrades = obj1.numOfGrades;
	// Deep copy
	if (obj1.grades != nullptr && obj1.fullName!=nullptr) {
		grades = new float[numOfGrades];
		for (int i = 0; i < numOfGrades; i++) {
			grades[i] = obj1.grades[i];
		}
		fullName = new char[strlen(obj1.fullName) + 1];
		strcpy(fullName, obj1.fullName);
	}
	else {
		fullName = nullptr;
		grades = nullptr;
	}
}



int main() {
	float grades[] = { 88.5,90.5,100.0 };
	float grades2[] = { 99.5,80.6,95.00 };
	Student anatoliy("Anatoliy Serputov", grades, 3,1);
	Student andrei("Andrei Batomunkuev", grades2, 3, 2);
	cout << "Checking Anatoliy: " << endl;
	anatoliy.display();
	cout << "Checking Andrei: " << endl;
	andrei.display();
	cout << "Checking for copy assignment operator: " << endl;
	anatoliy = andrei;
	cout << "Checking Anatoliy: After copy assignment operaotr" << endl;
	anatoliy.display();
	cout << "Checking += operator" << endl;
	anatoliy += 76.00;
	anatoliy.display();
}
