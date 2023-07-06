#include <iostream>
#include <string>

using namespace std;

int main() {
    const int maxCourses = 100;
    string courseNames[maxCourses];
    int credit[maxCourses];
    string gradeString[maxCourses];
    int numCourses = 0;
    double totalCredits = 0.0, cumulativeCredits = 0.0;
    double totalGradePoints = 0.0, cumulativeGpa = 0.0;
    
    cout << "GRADE CALCULATOR ON A 4 POINT GPA SYSTEM." << endl << endl;
    
    // Get cumulative gpa
    cout << "Do you have a cumulative GPA? (y/n): ";
    cin >> addAnother;
    if (addAnother == 'y')
    {
        cout << "Enter cumulative GPA: " << endl;
        cin >> cumulativeGpa;
        cout >> "Enter cumulative credit hours";
        cin >> cumulativeCredits;
    }
    // Get course information from the user
    char addAnother = 'y';
    while (numCourses < maxCourses && (addAnother == 'y' || addAnother == 'Y')) {
        cout << "Enter course name: ";
        cin >> courseNames[numCourses];
        cout << "Enter number of credit hours: ";
        cin >> credit[numCourses];
        cout << "Enter grade (A, A-, B+, B, B-, C+, C, C-, D, F): ";
        cin >> gradeString[numCourses];
        
        // Convert grade to numeric value
        double grade = 0.0;
        if (gradeString[numCourses] == "A") {
            grade = 4.0;
        } else if (gradeString[numCourses] == "A-") {
            grade = 3.67;
        } else if (gradeString[numCourses] == "B+") {
            grade = 3.33;
        } else if (gradeString[numCourses] == "B") {
            grade = 3.0;
        } else if (gradeString[numCourses] == "B-") {
            grade = 2.67;
        } else if (gradeString[numCourses] == "C+") {
            grade = 2.33;
        } else if (gradeString[numCourses] == "C") {
            grade = 2.0;
        } else if (gradeString[numCourses] == "C-") {
            grade = 1.67;
        } else if (gradeString[numCourses] == "D") {
            grade = 1.0;
        } else if (gradeString[numCourses] == "F") {
            grade = 0.0;
        } else {
            cout << "Invalid grade entered. Please try again." << endl;
            continue;
        }
        
        // Update GPA calculation variables
        totalCredits += credit[numCourses];
        totalGradePoints += grade * credit[numCourses];
        numCourses++;
        
        // Ask if user wants to add another course
        cout << "Add another course? (y/n): ";
        cin >> addAnother;
    }
    
    // Calculate and display GPA
    if (numCourses == 0) {
        cout << "No courses entered. GPA cannot be calculated." << endl;
    } else {
        if (cumulativeCredits == 0)
        {
            double gpa = (totalGradePoints + (cumulativeGpa * cumulativeCredits)) / (totalCredits + cumulativeCredits);
        }
        else
        {
            double gpa = (totalGradePoints / totalCredits);
        }
        cout << endl << "GPA: " << gpa << endl;
    }
    
    return 0;
}
