//Muhammed Ümit TAVUS -- CS201-01--22203317

#include <iostream>
#include "Issue.h"
#include "Employee.h"


// Constructor and Destructor
Issue::Issue ()
{
    ID = 0;
    description = "";
    assignee = "";
}
Issue::Issue(const int newID, const string newDescription)
{
    ID = newID;
    description = newDescription;
    assignee =  "";

}

Issue::~Issue(){}

// Getters
int Issue ::  getID () const
{
    return ID;
}
string Issue ::  getDescription() const
{
    return description;
}
string Issue ::  getAssignee() const
{
    return assignee;
}

// Setters
void Issue ::  setID(const int newID)
{
    ID = newID;
}
void Issue ::  setDescription(const string newDescription)
{
    description = newDescription;
}
void Issue :: setAssignee ( const string newAssignee)
{
    assignee = newAssignee;
}

//toString function
string Issue :: toString() const
{
    string issue =  to_string(ID) + ", " + description + ", " + assignee + ".";
    return issue;
}
