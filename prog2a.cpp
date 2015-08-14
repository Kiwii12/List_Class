/*************************************************************************//**
 * @file 
 *
 * @mainpage Program 2 - Linked lists
 * 
 * @section course_section Course Information 
 *
 * @author Marcus Berger
 * 
 * @date Nov 4, 2013
 * 
 * @par Professor: 
 *         Professor Schrader
 * 
 * @par Course: 
 *         CSC-250 - M001-2013FA -  2:00-3:00 PM MWTHF
 * 
 * @par Location: 
 *         Classroom - CB 166
 *
 * @section program_section Program Information 
 * 
 * @details This Program will read in integers from a file and put them into
 *		two lists based on the following rules: (1) if the integer is not in
 *		the first linked list. Put it into the list in order. (2) If the number
 *		is in the first list, remove it from the list and put it in the second
 *		list at the biggining. (3) If it is in the second list remove from both
 *	    lists and put at the end of the second list.
 *
 * The program uses command line arguments to open the file with the intagers
 *		and then it will change the ending of that file to .rus based on the
 *		last '.' found in the file.
 *
 * The output file will print out both list starting with the list number
 *		followed by 80 '-' on the next line. Each number is alloted 7 spaces
 *		per number so if each number is 3 digits long there will be 4 spaces
 *		between numbers. Prog2a.ccp uses STL functions.
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions: 
 *      Runs from the commandline. Looks at commandline aurgument for a
			file filled with numbers.
 * 
 * @par Usage: 
   @verbatim  
   c:\> Prog2.exe 
   @endverbatim 
 *
 * @section todo_bugs_modification_section Todo, Bugs, and Modifications
 * 
 * @todo add more functions
 * 
 * @par Modifications and Development Timeline: 
   @verbatim 
   Date          Modification 
   ------------  -------------------------------------------------------------- 
   Oct 24, 2013  started part 2.
   Oct 26, 2013  started some doxygen
   oct 28, 2013  lots of doxygen
   Nov  1, 2013  finsihed doxygen and added extra functions
   @endverbatim
 *
 *****************************************************************************/

/*************************************************************************//**
 * @file 
 *
 * @brief pulls in all the libraries needed for library functions
 ****************************************************************************/
#include <list>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <string>
using namespace std;

/**************************************************************************//** 
 * @author Marcus Berger
 * 
 * @par Description: 
 * This function creates to lists and organizes the list based on three rules
 * Rule one: if it is not in the first list, put in the first list in order
 * Rule two: if it is in list one but not in list two put at the start of list
 *			 two, and remove from list 1.
 * Rule three: if it is in list two remove from list 2 and at the end of list
 *             three
 * 
 * @param[in]      argc - Number of aurments from the commandline
 * @param[out]     argv - an array of commandline aurgments
 * 
 * @returns 0 program ran successful.
 * @returns -1 there was an error with a file. 
 * @returns -2 Used incorrectly
 * 
 *****************************************************************************/
int main1(int argc, char* argv[])
{
	ifstream fin; // input file stream
	ofstream fout; // output file stream
	list<int> list1; // list1
	list<int> list2; // list2
	list<int>::iterator it; // iterator
	
	unsigned int period; // int for period
	int value = 0; // value 
	int j = 0; // value for loop

	string filename; // string for filename
	filename = string(argv[1]); // filename equals argv[1]

	// errror check command line
	if (argc < 2)
	{
		cout << "Usage: prog2.exe filename" << endl;
		cout << "filename = name of input file" << endl;
		return -1;
	}
	if (argc > 2)
	{
		cout << "Usage: prog2.exe filename" << endl;
		cout << "filename = name of input file" << endl;
		return -1;
	}

	

	//opens file using file name from the commandline
	fin.open(filename);
	//checks if file was opened succesfully
	if (!fin)
	{
		cout << "Error opening file";
		//all_array_delete( vars );
		return(-1);
	}

	while( fin >> value )
	{
		//if it can remove from list1 it must be in list 1
		if ( find(list1.begin(), list1.end(), value) != list1.end()) // list 1 check
		{
			list1.remove(value); // run remove for list1
			if ( find(list2.begin(), list2.end(), value) != list2.end())// list 2 check
			{
				list2.remove(value); // run remove for list2
				list2.push_back( value );//needs to insert at end of list 2

			}
			else
			{
				list2.push_front( value );//needs to insert at beggining of list 2
			}
		}
		else
		{
			if ( find(list2.begin(), list2.end(), value) != list2.end())// list 2 check
			{
				list2.remove( value ); // run remove for list 2
				list2.push_back( value );//needs to insert at end of list 2
			}

			else
			{
				list1.push_front(value);//needs to insert in order in list 1
			}
		}

	}
	list1.sort(); // sort list1
	fin.close(); // close ifstream

	
	//finds the last period and changes it to ".rus"
	period = filename.rfind('.');
	// string iterator for .rus
	string::iterator i = filename.end();
	//error check period
	if (period == string::npos)
	{
		cout << "error no period found";
	}
	if (period != string::npos)
	{
		for(int i = filename.length(); i != period; i--)
		filename.pop_back();
	}
	filename.append(".rus"); //append .rus to filename

	fout.open(filename); // open output file
	//checks if file was opened succesfully
	if (!fout)
	{
		cout << "Error opening file";
		return(-1);
	}

	fout << "List 1" << endl;
	fout << "---------------------------------------------------------------"
		<< "-----------------" << endl;
		 //list 1 output
	j = 0;
	for(it = list1.begin(); it != list1.end(); it++) 
	{
		j++;
		fout << setw(7) << *it;
		if ( j % 10 == 0 )
		{
			fout << endl;
		}
	}

	// list 2 output
	fout << endl << "List 2" << endl;
	fout << "---------------------------------------------------------------"
		<< "-----------------" << endl;

	j = 0;
	for(it= list2.begin(); it != list2.end(); it++) 
	{
		j++;
		fout << setw(7) << *it;
		if ( j % 10 == 0 )
		{
			fout << endl;
		}
	}

	


	return 0;
}