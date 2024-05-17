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
        cout << "���� 2�� �������� �����ؼ� �Է��ϼ���: ";
        cin >> n1;
        cin >> n2;

        string op = "";
        cout << "�����ڸ� �Է��ϼ��� (+, -, *, /): ";
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
            cout << "��ȣ�� �ùٸ��� �ʽ��ϴ�.\n" << endl;
            continue;
        }

        cout << calculaterFunc(n1, n2) << "\n" << endl;
    }
}
