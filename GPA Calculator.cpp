#include <iostream>
#include <map>
#include <limits>
#include <vector>
#include <string>
using namespace std;

// We create Function to get the GPA value of a grade
double getGradePoint(const string& grade) {
    //use map keyward for map the resula and credit values
    map<string, double> gradeMap = {
        {"A+", 4.0}, {"A", 4.0}, {"A-", 3.7}, {"B+", 3.3},
        {"B", 3.0}, {"B-", 2.7}, {"C+", 2.3}, {"C", 2.0},
        {"C-", 1.7}, {"D+", 1.3}, {"D", 1.0}, {"D-", 0.7},
        {"F", 0.0}
    };

    auto it = gradeMap.find(grade);
    if (it != gradeMap.end()) {
        return it->second;
    }
    else {
        cout << "Invalid grade entered! Defaulting to 0.0" << endl;
        return 0.0;
    }
}

int main() {
    char hasPreviousData;
    double previousCredits = 0.0, previousGPA = 0.0;

    // If there exist previous Prompt user for previous semester data
    cout << "Do you have previous semester GPA and total credits? (y/n): ";
    cin >> hasPreviousData;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear newline character

    if (tolower(hasPreviousData) == 'y') {
        // Ensure valid input for previous credits
        while (true) {
            cout << "Enter total credits from previous semesters: ";
            cin >> previousCredits;
            if (cin.fail() || previousCredits < 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a non-negative number." << endl;
            }
            else {
                break;
            }
        }

        // Ensure valid input for previous GPA
        while (true) {
            cout << "Enter cumulative GPA from previous semesters: ";
            cin >> previousGPA;
            if (cin.fail() || previousGPA < 0.0 || previousGPA > 4.0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a GPA between 0.0 and 4.0." << endl;
            }
            else {
                break;
            }
        }
    }

    int numSubjects;
    // Ensure valid input for number of subjects
    while (true) {
        cout << "Enter the number of subjects for the current semester: ";
        cin >> numSubjects;
        if (cin.fail() || numSubjects <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a positive integer." << endl;
        }
        else {
            cin.ignore(); // Clear newline character
            break;
        }
    }

    double totalCredits = 0.0, totalPoints = 0.0;
    vector<pair<string, double>> subjects;

    for (int i = 0; i < numSubjects; ++i) {
        string subjectName;
        double credit;
        string grade;

        cout << "Enter subject name: ";
        getline(cin, subjectName);

        // Ensure valid input for credits
        while (true) {
            cout << "Enter credit hours for " << subjectName << ": ";
            cin >> credit;
            if (cin.fail() || credit <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a positive number." << endl;
            }
            else {
                break;
            }
        }

        cout << "Enter grade for " << subjectName << ": ";
        cin >> grade;
        cin.ignore(); // Clear newline character for next input

        double gradePoint = getGradePoint(grade);
        subjects.push_back({ subjectName, gradePoint });
        totalCredits += credit;
        totalPoints += credit * gradePoint;
    }

    cout << "\nSubject-wise Results:" << endl;
    for (const auto& subject : subjects) {
        cout << subject.first << " = " << subject.second << endl;
    }

    double currentGPA = (totalCredits == 0) ? 0 : (totalPoints / totalCredits);
    cout << "\nYour GPA for the current semester is: " << currentGPA << endl;

    // Calculate cumulative GPA if previous data exists
    if (tolower(hasPreviousData) == 'y' && previousCredits > 0) {
        double cumulativeTotalPoints = (previousGPA * previousCredits) + totalPoints;
        double cumulativeTotalCredits = previousCredits + totalCredits;
        double cumulativeGPA = cumulativeTotalPoints / cumulativeTotalCredits;
        cout << "Your cumulative GPA is: " << cumulativeGPA << endl;
    }

    return 0;
}