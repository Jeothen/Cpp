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



1:41