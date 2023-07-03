#include <iostream>
#include <iomanip>
using namespace std;

string error() 
{
    string errorList = "\nList of Possible Errors:\n(0x0001): Unacceptable value inputted.\n";
    return errorList;
}

int main()
{
    //Declaration.
    float gpa = 4, gpaM = 0, cumulativeGPA, creditSum = 0, credit[1000], grade[1000];
    string courseNames[1000], gradeString[1000];
    int n = -1;
    string selector;

    cout << "GRADE CALCULATOR ON A 4 POINT GPA SYSTEM.\n";
    cout << "Do You Want to Calculate Cumulative GPA With GPAs From Past Semesters? (y for Yes, n for No): ";
    cin >> selector;

    //Cumulative GPA Prompt.
    if (selector == "y" || selector == "Y")
    {
        cout << "Is the old GPA with you? (y for Yes, n for No): ";
        cin >> selector;
            //Old GPA Collection.
            if (selector == "y" || selector == "Y")
            {
                selector = "0";
                cout << "Enter the old cumulative GPA: ";
                cin >> cumulativeGPA;

            }
            else if (selector == "n" || selector == "N")
            {
                selector = "0";
                cout << "No worries, we will calculate it for you. \n";
            }
            else
            {
                cout << "\nRun Time Error (0x0001)" << error();
                return 0;
            }
    }
    else if (selector == "n" || selector == "N")
    {
        selector = "skip";
        cout << "Alright we will just process this semester's grade. \n";
    }
    else 
    {
        cout << "\nRun Time Error (0x0001)" << error();
        return 0;
    }

    do
    {
        n++;
        cout << "Enter Course Name: ";
        cin >> courseNames[n];
        cout << "Enter number course credit hours: ";
        cin >> credit[n];
        cout << "Enter grade Only(A, A-, B+, B, B-, C+, C, C-, D, F) are accepted: ";
        cin >> gradeString[n];
        selector = "skip";
        cout << "Total Number of Courses Registered is " << n + 1 << " Courses, Do You Want to Add More? (y for Yes, n for No): " << std::endl;
        cin >> selector;
    } while (selector != "n" || selector != "N");

    for (int i = 0; i < n; i++)
    {
        if (gradeString[i] == "A")
            grade[i] = 4;
        else if (gradeString[i] == "A-")
            grade[i] = 3.67;
        else if (gradeString[i] == "B+")
            grade[i] = 3.33;
        else if (gradeString[i] == "B+")
            grade[i] = 3;
        else if (gradeString[i] == "B-")
            grade[i] = 2.67;
        else if (gradeString[i] == "C+")
            grade[i] = 2.33;
        else if (gradeString[i] == "C")
            grade[i] = 2;
        else if (gradeString[i] == "C-")
            grade[i] = 1.67;
        else if (gradeString[i] == "D")
            grade[i] = 1;
        else
            grade[i] = 0;
    }

    for (int j = 0; j < (n+1); j++)
    {
        creditSum += credit[j];
    }
    for (int k = 0; k < n; k++)
    {
        gpaM += credit[k] * grade[k];
    }
    gpa = gpaM / creditSum;
    cout << "Your GPA is: " << gpa << " of 4.\n";
    system("pause");
    return 0;
}
