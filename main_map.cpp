#include <iostream>
#include "map.hpp"

#ifndef NAMESPACE
# define NAMESPACE ft
#endif
// Consturctor test
bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
	bool operator() (const char& lhs, const char& rhs) const
	{return lhs<rhs;}
};

void	constructor_test()
{
	NAMESPACE::map<char,int> first;

	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;

	NAMESPACE::map<char,int> second (first.begin(),first.end());

	NAMESPACE::map<char,int> third (second);

	NAMESPACE::map<char,int,classcomp> fourth;

	bool(*fn_pt)(char,char) = fncomp;
	NAMESPACE::map<char,int,bool(*)(char,char)> fifth (fn_pt);

}

// Operator = test
void	operator_equal_test()
{
	NAMESPACE::map<char,int> first;
	NAMESPACE::map<char,int> second;

	first['x']=8;
	first['y']=16;
	first['z']=32;

	second=first;
	first=NAMESPACE::map<char,int>();

	std::cout << "Size of first: " << first.size() << '\n';
	std::cout << "Size of second: " << second.size() << '\n';
}

void	iterator_test()
{
	NAMESPACE::map<char,int>	mymap;

	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;

	std::cout << "iterator" << std::endl;
	for (NAMESPACE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "const_iterator" << std::endl;
	for (NAMESPACE::map<char,int>::const_iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "reverse_iterator" << std::endl;
	NAMESPACE::map<char,int>::reverse_iterator rit;
	for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
		std::cout << rit->first << " => " << rit->second << '\n';

	std::cout << "const_reverse_iterator" << std::endl;
	NAMESPACE::map<char,int>::const_reverse_iterator crit;
	for (crit=mymap.rbegin(); crit!=mymap.rend(); ++crit)
		std::cout << crit->first << " => " << crit->second << '\n';
}

void	capacity_test()
{
	NAMESPACE::map<char,int> mymap;

	std::cout << "Empty test :" << std::endl;
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	while (!mymap.empty())
	{
		std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
		mymap.erase(mymap.begin());
	}

	std::cout << "size test :" << std::endl;
	mymap['a']=101;
	mymap['b']=202;
	mymap['c']=302;

	std::cout << "mymap.size() is " << mymap.size() << '\n';
	std::cout << "maxsize test" << std::endl;
	std::cout << "mymap.maxsize() " << mymap.max_size() << std::endl;

}

void	operator_test()
{
	NAMESPACE::map<char,std::string> mymap;

	mymap['a']="an element";
	mymap['b']="another element";
	mymap['c']=mymap['b'];

	std::cout << "mymap['a'] is " << mymap['a'] << '\n';
	std::cout << "mymap['b'] is " << mymap['b'] << '\n';
	std::cout << "mymap['c'] is " << mymap['c'] << '\n';
	std::cout << "mymap['d'] is " << mymap['d'] << '\n';

	std::cout << "mymap now contains " << mymap.size() << " elements.\n";

}

void	insert_test()
{
	NAMESPACE::map<char,int> mymap;

	// first insert function version (single parameter):
	mymap.insert ( NAMESPACE::pair<char,int>('a',100) );
	mymap.insert ( NAMESPACE::pair<char,int>('z',200) );

	NAMESPACE::pair<NAMESPACE::map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( NAMESPACE::pair<char,int>('z',500) );
	if (ret.second==false) {
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}

	// second insert function version (with hint position):
	NAMESPACE::map<char,int>::iterator it = mymap.begin();
	mymap.insert (it, NAMESPACE::pair<char,int>('b',300));  // max efficiency inserting
	mymap.insert (it, NAMESPACE::pair<char,int>('c',400));  // no max efficiency inserting

	// third insert function version (range insertion):
	NAMESPACE::map<char,int> anothermap;
	anothermap.insert(mymap.begin(),mymap.find('c'));

	// showing contents:
	std::cout << "mymap contains:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "anothermap contains:\n";
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void	erase_test()
{
	NAMESPACE::map<char,int> mymap;
	NAMESPACE::map<char,int>::iterator it;

	// insert some values:
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	mymap['d']=40;
	mymap['e']=50;
	mymap['f']=60;

	it=mymap.find('b');
	mymap.erase (it);                   // erasing by iterator

	mymap.erase ('c');                  // erasing by key

	it=mymap.find ('e');
	mymap.erase ( it, mymap.end() );    // erasing by range

	// show content:
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void	swap_test()
{
	NAMESPACE::map<char,int> foo,bar;

	foo['x']=100;
	foo['y']=200;

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;

	foo.swap(bar);

	std::cout << "foo contains:\n";
	for (NAMESPACE::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "bar contains:\n";
	for (NAMESPACE::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

}

void	clear_test()
{
	NAMESPACE::map<char,int> mymap;

	mymap['x']=100;
	mymap['y']=200;
	mymap['z']=300;

	std::cout << "mymap contains:\n";
	for (NAMESPACE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	mymap.clear();
	mymap['a']=1101;
	mymap['b']=2202;

	std::cout << "mymap contains:\n";
	for (NAMESPACE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

}

void	comp_test()
{
	NAMESPACE::map<char,int> mymap;

	NAMESPACE::map<char,int>::key_compare mycomp = mymap.key_comp();

	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;

	std::cout << "mymap contains:\n";

	char highest = mymap.rbegin()->first;     // key value of last element

	NAMESPACE::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );

	std::cout << '\n';

	NAMESPACE::pair<char,int> highest2 = *mymap.rbegin();

	it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mymap.value_comp()(*it++, highest2) );

}

void	find_test()
{
	NAMESPACE::map<char,int> mymap;
	NAMESPACE::map<char,int>::iterator it;

	mymap['a']=50;
	mymap['b']=100;
	mymap['c']=150;
	mymap['d']=200;

	it = mymap.find('b');
	if (it != mymap.end())
		mymap.erase (it);

	// print content:
	std::cout << "elements in mymap:" << '\n';
	std::cout << "a => " << mymap.find('a')->second << '\n';
	std::cout << "c => " << mymap.find('c')->second << '\n';
	std::cout << "d => " << mymap.find('d')->second << '\n';

}

void	count_test()
{
	NAMESPACE::map<char,int> mymap;
	char c;

	mymap ['a']=101;
	mymap ['c']=202;
	mymap ['f']=303;

	for (c='a'; c<'h'; c++)
	{
		std::cout << c;
		if (mymap.count(c)>0)
		std::cout << " is an element of mymap.\n";
		else 
		std::cout << " is not an element of mymap.\n";
	}
}

void	bound_test()
{
	NAMESPACE::map<char,int> mymap;
	NAMESPACE::map<char,int>::iterator itlow,itup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;

	itlow=mymap.lower_bound ('b');  // itlow points to b
	itup=mymap.upper_bound ('d');   // itup points to e (not d!)

	mymap.erase(itlow,itup);        // erases [itlow,itup)

	// print content:
	for (NAMESPACE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void	equal_test()
{
	NAMESPACE::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	NAMESPACE::pair<NAMESPACE::map<char,int>::iterator,NAMESPACE::map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';

}

void	allocator_test()
{
	int psize;
	NAMESPACE::map<char,int> mymap;
	NAMESPACE::pair<const char,int>* p;

	// allocate an array of 5 elements using mymap's allocator:
	p=mymap.get_allocator().allocate(5);

	// assign some values to array
	psize = sizeof(NAMESPACE::map<char,int>::value_type)*5;

	std::cout << "The allocated array has a size of " << psize << " bytes.\n";

	mymap.get_allocator().deallocate(p,5);

}

int main ()
{
	std::cout << "Constructor test" << std::endl;
	constructor_test();
	std::cout << "================" << std::endl;
	std::cout << "operator_equal test" << std::endl;
	operator_equal_test();
	std::cout << "================" << std::endl;
	std::cout << "iterator test" << std::endl;
	iterator_test();
	std::cout << "================" << std::endl;
	std::cout << "capacity test" << std::endl;
	capacity_test();
	std::cout << "================" << std::endl;
	std::cout << "operator test" << std::endl;
	operator_test();
	std::cout << "================" << std::endl;
	std::cout << "insert test" << std::endl;
	insert_test();
	std::cout << "================" << std::endl;
	std::cout << "erase test" << std::endl;
	erase_test();
	std::cout << "================" << std::endl;
	std::cout << "swap test" << std::endl;
	swap_test();
	std::cout << "================" << std::endl;
	std::cout << "clear test" << std::endl;
	clear_test();
	std::cout << "================" << std::endl;
	std::cout << "comp test" << std::endl;
	comp_test();
	std::cout << "================" << std::endl;
	std::cout << "find test" << std::endl;
	find_test();
	std::cout << "================" << std::endl;
	std::cout << "count test" << std::endl;
	count_test();
	std::cout << "================" << std::endl;
	std::cout << "bound test" << std::endl;
	bound_test();
	std::cout << "================" << std::endl;
	std::cout << "equal test" << std::endl;
	equal_test();
	std::cout << "================" << std::endl;
	std::cout << "allocator test" << std::endl;
	allocator_test();
	std::cout << "================" << std::endl;
	return 0;
}