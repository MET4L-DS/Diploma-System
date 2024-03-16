#include <iostream>
#include <stdlib.h>

using namespace std;

class COURSE
{
private:
    int courseID;
    string courseName;
    bool assignment[5] = {0};
    bool status = 0;

public:
    void SetCourseID(int inputCourseID) {
        courseID = inputCourseID;
    }

    int ReadCourseID() {
        int returnCourseID = courseID;
        return returnCourseID;
    }

    void SetCourseName(string inputCourseName) {
        courseName = inputCourseName;
    }

    string ReadCourseName() {
        string returnCourseName = courseName;
        return returnCourseName;
    }

    void SetAssignment(int i, bool inputAssignment) {
        assignment[i] = inputAssignment;
    }

    bool ReadAssignment(int i) {
        bool returnAssignment = assignment[i];
        return returnAssignment;
    }

    void SetStatus(bool inputStatus) {
        status = inputStatus;
    }

    bool ReadStatus() {
        bool returnStatus = status;
        return returnStatus;
    }

    COURSE *next = NULL;
};
COURSE *courseHead = NULL;

class STUDENT
{
private:
    int rollNo;
    string name;

public:
    void SetRollNo(int inputRollNo) {
        rollNo = inputRollNo;
    }

    int ReadRollNo() {
        int returnRollNo = rollNo;
        return returnRollNo;
    }

    void SetName(string inputName) {
        name = inputName;
    }

    string ReadName() {
        string returnName = name;
        return returnName;
    }

    STUDENT *next = NULL;
    COURSE *studentCourseHead = NULL;
};
STUDENT *studentHead = NULL;


void InsertCourse(int insertCourseID, string insertCourseName);
void DeleteCourse(int deleteID);
void DisplayCourse();
void InsertStudent(int insertRollNo, string insertName);
void DeleteStudent(int deleteRollNo);
void DisplayStudent();


int main()
{
    system("cls");

    int mainOption;
    do {
        system("cls");
        cout << "\n----------MAIN MENU----------\n";
        cout << "\n0: Exit System";
        cout << "\n1: Course Management";
        cout << "\n2: Student Management";
        cout << "\n3: Overview of Student";
        cout << "\n4: Student Login";
        cout << "\n\nINPUT : ";

        cin >> mainOption;
        switch (mainOption) {
            case 0:
                break;

            case 1:
                {
                    int subOption1;
                    do {
                        system("cls");
                        cout << "\n------COURSE MANAGEMENT-------\n";
                        cout << "\n0: Go Back";
                        cout << "\n1: Add a Course";
                        cout << "\n2: Remove a Course";
                        cout << "\n3: View all Courses";
                        cout << "\n\nINPUT : ";

                        cin >> subOption1;
                        switch (subOption1) {
                            case 0:
                                break;

                            case 1:
                                {
                                    system("cls");

                                    int enterCourseID;
                                    cout << "\nEnter Course ID : ";
                                    cin >> enterCourseID;
                                    getchar();

                                    string enterCourseName;
                                    cout << "Enter Course Name : ";
                                    getline(cin, enterCourseName);

                                    InsertCourse(enterCourseID, enterCourseName);

                                    break;
                                }

                            case 2:
                                {
                                    int subSubOption12;
                                    system("cls");
                                    cout << "\nEnter the Course ID : ";
                                    int enterDeleteID;
                                    cin >> enterDeleteID;
                                    do {
                                        DeleteCourse(enterDeleteID);
                                        cout << "\n\n0: Go Back";
                                        cout << "\n\nINPUT : ";
                                        cin >> subSubOption12;
                                    } while (subSubOption12 != 0);

                                    break;
                                }

                            case 3:
                                {
                                    int subSubOption13;
                                    do {
                                        system("cls");

                                        cout << "\n----------------------------------------------";
                                        cout << "\nCOURSES:";
                                        DisplayCourse();

                                        cout << "\n\n0: Go Back";
                                        cout << "\n\nINPUT : ";
                                        cin >> subSubOption13;
                                    } while (subSubOption13 != 0);

                                    break;
                                }
                        }
                    } while (subOption1 != 0);

                    break;
                }

            case 2:
                {
                    int subOption2;
                    do {
                        system("cls");
                        cout << "\n------STUDENT MANAGEMENT------\n";
                        cout << "\n0: Go Back";
                        cout << "\n1: Add a Student";
                        cout << "\n2: Remove a Student";
                        cout << "\n3: View all Students";
                        cout << "\n\nINPUT : ";

                        cin >> subOption2;
                        switch (subOption2) {
                            case 0:
                                break;

                            case 1:
                                {
                                    system("cls");

                                    int enterRollNo;
                                    cout << "\nEnter Student Rollno : ";
                                    cin >> enterRollNo;
                                    getchar();

                                    string enterName;
                                    cout << "Enter Student Name : ";
                                    getline(cin, enterName);

                                    InsertStudent(enterRollNo, enterName);

                                    break;
                                }

                            case 2:
                                {    
                                    int subSubOption22;
                                    system("cls");
                                    cout << "\nEnter the Student Rollno : ";
                                    int enterDeleteRollNo;
                                    cin >> enterDeleteRollNo;
                                    do {
                                        DeleteStudent(enterDeleteRollNo);
                                        cout << "\n\n0: Go Back";
                                        cout << "\n\nINPUT : ";
                                        cin >> subSubOption22;
                                    } while (subSubOption22 != 0);

                                    break;
                                }

                            case 3:
                                {   
                                    int subSubOption23;
                                    do {
                                        system("cls");

                                        cout << "\n------------------------------";
                                        cout << "\nSTUDENTS:";
                                        DisplayStudent();

                                        cout << "\n\n0: Go Back";
                                        cout << "\n\nINPUT : ";
                                        cin >> subSubOption23;
                                    } while (subSubOption23 != 0);

                                    break;
                                }
                        }
                    } while (subOption2 != 0);

                    break;
                }
                
            case 3:
                {
                    system("cls");

                    cout << "\n-----Overview of Students-----\n";

                    cout << "\n------------------------------";
                    cout << "\nStudents Available:";
                    DisplayStudent();

                    int loginStudentID;
                    cout << "\n\nEnter the STUDENT ROLLNO to view.";
                    cout << "\nEnter Student Rollno : ";
                    cin >> loginStudentID;
                    STUDENT *temp = studentHead;
                    while (temp != NULL and temp->ReadRollNo() != loginStudentID) {
                        temp = temp->next;
                    }

                    if (temp == NULL) {
                        cout << "\nINVALID Rollno";
                        break;
                    }

                    int subOption;
                    do {
                        system("cls");

                        cout << "\n----------------------------------------------";
                        cout << "\nOverview of " << temp->ReadName();
                        cout << "\n----------------------------------------------";
                        int countAssignent = 0;
                        int countCourse = 0;
                        bool overallStatus = 1;
                        COURSE *cTemp = temp->studentCourseHead;
                        while (cTemp != NULL) {
                            countCourse++;
                            cout << "\nCourse ID : " << cTemp->ReadCourseID() << "\tName : " << cTemp->ReadCourseName();
                            cout << "\nStatus : ";
                            for (int i = 0; i < 5; i++) {
                                if (cTemp->ReadAssignment(i) == true) {
                                    countAssignent++;
                                }
                            }
                            if (cTemp->ReadStatus() == true) {
                                cout << "Pass";
                            } else {
                                overallStatus = 0;
                                cout << "Fail";
                            }
                            cTemp = cTemp->next;
                            cout << "\n----------------------------------------------";
                        }
                        cout << "\nOverall Status : ";
                        if (overallStatus == true) {
                            if (countAssignent >= (countCourse - 1) * 4 + 5) {
                                cout << "Distinction";
                            } else {
                                cout << "Pass";
                            }
                        } else {
                            cout << "Fail";
                        }
                        cout << "\n----------------------------------------------";
                        cout << "\n\n0: Go Back";
                        cout << "\n\nINPUT : ";
                        cin >> subOption;
                    } while (subOption != 0);
                    break;
                }

            case 4:
                {
                    system("cls");

                    cout << "\n-----STUDENT LOGIN PORTAL-----\n";

                    cout << "\n------------------------------";
                    cout << "\nStudents Available:";
                    DisplayStudent();

                    int loginRollNo;
                    cout << "\n\nEnter the STUDENT ROLLNO to Login.";
                    cout << "\nEnter Login Rollno : ";
                    cin >> loginRollNo;
                    STUDENT *temp = studentHead;
                    while (temp != NULL and temp->ReadRollNo() != loginRollNo) {
                        temp = temp->next;
                    }

                    if (temp == NULL) {
                        cout << "\nINVALID Rollno";
                        break;
                    }

                    int subOption;
                    do {
                        system("cls");

                        cout << "\n------------------------------";
                        cout << "\nHello " << temp->ReadName();
                        cout << "\n------------------------------";
                        cout << "\n0: Go Back";
                        cout << "\n1: Enroll in Courses";
                        cout << "\n2: See your enrollment";
                        cout << "\n3: Revoke Enrollment";
                        cout << "\n4: Submit Assignments";
                        cout << "\n\nINPUT : ";
                        cin >> subOption;
                        switch (subOption) {
                            case 0:
                                break;

                            case 1:
                                {
                                    system("cls");

                                    cout << "\n----------------------------------------------";
                                    cout << "\nAvailable Enrollment:";
                                    DisplayCourse();

                                    int enrollCourseID;
                                    cout << "\n\nEnter the Course ID to Enroll : ";
                                    cin >> enrollCourseID;
                                    COURSE *cTemp = courseHead;
                                    while (cTemp != NULL and cTemp->ReadCourseID() != enrollCourseID) {
                                        cTemp = cTemp->next;
                                    }

                                    if (cTemp == NULL) {
                                        cout << "\nINVALID COURSE ID";
                                        break;
                                    }

                                    COURSE *cPtr = new COURSE;
                                    cPtr->SetCourseID(cTemp->ReadCourseID());
                                    cPtr->SetCourseName(cTemp->ReadCourseName());
                                    cPtr->next = NULL;

                                    if (temp->studentCourseHead == NULL) {
                                        temp->studentCourseHead = cPtr;
                                        break;
                                    }

                                    COURSE *cTemp1 = temp->studentCourseHead;
                                    while (cTemp1->next != NULL) {
                                        cTemp1 = cTemp1->next;
                                    }
                                    cTemp1->next = cPtr;

                                    break;
                                }

                            case 2:
                                {
                                    int subSubOption;
                                    do {
                                        system("cls");

                                        COURSE *ctemp = temp->studentCourseHead;
                                        cout << "\n----------------------------------------------";
                                        cout << "\nCourses Enrolled by " << temp->ReadName();
                                        cout << "\n----------------------------------------------";
                                        while (ctemp != NULL) {
                                            cout << "\nCourse ID : " << ctemp->ReadCourseID() << "\tName : " << ctemp->ReadCourseName();
                                            int countAssignent = 0;
                                            for (int i = 0; i < 5; i++) {
                                                if (ctemp->ReadAssignment(i) == true) {
                                                    countAssignent++;
                                                }
                                            }

                                            if (countAssignent > 2) {
                                                ctemp->SetStatus(1);
                                            } else {
                                                ctemp->SetStatus(0);
                                            }
                                            cout << "\nAssignment Submitted : " << countAssignent;
                                            cout << "\nStatus : ";
                                            if (ctemp->ReadStatus() == true) {
                                                cout << "Pass";
                                            } else {
                                                cout << "Fail";
                                            }
                                            ctemp = ctemp->next;
                                            cout << "\n----------------------------------------------";
                                        }
                                        cout << "\n\n0: Go Back";
                                        cout << "\n\nINPUT : ";
                                        cin >> subSubOption;
                                    } while (subSubOption != 0);

                                    break;
                                }

                            case 3:
                                {
                                    system("cls");

                                    int deEnrollID;
                                    COURSE *cTemp = temp->studentCourseHead;
                                    COURSE *cPrev = NULL;
                                    cout << "\n----------------------------------------------";
                                    cout << "\nAvailable For De-enrollment";
                                    cout << "\n----------------------------------------------";
                                    while (cTemp != NULL) {
                                        cout << "\nCourse ID : " << cTemp->ReadCourseID() << "\tName : " << cTemp->ReadCourseName();
                                        cTemp = cTemp->next;
                                    }
                                    cout << "\n----------------------------------------------";
                                    cout << "\nEnter the COURSE ID to De-enroll : ";
                                    cin >> deEnrollID;

                                    cTemp = temp->studentCourseHead;
                                    if (temp->studentCourseHead->ReadCourseID() == deEnrollID) {
                                        temp->studentCourseHead = temp->studentCourseHead->next;
                                        delete cTemp;
                                        cout << "\nDe-enrollment Successfull";
                                        break;
                                    }

                                    while (cTemp != NULL and cTemp->ReadCourseID() != deEnrollID) {
                                        cPrev = cTemp;
                                        cTemp = cTemp->next;
                                    }

                                    if (cTemp == NULL) {
                                        cout << "\nINVALID COURSE ID : De-enrollment unsuccessful";
                                        break;
                                    }

                                    COURSE *deleteEnrollment = cTemp;
                                    cPrev->next = cTemp->next;
                                    delete deleteEnrollment;
                                    cout << "\nDe-enrollment Successfull";

                                    break;
                                }

                            case 4:
                                {
                                    system("cls");

                                    COURSE *ctemp = temp->studentCourseHead;
                                    cout << "\n----------------------------------------------";
                                    cout << "\nCourses Enrolled by " << temp->ReadName();
                                    cout << "\n----------------------------------------------";
                                    while (ctemp != NULL) {
                                        cout << "\nCourse ID : " << ctemp->ReadCourseID() << "\tName : " << ctemp->ReadCourseName();
                                        ctemp = ctemp->next;
                                    }
                                    cout << "\n----------------------------------------------";

                                    int inputEnrollID;
                                    cout << "\nEnter the Course ID to Submit Assignments : ";
                                    cin >> inputEnrollID;
                                    ctemp = temp->studentCourseHead;
                                    while (ctemp != NULL and ctemp->ReadCourseID() != inputEnrollID) {
                                        ctemp = ctemp->next;
                                    }

                                    if (ctemp == NULL) {
                                        cout << "\nINVALID COURSE ID";
                                        break;
                                    }

                                    system("cls");

                                    cout << "\n----------------------------------------------";
                                    cout << "\nSubmit Assignments for " << ctemp->ReadCourseName();
                                    cout << "\n----------------------------------------------";
                                    cout << "\nEnter (1/0) as INPUT for (submitted/not-submitted)";

                                    for (int i = 0; i < 5; i++) {
                                        bool enterAssignment;
                                        cout << "\nAssignment " << i + 1 << " : ";
                                        cin >> enterAssignment;
                                        ctemp->SetAssignment(i, enterAssignment);
                                    }

                                    break;
                                }
                        }
                    } while (subOption != 0);

                    break;
                }
        }
    } while (mainOption != 0);

    return 0;
}


void InsertCourse(int insertCourseID, string insertCourseName) {
    COURSE* temp = new COURSE;
    temp->SetCourseID(insertCourseID);
    temp->SetCourseName(insertCourseName);
    temp->next = NULL;

    if (courseHead == NULL) {
        courseHead = temp;
        return;
    }

    COURSE* temp1 = courseHead;
    while (temp1->next != NULL) {
        temp1 = temp1->next;
    }
    temp1->next = temp;
}

void DeleteCourse(int deleteID) {
    COURSE* temp = courseHead;
    COURSE* prev = NULL;
    if (courseHead->ReadCourseID() == deleteID) {
        courseHead = courseHead->next;
        delete temp;
        cout << "\nDelete Successfull";
        return;
    }

    while (temp != NULL and temp->ReadCourseID() != deleteID) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "\nDelete Unsuccessfull : Student was not found!";
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "\nDelete Successfull";
}

void DisplayCourse() {
    COURSE* temp = courseHead;
    cout << "\n----------------------------------------------";
    while (temp != NULL) {
        cout << "\nCourse ID : " << temp->ReadCourseID() << "\tName : " << temp->ReadCourseName();
        temp = temp->next;
    }
    cout << "\n----------------------------------------------";
}

void InsertStudent(int insertRollNo, string insertName) {
    STUDENT* temp = new STUDENT;
    temp->SetRollNo(insertRollNo);
    temp->SetName(insertName);
    temp->next = NULL;

    if (studentHead == NULL) {
        studentHead = temp;
        return;
    }

    STUDENT* temp1 = studentHead;
    while (temp1->next != NULL) {
        temp1 = temp1->next;
    }
    temp1->next = temp;
}

void DeleteStudent(int deleteRollNo) {
    STUDENT* temp = studentHead;
    STUDENT* prev = NULL;
    if (studentHead->ReadRollNo() == deleteRollNo) {
        studentHead = studentHead->next;
        delete temp;
        cout << "\nDelete Successfull";
        return;
    }

    while (temp != NULL and temp->ReadRollNo() != deleteRollNo) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "\nDelete Unsuccessfull : Student was not found!";
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "\nDelete Successfull";
}

void DisplayStudent() {
    STUDENT* temp = studentHead;
    cout << "\n------------------------------";
    while (temp != NULL) {
        cout << "\nRollno : " << temp->ReadRollNo() << "\tName : " << temp->ReadName();
        temp = temp->next;
    }
    cout << "\n------------------------------";
}
