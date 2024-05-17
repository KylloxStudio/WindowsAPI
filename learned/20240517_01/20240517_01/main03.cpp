#include <iostream>
using namespace std;

class Calculator
{
public:
	void InputNumber()
	{
		cin >> _num1;
		cin >> _num2;
	}

	void InputOperator()
	{
		cin >> _operator;
	}

	void PrintResult()
	{
		cout << _result << "\n" << endl;
	}

private:
	constexpr unsigned int HashCode(const char* str)
	{
		return str[0] ? static_cast<unsigned int>(str[0]) + 0xEDB8832Full * HashCode(str + 1) : 8603;
	}

	void Add()
	{
		_result = _num1 + _num2;
	}

	void Substract()
	{
		_result = _num1 - _num2;
	}

	void Multiple()
	{
		_result = _num1 * _num2;
	}

	void Divide()
	{
		_result = _num1 / _num2;
	}

	void Culculate()
	{
		switch (_operator)
		{
		case 0:
			calculaterFunc = &Calculator::Add;
			break;
		case 1:
			calculaterFunc = &Calculator::Substract;
			break;
		case 2:
			calculaterFunc = &Calculator::Multiple;
			break;
		case 3:
			calculaterFunc = &Calculator::Divide;
			break;
		default:
			cout << "��ȣ�� �ùٸ��� �ʽ��ϴ�.\n" << endl;
			break;
		}
	}

	double _num1 = 0;
	double _num2 = 0;
	int _operator = 0;
	double _result = 0;

	void (Calculator::*calculaterFunc)(void) = nullptr;
};

void main()
{
	Calculator calculator;

	cout << "���� 2�� �������� �����ؼ� �Է��ϼ���: ";
	calculator.InputNumber();

	cout << "�����ڸ� �Է��ϼ��� (+, -, *, /): ";
	calculator.InputOperator();

	calculator.PrintResult();
}
