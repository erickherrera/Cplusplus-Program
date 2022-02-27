#include <Python.h>
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <cmath>
#include <string>
#include <fstream>
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
	PyObject* my_module = PyImport_ImportModule("PythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	PyErr_Print();

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
	pName = PyUnicode_FromString((char*)"PythonCode");
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
	pName = PyUnicode_FromString((char*)"PythonCode");
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


int main()
{
	int userChoice;
	do {
		cout << "1: Show all items purchased today and the amount for each" << endl << "2: Search for item purchase frequency" <<
		endl << "3: Display \"Histogram\""<< endl << "4: Exit Program"<< endl;
		cin >> userChoice;
		switch (userChoice) {
			case 1:
			{
				system("CLS");
				CallProcedure("CountAll");
				cout <<endl;
			}
			break;
			case 2:
			{	
				system("CLS");
				cout << endl << "Item to search: ";
				string item;
				int wordCount = 0;
				cin >> item;
				wordCount = callIntFunc("CountInstances", item);
				std::cout << std::endl << item << " : " << wordCount << std::endl << std::endl;

			}
			break;
			case 3: {
				ifstream fileInput;
				string itemName;
				int itemQuantity = 0;
				system("CLS");
				CallProcedure("Histogram");

				fileInput.open("frequency.dat");
				fileInput >> itemName;
				fileInput >> itemQuantity;
				while (!fileInput.fail()) {
					std::cout << std::setw(14) << std::left << itemName << std::setw(6);

					//Print itemQuantity number of asterisks
					for (int i = 0; i < itemQuantity; i++) {
						//Print green asterisks in line.
						std::cout << std::right << "*";
					}
					//Prepare for the next line, then set the next item's name and quantity.
					std::cout << std::endl;
					fileInput >> itemName;
					fileInput >> itemQuantity;
				}
				//Close frequency.dat
				fileInput.close();
			}
			break;
			case 4:
			{
				cout << "Thank you...Exiting..." << endl;
				exit(userChoice);
			}
			break;

			default:
				cout << "Invalid selection please try again...";
				cout << endl;
				break;
		}	
	} while (userChoice >= 0);
	
}