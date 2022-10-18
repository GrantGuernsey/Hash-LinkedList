#ifndef HASHLL
#define HASHLL

#include "List.h"
#include "Hash.h"
using namespace std;

template <typename T>
class HashLL : public Hash<T>{
private:
	/* HASH TABLE ATRRIBUTES */
	List<T>* table;
	int count, len;

	/* IMPORTED HASH FUNCTION */
	using Hash<T>::hash;

public:
	/* CONSTRUCTORS AND DESTRUCTOR */
	HashLL(){
		count = 0;
		len = 100;

		table = new List<T>[len];
		for (int n = 0; n < len; n++) {
			table[n] = List<T>();
		}
	}
	HashLL(int length){
		count = 0;
		len = length;
		
		table = new List<T>[len];
		for (int n = 0; n < len; n++) {
			table[n] = List<T>();
		}
	}
	~HashLL(){
		delete[] table;
	}

	/* UTILITY METHODS */
	bool isEmpty(){
		return count == 0;
	}
	int getLen(){
		return count;
	}
	int getCompCount(){
		if (isEmpty()) return -1; 

		int itr = 0;

		//Iterate through the linked lists
		for (int n = 0; n < len; n++) {
			//Skips empty lists
			if (!table[n].isEmpty()){
				itr += table[n].getCompCount();
			}
		}

		return itr;
	}

	/* DISPLAY METHOD */
	void print(){
		//Empty table handling
		if (isEmpty()){ 
			cout << "Empty table" << endl;
			return;
		}
		
		//Iterate through the linked lists
		for (int n = 0; n < len; n++) {
			//Skips empty lists
			if (!table[n].isEmpty()){
				cout << "Contents at index " << n << ":" << endl;

				//Create an array that contains the elements of the list
				int end = table[n].getLen();
				T* arr = new T[end];
				table[n].makeArray(arr);

				//Iterate through the elements
				for (int i = 0; i < end; i++){
					cout << arr[i] << endl;
				}
				cout << endl;

				delete[] arr; //Clean-up
			}
		}
	}

	/* HASH TABLE METHODS */
	void addItem(T* inVal){
		//Find list that would contain data
		T data = *inVal;
		int idx = hash(data, len);

		table[idx].addItem(data);
		count += 1;
	}
	T* getItem(T* outVal){
        //Empty table handling
        if (isEmpty()) return nullptr;

        //Find list that would contain data
		T data = *outVal;
		int idx = hash(data, len);

        //Return
        if (!table[idx].contains(data)) return nullptr;
		T* retVal = new T[1]{table[idx].getItem(data)};
        return retVal;
    }
	T* removeItem(T* outVal){
		//Empty table handling
		if (isEmpty()) return nullptr;

		//Find list that would contain data
		T data = *outVal;
		int idx = hash(data, len);

		//Remove data and return
		if (!table[idx].contains(data)) return nullptr;
		T* retVal = new T[1]{table[idx].removeItem(data)};
		count -= 1;
		return retVal;
	}
};

#endif