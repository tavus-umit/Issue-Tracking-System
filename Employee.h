//Muhammed Ümit TAVUS -- CS201-01--22203317

#include <string>
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Issue.h"
using namespace std;

class Issue;

class Employee
{
    public:

        // Constructor and Destructor
        Employee();
        Employee(const string newName, const string newTitle);
        ~Employee();



        // Getters
        string getName() const;
        string getTitle() const;
        int getAssignedIssuesSize() const;
        Issue* getAssignedIssues()const;

        // Operator "=" overloading
        Employee& operator=( const Employee& right );

        // Setters
        void setName(const string newName);
        void setTitle(const string newTitle);
        void setAssignedIssues(Issue* newAssignedIssues);
        void setAssignedIssuesSize(const int newAssignedIssuesSize);

        //toString function
        string toString();

        // Member Function
        void addIssue(Issue* newIssue);
        void removeIssue(Issue* removedIssue);
        void destroyAssignedIssues();



    private:
        string name;
        string title;
        int assignedIssuesSize;
        Issue* assignedIssues;

};
#endif // EMPLOYEE_H


