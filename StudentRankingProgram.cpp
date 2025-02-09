#include <iostream>
#include <string>
using namespace std;

//giving constant max sub and student
const int maxsubject = 10;
const int maxstudent = 50;


string subjects[maxsubject];
string names[maxstudent];
int marks[maxstudent][maxsubject] = {0};
int subNo = 0; 
int n = 0;

// Function to add subjects
//This Function Will Help User to Enter the Number Of Subject He Wanted The Add The Subject
//to the array of subject[]
void addSubjects() {
    cout << "Enter the number of subjects:";
    cin >> subNo;
    if (subNo > maxsubject) {
        cout << "Number of subjects exceeds the maximum limit. Setting to " << maxsubject << ".\n";
        subNo = maxsubject;
    }
    for (int sub = 0; sub < subNo; ++sub) {
        cout << "Enter the name of subject " << sub + 1 << ": ";
        cin >> subjects[sub];
    }
}

// Function to add students and their marks
//This will Add to Each Student with Marks of His Subjects
void addStudentsAndMarks() {
    cout << "Enter the number of students: ";
    cin >> n;
    if (n > maxstudent) {
        cout << "Number of students exceeds the maximum limit.\n";
        n = maxstudent;
    }
    //names will hold the names of the student
    //marks will the marks for each student for the particular subject
    for (int i = 0; i < n; ++i) {
        cout << "Enter the name of student " << i + 1 << ": ";
        cin.ignore();
        getline(cin, names[i]);
        for (int sub = 0; sub < subNo; ++sub) {
            cout << "Enter marks for " << names[i] << " in " << subjects[sub] << ": ";
            cin >> marks[i][sub];
        }
    }
}

// Function to display students and their marks
void displayStudentsAndMarks() {
    for (int i = 0; i < n; ++i) {
        cout << "Student: " << names[i] << "\n";
        for (int sub = 0; sub < subNo; ++sub) {
            cout << " " << subjects[sub] << ": " << marks[i][sub] << "\n";
        }
    }
}

// Function to rank students by subject
void rankStudentsBySubject() {
    for (int sub = 0; sub < subNo; ++sub) 
    {
        int ranking[maxstudent];
        for (int i = 0; i < n; ++i) {
            ranking[i] = i; 
        }
        // Sort students by marks in descending order
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (marks[ranking[i]][sub] < marks[ranking[j]][sub]) {
                    int temp = ranking[i];
                    ranking[i] = ranking[j];
                    ranking[j] = temp;
                }
            }
        }
        cout << "Subject: " << subjects[sub] << "\n";
        for (int rank = 0; rank < n; ++rank) {
            cout << " Rank " << rank + 1 << ": " << names[ranking[rank]]
                 << " with marks " << marks[ranking[rank]][sub] << "\n";
        }
    }
}

int main() {
    string name;
    cout <<"HELLO WELCOME TO THE RAINKING SYSTEM!"<<endl;
    cout<<"Enter Your Name:";
    getline(cin,name);
    if(name!=""){
        cout<<"Welcome Mr/Mrs: "<<name<<endl;
        int choice;
    do {
        cout << "\n1. Add Subjects\n2. Add Students and Marks\n3. Display Students and Marks\n4. Rank Students by Subject\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addSubjects();
                break;
            case 2:
                addStudentsAndMarks();
                break;
            case 3:
                displayStudentsAndMarks();
                break;
            case 4:
                rankStudentsBySubject();
                break;
            case 5:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
    }
    cout<<"Bye";
    return 0;
}