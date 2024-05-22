#include <iostream>
#include <fstream>
using namespace std;

void main()
{
    // File Write
    // - C Style
    // - C++ Style

    /// C++ Style
    if (false)
    {
        ofstream ofs;
        ofs.open("test2.txt");
        int a = 3;
        int b = 2;
        ofs << a;
        ofs << endl;
        ofs << b;

        ofs.close();
    }

    if (true)
    {
        ifstream ifs;
        ifs.open("test2.txt");

        int a, b;
        ifs >> a;
        ifs >> b;

        ifs.close();

        cout << "a: " << a << endl;
        cout << "b: " << b << endl;
    }
}
