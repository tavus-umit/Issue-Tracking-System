#include <iostream>
#include "IssueTrackingSystem.h"
using namespace std;

int main()
{
    IssueTrackingSystem ITS;

    ITS.showAllEmployees();
    cout << endl;

    ITS.addEmployee( "Alper", "Software Engineer" );
    ITS.addEmployee( "Enes", "Software Engineer" );
    ITS.addEmployee( "Ayse", "Software Engineer" );
    ITS.addEmployee( "Salih", "Software Engineer" );
    ITS.addEmployee( "Salih", "ML Engineer" );
    ITS.addEmployee( "Fatma", "Software Engineer" );
    ITS.addEmployee( "Yusuf", "Cook" );
    ITS.removeEmployee( "Kamil");
    ITS.removeEmployee( "Enes");
    ITS.addEmployee( "Merve", "Researcher" );
    ITS.addEmployee( "Ali", "DevOps Engineer" );
    ITS.removeEmployee( "Ali" );
    cout << endl;

    ITS.addIssue( 1, "Code payment module", "Ayse" );
    ITS.addIssue( 2, "Code login page", "Salih" );
    ITS.addIssue( 3, "Code logout page", "Fatma" );
    ITS.addIssue( 4, "Code search engine", "Ayse" );
    ITS.addIssue( 5, "Create algorithm for new recommendation engine", "Merve" );
    ITS.addIssue( 6, "Create robots.txt to inform crawlers", "Alper" );
    ITS.addIssue( 7, "Code profile pages", "Alper" );
    ITS.addIssue( 1, "Fix image not found bug", "Merve" );
    ITS.addIssue( 2, "Fix login bug", "Salih" );
    ITS.removeIssue(4);
    ITS.removeIssue( 8 );
    ITS.removeIssue( 1 );
    cout << endl;
    ITS.showAllIssues();

    //ITS.changeAssignee( "Salih", "Fatma" );
    ITS.removeEmployee( "Salih" );
    ITS.removeEmployee( "Fatma" );

    ITS.removeEmployee( "Ayse" );
    cout << endl;

    ITS.showAllEmployees();
    cout << endl;
    ITS.showEmployee( "Fatma" );
    cout << endl;
    ITS.showEmployee( "John" );
    cout << endl;
    ITS.showAllIssues();
    cout << endl;
    ITS.showIssue( 1 );
    cout << endl;
    ITS.showIssue( 3 );





    return 0;
}
