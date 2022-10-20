#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <iomanip>
#include <string>
#include <stdlib.h>

using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonModules.PythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonModules.PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonModules.PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}

void display() {
	cout << endl << string(5, ' ') << string(39, '*') << endl;
	cout << string(5, ' ') << "*" << string(12, ' ') << "Grocer Corner" << string(12, ' ') << "*" << endl;
	cout << string(5, ' ') << "*" << string(37, '*') << "*" << endl;
	cout << string(5, ' ') << "*" << string(37, ' ') << "*\n";
	cout << string(5, ' ') << "*    1.List of Items and Quantity " << string(4,' ') << "*\n";
	cout << string(5, ' ') << "*" << string(37, ' ') << "*\n";
	cout << string(5, ' ') << "*    2.Search Item Quantity" << string(11, ' ') << "*\n";
	cout << string(5, ' ') << "*" << string(37, ' ') << "*\n";
	cout << string(5, ' ') << "*    3.Display Histogram" << string(14, ' ') << "*\n";
	cout << string(5, ' ') << "*" << string(37, ' ') << "*\n";
	cout << string(5, ' ') << "*    4.Exit Program" << string(19, ' ') << "*\n";
	cout << string(5, ' ') << "*" << string(37, ' ') << "*\n";
	cout << string(5, ' ') << "*" << string(37, '*') << "*\n";
	cout << endl;
	cout << string(5, ' ') << "Enter Option: ";
}


int main() {
	//CallProcedure("printsomething");
	//cout << callIntFunc("PrintMe", "House") << endl;
	//cout << callIntFunc("SquareValue", 2);
	//cout << endl;

	while (true) {
		system("title Corner Grocer: Grocery-Tracking Program ");
		display();
		int delay = 800;
		int userInput = 0;
		string userItem;
		cin >> userInput;
		while (cin.fail()) {
			system("cls");
			cout << "Input must be an integer!" << endl;
			Sleep(delay);
			cin.clear();
			cin.ignore(256, '\n');
			break;
		}
		if (userInput > 4) {
			system("cls");
			cout << "Invalid input!\n";
			Sleep(delay);
		}
		system("cls");
		switch (userInput) {
		case 1:
			system("cls");
			CallProcedure("ListItemsAndAmount");
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			cout << "Enter an item: ";
			cin >> userItem;
			userItem[0] = toupper(userItem[0]);
			while (cin.fail()) {
				cout << "Input must be an item in the list!" << endl;
				cin.clear();
				cin.ignore(256, '\n');
				break;
			}
			system("cls");
			cout << userItem << ": "
				<< callIntFunc("FrequencyOfItem", userItem) << endl; 

			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			CallProcedure("CreateHistogramFile");
			CallProcedure("DrawHistogram");
			system("pause");
			system("cls");
			break;
		case 4:
			cout << "System shutting down...\n";
			Sleep(delay);
			system("cls");
			return 0;
		default:
			system("cls");
			break;
		}
	}

	return 0;
}