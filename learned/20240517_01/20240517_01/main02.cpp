#include <iostream>
using namespace std;

constexpr unsigned int HashCode(const char* str)
{
    return str[0] ? static_cast<unsigned int>(str[0]) + 0xEDB8832Full * HashCode(str + 1) : 8603;
}

double Add(double n1, double n2)
{
    return n1 + n2;
}

double Substract(double n1, double n2)
{
    return n1 - n2;
}

double Multiple(double n1, double n2)
{
    return n1 * n2;
}

double Divide(double n1, double n2)
{
    return n1 / n2;
}

void main()
{
	double (*calculaterFunc)(double p0, double p1) = nullptr;
    while (true)
    {
        double n1 = 0, n2 = 0;
        cout << "숫자 2개 공백으로 구분해서 입력하세요: ";
        cin >> n1;
        cin >> n2;

        string op = "";
        cout << "연산자를 입력하세요 (+, -, *, /): ";
        cin >> op;

        switch (HashCode(op.c_str()))
        {
        case HashCode("+"):
            calculaterFunc = &Add;
            break;
        case HashCode("-"):
            calculaterFunc = &Substract;
            break;
        case HashCode("*"):
            calculaterFunc = &Multiple;
            break;
        case HashCode("/"):
            calculaterFunc = &Divide;
            break;
        default:
            cout << "부호가 올바르지 않습니다.\n" << endl;
            continue;
        }

        cout << calculaterFunc(n1, n2) << "\n" << endl;
    }
}
