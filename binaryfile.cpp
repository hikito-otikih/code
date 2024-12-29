#include <iostream>
#include<fstream>
#include<cstring>
using namespace std;

struct Item
{
    int ID;
    char *name;
    float price;
};

void writeBinaryFile()
{
    int n = 5;
    Item items[n];
    items[0].ID = 1;
    items[0].name = (char *)"Item 1";
    items[0].price = 10;
    ///
    items[1].ID = 2;
    items[1].name = (char *)"Ite";
    items[1].price = 20.3;
    ///
    items[2].ID = 3;
    items[2].name = (char *)"Item 3xx";
    items[2].price = 30.54;
    ///
    items[3].ID = 4;
    items[3].name = (char *)"Item 4";
    items[3].price = 40.5555;
    ///
    items[4].ID = 5;
    items[4].name = (char *)"Item 5hjnfdjnfdmkndfmfdnlkdskldsjkkdnffnfnfnnfsdnljfnfnmfnmfnmfnmfnfnmfnmfnmfnmfmnnmfnmnmfnmnmfnmnfnmnmfnmfnmnfnnmfnnmfnfnmmnfnmfnmfnmfmnfmnfnmfnmfmnfmfmnfnnmfmnmnfmnmfnfmnfmnmnfnmnmfmnfnnfmnmnffmnnmfmnfmnfmnfmnfmnfmnsdfkldsfkldnmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmasjksjkasdjnbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbmASDJHHHNMMMMMMMMMBBBBBasddddddddddddddddddddddddddddddddddddddddddddddddddd,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAsfkldsfmnfdsmnfdsndsfmfsdmfdsjkX";
    items[4].price = 50.66;
    ///
    ofstream out("items.dat", ios::binary);
    out.write((char *)&n, sizeof(n));
    int sumChar = 0;
    for (int i = 0; i < n; i++)
    {
        out.seekp((i + 2) * 4);
        out.write((char *)&items[i].ID, sizeof(items[i].ID));
        out.seekp((i + 2) * 4 + n * 4);
        out.write((char *)&items[i].price, sizeof(items[i].price));
        out.seekp((2 * n + 2) * 4 + sumChar);
        out.write((char *)&items[i].name, sizeof(items[i].name));
        sumChar += sizeof(items[i].name);
    }
    cout << sizeof(&items[4].name) << endl;
    cout << sumChar << endl;
}

void readBinaryFile()
{
    int n;
    ifstream in("items.dat", ios::binary);
    in.read((char *)&n, sizeof(n));
    Item items[n];
    int sumChar = 0;
    for (int i = 0; i < n; i ++)
    {
        in.seekg((i + 2) * 4);
        in.read((char *)&items[i].ID, sizeof(items[i].ID));
        in.seekg((i + 2) * 4 + n * 4);
        in.read((char *)&items[i].price, sizeof(items[i].price));
        in.seekg((2 * n + 2) * 4 + sumChar);
        in.read((char *)&items[i].name, sizeof(items[i].name));
        sumChar += sizeof(items[i].name);
    }   
    for (int i = 0; i < n; i ++)
    {
        cout << "ID: " << items[i].ID << endl;
        cout << "Name: " << items[i].name << endl;
        cout << "Price: " << items[i].price << endl;
    }
}

int main()
{
    //writeBinaryFile();
    readBinaryFile();
    return 0;
}