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