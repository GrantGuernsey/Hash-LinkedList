#include "Student.h"
#include "Hash.h"
#include "HashLL.h"

#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

/* THE LINKED LIST FROM LAB 8 WAS UPDATED TO BETTER FIT THE NEEDS OF THIS LAB */
/* MNUMBER IS A STRING TO ALLOW THE HASH FUNCTION TO OPERATE PROPERLY */

void talk(string& mNumber){
	//Mnumber
	bool getNum = true;
	bool ignore = true;

	while (getNum){
		cout << "Mnumber (without the M): ";
		if (ignore) cin.ignore();
		getline(cin, mNumber);

		getNum = false;
		ignore = false;

		//Make sure only numbers were inputted
		for (int n = 0; n < mNumber.size(); n++){
			if (mNumber[n] < 48 || mNumber[n] > 57){
				cout << "ERROR. Only input the number" << endl << endl;
				getNum = true;
				break;
			}
		}
	}
}
void talk(string& name, string& mNumber){
	//Name
	cout << "Name: ";
	cin.ignore();
	getline(cin, name);

	//Mnumber
	bool getNum = true;
	while (getNum){
		cout << "Mnumber (without the M): ";
		getline(cin, mNumber);

		getNum = false;

		//Make sure only numbers were inputted
		for (int n = 0; n < mNumber.size(); n++){
			if (mNumber[n] < 48 || mNumber[n] > 57){
				cout << "ERROR. Only input the number" << endl << endl;
				getNum = true;
				break;
			}
		}
	}
}

void task5(int opCount){
	cout << "Task 5 for " << opCount << " operations:" << endl;

	Student** students = new Student*[opCount];
	Hash<Student> array(opCount);
	HashLL<Student> linkedList(opCount);

	for(int x = 0; x < opCount; x++){
		//Make Student instance
		int randNum = 99999999 + (rand() % (99999999 - 10000000 + 1 ));
		string mNum = to_string(randNum);
		Student* addition = new Student(mNum);

		//Insert Student instance
		students[x] = addition;
		array.addItem(addition);
    	linkedList.addItem(addition);
	}

	//Itr testing
	for(int x = 0; x < opCount; x++){
		Student* cur = students[x];
		Student a = *array.getItem(cur);
		Student l = *linkedList.getItem(cur);

		if (a != *cur) cout << "Array has a getItem issue" << endl;
		if (l != *cur) cout << "LinkedList has a getItem issue" << endl;
	}

	cout << "For Hash there were " << array.getCompCount() <<  " comparisons conducted" << endl;
	cout << "For HashLL there were " << linkedList.getCompCount() <<  " comparisons conducted" << endl << endl;
}

void task3(){
	HashLL<Student> table;

	bool looper = true;
	while(looper){
		cout << "1. Add Student" << endl;
		cout << "2. Get Student by MNumber" << endl;
		cout << "3. Remove Student by MNumber" << endl;
		cout << "4. Check if Table is Empty" << endl;
		cout << "5. Get Table Size" << endl;
		cout << "6. Exit" << endl;
    	cout << "Enter a value 1-6: ";

		int option;
		cin >> option;

		if (option == 1){
			//IO handling
			string name, mNumber;
			talk(name, mNumber);

			//Add instance
			Student* s = new Student(mNumber, name);
			table.addItem(s);
			cout << endl;
		}
		else if (option == 2){
			//IO handling
			string mNumber;
			talk(mNumber);

			//Search for instance
			Student* s = new Student(mNumber);
			Student* ans = table.getItem(s);
			if (ans == nullptr) cout << endl << "This student does not exist" << endl;
			else{
				cout << endl << "Name: " << ans->getName() << endl;
				cout << "Mnumber: " <<ans->getMNumber() << endl;
			}
			cout << endl;
		}
		else if (option == 3){
			//IO handling
			string mNumber;
			talk(mNumber);

			//Remove instance
			Student* s = new Student(mNumber);
			Student* ans = table.removeItem(s);
			if (ans == nullptr) cout << endl << "This student does not exist" << endl;
			else{
				cout << endl << "The following student has been removed:" << endl;
				cout << "Name: " << ans->getName() << endl;
				cout << "Mnumber: " <<ans->getMNumber() << endl;
			}
			cout << endl;
		}
		else if (option == 4){
			if (table.isEmpty()) cout << "Table is empty" << endl << endl;
			else cout << "Table is not empty" << endl << endl;
		}
		else if (option == 5){
			cout << "Table size = " << table.getLen() << endl << endl;
		}
		else if (option == 6){
			looper = false;
		}
		else cout << "Please enter a correct value." << endl << endl;
	}
}

int main(){
	int ans = 0;

	bool loop = true;
	while (loop){
		cout << "3. Task 3" << endl;
		cout << "5. Task 5" << endl;
		cout << "Select which task to run: ";
		cin >> ans;

		//Error handling
		if (ans != 3 && ans != 5){
			cout << "ERROR. Enter a 3 or 5" << endl << endl; 
		}

		//Task calls
		else{
			if (ans == 3){
				cout << endl;
				task3();
			}
			else{
				cout << endl;
				task5(50);
				task5(150);
				task5(200);
				task5(250);
			}

			char cont = ' ';

			bool halt = true;
			while (halt){
				cout << "Would you like to continue? Y/n: ";
				cin >> cont;

				if (cont == 'Y' || cont == 'y'){
					cout << endl;
					halt = false;
				}
				else if (cont == 'N' || cont == 'n'){
					halt = false;
					loop = false;
				}
				else cout << "ERROR. Enter a Y or n" << endl << endl;
			}
		}
	}

	return 0;
}