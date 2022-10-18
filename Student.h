#ifndef STUDENT
#define STUDENT

#include <string>
#include <iostream>
using namespace std;

class Student{
private:
	/* STUDENT ATTRIBUTES */
	string mNumber;
	string name;

public:
	/* CONSTRUCTORS */
	Student(){
		mNumber = "00000000";
		name = "";
	}
	Student(string mNumber){
		this->mNumber = mNumber;
		name = "";
	}
	Student(string mNumber, string name){
		this->mNumber = mNumber;
		this->name = name;
	}

	/* STUDENTS GETTER AND SETTER METHODS */
	string getName(){ return name; }
	string getMNumber(){ return mNumber; }
	void setName(string name){ this->name = name; }
	void setMNumber(string mNumber){ this->mNumber = mNumber; }

	/* STUDENT OVERLOADS */
	bool operator<(const Student& s){
		return stoi(this->mNumber) < stoi(s.mNumber);
	}
	bool operator>(const Student& s){
		return stoi(this->mNumber) > stoi(s.mNumber);
	}
	bool operator==(const Student& s){
		return stoi(this->mNumber) == stoi(s.mNumber);
	}
	bool operator!=(const Student& s){
		return stoi(this->mNumber) != stoi(s.mNumber);
	}
	friend ostream& operator<<(ostream& os, const Student& s){
		os << s.mNumber;
		return os;
	}
	operator string&() {
    	return this->mNumber;
  	}
};

#endif