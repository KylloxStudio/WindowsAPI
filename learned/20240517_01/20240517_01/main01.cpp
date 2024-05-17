#include <iostream>
using namespace std;

int a = 0;
int b = 0;

constexpr unsigned int HashCode(const char* str)
{
    return str[0] ? static_cast<unsigned int>(str[0]) + 0xEDB8832Full * HashCode(str + 1) : 8603;
}

void Function()
{
    cout << "[Function]" << endl;
}

void Function1(int p0, int p1)
{
    cout << "[Function1] " << p0 << ", " << p1 << endl;
}

double Add(double n1, double n2)
{
    return n1 + n2;
}

double Minus(double n1, double n2)
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
    /*** 함수포인터 ***/
    // - 포인터: 주소를 가리키는 자료형
    // - 함수포인터: 함수의 ''
    
    // 함수도 메모리를 차지함
    // - int: 4byte
    // - (모든) 함수: 4byte

    // 함수포인터: 함수의 주소를 사용하여 호출
    // - 포인터 <<< C, C++에만 있음
    // - 다른 언어에서는 콜백 함수 (Callback Function)

    // 포인터 (*)
    // int*: int 자료형의 주소를 담을 수 있음
    // void*: 어떤 주소든 담을 수 있음
    // => void* func1 = &Function;
    // 함수: 함수반환형 (네임스페이스::*변수명)(매개변수)
    // => void (*func1)(void) = &Function;

    // void (*functionPointer)(void) = &Function;
    // functionPointer();

    // void (*functionPointer2)(int, int) = &Function1;
    // functionPointer2(10, 10);

    // int (*functionPointer3)(int, int) = &Add;
    // int value = functionPointer3(2, 3);
    // cout << value << endl;


    // 사칙연산 계산기
    double (*addPointer)(double, double) = &Add;
    double (*minusPointer)(double, double) = &Minus;
    double (*multiplePointer)(double, double) = &Multiple;
    double (*dividePointer)(double, double) = &Divide;

    while (true)
    {
        double n1, n2;
        cout << "숫자 2개 공백으로 구분해서 입력하세요: ";
        cin >> n1;
        cin >> n2;

        string input;
        cout << "부호를 입력하세요 (+, -, *, /): ";
        cin >> input;

        double result = 0;
        switch (HashCode(input.c_str()))
        {
        case HashCode("+"):
            result = addPointer(n1, n2);
            break;
        case HashCode("-"):
            result = minusPointer(n1, n2);
            break;
        case HashCode("*"):
            result = multiplePointer(n1, n2);
            break;
        case HashCode("/"):
            result = dividePointer(n1, n2);
            break;
        default:
            cout << "부호가 올바르지 않습니다.\n" << endl;
            continue;
        }

        cout << result << "\n" << endl;
    }
}
