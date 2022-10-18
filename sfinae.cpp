#include <stdlib.h>
#include <iostream>

using namespace std;

class X {};

struct Y {
		using type = X;
	};

template <class T>
void f(T) {
	cout << "f(T)" << endl;
}

template <class T>
void f(typename T::type) {
	cout << "f(T::type)" << endl;
}

int main() {
	f<X>( X{} );
	f<Y>( X{} );
	return EXIT_SUCCESS;
}