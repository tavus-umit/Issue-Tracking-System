//Muhammed Ümit TAVUS -- CS201-01--22203317

#include <iostream>
#include "IssueTrackingSystem.h"
#include "Employee.h"
#include "Issue.h"

IssueTrackingSystem::IssueTrackingSystem()
{
    employeesSize = 0;
    employees = nullptr;

}

IssueTrackingSystem::~IssueTrackingSystem()
{
    if(employees){
        for(int i = 0 ; i < employeesSize ; i++)
            {
                employees[i].destroyAssignedIssues();
            }
        delete [] employees;
    }

}


void IssueTrackingSystem::addEmployee( const string name, const string title )
{
        if(employeesSize == 0)
        {
            employees = new Employee [++employeesSize];
            Employee newEmployee = Employee(name, title);
            employees [employeesSize - 1] = newEmployee;

            cout << "Added employee " << name << "." << endl;

        }
        else{

            bool nameChecker = false;
            for(int i = 0 ; i < employeesSize ; i++ )
            {
                if(employees [i].getName() == name){nameChecker = true;}
            }


            if(nameChecker){cout << "Cannot add employee. Employee with name " << name << " already exists." << endl;}


            else{

            Employee newEmployee = Employee(name, title);
            Employee* temp = employees;
            employees = new Employee [employeesSize + 1];
            for(int i = 0 ; i < employeesSize ; i++)
            {
                employees[i] = temp[i];
            }
            employees[employeesSize] = newEmployee;

            for(int i = 0 ; i < employeesSize ; i++)
            {
                temp[i].destroyAssignedIssues();
            }
            delete [] temp;
            employeesSize++;

            cout << "Added employee " << name << "." << endl;
            }
        }

}


void IssueTrackingSystem :: removeEmployee( const string name )
{
    bool isRemoveFound = false;
    int removeFoundIndex = 0;
    int removeFoundSize = 0;
    for(int i = 0; i < employeesSize && !isRemoveFound ; i++)
    {
        if(employees[i].getName() == name)
        {
            removeFoundSize = employees[i].getAssignedIssuesSize();
            removeFoundIndex = i;
            isRemoveFound = true;
        }
    }

    if(isRemoveFound){

            if(removeFoundSize == 0)
            {
                Employee* temp = employees;
                employees = new Employee [employeesSize - 1];

                if(!removeFoundIndex)
                {
                    for(int i = 0 ; i < employeesSize - 1 ; i++)
                        employees[i] = temp [i + 1];
                }
                else if (removeFoundIndex == employeesSize - 1)
                {
                    for(int i = 0 ; i < employeesSize - 1 ; i++)
                        employees[i] = temp [i];
                }
                else{
                    for(int i = 0 ; i < removeFoundIndex ; i++ )
                        employees [i] = temp[i];
                    for(int j = removeFoundIndex ; j < employeesSize - 1 ; j++)
                        employees [j] = temp[j + 1];
                }

                for(int i = 0 ; i < employeesSize ; i++)
                {
                    temp[i].destroyAssignedIssues();
                }

                delete[] temp;
                employeesSize--;
                cout << "Removed employee " << name << "." << endl;
            }

            else{
                    cout << "Cannot remove employee. " << name << " has assigned issues."  << endl;
            }
    }

    else{
            cout << "Cannot remove employee. There is no employee with name " <<  name << "." << endl;
    }

}

void IssueTrackingSystem:: addIssue( const int issueId, const string description, const string assigneeName)
{

        Employee* chosenEmployee;
        bool assigneeNameChecker = false;
        for(int i = 0 ; i < employeesSize && !assigneeNameChecker  ; i++)
        {

            if(employees[i].getName() == assigneeName){ chosenEmployee = &employees[i]; assigneeNameChecker = true;}
        }

        bool issueChecker = false;

        for(int i = 0 ; i < employeesSize && !issueChecker ; i++){
            for(int j = 0; j < employees[i].getAssignedIssuesSize() && !issueChecker ; j++ )
            {
                if(employees[i].getAssignedIssues()[j].getID() == issueId)
                {
                    issueChecker = true;
                }
            }
        }

        if(assigneeNameChecker)
        {
            if(issueChecker)
            {
                cout << "Cannot add issue. Issue with ID " << issueId << " already exists." << endl;
            }
            else{

                Issue* newIssue = new Issue(issueId, description);
                newIssue->setAssignee(chosenEmployee->getName());
                chosenEmployee->addIssue(newIssue);
                delete newIssue;
                cout << "Added issue " << issueId << "." << endl;
            }
        }

        else{cout << "Cannot add issue. There is no employee with name " <<  assigneeName << "." << endl;}


}

void IssueTrackingSystem:: removeIssue( const int issueId )
{

    bool isRemoveFound = false;
    Issue* removeFound;
    Employee* chosenEmployee;
    for(int i = 0; i < employeesSize && !isRemoveFound ; i++)
    {
        for(int j = 0 ; j < employees [i].getAssignedIssuesSize(); j++)
        {
            if(employees[i].getAssignedIssues()[j].getID() == issueId)
            {
                removeFound = &employees[i].getAssignedIssues()[j];
                chosenEmployee = &employees[i];
                isRemoveFound = true;
            }
        }

    }
    if(isRemoveFound){

        chosenEmployee->removeIssue(removeFound);
        cout << "Removed issue " << issueId << "." << endl;
    }
    else{cout << "Cannot remove issue. There is no issue with ID " <<  issueId << "." << endl; }

}

void IssueTrackingSystem:: changeAssignee( const string previousAssignee, const string newAssignee )
{
    bool isPreviousFound = false;
    bool isNewFound = false;

    Employee* prevEmp;
    Employee* newEmp;
    for(int i = 0 ; i < employeesSize && !isPreviousFound ; i++)
    {
        if(employees[i].getName() == previousAssignee)
        {
            prevEmp = &employees[i];
            isPreviousFound = true;

        }
    }
    for(int i = 0 ; i < employeesSize && !isNewFound; i++)
    {

        if(employees[i].getName() == newAssignee)
        {
            newEmp = &employees[i];
            isNewFound = true;

        }
    }

    if(isPreviousFound && isNewFound){


        int prevSize = prevEmp->getAssignedIssuesSize();
        Issue* temp = new Issue [prevSize];
        for(int i = 0 ; i < prevSize; i++)
        {
            temp[i] = prevEmp->getAssignedIssues()[i];
        }
        for(int j = 0 ; j < prevSize ; j++)
        {
            temp[j].setAssignee(newEmp->getName());
            newEmp->addIssue(&temp[j]);
        }
        prevEmp->destroyAssignedIssues();

        delete [] temp;


        cout << previousAssignee << "'s issues are transferred to " << newAssignee << "." << endl;
    }
    else{
        cout << "Cannot change assignee. Previous or/and new assignee does not exist." << endl;
    }

}

void IssueTrackingSystem:: showAllEmployees() const
{
    cout << "Employees in the system:" << endl;
    if(!employeesSize)
    {
        cout << "None" << endl;
    }
    else{
        for(int i = 0 ; i < employeesSize ; i++)
        {
            cout << employees[i].toString() << endl;
        }
    }

}

void IssueTrackingSystem:: showAllIssues() const
{
    bool issueSizeChecker = false;
    for(int i = 0 ; i < employeesSize && !issueSizeChecker; i++){
        if(employees[i].getAssignedIssuesSize()){issueSizeChecker = true;}
    }

    cout << "Issues in the system:" << endl;
    if(!issueSizeChecker)
    {
        cout << "None" << endl;
    }
    else{
        for(int i = 0 ; i < employeesSize; i++){

            for(int j = 0; j < employees[i].getAssignedIssuesSize() ; j++ )
            {

                cout << employees[i].getAssignedIssues()[j].toString() << endl;
            }
        }
    }
}

void IssueTrackingSystem:: showEmployee( const string name ) const
{
    bool isEmployeeFound = false;
    Employee foundEmployee;
    for(int i = 0; i < employeesSize && !isEmployeeFound ; i++ )
    {
        if(employees[i].getName() == name)
        {
            isEmployeeFound = true;
            foundEmployee = employees[i];
        }
    }

    if(isEmployeeFound)
    {
        cout << foundEmployee.toString() << endl;
    }

    else{cout << "Cannot show employee. There is no employee with name " << name << "." << endl;}



}

void IssueTrackingSystem:: showIssue( const int issueId ) const
{
    bool isIssueFound = false;
    Issue foundIssue;

    for(int i = 0; i < employeesSize && !isIssueFound ; i++ )
    {

        for(int j = 0 ; j < employees[i].getAssignedIssuesSize(); j++)
        {

            if(employees[i].getAssignedIssues()[j].getID() == issueId)
            {
                foundIssue = employees[i].getAssignedIssues()[j];
                isIssueFound = true;
            }
        }
    }

    if(isIssueFound){cout << foundIssue.toString() << endl;}
    else{cout << "Cannot show issue. There is no issue with ID " << issueId << "." << endl;}

}


