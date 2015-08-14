/*************************************************************************//**
 * @file 
 *
 * @brief This file shows the documentation of other source code.
 ****************************************************************************/
#include "mylist.h"

/**************************************************************************//** 
 * @author Marcus Berger
 * 
 * @par Description: 
 * Creates a list that uses the mylist class 
 *
 *****************************************************************************/
mylist::mylist()
{
	
}

/**************************************************************************//** 
 * @author Johnny Ackerman
 * 
 * @par Description: 
 * Destroyes the list when the list goes out of scope
 * 
 *****************************************************************************/
mylist::~mylist()
{
	node *temp; //temporary node so that the pointer to a node is not lost
	while ( headptr != nullptr )
	{
		//sets tempt to the first value in the list
		temp = headptr;

		//set headptr to the second value in the list making in the new first
		//value
		headptr = headptr -> next;

		//delets the old first value
		delete temp;
	}
}

/**************************************************************************//** 
 * @author Johnny Ackerman
 * 
 * @par Description: 
 * Checks a list in the mylist class to see if it is empty
 * 
 * @returns true the list is empty
 * @returns false the list is not empty
 * 
 *****************************************************************************/
bool mylist::isEmpty()
{
	//if headptr points to nothing it must be empty
	if (headptr == nullptr)
	{
		return true;
	}

	//if headptr points to anything else it is not empty
	return false;
}

/**************************************************************************//** 
 * @author Marcus Berger
 * 
 * @par Description: 
 * outputs a list from the mylist class to an open output file
 * 
 * @param[in]      fout - Output file
 * 
 *****************************************************************************/
 void mylist::print( ostream &fout )
{
	int j = 0;
	node *temp; //use a temporary value so that headpointer is not affected
	temp = nullptr; //makes sure temp is empty
	temp = headptr; //sets temp to the start of the list

	//as soon as temp is nullptr the entire list has been output to the file
	while(temp != nullptr)
	{
		//gives 7 spaces to each number as it is outputed
		j++;
		fout << setw(7) << temp -> num;
		if(j % 10 == 0)
		{
			fout << endl;
		}

		//goes to next number
		temp = temp -> next;
	}
	return;
}

 /**************************************************************************//** 
 * @author Johnny Ackerman
 * 
 * @par Description: 
 * outputs a list from the mylist class to the screen
 * 
 *****************************************************************************/
 void mylist::print( )
{
	int j = 0;
	node *temp; //use a temporary value so that headpointer is not affected
	temp = nullptr; //makes sure temp is empty
	temp = headptr; //sets temp to the start of the list

	//as soon as temp is nullptr the entire list has been output to the file
	while(temp != nullptr)
	{
		//gives 7 spaces to each number as it is outputed
		j++;
		cout << setw(7) << temp -> num;
		if(j % 10 == 0)
		{
			cout << endl;
		}

		//goes to next number
		temp = temp -> next;
	}
	return;
}

 /**************************************************************************//** 
 * @author Johnny Ackerman
 * 
 * @par Description: 
 * A detailed description of the function.  It can
 * extend to multiple lines
 * 
 * @returns count the number of items in the list
 * 
 *****************************************************************************/
int mylist::count()
{
	node *temp; //temporary value so headptr isn't affected
	int count = 0; //number of nodes in the list

	temp  = nullptr;//makes sure temp is empty
	temp = headptr;//sets temp to start of list

	//runs threw entire list counting nodes
	while( temp != nullptr)
	{
		count++;
		temp = temp -> next;
	}
	
	return count;
}


/**************************************************************************//** 
 * @author Johnny Ackerman
 * 
 * @par Description: 
 * looks to see if an item is in the list
 * 
 * @param[in]      target - item that is being looked for
 * 
 * @returns true the item was found
 * @returns false the item wasn't found.
 * 
 *****************************************************************************/
bool mylist::find( int target )
{
	//sets temp to headptr so headptr isn't changed
	node *temp;
	temp = headptr;

	//looks though entire linked list for target value
	while( temp != nullptr)
	{
		if ( temp -> num == target)
			return true;
		temp = temp -> next;
	}
	return false;
}


/**************************************************************************//** 
 * @author Johnny Ackerman
 * 
 * @par Description: 
 * inserts a value into the list in order
 * 
 * @param[in]      value - value being inserted
 * 
 * @returns true program ran successful.
 * @returns false memory was not allocated
 * 
 *****************************************************************************/
bool mylist::insert( int value )
{
	//iterators that run though the linked list
	node *prev = headptr;
	node *curr = headptr;

	//temporary value to hold what will be inserted to the list.
	node *temp;

	//allocates node
	temp = new ( nothrow ) node;
	if ( temp == nullptr )
	{
		//handles node failure
		cout << "Dynamicly failed to allocated a node" << endl;
		exit(0);
	}

	//sets temp node to passed in value
	temp -> num = value;
	temp -> next = nullptr;

	//sets temp to first position in array if empty
	if ( isEmpty() )
	{
		headptr = temp;
		return true;
	}

	//sets temp to first position in array
	if ( (temp -> num) <= (headptr -> num) )
	{
		temp -> next = headptr;
		headptr = temp;
		return true;
	}

	
	//loops though and puts temp in order
	//will handle last position
	while ( curr != nullptr && curr -> num < temp -> num )
	{
		prev = curr;
		curr = curr -> next;
	}

	//cleans up pointers
	prev -> next = temp;
	temp -> next = curr;

	return true;
}


/**************************************************************************//** 
 * @author Marcus Berger
 * 
 * @par Description: 
 * removes a specific value from the list.
 * 
 * @param[in]      value - item being removed
 * 
 * @returns true program ran successful.
 * @returns false program didn't find a value
 * 
 *****************************************************************************/
bool mylist::remove( int value )
{
	//itterators that loop though the list
	node *prev;
	node *curr;

	//temporary value need so that the pointers stay in order
	node *temp;

	//makes sure that temp doesn't have a garbage value
	temp = nullptr;

	//checks if the list is empty
	if ( isEmpty() )
	{
		return false;
	}

	//checks if the value is at the start of the list
	if ( (headptr -> num) == value )
	{
		temp = headptr;
		headptr = headptr -> next;
		delete temp;
		return true;
	}

	//sets itterators to start of list
	prev = headptr;
	curr = headptr;

	//looks for item in the list
	while ( curr != nullptr && (curr -> num) != value )
	{
		prev = curr;
		curr = curr -> next;
	}

	//if it looked all the way though without finding the value return false
	if ( curr == nullptr )
	{
		return false;
	}

	//cleans up ptr values
	((prev -> next) = (curr -> next));

	//reomves the value
	delete curr;

	return true;
}



/**************************************************************************//** 
 * @author Johnny Ackerman
 * 
 * @par Description: 
 * puts an item at the biggining
 * 
 * @param[in]      value - value being inserted
 * 
 * @returns true program ran successful.
 * @returns false memory not allocated.
 * 
 *****************************************************************************/
bool mylist::insertStart( int value )
{
	node *temp;
	//allocates node
	temp = new ( nothrow ) node;
	if ( temp == nullptr )
	{
		//handles node failure
		cout << "Dynamicly failed to allocated a node" << endl;
		exit(0);
	}

	//sets temp node to passed in value
	temp -> num = value;
	temp -> next = nullptr;

	//sets temp to first position in array if empty
	if ( isEmpty() )
	{
		headptr = temp;
		return true;
	}

	//sets temp to first position in array
	temp -> next = headptr;
	headptr = temp;

	return true;
}

/**************************************************************************//** 
 * @author Johnny Ackerman
 * 
 * @par Description: 
 * inserts item at the end of the function
 * 
 * @param[in]      value - value being inserted
 * 
 * @returns true program ran successful.
 * @returns false memory allocation failed
 * 
 *****************************************************************************/
bool mylist::insertEnd( int value )
{
	//iterators
	node *prev;
	node *curr;

	//new node being inserted
	node *temp;

	//allocates node
	temp = new ( nothrow ) node;
	if ( temp == nullptr )
	{
		//handles node failure
		cout << "Dynamicly failed to allocated a node" << endl;
		exit(0);
	}

	//sets temp node to passed in value
	temp -> num = value;
	temp -> next = nullptr;

	//sets up itterators at the start of the list
	prev = headptr;
	curr = headptr;

	//handles last position
	while ( curr != nullptr)
	{
		prev = curr;
		curr = curr -> next;
	}

	//cleans up pointers
	prev -> next = temp;
	temp -> next = curr;

	return true;
}

/**************************************************************************//** 
 * @author Johnny Ackerman
 * 
 * @par Description: 
 * adds all the numbers in a list together
 * 
 * @returns 0 program was empty or list actually added to 0
 * @returns sum the added numbers from the entire list.
 * 
 *****************************************************************************/
int mylist::sumUp( )
{
	int sum = 0;//numbers being added
	node *temp = headptr;//sets temp to headptr to protect data

	//checks for empty list
	if( headptr == nullptr );
	{
		return 0;
	}

	//adds numbers from list
	while ( temp != nullptr )
	{
		sum = sum + temp -> num;
		temp = temp -> next;
	}

	//returns sum of numbers from list
	return sum;
}

/**************************************************************************//** 
 * @author Johnny Ackerman
 * 
 * @par Description: 
 * returns the average of the items in the list
 * 
 * param[in] sum sum of values in list
 * param[in] count number of items in list
 *
 * @returns 0 program was empty or list actually averaged to 0
 * @returns ave the average of the numbers from the entire list.
 * 
 *****************************************************************************/
double mylist::averageUp( int sum, int count )
{
	//initialization
	double average = 0;

	//checks for an empty list to stop any posible dividing by 0;
	if( headptr == nullptr )
	{
		return 0;
	}

	//average calculation
	average = double(sum) / double(count);

	return average;
}