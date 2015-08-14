/*************************************************************************//**
 * @file 
 *
 * @brief this file contains the Class for mylist.cpp.  It 
 * should be included with prog2.cpp.
 ****************************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <string>
using namespace std;



/*! 
 * @brief The Mylist class holds a list and allows multiple class functions
 * to work on the list
 *
 * @details Mylist class can insert anywhere in the linked list, or remove from
 * anywhere in the list. It can also find any value and count the numbers in
 * the list.
 */ 
#ifndef __MYLIST__H__
#define __MYLIST__H__
class mylist 
{ 
 public: 
 /*******************************************************************************
 *                         Function Prototypes
 ******************************************************************************/

 /*!
 *  @brief The constructor, creates an initial list.
 */
 mylist(); 

/*!
 *  @brief The destructor, destroys the list.
 */
 ~mylist(); 

 /*!
 *  @brief Inserts into a list
 */
 bool insert ( int value );

 /*!
 *  @brief inserts at end of list
 */
 bool insertEnd ( int value );

 /*!
 *  @brief inserts at start of list
 */
 bool insertStart ( int value );

 /*!
 *  @brief removes value from list
 */
 bool remove ( int value ); 

 /*!
 *  @brief serches for a target in a list
 */
 bool find ( int target ); 

 /*!
 *  @brief Checks list to see if it is empty
 */
 bool isEmpty(); 

 /*!
 *  @brief counts the number of nodes in the list
 */
 int count(); 

 /*!
 *  @brief Prints the list to a file
 */
 void print( ostream &fout );

 /*!
 *  @brief Prints the list to a file
 */
 void print( );

 /*!
 *  @brief sums up the items in the list
 */
 int sumUp( );

 /*!
 *  @brief gives the average of the list.
 */
 double mylist::averageUp( int sum, int count);


 private: 

 /*!
 * @brief holds the values stored in a given node
 *
 * @details The node has a pointer to the next node and a number stored in num
 */
 struct node 
 { 
 int num; /*!< part of a node that holds a value in the node */
 node *next; /*!<part of a node that points to the next node */
 }; 
 node *headptr; /*!<pointer to the very front of a list */

}; 

#endif

