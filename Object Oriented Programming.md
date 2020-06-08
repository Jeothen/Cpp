# Object Oriented Programming







```c++

// 복소수 2개를 더하고 싶다.
void add(double ar, double ai, double br, double bi, // in parameter
	    double* sr, double* si) { // out parameter
	*sr = ar + br;
	*si = ai + bi;
}

int main() {
	double xr = 1, xi = 1; // 1+ 1i
	double yr = 2, yi = 2; // 2+ 2i
	double sr, si;
	add(xr, xi, yr, yi, &sr, &si);
	// sr, si 결과가 있다.
}
```



```c++
Struct Complex{
    double real;
    double image;
};

Complex add(const Complex& c1, Complex c2) {  // const &함수가 성능 향상에 좋다
    Complex temp;
    temp.real = c1.real + c2.real;
    temp.image = c1.image + c2.image;
    return temp;
}

int main() {
    Complex c1 = {1,1};
    Complex c2 = {2,2};
    Complex ret = add(c1,c2);
}
```



* buffer가 1개일 때

```c++
#include <iostream>

int buf[10];
int idx = 0;

void push(int value) {
	buf[idx++] = value;
}

int pop() {
	return buf[--idx];
}

int main() {
	push(10);
	push(20);
	push(30);
	std::cout << pop() << std::endl;
	std::cout << pop() << std::endl;
}

```



* buffer가 2개일 때

```c++
#include <iostream>

void push(int* buf, int* idx, int value) {
	buf[++(*idx)] = value;
}

int pop(int* buf, int* idx) {
	return buf[(*idx)--];
}

int main() {
	int buf1[10];
	int idx1 = 0;
	int buf2[10];
	int idx2 = 0;
	push(buf1, &idx1, 10);
	push(buf1, &idx1, 20);
	push(buf1, &idx1, 30);
	push(buf2, &idx2, 30);
	std::cout << pop(buf1, &idx1) << std::endl;
	std::cout << pop(buf1, &idx1) << std::endl;
	std::cout << pop(buf2, &idx2) << std::endl;

}
```

* buffer와 index를 하나의 struct로 표현
  * Stack의 "상태를 나타내는 데이터와 상태를 조작하는 함수가 분리"되어 있다.  push와 pop 함수가 "1번째 인자로 Stack을 전달" 받아야 한다.
  * push, pop 함수 이외의 함수에서도 idx와 buf에 접근할 수 있다.

```c++
#include <iostream>

struct Stack {
	int buf[10];
	int idx;
};

void push(Stack* s, int value) {
	s->buf[s->idx++] = value;
}

int pop(Stack* s) {
	return s->buf[--(s->idx)];
}

int main() {
	Stack s1;
	Stack s2;
	s1.idx = 0; s2.idx = 0;
	push(&s1, 10);
	push(&s1, 20);
//	s1.idx = 0;
	push(&s2, 30);

	std::cout << pop(&s1) << std::endl;
	std::cout << pop(&s2) << std::endl;
}

```

* 위 단점 극복 (Stack 내에 함수를 삽입)

```c++
#include <iostream>

struct Stack {
	int buf[10]; // member data
	int idx;

	void push(int value) { // member 함수 - member data에 접근 가능
		buf[idx++] = value;
	}

	int pop() {
		return buf[--idx];
	}
};

int main() {
	Stack s1;
	Stack s2;
	s1.idx = 0; s2.idx = 0;
	s1.push(10);
	s1.push(20);
	s2.push(30);
	
	std::cout << s1.pop() << std::endl;
	std::cout << s2.pop() << std::endl;
}
```

* 정보 온닉 - stack 내에서만 idx 수정 가능

```c++
#include <iostream>

/*
struct Stack {
// 접근 지정자 설정
private : // 멤버 함수 내에서만 접근할 수 있다 (main에서 사용 불가)
	int buf[10]; // member data
	int idx;
*/

class Stack {  // struct는 private을 적지 않으면 public 처리 / class는 private 처리
	int buf[10];
	int idx;
public:  // 멤버 함수가 아닌 함수에서도 접근 가능  (외부에서 접근하면 객체가 불안정할 수 있음)
	void init() { idx = 0;  } // private에 접근 가능 (멤버함수)
	void push(int value) { // member 함수 - member data에 접근 가능
		buf[idx++] = value;
	}
	int pop() {
		return buf[--idx];
	}
};

int main() {
	Stack s1;
	Stack s2;
	s1.init(); s2.init();
	s1.push(10);
	s1.push(20);
	s2.push(30);
	
	std::cout << s1.pop() << std::endl;
	std::cout << s2.pop() << std::endl;
}
```

* 초기화를 자동으로

```c++
#include <iostream>



class Stack { 
private:
	int buf[10];
	int idx;
public:  
	Stack() { idx = 0;  } // 반환값과 Class 이름과 동일하면 생성자 (init기능)

	void push(int value) {
		buf[idx++] = value;
	}
	int pop() {
		return buf[--idx];
	}
};

int main() {
	Stack s1;
	Stack s2;
	s1.push(10);
	s1.push(20);
	s2.push(30);
	
	std::cout << s1.pop() << std::endl;
	std::cout << s2.pop() << std::endl;
}
```

* 소멸자

```c++
#include <iostream>

class Stack {  
private:
	int* buf;
	int idx;
public: 
	Stack(int size = 10) { 
		buf = new int[size]; // new로 만든 메모리는 delete로 삭제
		idx = 0;  
	}
	~Stack() { delete[] buf; } // 소멸자  (함수를 벗어날 때 자동으로 호출)

	void push(int value) {
		buf[idx++] = value;
	}
	int pop() {
		return buf[--idx];
	}
};
```

* 파일 분할

```c++
# stack.h  // 보통 header 파일로 만듦
class Stack {   
public:  // 선언만 해줌
	Stack(int size = 10);
	~Stack();
	void push(int a);
	int pop();
    
private:  // 관례상 private을 아래로 둔다
	int* buf;
	int idx;
};

#include "stack.h"
Stack::Stack(int size = 10) {
	buf = new int[size]; 
	idx = 0;
}
Stack::~Stack() { delete[] buf; } 
void Stack::push(int value) { buf[idx++] = value; } // Stack의 member 함수인 걸 표현
int Stack::pop() { return buf[--idx]; }

```

* class template 

```c++
#include <iostream>

template<typename T> // 하나의 Stack에 여러 타입이 보관되는 게 아니라, 각각의 type을 저장하는 별도의 Stack 클래스 코드를 컴파일러가 생성하는 것
class Stack {
private:
	T* buf;
	int idx;
public:
	Stack(int size = 10) {
		buf = new T[size]; // new로 만든 메모리는 delete로 삭제
		idx = 0;
	}
	~Stack() { delete[] buf; } // 소멸자  (함수를 벗어날 때 자동으로 호출)

	void push(T value) {
		buf[idx++] = value;
	}
	T pop() {
		return buf[--idx];
	}
};

int main() {
	Stack <int> s1(30); // 다양한 buf 사이즈를 선택 가능
	Stack <double> s2(10);
	s1.push(10);
	s1.push(20);
	s2.push(30.0);
	
	std::cout << s1.pop() << std::endl;
	std::cout << s2.pop() << std::endl;

}
```



* Programming Paradigm
  * 변수 (Variable) 
    * "변"하는 "수"
    * "메모리의 특정 위치를 가리키는 이름"
    * 변수를 사용하면 "메모리에 값을 읽거나 쓸 수" 있다
    * 언어가 제공하는 "기본 타입(primitive type)의 인스턴스"
  * 객체 (Object)
    * 메모리를 할당하고 "자신을 스스로 초기화" 한다.
    * 상태와 동작을 가질 수 있는 존재
    * 객체를 사용하면 해당 "객체가 제공하는 다양한 서비스를 사용"할 수 있다.
    * "사용자 정의 타입( User Define Type)으로 만든 변수"

```c++
int main(){
	int n = 10;  // 변수
    
    std::stack<int> s; // 객체
}
```

* C++은 "다중 패러다임(Multi Paradigm)"언어이다.
  * "명령형(절차적) 프로그래밍 패러다임" 지원
  * "객체 지향 프로그래밍 패러다임" 지원
  * "일반화 프로그래밍 패러다임" 지원
  * "함수형 프로그래밍 패러다임" 지원



* STL, Stack, Vector
  * STL
    * C++에서 제공하는 표준 라이브러리
    * Standard Template Library
  * STL에서 제공하는 Stack
    * Stack 헤더
    * 클래스 템플릿으로 되어 있다.
    * push, top, pop
  * Vector
    * 배열과 유사하게 연속된 메모리를 사용하는 컨테이너
    * <vector> 헤더파일
    * 배열과 동일한 방법으로 사용 가능 - [] 연산 사용 가능
    * 크기를 조절할 수 있다. - resize 멤버 함수

```c++
#include <iostream>
#include <vector>

int main() {
	
	std::vector <int> v = { 1,2,3,4,5,6,7,8,9,10 };

	x[0] = 10;
	
	x.resize(20);
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << std::endl;
	}
}
```

* 접근 지정자 (access specifier)
  * private, public, protected
  * 일반적으로 private : 멤버 데이터 / public : 멤버 함수   
  * 객체의 "사용자는 객체의 멤버 데이터의  구조에 대해서는 알 필요 없다" -> 정보 은닉
  * 멤버 함수를 통해서만 상태를 변경할 수 있기 때문에 "객체의 상태를 안전하게 유지" -> 캡슐화
  * setter / getter : 멤버 데이터의 값을 변경하거나 얻기 위해 사용하는 멤버 함수를 나타내는 용어

```c++
struct Bike {
public:
	void changeGear(int n) {
		// member 함수 내에서 제어할 수 있음
		if (n < 1) return;
		gear = n;
	}
    int getGear() { return gear;}
private:
	int color;
	int gear;
};

int main() {
	Bike b;
//	b.gear = -7; // 멤버 데이터를 "외부에서 직접 접근하면 잘못된 상태를 가질 수 있음" (private 처리)

	b.changeGear(-7); // 멤버 함수를 통해서만 멤버 데이터를 변경 할 수 있다. - 멤버 함수는 유효성 여부 조사 
    int n = b.getGear();  
}
```

* friend 함수
  * 멤버함수가 아닐 때 private에 접근할 수 없다.
  * friend 함수는 멤버 함수는 아니지만 private에 접근할 수 있다.
  * getter/setter를 제공하면 모든 함수에서 접근할 수 있지만 friend로 만들면 특정 함수에서만 접근

```c++
class Airplane {
	int color;
	int speed;
	int engineTemp;
public:
	int getSpeed() { return speed; }
	
	friend void fixAirplane(Airplane &a);
};

void fixAirplane(Airplane& a) {
	int n = a.engineTemp;
}

int main() {
	Airplane a;
	fixAirplane(a);
}
```



* 생성자 

```c++
#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
//	Point() { x = 0; y = 0; cout << "1" << endl; }
//	Point(int a, int b) { x = a, y = b; cout << "2" << endl; }
};

int main() {
	Point p1;  // 생성자를 선언하지 않으면 compiler가 인자가 없는 default 생성자를 만든다
//	Point p2(1, 2);
}
```



```c++
#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point() { x = 0; y = 0; cout << "1" << endl; }
	Point(int a, int b) { x = a, y = b; cout << "2" << endl; }
};

int main() {
	Point p1(1, 2); // 2번째
	Point p2{ 1,2 }; // 직접 초기화 문법 2번째 / c++ 11 이후
	Point p3 = { 1,2 }; // 복사 초기화 2번째 / c++11 이후

	Point p4; // 1번
	Point p5();  // 함수의 선언 - p5 객체 생성이 아님
	Point p6{};  // 1번 생성자 -  직접 초기화
	Point p7 = {}; // 1번 - 복사 초기화

	Point p8[3]; // 1번 생성자를 3번 호출
	Point p9[3] = { Point(1,1) }; // 첫번째 - 2번 / 두세번째 - 1번 생성자 호출 
	Point p10[3] = { {1,1}, {2,2} };  //  1,2번째 - 2번 / 세번째 - 1번  / c++11 부터 사용

	Point* p11;  // 포인터 변수만 만들었기에 생성자 호출x


	// 메모리만 할당 됨 - 생성자 할당x
	p11 = static_cast<Point*>(malloc(sizeof(Point)));
	free(p11);

	// new는 생성자 호출 (일반 생성자)
	p11 = new Point;
	delete p11;

	p11 = new Point(); // 1번 생성자
	delete p11;

	p11 = new Point(1, 2); // 2번 생성자
	delete p11;


}
```

* 생성자 / 소멸자 호출 순서

```c++
#include <iostream>
class Point {
	int x, y;
public:
	Point() { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

class Rect {
	Point p1;
	Point p2;
public:
	Rect() { std::cout << "Rect()" << std::endl; }
	~Rect() { std::cout << "~Rect()" << std::endl; }
};

int main() {
	Rect r;
}
```

객체 생성 : 멤버 생성자 먼저 호출  -> 자신의 생성자 호출

객체 파괴 : 자신의 소멸자 호출 -> 멤버 소멸자 호출



* 위임생성자 
  * 생성자에서 다른 생성자를 호출 (클래스 구현부에 표기)

```c++
class Point {
	int x, y;
public:
	Point() : Point(0, 0)
	{
//		x = 0;
//		y = 0;
	}
	Point(int a, int b) 
	{
		x = a;
		y = b;
	}
};

int main() {
	Point p;
}

---------------------------------------------------------------
    // Point. h
class Point
{
	int x, y;
public:
	Point();
	Point(int a, int b);
};

// Point.cpp
#include "Point.h"

Point::Point() : Point(0, 0)
{
}

Point::Point(int a, int b)
{
	x = a; y = b;
}
```

* default 생성자

```c++
class Point
{
	int x; int y;
public:
	Point() = default;   // default 생성자도 제공해줌 - 구현부에 만들어 줄 필요 없다
//  Point() = delete // 생성자도 삭제할 수 있다. - 복사 생성자에서 많이 사용    
//	Point() {}
	Point(int a, int b) {}  
};

int main() {
	Point p1;
	Point p2(1, 2);
}
```



* 소멸자
  * 사용자가 소멸자를 만들지 않으면 compiler가 제공함

```c++
// c style
#include <stdio.h>

int main() {
	FILE* f = fopen("a.txt", "wt");

//	f = 0;  자원의 핸들을 담는 "변수에 직접 접근" 할 수 있다
	fputs("hello", f);

//	fclose(f); 획득한 자원은 반드시 반납
}

--------------------------------------
    
```

* 생성자에서 자원을 할당하고 소멸자에서 자원을 해지 (c++)

```c++
#include <iostream>
#include <cstdio>
#include <string>

class File {
	FILE* file = 0;  // 자원의 번호를 담은 멤버 변수는 private에 넣어 외부에서 접근 못하게 함
public:
	File(std::string filename, std::string mode) 
	{
		file = fopen(filename.c_str(), mode.c_str());
	}
	~File() 
	{
		fclose(file);
	}
	// RW 함수들
	void puts(std::string s) 
	{
		fputs(s.c_str(), file);
	}
};

int main() {
	File f("a.txt", "wt");
	f.puts("hello");
}
```



### 초기화 리스트

* class의 멤버 데이터에 const 나 reference가 있는 경우 생성자에서 초기화를 해야됨(대입x)

```c++
#include <iostream>

class Point {
	int x; 
	int y;
	const int cval;
	int &r; 

public :
	Point(int a, int b, int c) : x(a), y(b), cval(c), r(a)  // 초기화
	{
//		cval = c; 대입이라 error
//		x = a;  대입 
//		y = b;
	}
};

int main() {
	Point p(1, 2,10);
	int a = 0; // 초기화 , 생성자 호출
	int b;   // 생성자 호출
	b = 0;  // 대입.  대입연산자 호출
}
```



* class 내에 default 생성자가 없는 type(Point)가 멤버로 있는 경우

```c++
#include <iostream>
class Point {
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};
/*
class Rect {
	Point p1{ 1,1 };
	Point p2{ 2, 2 };
public:
	Rect() {}
};
*/
class Rect {
	Point p1;
	Point p2;
public:
	Rect(int a, int b, int c, int d) : p1(a, b), p2(c, d) 
	{
	}
};
int main() {
	Rect r(1,2,3,4);
}	
```

* 멤버 초기화 리스트 

```c++
#include <iostream>

class Point {
public:
	int x;
	int y;
public:
	Point() : y(0), x(y) {}
};

int main() {
	Point p;
	// 메모리에 x와 y가 잡히는데 x가 먼저 선언되었음 (초기화는 만들어질 때 초기화가 됨)
	std::cout << p.x << std::endl; // x부터 초기화되고 y가 초기화 됨
}
```



```c++
// Point.h
class Point{
	int x = 0;
	int y = 0;
public:
	Point(int a, int b);
}

// Point.cpp
#include "Point.h"

Point::Point(int a, int b) : x(a), y(b) {}  // 위임생성자도 : 뒤에 사용
```

* explicit 생성자

```c++
#include <iostream>

class OFile {
	FILE* file;
public:
	OFile(const char* filename) {
//	explicit OFile(const char* filename);  직접 초기화만 허용하고 복사 초기화는 X
		file = fopen(filename, "wt");
	}
	~OFile() { fclose(file); }
};

void foo(OFile f) {}

int main() {
	OFile f1("a.txt");  // 직접 초기화
    OFile f2 = "a.txt";  // 복사 초기화
	foo(f1);
	foo("hello");  // OFile f = hello로 복사 초기화 발생

}
```

* class 생성자 explicit

```c++
#include <iostream>
#include <vector>
#include <string>
#include <memory>

int main() { 
	std::string s1("hello"); // OK
	std::string s2 = "hello"; // OK

	std::vector<int> v1(10); // OK
	std::vector<int> v2 = 10; // Error (생성자가 explicit)
	std::vector<int> v2 = { 10 }; // OK  ({}는 explicit으로 생성자를 만들지 않음)
	
	// c++ 표준 스마트 포인터
	std::shared_ptr<int> p1(new int); // ok
	std::shared_ptr<int> p2 = new int; // error (생성자가 explicit)
}
```

### 복사생성자

* 자신과 동일한 타입 한개를 인자로 가지는 생성자

* 사용자가 복사 생성자를 만들지 않으면 compiler가 default 복사 생성자를 만든다. - 모든 멤버를 복사

```c++
#include <iostream>

class Point {
public:
	int x;
	int y;

	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}

};

int main() {
	Point p1; // 1번 OK
	Point p2(1, 2); // 2번  OK
//	Point p3(1); // ERROR
	Point p4(p2); // Point(Point) - ok.
}

/* 동일한 타입의 생성자가 없는 경우 compiler가 생성자를 만듦
 - 

Point(const Point& p)
	: x(p.x), y (p.y) {}

*/
```

* 복사 생성자가 호출되는 3가지

  * 자신과 동일한 타입의 객체로 초기화 될 때

  ```c++
  #include <iostream>
  
  class Point {
  public:
  	int x;
  	int y;
  	Point(int a, int b) : x(a), y(b) {
  		std::cout << "ctor" << std::endl;
  	}
  	Point(const Point& p) : x(p.x), y(p.y) {
  		std::cout << "copy ctor" << std::endl;
  	}
  };
  
  int main() {
  	Point p1(1, 2); // 생성자
  	Point p2(p1);   // 복사 생성자
  	Point p3{ p1 }; // 직접 초기화
  	Point p4 = { p1 }; // 복사 초기화 - explicit 처리 시 Error
  	Point p5 = p1 ;    // 복사 초기화
  }
  ```

  * 함수 인자를 call by value로 받을 경우

  ```c++
  #include <iostream>
  
  class Point {
  public:
  	int x;
  	int y;
  
  	Point(int a, int b) : x(a), y(b) {
  		std::cout << "ctor" << std::endl;
  	}
  	Point(const Point& p) : x(p.x), y(p.y) {
  		std::cout << "copy ctor" << std::endl;
  	}
  };
  
  // void foo(Point pt) { // Point pt = p1 - 복사 생성자 (call by value)
  void foo(const Point& pt) {  // 메모리에 복사본을 만드는 게 아니라 참조하는 것이니 explicit 가능
  }
  
  int main() {
  	Point p1(1, 2); // 생성자
  	foo(p1);
  }
  ```

  * return 타입

  ```c++
  #include <iostream>
  
  class Point {
  public:
  	int x;
  	int y;
  
  	Point(int a, int b) : x(a), y(b) {
  		std::cout << "ctor" << std::endl;
  	}
  	Point(const Point& p) : x(p.x), y(p.y) {
  		std::cout << "copy ctor" << std::endl;
  	}
  };
  
  Point p; // 생성자
  //Point& foo() {  인 경우 복사 생성자를 부르지 않고 참조만 한다. 
  // 단, 지역 변수인 경우 참조로 반환하면 안된다 (전역 변수인 경우만 사용)
  
  Point foo() { // 값 타입 반환인 경우 return용 임시 객체를 만든다 (만들 때 복사 생성자 호출)
  	return p;
  }
  
  int main() {
  	foo();
  }
  
  ```

* default 복사 생성자의 문제점

  * 얕은 복사 : 클래스 안에 포인터 멤버가 있을 때, 디폴트 복사 생성자가 "메모리 자체를 복사하지 않고 주소만 복사하는 현상"

```c++
#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

class Person {
	char* name;
	int age;
public:
	Person(const char* n, int a) : age(a) {
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	~Person() { delete[] name; }
};

int main() {
	Person p1("kim", 20);
	// Shallow copy - 얕은 복사 ( 메모리 자체를 복사하지 않고 주소만 복사하는 현상)
	Person p2 = p1; // 실행시 error - 복사 생성자가 없으니 default 복사 생성자 호출 
	//  p2가 파괴될 때, "kim" 메모리 파괴 - p1에서 name을 delete할 때 이미 delete 된 메모리
}
```

* 객체의 복사 방법
  * 깊은 복사 : 클래스 안에 포인테 멤버가 있을 때, "메모리 주소를 복사하지 말고 메모리 자체의 복사본을 만드는 기술"

```c++
Person(const Person& p) : age(p.age) { 
    //		age = p.age;
    //		name = p.name; // 포인터를 제외한 모든 멤버를 복사
    name = new char[strlen(p.name) + 1];
    strcpy(name, p.name);
}

```



* 참조 계수
  * 여러 객체가 하나의 자원을 공유
  * 단, 몇 개의 객체가 자원을 사용하는지 "개수를 관리"

```c++
class Person {
	char* name;
	int age;
	int* ref; // 참조 계수를 가리키는 포인터 변수
public:
	Person(const char* n, int a) : age(a) {
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	
//		ref = new int;
//		*ref = 1;  or
		ref = new int(1); // 초기값
	}
	~Person() { 
		// 참조 계수 기반일 때 소멸자
		if (--(*ref) == 0) {
			delete[] name; 
			delete ref;
		}
	}

	Person(const Person& p) : name (p.name), age(p.age), ref(p.ref) { 
		++(*ref); // ref 증가
	}
};
```

* 복사 금지

```c++
#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

class Person {
	char* name;
	int age;
public:
	Person(const char* n, int a) : age(a) {
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	~Person() { delete[] name; }
    
    Person(const Person&) = delete; // 복사 생성자를 못만들게 함
};

int main() {
	Person p1("kim", 20);
	Person p2 = p1; // 컴파일 에러 발생
}
```

* String STL

```c++
#include <iostream>
#include <cstring>
#include <string>
#pragma warning(disable:4996)

// string이 내부적으로 자원 관리 - 동적할당을 할 필요 없다
class Person {
	std::string name;
	int age;
public:
	Person(std::string n, int a) : name(n), age(a) {
		
	}
};

int main() {
	Person p1("kim", 20);
	Person p2 = p1;
}
```

### Static Member

