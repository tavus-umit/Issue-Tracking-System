//Muhammed Ümit TAVUS -- CS201-01--22203317

#include <string>
#ifndef ISSUE_H
#define ISSUE_H

#include "Employee.h"
using namespace std;

class Employee;

class Issue
{
    public:

        // Constructor and Destructor
        Issue();
        Issue(const int newID, const string newDescription);
        ~Issue();

        // Getters
        int getID () const;
        string getDescription() const ;
        string getAssignee() const ;

        // Setters
        void setID(const int newID);
        void setDescription(const string newDescription);
        void setAssignee (const string newAssignee);

        //toString function
        string toString() const;

    private:
        int ID;
        string description;
        string assignee;
};
#endif // ISSUE_H

