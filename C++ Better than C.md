

# C++ Better than C



### 1. Namespace

---



* Qualified name

```c++
#include <stdio.h>

namespace Audio {
	void init() {
		printf("Audio init\n");
	}
}

namespace Video {
	void init() {
		printf("Video init\n");
	}
}

// global namespace

void init() {
	printf("System init\n");
}

int main() {
//	init(); // global namespace or namespace both side search
	::init(); // only global namespace
	Audio::init();
	Video::init();

}
```



* Using declaration

```c++
#include <stdio.h>

namespace Audio {
	void init() { printf("Audio init \n"); }
	void reset() { printf("Audio reset\n"); }
}

int main() {
	Audio::init();

	using Audio::init; // using 선언   -> init 이라는 함수는 Audio라는 namespace 없이 사용
	init();
//	reset(); // error;

 }
```



* Using directive

```c++
#include <stdio.h>

namespace Audio {
	void init() { printf("Audio init \n"); }
	void reset() { printf("Audio reset\n"); }
}

int main() {
	Audio::init();

	using namespace Audio; // using directive
	init();
	reset();
 }
```



* Include header file

```c++
**** Audio.h ***
namespace Audio{ 
    void init();
    void reset();
}

***Audio.cpp****

#include <Audio.h>

namespace Audio{
    void init(){
        
    }
    void reset() {
    }
}

/*
	void Audio::init();
	void Audio::reset();
*/

// namespace3.cpp 와 Audio.cpp 동시에 build
***namespace3.cpp ****
    
int main(){
    Audio::init();
}
```



* std namespace



```c++
// #include <stdio.h>  c언어
#include <cstdio>
#include <algorithm>
// c++은 표준의 모든 요소를 "std" 이름 공간 내에 존재

int main(){
	int n = std::max(1,2); // qualified name    
}

/*
#include <stdio.h>

using std::max // max라는 함수는 std 없이 사용

int main(){
	int n = max(1,2);
}
*/


/* 

#include <stdio.h>
using namespace std; // std의 모든 요소를 std 없이 사용

int count = 0;
int main(){
	int n = max(1,2);
	printf("%d\n", count); // error -> function count와 name conplict
	printf("%d\n",::count); 
}
*/

```



```c++
/*
#include <stdio.h>
std::printf("aa"); // error  printf() 등의 표준 함수가 "global namespace"에 있다
*/
#include <cstdio.h>
// printf() 등의 표준 함수가 "global namespace"와 "std" 이름 공간에 있다
std::printf("AA"); // build success
printf("AA"); // success

```

* 전역공간에 있는 함수를 namespace에 포함시키는 방법

```c++
void foo() {}

namespace Audio {
    using ::foo; //Audio라는 namespace 내에서 foo라는 전역 변수를 사용
	void init() {}		
}

int main(){
    Audio::init();
    
    using Audio::init // using 선언
    init();
    
    foo();
    Audio::foo();
    
}
```



### 2. C++ 표준 입출력

----

* 표준 입출력 
  * std::cin : 서식 문자열이 필요 없고, 주소 연산자를 사용하지 않음
  * std::cout  : 변수 출력시 '서식 문자열을 지정할 필요 X'

```c++
 #include <iostream>

int main(){
    std::cout << "hello" << std::endl;
}
```

```c++
#include <iostream>
using std::cout;
using std::endl;

int main(){
    cout << "hello" << endl;
}
```

```c++
#include <iostream>
using namespace std;

int main(){
	cout << "hello" << endl;	
}
```

* io manipulator

```c++
#include <iostream>
#incldude <iomanip>
int main(){
    int n = 10;
    
    std::cout << n << std::endl; // 10진수
    
    std::cout << std::hex << n << std::endl; // 16진수
    
    std::cout << n << std::endl;  // 16진수
    
    std::cout <<std::dec;
    
    std::cout << n << std::endl; // 10진수
    
    std::cout << std::setw(10) << std::setfill('#') << "hello" << std::endl;
    // output #####hello
    std::cout << std::setw(10) << std::setfill('#') << std::setleft << "hello" << std::endl;
    // output hello#####
  
}
```



www.cppreference.com 참고

| function     | description             |
| ------------ | ----------------------- |
| std::dec     | 변수 값을 10진수로 출력 |
| std::hex     | 변수 값을 16진수로 출력 |
| std::setw    | 문자열 출력시 개수 지정 |
| std::setfill | 공백을 채울 문자 지정   |
| std::left    | 왼쪽 정렬(align)        |



### 3. C++ 변수의 특징

---



```c++
#include <iostream>
using namespace std;


struct Point {
	int x;  // c++ 11부터 int x=0; 으로 초기화 가능
	int y;
};

int main() {
	int n = 0;
	// struct Point pt
	Point pt;
	int a = 0102;  // 8진법
	int b = 0x15;  // 16진법
	int c = 0b10;  // 2진법
	cout << a << " " << b << " " << c << endl;
	int d = 100'000'000; // 자리수 표기
	cout << d << endl;

	bool z = true; // false;
	long long ll = 10; // 64bit
}
```

* Uniform Initialization

```c++
#include <iostream>
using namespace std;

struct Point {
	int x;
	int y;
};

int main() {
	/*
	int n1 = 10;
	int n2 = { 20 }; // c++

	int x[2] = { 1,2 };
	Point pt = { 1,2 };

	// 암시적 형변환에 의해 데이터 손실
	// compile possible
	int n3 = 3.4;
	char c = 300;
	*/

	// uniform initialization

	int n1 = { 10 };  // copy initialization    // recall을 이용해 initialization
	int n2{ 20 };     // direct initialization  // not recall / int n2(20);

	int x[2] = { 1,2 };
	Point pt = { 1,2 };

	/*
	// data 손실이 발생할 경우 compile error (prevent narrow)
	int n3 = { 3.4 };
	char c = { 300 };
	*/
}
```

* 함수의 인자로 '중괄호를 사용한 초기값'을 전달할 수 있음

```c++
#include <iostream>
using namespace std;

struct Point {
	int x;
	int y;
};

void foo(int n) {}; // int n = 10;
void goo(Point p) {}; 


int main() {
	int n = { 10 };

	foo(10);
	foo({ 10 });

	Point p = { 1,2 };
	goo({ 1,2 });

}
```

* auto / decltype

```c++


int main() {
	double x[5] = { 1,2,3,4,5 };

	auto n1 = x[0]; // 우변의 type을 통해 좌변의 type을 결정
    // n1의 type을 이용해 n3 type 결정 (변수의 type을 compiler가 결정) - 컴파일 시간에 결정되므로 Overhead X
	decltype(n1) n3;  
	decltype(n1) n4 = n1;

}
```

* 배열과 type 추론

```c++
int main(){
    int n1 = 10;
    
    auto a1 = n1;    // int
    decltype(n1) d1; // int
    
    int x[3] = {1,2,3};
    auto a2 = x;  // 1. int a2[3] = x;라고 추론하면 error
    			  // 2. int* a2 = x; 라고 추론하면 ok
    decltype(x) d2;  // int d2[3]; 로 추론
//  decltype(x) d3 = x; // int d3[3] = x; -> compile error
    
    int y[2] = {1,2};
    
    auto a4 = y[0]; // integer
//  decltype(y[0]) d4;  // int가 아니라 int&
    
}
```

* decltype과 함수 호출식

```c++
#include <iostream>
#include <typeinfo>

int foo(int a, double b) {
	return 0;
}

int main() {
	foo(1, 3.1);

	decltype(foo) d1; // 함수 타입 - int(int,double)

	decltype(&foo) d2;  // 함수 포인터 타입 - int(*)(int, double)

	decltype(foo(1, 3.1)) d3; // 함수 반환 타입 - int
	// unevaluated expression - 실제 함수가 호출 되는 것은 아님

	std::cout << typeid(d1).name() << std::endl;
	std::cout << typeid(d2).name() << std::endl;
	std::cout << typeid(d3).name() << std::endl;

	const int c = 0;
	std::cout << typeid(c).name() << std::endl; // 보다 정확히 출력하려면 boost library 사용
}
```

* using

```c++
using DWORD = int; // typedef int DWORD;
using F = void(*)(int, int);  //typedef void(*F) (int, int);

int main() {
	DWORD n; // int n;
	F f;     // void(*f)(int,int);
}
```

* const

```c++

void foo(const int s) {
//	int arr[s];  - s의 value가 compile 되지 않음
}

int main() {
	const int c1 = 10;
//	c1 = 20; // error
	constexpr int c2 = 10;
//	c2 = 20; // error


	int arr1[10];
	int s1 = 10;
//	int arr2[s1];  // g++은 지원하지만, micro cl compiler는 지원X

	const int s2 = 10;
	int arr3[s2];
	
	const int s3 = s1; // compile할 때는 s1의 값을 알 수 없다
//	int arr4[s3];
} 
```

* const  vs constexpr

const : "compile 시간 상수"와 "실행시간 상수"를 모두 만들 수 있다.

​			"변수 값으로 초기화" 할 수 있다

constexpr : "컴파일 시간 상수"만 만들 수 있다.

​					"컴파일 시간에 계산될 수 있는 값"으로만 초기화 가능

​					"template 인자로 사용"될 수 있다.

```c++

constexpr double pi = 3.14;

int main() {
	int n = 10;

	const int c1 = 10; // compile 상수, 배열 크기
	const int c2 = n;  // 실행시간 상수, 배열 크기 안 됨

	constexpr int c3 = 10; // compile 상수만 됨
//	constexpr int c4 = n; // error

}
```

* structured binding (17부터 지원)

```c++
#include <iostream>

struct Point {
	int x{ 10 };
	int y{ 20 };
};

int main() {
	Point pt;

	int x = pt.x;
	int y = pt.y;
	auto [x, y] = pt;
	
	int arr[2] = { 1,2 };
	auto[x, y] = arr;

//	int[x, y] = pt; //structured binding은 int type을 사용할 수 없다 / type은 반드시 auto
	const auto[x, y] = pt;

//	int x = 10; // error  앞서 선언한 x는 일반적인 변수로 사용

	std::cout << x << ", " << y << std::endl;
}
```

* string

````c++
#include <stdio.h>
#include <iostream>
#include <string> // <- c++ string type /  c string type -> cstring or string.h

int main() {
	char s1[32] = "hello";
	const char*s2 = "world";

//	s1 = s2;  // c언어는 배열의 이름을 포인터 상수로 보기 때문에 error
	strcpy(s1, s2);
//	if (s1 == s2) {}  // 비교 
	if (strcmp(s1, s2) == 0) {}


	std::string s3 = "hello";
	std::string s4 = "world";
	s3 = s4;
	if (s3 == s4) {
		std::cout << "Same" << std::endl;
	}
	std::string s5 = s3 + s4;
	std::cout << s5 << std::endl;	
}
````

* std::string과 c언어 호환

```c++
#include <iostream>
#include <string>

void foo(const char* s) {
	printf("foo : %s\n", s);
}

int main() {
	std::string s = "hello";
//	foo(s); // error
//	foo((const char*)s); //error

	foo(s.c_str()); // ok  - member 함수  // std::string을 const char*로 변환
}
```



### 4. C언어와 다른 C++ 함수

---

* default parameter

```c++


void setAlarm(int h, int m = 0, int s = 0) { // 인자를 받지 않으면 default로 사용
	//...
}

int main() {
	setAlarm(3, 4, 5);
	setAlarm(3, 0, 0);  // 3,0,0
	setAlarm(3); // 3,0,0
	setAlarm(3, 1); // 3,1,0
}

/* error(default인자는 마지막 인자부터 )
void foo(int a = 10, int b) {

}

int main() {
	foo(10);
}
*/
```



선언부에서 default를 지정했지만, 구현부에서 변경한다고 인식

```c++

void foo(int a = 0, int b = 0); // 선언부
// void foo(int a, int b)로 지정하면 foo(1,2)는 compile되지만, foo(1)은 인자가 부족하다고 판단

int main() {
	foo(1, 2);
	foo(1);
	foo();
}

void foo(int a = 0, int b = 0) { // 구현부

}

-->와 같이 선언부에만 default 설정
void foo(int a = 0, int b = 0);

int main() {
    foo(1,2);
    foo(1);
    foo(0);
}

void foo(int a /* =0 */ , int b) {}; // 주석으로 알려주기도 함

```

* function overloading

```c++

int square(int a) {
	return a * a;
}

double square(double a) {
	return a * a;
}

// c++에서 인자의 type이나 갯수가 다르면 사용 가능
int main() {
	square(3);
	square(3.3);
}
```



```c++

void f1(int a) {}
void f1(double d) {}

void f2(int a){}
void f2(int a, int b) {}

void f3(int a) {}
void f3(int a, int b = 0) {} // error
//f3(10); 

// 반환 타입만 다른 경우 overloading X
// int f4(int a) { return 0; }
// double f4(int a) { return 0; }



// 정수 타입과 포인터 타입에 대한 오버로딩은 사용 X
void f5(int n) {}
void f5(char* s) {}
// f5(0); // f5(int);
//f5(nullptr); // f5(char*) // C++11

int main() {

}
```



* template

```c++
/*
int square(int a) {
	return a * a;
}

double square(double a) {
	return a * a;
}
*/

template <typename T> // template parameter  - template을 만드려면 type하나를 만들어 줘야 함
// template <class T> // typename과 class 동일하게 사용
T square(T a) {  // call parameter
	return a * a;
}

// 구현이 동일하거나 유사한 함수가 여러개 있는 경우 컴파일러가 함수를 생성 (template intstantiation)

int main() {

	square <int> (3); // type을 int로 만듦
	square <double> (3.3);

	// type deduction - compiler가 type을 결정
	square(3);
	square(3.3);
}
```

* struct type template

```c++
struct Point {
	int x; 
	int y;
};

int main() {
	Point pt;
//	pt.x = 1.1; 
	pt.x = 1; 
	// 사용자가 type을 정하고 싶을 땐 template으로 구현
	pt.y = 1;

}
```

```c++
template <typename T>
struct Point {
	T x; 
	T y;
};

int main() {
	Point <int> pt;
	Point <double> pt2;
//	pt.x = 1.1; 
	pt.x = 1; 
	// 사용자가 type을 정하고 싶을 땐 template으로 구현
	pt.y = 1;

}
```

* inline function
  * cl 소스이름.cpp/FAs  -> 소스이름.asm
  * g++ 소스이름.cpp -S  -> 소스이름.s
  * 인라인 함수의 실제 치환 여부는 '컴파일러의 종류', '컴파일 옵션', '함수 크기' 등에 따라 달라짐
  * cl 컴파일러 같은 경우 '/Ob1' 옵션 사용 시 치환 적용 

```c++
int add1(int a, int b) {
	return a + b;
}

inline int add2(int a, int b) { // 치환되는 함수가 큰 경우 '목적 코드가 커질 수 있다'
	return a + b;
}

int main() {
	int n1 = add1(1, 2); // 호출
	int n2 = add2(1, 2); // function 호출이 아니라 기계어 코드를 치환
}
```

* delete function

```c++
void foo(int) = delete; // 함수 삭제

int main() {
//	foo(10);  - compile error / 삭제된 함수를 호출하면 compile 시간에 error

}
```

```c++
int gcd(int a, int b) {
	return b != 0 ? gcd(b, a%b) : a;
}

// double gcd(double a, double b); // 함수 선언만 하게 되면, Link Error를 발생
double gcd(double a, double b) = delete; // compile type error 발생

int main() {
	gcd(2, 10);
//	gcd(2.2, 4.3); // gcd(double, double) - 함수 호출 시 '인자의 암시적 형변환을 통해 호출 가능한 함수를 찾음'
}
```

```c++
template <typename T>

T square(T a) {
	return a * a;
}

char square(char) = delete;

int main() {
	square(3);
	square(3.3);
//	square('a');
}
```

* suffix return

```C++
// trailing return type   or   suffix return type
// lambda 표현식이나 함수 template에서 주로 사용

// int square(int a)
auto square(int a) -> int {
	return a * a;
}

int add(int a, int b) {
	return a + b;
}


// template 생성
template <typename T1, typename T2>
// decltype(a+b) add(T1 a, T2 b){  // 선언 시점보다 사용 시점이 더 빠름
auto add(T1 a, T2 b) ->decltype(a+b) { // C++14부터는 -> 이후 생략 가능
	return a+b;
}

//int main() {
auto main() ->int {
	square(3);

	add(1, 2.1); 
	
}
```

* constexpr function

```c++
// 함수의 인자 값을 compile 시간에 결정할 수 있으면 'compile 시간에 함수를 실행'

template <typename T, int N>
struct Buffer {
	T data[N];
};

constexpr int add(int a, int b) {
	return a + b;
}

int main() {
	int x = 1;
	int y = 1;

	int n1 = add(1, 1); // literal
	int n2 = add(x, y); // 함수의 인자 값을 컴파일 시간에 결정할 수 없으면 '실행 시간에 함수를 실행' - 일반 함수

	Buffer <int, 1024> b1;
//	Buffer <int, x> b1; compile 시간에 x 를 알 수 없으니 error
	Buffer <int, add(1, 1)> b2;
//  Buffer <int, add(x,2)> b3; // error

}
```

* constexpr function의 제약

```c++
#include <iostream>

constexpr int factorial(int n) {
	if (n == 1) { return 1; }
	return n * factorial(n - 1);
}

int main() {
	int n = factorial(5);
	std::cout << n << std::endl;

}
```

* lambda expression  (function literal)
  - 코드 내에서 이름이 없는 함수를 만듦

```c++
#include <iostream>

void foo(int a) {
	std::cout << "foo : " << a << std::endl;
}

int main() {
	foo(1); // 함수(함수 인자) : 함수 호출
	
	// lambda expression
	[](int a) {
		std::cout << "foo : " << a << std::endl;
	} (10);

}
```



```c++
#include <iostream>

int add(int a, int b) { return a + b; }

int main() {
	int n1 = add(1, 2);

	// lambda expression - making function
	int n2 = [](int a, int b) { return a + b; } (1,2); // 함수 호출    [] : lambda introducer

	std::cout << n1 << ", " << n2 << std::endl;
}
```



```c++
#include <iostream>
#include <algorithm>

bool cmp(int a, int b) { return a > b; } // 앞에 것이 더 작으면 교환

int main() {
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	//std::sort(x, x + 10); // 배열의 시작주소와 마지막 요소의 다음 주소
//	std::sort(x, x + 10, 크기 비교 함수);
//	std::sort(x, x + 10, cmp); -> 간단한 함수인 경우
	std::sort(x, x + 10,
		[](int a, int b) {return a > b; });
	for (auto n : x) std::cout << n << ", ";

}
```



### 5. C언어와 다른 C++ 제어문

---

* range for (C++11 부터 지원)

```c++
#include <iostream>

int main() {
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	// 배열 뿐 아니라, STL의 다양한 컨테이너(list, vector, set 등) 사용 가능
	// auto와 함께 사용되는 경우가 많음
	// 사용자가 만든 list도 사용 가능

	for (auto n : x) {
		std::cout << n << ", ";
	}
	/*
	for (int i = 0; i < 10; i++) {
	}
		std::cout << x[i] << ', ';
	*/
}
```

* if init, if constexpr (C++ 17부터 지원)

```C++
int foo() { return -1; }

int main() {
	/*
	int ret = foo();

	if (ret == -1) {
		// ...
	}
	*/

	if (int ret = foo(); ret == -1) {

	}

	/*
	int n = foo();
	switch (n) {
	case 10: break;
	case 20: break;
	}
	*/
	switch (int n = foo(); n) {
	case 10: break;
	case 20: break;
	}

}
```



```c++
int main() {
	int n = 0;

	if (n == 0) {  // 실행 시간에 조사
		// ....
	}


//	if constexpr (n == 0) {  // compile 시간에 조사 (반드시 compile 시간에 값을 정할 수 있어야 함) - static if
	if constexpr (sizeof(n) == 0 ) {
		// ...
	}
}
```



```c++
template <typename T>

void foo(T a) {
	if (0) *a = 0; // 실행 시간에 조사
	if constexpr (0) *a = 0; // compile 시간에 조사 - 특정 코드를 생성하지 못하게 할 때 주로 사용
}

int main() {
	int n = 0;
	foo(&n); // T : int*
	foo(n);  // T : int
}
```



### 6. Reference

---

* reference
  * 변수 : 메모리의 특정 위치를 가리키는 이름 (메모리에 접근)
  * reference 변수 : 기존 변수(메모리)에 또 다른 이름(alias) 을 부여

```c++
#include <iostream>

int main() {
	int n = 10;
	n = 20;

	int& r = n; // reference
	
	r = 30;
	
	std::cout << n << std::endl;
	std::cout << r << std::endl;
	std::cout << &n << std::endl;
	std::cout << &r << std:: endl;
}
```



```c++
#include <iostream>


void f1(int n) { ++n; }
void f2(int* p) { ++(*p); } //pointer 변수가 만들어지면서 주소가 가리키는 곳을 증가
void f3(int& r) { ++r; } // int&r = c  --> 


int main() {
	int a = 0, b = 0, c = 0;
	f1(a);
	f2(&b); // b가 변경될 수 있다고 예측 가능
	f3(c);  // 

	std::cout << a << std::endl; // 0 call by value
	std::cout << b << std::endl; // 1 call by pointer
	std::cout << c << std::endl; // 1

}
```

|           | Pointer                                  | Reference                                      |
| --------- | ---------------------------------------- | ---------------------------------------------- |
| 초기화    | 변수 주소로 초기화<br />초기값 생략 가능 | 변수 이름으로 초기화<br />초기값이 반드시 필요 |
| 요소 접근 | *연산자 사용<br /> *p1 = 10;             | *연산자가 필요 없다<br />r1 = 10;              |
| null      | NULL값을 가질 수 있다.                   | NULL 값을 가질 수 없다.                        |
| 주소 출력 | Pointer 변수의 주소                      | 기존 변수와 동일 주소                          |



```c++
#include <iostream>

int main() {
	int n = 10;

	// 포인터와 reference 둘 다 기존 변수(메모리)를 가리킨다
	int* p1 = &n;
	int& r1 = n;

//	int* p1 = 0; // null pointer 가능
//	int& r2;  - error / 초기값이 반드시 필요

	*p1 = 20;
	r1 = 20;

	if (p1 != 0) {}
	if (r1 != 0) {} // r1은 if문으로 조사할 필요 없다
	
	std::cout << &p1 << std::endl; // pointer 주소
	std::cout << &r1 << std::endl;  // 기존 value와 동일한 주소
}
```



* const reference
  * Overhead 방지
  * 인자에 대한 '복사본을 만들지 않는다'
  * '복사 생성자와 소멸자가 호출되지 않는다'

| type             | preference             |
| ---------------- | ---------------------- |
| primitive type   | call by value가 좋다   |
| user define type | const reference가 좋다 |



```c++
#include <iostream>

struct Date {
	int year;
	int month;
	int day;
};


/* overhead가 존재
void foo(Date d) { // call by value
	d.year = 1000;
}*/

void foo(const Date& d) {  // reference로 인자를 받지만 변경 X
//	d.year = 1000;  ERROR 처리
}


int main() {
	Date date = { 2020,3,28 };
	foo(date);
	std::cout << date.year << std::endl;
}
```



```c++
#include <iostream>

void foo(int x) {  // const reference	 or    call by value
				// 표준 type 같은 경우 call by value가 reference보다 최적화가 잘 됨

}

int main() {
	int n = 10;

	// foo 함수에서는 절대로 n을 변경해서는 안된다
	foo(n);

	std::cout << n << std::endl;
}
```





* reference return

```c++
#include <iostream>

struct Point {
	int x; 
	int y;
//	Point() {};
};

void f1(Point pt) {} // 복사본 생성
void f2(Point& pt) {} // 복사본 생성 X

Point pt = { 0,0 };

// Point foo() { return pt; } // value type return

Point& foo() {  // return 용 임시 객체가 아닌 pt return
	return pt;
}

int main() {
	foo().x = 10;  // return 용 임시 객체가 생성 - 복사본 / 임시 객체는 왼쪽항에 올 수 없음 - Error
	std::cout << pt.x << std::endl;
}
```



```c++
#include <iostream>

int x = 10;

int f1() { return x; }
int& f2() { return x; }

// n은 지역 변수라 파괴된 메모리의 alias를 사용하면 안됨
/*	 전역 변수만 참조 반환
int& f3() {
	int n = 10;
	return n;
}*/

int main() {
//	f1() = 20;  Error 10 = 20
	f2() = 20;  // f2()는 x의 메모리
}
```



* rvalue reference

```c++


int main() {
	int v1 = 0, v2 = 0;

	v1 = 10;      // 10 : rvalue  (오른쪽에만 올 수 있는 값)
//	10 = v1; error	v1 : lvalue (양쪽에 모두 올 수 있음)
	v2 = v1;

	// lvalue reference
	int& r1 = v1; // lvalue를 가리키는 것 ok
//	int& r2 = 10;    rvalue를 가리키면 compile error


	// const reference는 rvalue와 lvalue 모두 사용 가능
	const int& r3 = v1;  
	const int& r4 = 10;


	// rvalue reference - rvalue는 compile  / lvalue는 compile error
//	int&& r5 = v1;  error
	int&&r6 = 10;

}
```



### 7. C++ Explicit Casting

---



```c++
#include <iostream>

int main() {
//	int *p1 = (int *)malloc(sizeof(int) * 10);  c
	int *p1 = static_cast<int*>(malloc(sizeof(int) * 10)); // malloc의 결과인 void type을 int* type으로 cating
	free(p1);
}
```



```c++
#include <iostream>


int main() {
	int n = 0;
//	double* p1 = &n;   pointer 변수는 다른 type에 담을 수 없다
	double* p1 = (double*)&n;  // 잘못된 메모리 참조 or 추가된 메모리에 다른 변수가 있으면 값이 변경됨

	*p1 = 3.4;

	const int c = 10;
//	int* p2 = &c;  const라 변경 불가능 함 *p2 = 20와 같은 입력 가능성이 있기 때문에 error
	int *p2 = (int *)&c;
	*p2 = 20;
	std::cout << c << std::endl;  // build는 되고 10으로 출력되지만 오류 발생
}
```



| casting          | description                                                  |
| ---------------- | ------------------------------------------------------------ |
| static_cast      | 가장 기본적인 캐스팅 연산자<br />정수와 실수 사이의 변환, 열거형과 정수 사이의 변환<br />void* -> 다른 타입* 변환<br />배열 -> 포인터, 함수 -> 함수 포인터 등<br />- 상수형을 제거하거나 서로 다른 타입의 포인터 끼리의 변환은 허용하지 않음 <br />   (단, 상속 관계는 허용) |
| reinterpret_cast | 서로 다른 포인터 타입 끼리의 변환<br />정수와 포인터 사이의 변환 |
| const_cast       | 포인터와 참조형의 상수성과 volatile 속성을 제거하는 데 사용  |
| dynamic_cast     | 안전한 다운 캐스팅(기반 클래스 포인터를 안전하게 파생 클래스 타입의 포인터로 캐스팅 할 때 사용)<br />실행시간 캐스팅 - 실행 시간 Overhead가 존재 |

* static_cast

```c++
#include <iostream>

void foo(int) {}
void foo(double) {}

int main() {
	const int c = 10;
	double d = 3.4;
	
	int n = static_cast<int>(d);  
	int* p1 = static_cast<int*>(malloc(100));

	auto p2 = static_cast<void(*)(int)>(&foo); // void를 반환하는 함수 포인터인데 인자가 int

//	int* p3 = static_cast<int*>(&d);  error
//	int* p4 = static_cast<int*>(&c);  error
}
```

* reinterpret_cast / const_cast

  * reinterpret_cast 
    * 서로 다른 타입의 포인터 사이의 변환
    * 정수와 포인터 사이의 변환

  ```c++
  #include <iostream>
  
  int main() {
  	int n = 10;
  	double* p1 = reinterpret_cast<double*>(&n);
  
  	int* p2 = reinterpret_cast<int*>(10);
  	std::cout << p2 << std::endl;
  
  //	double d = reinterpret_cast<double>(n);  integer를 double에 넣는거 (용도가 틀림)
  }
  ```

  * const_cast
    * 포인터 변수와 참조 변수 사이의 상수성(const)과 volatile 속성을 제거하기 위한 캐스팅

  ````c++
  int main() {
  	const int c = 10;
  	volatile int v = 20;
  
  	int n = c;
  
  	int* p1 = const_cast<int*>(&c);  // 괄호 안의 상수성을 제거
  	int* p2 = const_cast<int*>(&v);
  
  //	double* p3 = const_cast<double*>(&c);  다른 타입으로 변경 불가
  
  }
  ````

```c++

int main() {
	const int c = 10;

//  char* p = static_cast<char*>(&c);  // const 속성 변경 불가

//  char* p = const_cast<char*>(&c);  const의 속성만 변경
	
//	char* p = reinterpret_cast<char*>(&c); const 속성 변경 불가

	// casting 2번
	char* p = reinterpret_cast<char*>(const_cast<int*>(&c));

	char* p1 = const_cast<char*>(reinterpret_cast<const char*>(&c));

	char* p2 = (char*)&c; // 개발자의 의도가 들어가 있지 않음
}
```



### 8. 동적 메모리 할당, nullptr

---

 

```C++
#include <stdio.h>
#include <malloc.h>

int main() {
	// c
	int* p1 = (int *)malloc(sizeof(int) * 10); // malloc은 casting을 해야 됨 - 생성자 호출 X
	free(p1);

	// c++
	int* p2 = new int;  // casting 없이 사용  - 생성자를 호출
	delete p2;

	int* p3 = new int[10]; // 40byte
	delete[] p3;
	// delete p3  미정의 동작(undefined)
}
```



```c++
#include <cstdio>


int main() {
	int* p1 = 0; 
	int* p2 = nullptr;  // c++ 11부터 지원
}
```



```c++
#include <iostream>

void foo(int n) { std::cout << "int" << std::endl; }
void foo(double d) { std::cout << "double" << std::endl; }
void foo(bool b) { std::cout << "bool" << std::endl; }
void foo(char* s) { std::cout << "char*" << std::endl; }

int main() {

	// 0은 int type이지만 실수, bool, 포인터 타입으로 암시적 형변환 가능
	int n = 0;
	int d = 0;
	int b = 0;
	char* s = 0;

	foo(0); // int를 호출하지만, 만약 주석처리하면 error 발생
	foo(0.0); // 실수 literal
	foo(false); // bool type 
	foo((char*)0); // char*, 포인터 literal
	foo(nullptr);
}
```



```c++

int* foo() { return 0; }

int main() {
	auto ret = foo();

	if (ret == nullptr) {  // pointer라는 확정을 줄 때 0이 아닌 nullptr 사용
		//...
	}
}
```

* nullptr과 데이터 타입
  * nullptr은 "std::nullptr_t" 타입
* nullptr_t 타입과 형변환
  * std::nullptr_t 타입은 "모든 타입의 포인터로 암시적 변환된다"
  * std::nullptr_t 타입은 "int 타입으로 변환될 수 있다"
  * std::nullptr_t 타입은 "bool 타입으로 직접 초기화(direct initialization)시 초기값으로 사용 가능"하다

```c++


int main() {
	0; // int
	0.0; // double
	nullptr; // std::nullptr_t

	int* p1 = nullptr;
	char* p2 = nullptr;
	void(*f)() = nullptr;

//	int n1 = nullptr;   error
	int n2 = 0;

	// bool type은 직접 초기화는 허용하지만 복사 초기화는 허용되지 않는다
//	bool b1 = nullptr; error
	bool b2(nullptr);
	bool b3{ nullptr };
//	bool b4 = { nullptr; } error
}
```

* NULL과 nullptr

```c++
#include <iostream>

void foo(int n) { std::cout << "int" << std::endl;}
void foo(void* p) { std::cout << "void*" << std::endl; }

void goo(char* n) { std::cout << "goo" << std::endl; }

#ifdef __cplusplus
#define NULL 0
#else
#define NULL (void*)0
#endif

int main(){
    foo(0); // int 
    foo((void*)0); // c++11부터 nullptr 사용 / 이전에는 casting
    foo(NULL); // void* -> (marco) int
    
    goo(NULL); // c에서는 void*가 다른 type으로 암시적 형변환 가능하지만, 
               // c++에서는 다른 type으로 형변환 불가능해 ERROR 
    
}

```



# 실습과제 #1

- 

C언어 에서는 2개의 정수 값을 교환하기 위해서는 아래 와 같이 Swap 함수를 만들어서 사용합니다.

```
#include <iostream>

void Swap(int* x, int* y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}
int main()
{
  int a = 10, b = 20;
  Swap(&a, &b);
  std::cout << a << ", " << b << std::endl;
}
```





실습 문제 1.
포인터 대신 참조(Reference)를 사용해서 만들어 보세요.


실습 문제 2.
int 타입 대신에 모든 타입에 사용할 수 있도록 함수 템플릿으로 만들어 보세요.


실습 문제 3.
Swap 함수를 전역 공간에 놓지 말고 Util 이라는 namespace 안에 넣고, main 함수에서 Swap을 사용하는 코드도 만들어 보세요.


실습 문제 4.
C++ 표준에는 이미 swap 함수를 템플릿 버전으로 제공하고 있습니다. swap 함수를 사용하려면 <algorithm> 헤더를 사용해야 합니다. 또한 swap 함수는 std namespace 안에 있습니다. C++ 표준에 있는 swap을 사용해 보세요.