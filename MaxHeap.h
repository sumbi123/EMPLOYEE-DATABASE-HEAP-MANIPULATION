// Assignment: ASU CSE310 HW#3 Spring 2023
// Your Name: Subash Lakshminarayanan
// ASU ID: 1221461384
// ASU Email address: slaksh34@asu.edu
// Description: This is the MAXHEAP that get implemented into the main class
//********************************************************
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

//Each Employee has a unique id
struct Employee
{
    string firstName, lastName;
    int id;
    double salary;
};

//class MaxHeap represents a max heap that contains Employee objects. The underline data structure
//is a one dimensional array of Employee.
class MaxHeap
{
    private:
    struct Employee* employeeArr;	//an array of Employees
    int capacity, size;

	public:
    MaxHeap(int capacity);
    ~MaxHeap();

	Employee* getEmployeeArr();
	int getSize();
	int getCapacity();
	int isFound(int anID);
	bool heapIncreaseID(int index, Employee oneEmployeeWithNewID);
	bool heapInsert(int id, string firstName, string lastName, double salary);
	void heapifyUp(int index);
    void heapifydown(int index);
	Employee getHeapMax();
	void extractHeapMax();
	int leftChild(int parentIndex);
	int rightChild(int parentIndex);
	int parent(int childIndex);
	void printHeap();
};

//Constructor to dynamically allocate memory for a heap with the specified capacity
MaxHeap::MaxHeap(int capacity)
{
 	//Add your own code
 	this->capacity = capacity;
    this->size = 0;
    this->employeeArr = new Employee[capacity];
}

//Destructor
//Before termination, the destructor is called to free the associated memory occupied by the heap.
//and prints the number of nodes deleted by it.
MaxHeap::~MaxHeap()
{
	//Add your own code
 	delete[] employeeArr;
    int employeeCount = size;
	cout << "\nThe number of deleted Employees is: " << employeeCount << endl;
}

//*******************************************************************
//increase the Employee's id located at the specific index
bool MaxHeap::heapIncreaseID(int index, Employee oneEmployeeWithNewID)
{
	if (index < 0 || index >= size )   //checking for if the array is empty
    {
        return false;
    }

    //Add your own code
    employeeArr[index].id = oneEmployeeWithNewID.id;  // taking the id of the employeewithnewid and replacing it with given index of the original array
    heapifyUp(index); //heapifing the last node up to maintain heap max property
    return true;
}

//Add your own code to finish other functions
Employee* MaxHeap::getEmployeeArr(){
    return employeeArr; //returns the array of employees
}
int MaxHeap::getSize(){
    int a = size; //returns the size of the array
    return a;
}

int MaxHeap::getCapacity(){
    int b = capacity; //returns the capacity of the array
    return b;
}

int MaxHeap::isFound (int anID){
for (int i = 0; i < size; i++){   //checks if the id was found inside the array
    if(employeeArr[i].id == anID){
        return i;
    }
}
 return -1;
}

bool MaxHeap::heapInsert (int id, string firstName, string lastName, double salary){

    for (int i =0; i<size; i++){   //checks if the id given is already inside the array
        if(employeeArr[i].id==id){
            return false;
        }
    }
    if(size == capacity){  //if the size of the array equals the capacity the capcity gets doubled
    capacity = capacity*2;
    Employee*newArr = new Employee[capacity];

    for (int i = 0; i<size; i++){              
        newArr[i] = employeeArr[i];
    }
    delete[] employeeArr;
    employeeArr = newArr;
    cout <<"Reach the capacity limit, double the capacity now."<<endl;
    cout <<"\nThe new capacity now is "<<capacity<<endl<<endl;

    }
    Employee newEmp = {firstName, lastName, id, salary};  //creating a new object employee and increasing it to maintain heap property
    size=size+1;
    employeeArr[size-1] = newEmp;
    heapIncreaseID(size-1, newEmp);
    return true;
}

void MaxHeap::heapifyUp(int index){  
    int pindex = parent(index);

    if(employeeArr[pindex].id>0){  // heapifying the last node of the tree up to maintain the max heap property

    if ( employeeArr[index].id > employeeArr[pindex].id) {  //comparing the given node to the parent node and if the parent node is smaller than swap the two nodes
        swap(employeeArr[index], employeeArr[pindex]);
        heapifyUp(pindex);
    }
    }
}
void MaxHeap::heapifydown(int index){
    int l = leftChild(index);  //heapifying down, taking the root node or the max node of the heap and moving it down to maintain heap property
    int r = rightChild(index);
    int max = index;

    if (l < size && employeeArr[l].id > employeeArr[max].id) {
        max = l;
    }

    if (r < size && employeeArr[r].id > employeeArr[max].id) {
        max = r;
    }

    if (max != index) {
        swap(employeeArr[index], employeeArr[max]);
        heapifydown(max);
    }
}

Employee MaxHeap:: getHeapMax(){
    if(size == 0) {
        Employee empty;
        return empty;
    }
        return employeeArr[0];  // since the heap maintains max heap property the max node is always the root
}

void MaxHeap::extractHeapMax(){
    if(size == 0){
        return;
    }
    Employee root = employeeArr[0];
    employeeArr[0] = employeeArr[size-1];
    size--;
    heapifydown(0);   //deleting the max node of the heap
}

int MaxHeap::leftChild(int parentIndex){
    int num = (2*parentIndex)+1;   //equation for the left child of the parent index
    return num;
}
int MaxHeap::rightChild(int parentIndex){
    int num = (2*parentIndex)+2;   //equation for the right child of the parent index
    return num;
}
int MaxHeap::parent(int childIndex){
    int num = ((childIndex-1)/2);    //equation for the parent index
    return num;
   
}

void MaxHeap::printHeap(){
    if(size == 0){
        cout<<"Empty heap, no elements"<<endl;
        return;
    }
    cout << "Heap capacity = " << capacity << endl;
    cout << "\nHeap size = " << size << endl<<endl;

    for (int i = 0; i < size; i++){
        Employee oneEmployee = employeeArr[i];
        cout << left;
cout << setw(8) << oneEmployee.id
     << setw(12) << oneEmployee.firstName
     << setw(12) << oneEmployee.lastName
     << setw(8) << fixed << setprecision(2) << oneEmployee.salary << endl;

    }
}































