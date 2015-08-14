/*************************************************************************//**
 * @file 
 *
 * @mainpage Program 2 - Linked lists
 * 
 * @section course_section Course Information 
 *
 * @author Marcus Berger, Johnny Ackerman
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
 *         Classroom - CB 116
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
 *		between numbers.
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
   Oct 21, 2013  Wrote most of the mandatory list function and put commandline 
				 Aurments in main.
   Oct 23, 2013  Wrote the main function, and fixed alot of errors in the
				 mylist functions
   Oct 24, 2013  part 1 seems to be working, started part 2.
   Oct 26, 2013  started some doxygen
   oct 28, 2013  lots of doxygen
   Nov  1, 2013  finsihed doxygen and added extra functions
   @endverbatim
 *
 *****************************************************************************/


/*************************************************************************//**
 * @file 
 *
 * @brief Holds the list class and defines a node and whats in the node.
 ****************************************************************************/
#include "mylist.h"

/**************************************************************************//**
 * @author Marcus Berger, Johnny Ackerman
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
int main(int argc, char* argv[])
{
	ifstream fin; //varible for opening the input file
	ofstream fout; //varible for opening the output file

	unsigned int period;
	int value = 0; //temperary hold for input values

	string filename; //stores the input, and later the output, file name
	filename = string(argv[1]); //stores input file name

	//Checks usage and outputs a usage statment
	if (argc < 2)
	{
		cout << "Usage: prog2.exe filename" << endl;
		cout << "filename = name of input file" << endl;
		return -2;
	}
	if (argc > 2)
	{
		cout << "Usage: prog2.exe filename" << endl;
		cout << "filename = name of input file" << endl;
		return -2;
	}

	//creats list 1 and 2
	mylist list1; 
	mylist list2; 

	//opens file using file name from the commandline
	fin.open(filename);
	//checks if file was opened succesfully and outputs error message
	if (!fin)
	{
		cout << "Error opening file";
		return(-1);
	}

	//reads in the entire file sorting into list1 and list2 for each number
	while( fin >> value )
	{
		//if it can remove from list1 it must be in list 1
		if ( list1.remove(value) )
		{
			//if an item is removed then it must of been in list 2
			if ( list2.remove(value) )
			{
				list2.insertEnd( value );//needs to insert at end of list 2
			}
			else //if it is not in list 2 it needs to go at the biggining of list 2
			{
				list2.insertStart( value );				
			}
		}
		else
		{
			//if an item is removed then it must of been in list 2
			if ( list2.remove(value) ) // list 2 check
			{
				list2.insertEnd( value );//needs to insert at end of list 2
			}

			else
			{
			list1.insert(value);//needs to insert in order in list 1
			}
		}

	}

	//closes the input file
	fin.close();

	//finds the last period and changes it to ".rus"
	period = filename.rfind('.');
	// string iterator for .rus
	string::iterator i = filename.end();
	if (period == string::npos)
	{
		cout << "error no period found";
	}
	if (period != string::npos)
	{
		for(int i = filename.length(); i != period; i--)
		filename.pop_back();
	}
	filename.append(".rus");


	//opens the renamed file name for output
	fout.open(filename);

	//checks if file was opened succesfully
	if (!fout)
	{
		cout << "Error opening file";
		return(-1);
	}


	//file formating
	fout << "List 1" << endl;
	fout << "---------------------------------------------------------------"
		<< "-----------------" << endl;

	//outputs the first list
	list1.print( fout ); //list 1

	//file formating for the second part
	fout << endl << "List 2" << endl;
	fout << "---------------------------------------------------------------"
		<< "-----------------" << endl;

	list2.print( fout ); //list 2


	
	//program ran successfully
	return 0;
}