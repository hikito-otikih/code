#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Student
{
    char StudentId[10];
    char *StudentName;
    char *StudentAddress;
    float StudentGPA;
};

int main()
{
    Student students[5];
    students[0] = {"S01", (char *)"Student 1", (char *)"Address 1", 3.5};
    students[1] = {"S02", (char *)"Student 2", (char *)"Address 2", 3.6};
    students[2] = {"S03", (char *)"Student 3", (char *)"Address 3", 3.7};
    students[3] = {"S04", (char *)"Student 4", (char *)"Address 4", 3.8};
    students[4] = {"S05", (char *)"Student 5", (char *)"Address 5", 3.9};

    ofstream out("students.dat", ios::binary);
    int numStudents = 5;
    out.write((char *)&numStudents, sizeof(numStudents));
    for (int i = 0; i < 5; i ++)
    {
        int len1 = strlen(students[i].StudentName) + 1;
        int len2 = strlen(students[i].StudentAddress) + 1;
        ///
        out.write((char *) students[i].StudentId, 10);
        out.write((char *) &len1, sizeof(len1));
        out.write((char *) students[i].StudentName, len1);
        out.write((char *) &len2, sizeof(len2));
        out.write((char *) students[i].StudentAddress, len2);
        out.write((char *) &students[i].StudentGPA, sizeof(students[i].StudentGPA));
    }
    out.close();

    ifstream in("students.dat", ios::binary);
    int numStudents2;
    in.read((char *) &numStudents2, sizeof(numStudents2));
    Student students2[numStudents2];
    for (int i = 0; i < numStudents2; i ++)
    {
        int len1, len2;
        in.read((char *) students2[i].StudentId, 10);
        in.read((char *) &len1, sizeof(len1));
        students2[i].StudentName = new char[len1];
        in.read((char *) students2[i].StudentName, len1);
        in.read((char *) &len2, sizeof(len2));
        students2[i].StudentAddress = new char[len2];
        in.read((char *) students2[i].StudentAddress, len2);
        in.read((char *) &students2[i].StudentGPA, sizeof(students2[i].StudentGPA));
    }
    in.close();

    for (int i = 0; i < numStudents2; i ++)
    {
        cout << students2[i].StudentId << " " << students2[i].StudentName << " " << students2[i].StudentAddress << " " << students2[i].StudentGPA << endl;
    }

    return 0;
}