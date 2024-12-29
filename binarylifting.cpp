#include <iostream>
#include <fstream>

using namespace std;

struct Student
{
    char StuId[8];
    char sFullName[100];
    char sHomeAddress[500];
    float gpa;
};

Student stu[100], stu1[100];

int main()
{
    int nStu = 4;
    stu[0] = {"B20DCCN", "Nguyen Van A", "Ha Noijhfjkfkdhjdjk", 3.5};
    stu[1] = {"B20DCCN", "Nguyen Van B", "Ha Noiiiikdjkdsjkdsjkdsjkdskjdsiii", 3.6};
    stu[2] = {"B20DCCN", "Nguyen Van C", "Ha Njfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfoi", 3.7};
    stu[3] = {"B20DCCN", "Nguyen trong van viet", "Ha Ndddnfnfnffnfnfnfnfnfnfnfnfnfnfnfdoi", 3.8};
    // ofstream out("students.dat", ios::binary);
    // out.write((char *)&nStu, sizeof(nStu));
    // out.write((char *)stu, nStu * sizeof(Student));

    ifstream in("students.dat", ios::binary);
    in.read((char *)&nStu, sizeof(nStu));
    in.read((char *)stu1, nStu * sizeof(Student));
    for (int i = 0; i < nStu; i++)
    {
        cout << stu1[i].StuId << " " << stu1[i].sFullName << " " << stu1[i].sHomeAddress << " " << stu1[i].gpa << endl;
    }

    return 0;
}