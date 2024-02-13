//Muhammed Ümit TAVUS -- CS201-01--22203317

#include <iostream>
#include <string>
#include "Employee.h"

// Constructor and Destructor
Employee::Employee()
{
    name = "";
    title = "";
    assignedIssuesSize = 0;
    assignedIssues = nullptr;

}

Employee::Employee(const string newName, const string newTitle)
{
    name = newName;
    title = newTitle;
    assignedIssuesSize = 0;
    assignedIssues = nullptr;
}



Employee::~Employee()
{
    delete [] assignedIssues;
}

// Operator "=" overloading

Employee& Employee::operator=( const Employee& right ) {

    if ( &right != this ) {

        name = right.name;
        title = right.title;

        if ( assignedIssuesSize != right.assignedIssuesSize ) {

            if ( assignedIssuesSize > 0 )
                delete[] assignedIssues;

            assignedIssuesSize = right.assignedIssuesSize;

            if ( assignedIssuesSize > 0 )
                assignedIssues = new Issue[ assignedIssuesSize ];

            else
                assignedIssues = nullptr;
 }
        for ( int i = 0; i < assignedIssuesSize; i++ )
            assignedIssues[ i ] = right.assignedIssues[ i ];

 }
    return *this;
}



// Getters

string Employee::  getName() const
{
    return name;
}
string Employee ::  getTitle() const
{
    return title;
}
int Employee :: getAssignedIssuesSize() const
{
    return assignedIssuesSize;
}
Issue* Employee ::  getAssignedIssues() const
{
    return assignedIssues;
}

// Setters

void Employee ::  setName(const string newName)
{
    name = newName;
}
void Employee ::  setTitle(const string newTitle)
{
    title = newTitle;
}
void Employee :: setAssignedIssuesSize(const int newAssignedIssuesSize)
{
    assignedIssuesSize = newAssignedIssuesSize;
}
void Employee ::  setAssignedIssues( Issue* newAssignedIssues)
{
    assignedIssues = newAssignedIssues;
}

// toString function
string Employee :: toString()
{

    string employee = name + ", " + title + ", " + to_string(assignedIssuesSize) + " issue(s).";
    return employee;
}

// Member Functions
void Employee::addIssue(Issue* newIssue) {

    if(assignedIssuesSize == 0)
    {
        assignedIssues = new Issue [++assignedIssuesSize];
        assignedIssues[assignedIssuesSize - 1] = *newIssue;
    }
    else{
        Issue* temp = assignedIssues;
        assignedIssues = new Issue [assignedIssuesSize + 1];

        for(int i = 0 ; i < assignedIssuesSize ; i++)
        {
            assignedIssues[i] = temp[i];
        }
        assignedIssues[assignedIssuesSize] = *newIssue;
        assignedIssuesSize++;
        delete [] temp;
    }
}

void Employee::removeIssue(Issue* removedIssue) {
    bool isRemoveFound = false;
    int removeIndex = 0;
    for (int i = 0; i < assignedIssuesSize && !isRemoveFound; i++) {
        if (assignedIssues[i].getID() == removedIssue->getID()) {
            removeIndex = i;
            isRemoveFound = true;
        }
    }

    if (isRemoveFound) {
        Issue* temp = assignedIssues;
        assignedIssues = new Issue[assignedIssuesSize - 1];

        if(!removeIndex)
        {
            for(int i = 0 ; i < assignedIssuesSize - 1 ; i++)
                assignedIssues[i] = temp [i + 1];
        }
        else if (removeIndex == assignedIssuesSize - 1)
        {
            for(int i = 0 ; i < assignedIssuesSize - 1 ; i++)
                assignedIssues[i] = temp [i];
        }
        else{
                for(int i = 0 ; i < removeIndex ; i++ )
                    assignedIssues [i] = temp[i];
                for(int j = removeIndex ; j < assignedIssuesSize - 1 ; j++)
                    assignedIssues [j] = temp[j + 1];
        }

        delete[] temp;
        assignedIssuesSize--;
    }
}

void Employee :: destroyAssignedIssues()
{
    delete [] assignedIssues;
    assignedIssues = nullptr;
    assignedIssuesSize = 0;
}

