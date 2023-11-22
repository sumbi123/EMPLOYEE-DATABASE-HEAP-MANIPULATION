// Assignment: ASU CSE310 HW#3 Spring 2023
// Name: Subash Lakshminarayanan
// ASU ID: 1121461384
// ASU Email Address: slaskh34@asu.edu
// Description: This program displays a menu of choices to a user
//              and performs the chosen task. It will keep asking a user to
//              enter the next choice until the choice of 'Q' (Quit) is entered.
//             	//---- is where you should add your own code
//********************************************************************************

#include "MaxHeap.h"

using namespace std;

void printMenu();
void heapSort(MaxHeap* oneMaxHeap);

int main()
{
	char input1 = 'Z';
	int id;
	string firstName, lastName;
    double salary;
	int capacity;   //array capacity and index
	bool success = false;

	//declare any other variables in case you need them
	int newID;
	Employee anEmployee;
	Employee maxEmployee;

	// instantiate an empty Heap
	MaxHeap* heap1 = nullptr;
	printMenu();

	do {
		cout << "\nWhat action would you like to perform?" << endl;
		cin.get(input1);
		input1 = toupper(input1);
		cin.ignore(20, '\n');	//flush the buffer

		// matches one of the cases
		switch (input1)
		{
			case 'C':	//create empty Heap with the relevant capacity
				cout << "\nPlease enter the heap capacity: ";
				cin >> capacity;
				cin.ignore(20, '\n');	//flush the buffer

				//Add your own code
				if (heap1 != nullptr){
          delete heap1;
        }
        heap1 = new MaxHeap(capacity);

				break;

			case 'D':	//delete the heap, call the destructor explicitly
				cout << "\nDelete the heap" << endl;
				//Add your own code
				delete heap1;
				//re-initialize it with capacity 4
				//Add your own code
				heap1 = new MaxHeap(4);
				break;

			case 'E':	//Extract the maximum node
                if (heap1 == nullptr)
                    cout << "\nEmpty heap, can NOT extract max" << endl;
                else
                {
                    //Add your own code
                    cout<<"Before extract heap max operation:"<<endl<<endl;
                    heap1->printHeap();
                    cout<<"After extract heap max operation:"<<endl<<endl;
                    heap1->extractHeapMax();
                    heap1->printHeap();
                }
				break;

			case 'F':	//Find an Employee
				cout << "\nEnter the Employee id you want to search: "<<endl;
				cin >> id;
				cin.ignore(20, '\n');	//flush the buffer

				//Add your own code
        if (heap1->isFound(id) == -1){
          cout << "Employee with id: " << id << " is NOT found" << endl;
        }
        else{
          cout << "Employee with id: " << id << " is found" << endl;
        }
				break;

			case 'I':	//Insert an Employee
				cout << "\nEnter the Employee firstName: "<<endl;
				cin >> firstName;

				cout << "Enter the Employee lastName: "<<endl;
				cin >> lastName;

				cout << "Enter the Employee id: "<<endl;
				cin >> id;

				cout << "Enter the Employee salary: "<<endl;
				cin >> salary;
				cin.ignore(20, '\n');	//flush the buffer

				//Add your own code
				if(heap1->heapInsert(id,firstName,lastName,salary) == true){
          cout<<"Employee "<<"\""<<firstName<<" "<<lastName<<"\""<<" is added"<<endl;
        }
        else if (heap1->heapInsert(id,firstName,lastName,salary) == false){
			cout<<"Duplicated Employee. Not added"<<endl<<endl;
          cout<<"Employee "<<"\""<<firstName<<" "<<lastName<<"\""<<" is NOT added"<<endl;
        }
				break;

			case 'K':	//increase the ID
				cout << "\nEnter the old employee id you want to increase: "<<endl;
				cin >> id;
				cout << "Enter the new employee id: "<<endl;
				cin >> newID;
				cin.ignore(20, '\n');	//flush the buffer

				//Add your own code
				if(newID <= id){
					cout<<"Increase ID error: new id is smaller than current id\n"<<endl;
					break;
				}
				if(heap1->isFound(id) == -1){
					cout<<"The old ID you try to increase does not exist"<<endl;
					break;
				}
				if(heap1->isFound(newID)!= -1){
					cout<<"The new ID you entered already exist, increase id operation failed\n"<<endl;
					break;
				}
				cout<<"Before increase ID operation:\n"<<endl;
				heap1->printHeap();
				anEmployee.id = newID;
				heap1->heapIncreaseID(heap1->isFound(id),anEmployee);
				cout<<"Employee with old id: "<<id<<" is increased to new id: "<<newID<<endl<<endl;
				cout<<"After increase id operation: "<<endl<<endl;
				heap1->printHeap();
				break;

			case 'M':	//get maximum node
			    //Add your own code
				if (heap1->getSize() == 0){
					cout<<"Empty heap, can NOT get max node"<<endl;
					break;
				}
				maxEmployee = heap1->getHeapMax();
				cout << "The maximum heap node is:" << endl;
        		cout << left << setw(8) << maxEmployee.id
        		<< setw(12) << maxEmployee.firstName
        		<< setw(12) << maxEmployee.lastName
        		<< setw(8) << fixed << setprecision(2) << maxEmployee.salary << endl;
				break;

			case 'P':	//Print heap contents
			    //Add your own code
				heap1->printHeap();

				break;

			case 'S':	//HeapSort
				cout << "\nHeap sort. Employees will be sorted in increasing order of their IDs" << endl;
				//Add your own code
				heapSort(heap1);
				break;

			case 'Q':	//Quit
				delete heap1;
				break;

			case '?':	//Display Menu
				printMenu();
				break;

			default:
				cout << "Unknown action\n";
				break;
		}
	} while (input1 != 'Q');
	return 0;
}

//*****************************************************
//Given a max heap, we want to sort it in increasing order according to ID, put the
//sorting result inside another array and print it out
void heapSort(MaxHeap* oneMaxHeap)
{
    //Add your own code
	int num =  oneMaxHeap->getSize(); //this gets the size of the array and sets the size to num
	Employee array[num];
	for(int i = num-1; i>=0; i--){    //this gets the max node of the array and inserts into the second array, then deletes the max node and repeats.
		array[i] = oneMaxHeap->getHeapMax();
		oneMaxHeap->extractHeapMax();
	}
	for (int i = 0; i < num; i++){
        Employee oneEmployee = array[i];
        cout << left;
	cout << setw(8) << oneEmployee.id
     << setw(12) << oneEmployee.firstName
     << setw(12) << oneEmployee.lastName
     << setw(8) << fixed << setprecision(2) << oneEmployee.salary << endl;

    }
}

//**The function displays the menu to a user**
void printMenu()
{
	cout << "Choice\t\tAction\n";
	cout << "------\t\t------\n";
	cout << "C\t\tCreate a heap\n";
	cout << "D\t\tDelete the heap\n";
	cout << "E\t\tExtract max node\n";
	cout << "F\t\tFind an Employee by ID\n";
	cout << "I\t\tInsert an Employee\n";
	cout << "K\t\tIncrease the ID\n";
	cout << "M\t\tGet the max node\n";
	cout << "P\t\tPrint the heap\n";
	cout << "S\t\tHeap Sort\n";
	cout << "Q\t\tQuit\n";
	cout << "?\t\tDisplay Help\n\n";
}