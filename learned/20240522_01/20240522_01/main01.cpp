#include <iostream>
using namespace std;

void main()
{
    // File Write
    // - C Style
    // - C++ Style

    /// C Style
    // Mode:
    // wb => write, binary
    // wt => write, text
    // rb => read, binary
    // rt => read, text
    if (false)
    {
        FILE* file = nullptr;
        fopen_s(&file, "test.txt", "wb");

        if (file == nullptr)
        {
            cout << "error: file nullptr" << endl;
            return;
        }

        int a = 3;
        fwrite(&a, sizeof(a), 1, file);
        fwrite(&a, sizeof(a), 1, file);
        fwrite(&a, sizeof(a), 1, file);
        fwrite(&a, sizeof(a), 1, file);
        fwrite(&a, sizeof(a), 1, file);

        fclose(file);
    }

    if (true)
    {
        FILE* file = nullptr;
        fopen_s(&file, "test.txt", "rb");

        if (file == nullptr)
        {
            cout << "error: file nullptr" << endl;
            return;
        }

        int value;
        fread(&value, sizeof(value), 1, file);
        fread(&value, sizeof(value), 1, file);
        fread(&value, sizeof(value), 1, file);
        fread(&value, sizeof(value), 1, file);
        fread(&value, sizeof(value), 1, file);

        printf("value: %d\n", value);
    }
}
