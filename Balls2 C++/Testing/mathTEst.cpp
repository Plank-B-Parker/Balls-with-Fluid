template<typename T>
class B;

template<typename T>
class A {
	B<T> b;

public:
	A() {
		b = B<T>(5);
	}
};

template<typename T>
struct B {
	friend A<T>;


private:
	int a;
	B(int A) : a(A) {

	}
	B() : a(0) {
	}
};