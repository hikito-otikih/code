#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // ofstream out("apcs.dat", ios::binary);
    // out.close();
    ifstream in("apcs.dat", ios::binary);
    int nStu;
    in.read((char *)&nStu, sizeof(nStu));
    if (in.eof())
    {
        cout << "File is empty" << endl;
    }
    in.close();
    return 0;
}