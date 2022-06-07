#include "vector.hpp"
#include <iostream>
#include <string>
#include <vector>

void	constructor_test(){
	ft::vector<int> first;
	ft::vector<int> second (4,100);
	ft::vector<int> third (second.begin(),second.end());
	ft::vector<int> fourth (third);

	int myints[] = {16,2,77,29};
	ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	std::cout << "The contents of fifth are:";
	for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';
}

void	operator_egal_test(){
	ft::vector<int> foo (3,0);
	ft::vector<int> bar (5,0);

	bar = foo;
	foo = ft::vector<int>();

	std::cout << "Size of foo: " << int(foo.size()) << '\n';
	std::cout << "Size of bar: " << int(bar.size()) << '\n';

	std::cout << "##################" << std::endl;
	std::cout << "begin vector" << std::endl;

	ft::vector<int> myvector;
	for (int i=1; i<=5; i++) myvector.push_back(i);

	std::cout << "myvector contains:";
	for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';
}

void	end_test(){
	ft::vector<int> myvector;

	for (int i=1; i<=5; i++) myvector.push_back(i);
	std::cout << "myvector contains:";
	for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';
}

void	rbegin_test(){
	ft::vector<int> myvector3 (5);
	int i=0;

	ft::vector<int>::reverse_iterator rit = myvector3.rbegin();
	for (; rit!= myvector3.rend(); ++rit)
	*rit = ++i;

	std::cout << "myvector3 contains:";
	for (ft::vector<int>::iterator it = myvector3.begin(); it != myvector3.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';
}

void	rend_test(){
	ft::vector<int> myvector4 (5);  // 5 default-constructed ints

	ft::vector<int>::reverse_iterator rit = myvector4.rbegin();

	int i=0;
	for (rit = myvector4.rbegin(); rit!= myvector4.rend(); ++rit)
	*rit = ++i;

	std::cout << "myvector4 contains:";
	for (ft::vector<int>::iterator it = myvector4.begin(); it != myvector4.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';
}

void	size_test(){
	ft::vector<int> myints2;
	std::cout << "0. size: " << myints2.size() << '\n';

	for (int i=0; i<10; i++) myints2.push_back(i);
	std::cout << "1. size: " << myints2.size() << '\n';

	myints2.insert (myints2.end(),10,100);
	std::cout << "2. size: " << myints2.size() << '\n';

	myints2.pop_back();
	std::cout << "3. size: " << myints2.size() << '\n';
}

void	max_size_test(){
	ft::vector<int> myvector5;

	for (int i=0; i<100; i++) myvector5.push_back(i);

	std::cout << "size: " << myvector5.size() << "\n";
	std::cout << "capacity: " << myvector5.capacity() << "\n";
	std::cout << "max_size: " << myvector5.max_size() << "\n";
}

void	resize_test(){
	ft::vector<int> myvector;

	for (int i=1;i<10;i++) myvector.push_back(i);

	myvector.resize(5);
	myvector.resize(8,100);
	myvector.resize(12);

	std::cout << "myvector contains:";
	for (int i=0;i<(int)myvector.size();i++)
	std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

void	capacity_test(){
	ft::vector<int> myvector7;

	for (int i=0; i<100; i++) myvector7.push_back(i);

	std::cout << "size: " << (int) myvector7.size() << '\n';
	std::cout << "capacity: " << (int) myvector7.capacity() << '\n';
	std::cout << "max_size: " << (int) myvector7.max_size() << '\n';
}

void	empty_test(){
	ft::vector<int> myvector8;
	int sum (0);

	for (int i=1;i<=10;i++) myvector8.push_back(i);

	while (!myvector8.empty())
	{
		sum += myvector8.back();
		myvector8.pop_back();
	}
	std::cout << "total: " << sum << '\n';
}

void	reserve_test(){
	ft::vector<int>::size_type sz;

	ft::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i=0; i<100; ++i) {
		foo.push_back(i);
		if (sz!=foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}

	ft::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);
	std::cout << "making bar grow:\n";
	for (int i=0; i<100; ++i) {
		bar.push_back(i);
		if (sz!=bar.capacity()) {
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
}

void	operator_croche_test(){
	ft::vector<int> myvector9 (10);
	ft::vector<int>::size_type sz = myvector9.size();

	// assign some values:
	for (unsigned i=0; i<sz; i++) myvector9[i]=i;

	// reverse vector using operator[]:
	for (unsigned i=0; i<sz/2; i++)
	{
		int temp;
		temp = myvector9[sz-1-i];
		myvector9[sz-1-i]=myvector9[i];
		myvector9[i]=temp;
	}

	std::cout << "myvector9 contains:";
	for (unsigned i=0; i<sz; i++)
	std::cout << ' ' << myvector9[i];
	std::cout << '\n';
}

void	at_test(){
	ft::vector<int> myvector10 (10);

	// assign some values:
	for (unsigned i=0; i<myvector10.size(); i++)
	myvector10.at(i)=i;

	std::cout << "myvector10 contains:";
	for (unsigned i=0; i<myvector10.size(); i++)
	std::cout << ' ' << myvector10.at(i);
	std::cout << '\n';
}

void	front_test(){
	ft::vector<int> myvector11;

	myvector11.push_back(78);
	myvector11.push_back(16);

	// now front equals 78, and back 16

	myvector11.front() -= myvector11.back();

	std::cout << "myvector11.front() is now " << myvector11.front() << '\n';
}

void	back_test(){
	ft::vector<int> myvector12;

	myvector12.push_back(10);

	while (myvector12.back() != 0)
	{
		myvector12.push_back ( myvector12.back() -1 );
	}

	std::cout << "myvector12 contains:";
	for (unsigned i=0; i<myvector12.size() ; i++)
		std::cout << ' ' << myvector12[i];
	std::cout << '\n';
}

void	assign_test(){
	ft::vector<int> first;
	ft::vector<int> second;
	ft::vector<int> third;

	first.assign (7,100);

	ft::vector<int>::iterator it;
	it=first.begin()+1;

	second.assign (it,first.end()-1);

	int myint2s[] = {1776,7,4};
	third.assign (myint2s,myint2s+3);

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
	std::cout << "Size of third: " << int (third.size()) << '\n';
}

void	push_back_test(){
	ft::vector<int> myvector13;
	int myint;

	std::cout << "Please enter some integers (enter 0 to end):\n";

	do {
		std::cin >> myint;
		if (!myint)
			break;
		myvector13.push_back (myint);
	} while (myint);

	std::cout << "myvector13 stores " << int(myvector13.size()) << " numbers.\n";
}

void	pop_back_test(){
	ft::vector<int> myvector14;
	int sum (0);

	myvector14.push_back (100);
	myvector14.push_back (200);
	myvector14.push_back (300);
	while (!myvector14.empty())
	{
		sum+=myvector14.back();
		myvector14.pop_back();
	}
	std::cout << "The elements of myvector14 add up to " << sum << '\n';
}

void	insert_test(){
	ft::vector<int> myvector15 (3,100);
	ft::vector<int>::iterator it;

	it = myvector15.begin();
	it = myvector15.insert ( it , 200 );

	myvector15.insert (it,2,300);

	// "it" no longer valid, get a new one:
	it = myvector15.begin();

	ft::vector<int> anothervector (2,400);
	myvector15.insert (it+2,anothervector.begin(),anothervector.end());

	int myarray [] = { 501,502,503 };
	myvector15.insert (myvector15.begin(), myarray, myarray+3);

	std::cout << "myvector15 contains:";
	for (it=myvector15.begin(); it<myvector15.end(); it++)
	std::cout << ' ' << *it;
	std::cout << '\n';
}

void	erase_test(){
	ft::vector<int> myvector16;

	// set some values (from 1 to 10)
	for (int i=1; i<=10; i++) myvector16.push_back(i);

	// erase the 6th element
	myvector16.erase (myvector16.begin()+5);

	// erase the first 3 elements:
	myvector16.erase (myvector16.begin(),myvector16.begin()+3);

	std::cout << "myvector16 contains:";
	for (unsigned i=0; i<myvector16.size(); ++i)
	std::cout << ' ' << myvector16[i];
	std::cout << '\n';
}

void	swap_test(){
	ft::vector<int> foo (3,100);   // three ints with a value of 100
	ft::vector<int> bar (5,200);   // five ints with a value of 200

	foo.swap(bar);

	std::cout << "foo contains:";
	for (unsigned i=0; i<foo.size(); i++)
	std::cout << ' ' << foo[i];
	std::cout << '\n';

	std::cout << "bar contains:";
	for (unsigned i=0; i<bar.size(); i++)
	std::cout << ' ' << bar[i];
	std::cout << '\n';
}

void	clear_test(){
	ft::vector<int> myvector17;
	myvector17.push_back (100);
	myvector17.push_back (200);
	myvector17.push_back (300);

	std::cout << "myvector17 contains:";
	for (unsigned i=0; i<myvector17.size(); i++)
	std::cout << ' ' << myvector17[i];
	std::cout << '\n';

	myvector17.clear();
	myvector17.push_back (1101);
	myvector17.push_back (2202);

	std::cout << "myvector17 contains:";
	for (unsigned i=0; i<myvector17.size(); i++)
	std::cout << ' ' << myvector17[i];
	std::cout << '\n';
}

void	get_allocator_test(){
	ft::vector<int> myvector;
	int * p;
	unsigned int i;

	// allocate an array with space for 5 elements using vector's allocator:
	p = myvector.get_allocator().allocate(5);

	// construct values in-place on the array:
	for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

	std::cout << "The allocated array contains:";
	for (i=0; i<5; i++) std::cout << ' ' << p[i];
	std::cout << '\n';

	// destroy and deallocate:
	for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
	myvector.get_allocator().deallocate(p,5);
}

void	relational_operators_test(){
	ft::vector<int> foo (3,100);
	ft::vector<int> bar (2,200);

	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
}

int main ()
{
	std::cout << "Constructor vector" << std::endl;
	constructor_test();
	std::cout << "##################" << std::endl;
	std::cout << "operator = vector" << std::endl;
	operator_egal_test();
	std::cout << "##################" << std::endl;
	std::cout << "end vector" << std::endl;
	end_test();
	std::cout << "##################" << std::endl;
	std::cout << "rbegin vector" << std::endl;
	rbegin_test();
	std::cout << "##################" << std::endl;
	std::cout << "rend vector" << std::endl;
	rend_test();
	std::cout << "##################" << std::endl;
	std::cout << "size vector" << std::endl;
	size_test();
	std::cout << "##################" << std::endl;
	std::cout << "maxsize vector" << std::endl;
	max_size_test();
	std::cout << "##################" << std::endl;
	std::cout << "resize vector" << std::endl;
	resize_test();
	std::cout << "##################" << std::endl;
	std::cout << "capacity vector" << std::endl;
	capacity_test();
	std::cout << "##################" << std::endl;
	std::cout << "empty vector" << std::endl;
	empty_test();
	std::cout << "##################" << std::endl;
	std::cout << "reserve vector" << std::endl;
	reserve_test();
	std::cout << "##################" << std::endl;
	std::cout << "operator[] vector" << std::endl;
	operator_croche_test();
	std::cout << "##################" << std::endl;
	std::cout << "at vector" << std::endl;
	at_test();
	std::cout << "##################" << std::endl;
	std::cout << "front vector" << std::endl;
	front_test();
	std::cout << "##################" << std::endl;
	std::cout << "back vector" << std::endl;
	back_test();
	std::cout << "##################" << std::endl;
	std::cout << "assign vector" << std::endl;
	assign_test();
	std::cout << "##################" << std::endl;
	std::cout << "push_back vector" << std::endl;
	push_back_test();
	std::cout << "##################" << std::endl;
	std::cout << "pop_back vector" << std::endl;
	pop_back_test();
	std::cout << "##################" << std::endl;
	std::cout << "insert vector" << std::endl;
	insert_test();
	std::cout << "##################" << std::endl;
	std::cout << "erase vector" << std::endl;
	erase_test();
	std::cout << "##################" << std::endl;
	std::cout << "swap vector" << std::endl;
	swap_test();
	std::cout << "##################" << std::endl;
	std::cout << "clear vector" << std::endl;
	clear_test();
	std::cout << "##################" << std::endl;
	std::cout << "get_allocator vector" << std::endl;
	get_allocator_test();
	std::cout << "##################" << std::endl;
	std::cout << "relational operators vector" << std::endl;
	relational_operators_test();
	std::cout << "##################" << std::endl;
	return 0;
}