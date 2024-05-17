#include <iostream>
#include <functional>
using namespace std;

class TestObject
{
public:
	void DoSomething()
	{
		cout << "DoSomething" << endl;
	}
};

void Function1()
{
	cout << "function" << endl;
}

void Function2(int a)
{
	cout << a << endl;
}

int Function3(int a)
{
	return a + 3;
}

void main()
{
	function<void()> myFunc1 = &Function1;
	function<void(int)> myFunc2 = &Function2;
	function<int(int)> myFunc3 = &Function3;

	myFunc1();
	myFunc2(2);
	cout << myFunc3(3) << endl;

	function<void(TestObject&)> myFunc4 = &TestObject::DoSomething;

	TestObject tobj;
	myFunc4(tobj);

	function<void()> myFunc5 = nullptr;
	myFunc5 = bind(&TestObject::DoSomething, &tobj);
	myFunc5();
}
