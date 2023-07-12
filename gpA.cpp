#include <iostream>
#include <fstream>
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
    char addAnother = 'y';
    double gpa = 0.0;
    string filename = "gpa.txt";

    // Load previous GPA from file if available
    ifstream infile(filename);
    if (infile.is_open()) {
        infile >> gpa;
        cout << "Your Last Calculated GPA is: " << gpa << endl << endl;
        infile.close();
    }

    // Get cumulative gpa
    cout << "Do you have a cumulative GPA? (y/n): ";
    cin >> addAnother;
    if (addAnother == 'y' || addAnother == 'Y')
    {
        cout << "Enter cumulative GPA: ";
        cin >> cumulativeGpa;
        cout << "Enter cumulative credit hours: ";
        cin >> cumulativeCredits;
    }
    addAnother = 'y';

    // Get course information from the user
    while (numCourses < maxCourses && (addAnother == 'y' || addAnother == 'Y')) {
        cout << "Enter course name: ";
        cin >> courseNames[numCourses];
        cout << "Enter number of credit hours: ";
        cin >> credit[numCourses];
        if (credit[numCourses] < 0) {
            cout << "Invalid number of credit hours entered. Please try again." << endl;
            continue;
        }
        cout << "Enter grade (A, A-, B+, B, B-, C+, C, C-, D, F): ";
        cin >> gradeString[numCourses];
        // Convert grade to numeric value
        double grade = 0.0;
        if (gradeString[numCourses] == "A" || gradeString[numCourses] == "a") {
            grade = 4.0;
        }
        else if (gradeString[numCourses] == "A-" || gradeString[numCourses] == "a-") {
            grade = 3.67;
        }
        else if (gradeString[numCourses] == "B+" || gradeString[numCourses] == "b+") {
            grade = 3.33;
        }
        else if (gradeString[numCourses] == "B" || gradeString[numCourses] == "b") {
            grade = 3.0;
        }
        else if (gradeString[numCourses] == "B-" || gradeString[numCourses] == "b-") {
            grade = 2.67;
        }
        else if (gradeString[numCourses] == "C+" || gradeString[numCourses] == "c+") {
            grade = 2.33;
        }
        else if (gradeString[numCourses] == "C" || gradeString[numCourses] == "c") {
            grade = 2.0;
        }
        else if (gradeString[numCourses] == "C-" || gradeString[numCourses] == "c-") {
            grade = 1.67;
        }
        else if (gradeString[numCourses] == "D" || gradeString[numCourses] == "d") {
            grade = 1.0;
        }
        else if (gradeString[numCourses] == "F" || gradeString[numCourses] == "f") {
            grade = 0.0;
        }
        else {
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
    }
    else {
        if (cumulativeCredits != 0)
        {
            gpa = (totalGradePoints + (cumulativeGpa * cumulativeCredits)) / (totalCredits + cumulativeCredits);
        }
        else
        {
            gpa = (totalGradePoints / totalCredits);
        }
        cout << endl << "GPA: " << gpa << endl;

        // Save GPA to file
        ofstream outfile(filename);
        if (outfile.is_open()) {
            outfile << gpa;
            outfile.close();
        }
    }
    return 0;
}
        
