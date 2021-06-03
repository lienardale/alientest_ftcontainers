/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_main_stl.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alienard@student.42.fr <alienard>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 20:30:46 by alienard          #+#    #+#             */
/*   Updated: 2021/05/21 13:43:12 by alienard@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iterator>
#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <cctype>
#include <iomanip>

void	ft_swap_2(){
	//   unsigned int i;
  std::vector<int> foo (3,100);   // three ints with a value of 100
  std::vector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (std::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "bar contains:";
  for (std::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

void	ft_relationnal_op(){
	 std::vector<int> foo (3,100);   // three ints with a value of 100
  std::vector<int> bar (2,200);   // two ints with a value of 200

  if (foo==bar) std::cout << "foo and bar are equal\n";
  if (foo!=bar) std::cout << "foo and bar are not equal\n";
  if (foo< bar) std::cout << "foo is less than bar\n";
  if (foo> bar) std::cout << "foo is greater than bar\n";
  if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
  if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
}

void	ft_clear(){
	  std::vector<int> myvector;
  myvector.push_back (100);
  myvector.push_back (200);
  myvector.push_back (300);

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

  myvector.clear();
  myvector.push_back (1101);
  myvector.push_back (2202);

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
}

void	ft_swap(){
	  std::vector<int> foo (3,100);   // three ints with a value of 100
  std::vector<int> bar (5,200);   // five ints with a value of 200

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

void	ft_erase(){
	std::vector<int> myvector;

  // set some values (from 1 to 10)
  for (int i=1; i<=10; i++) myvector.push_back(i);

  // erase the 6th element
  myvector.erase (myvector.begin()+5);

  // erase the first 3 elements:
  myvector.erase (myvector.begin(),myvector.begin()+3);

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); ++i)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
}

void	ft_insert(){
	  std::vector<int> myvector (3,100);
  std::vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert ( it , 200 );

  myvector.insert (it,2,300);

  // "it" no longer valid, get a new one:
  it = myvector.begin();

  std::vector<int> anothervector (2,400);
  myvector.insert (it+2,anothervector.begin(),anothervector.end());

  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

void	ft_pop_back(){
	  std::vector<int> myvector;
  int sum (0);
  myvector.push_back (100);
  myvector.push_back (200);
  myvector.push_back (300);

  while (!myvector.empty())
  {
    sum+=myvector.back();
    myvector.pop_back();
  }

  std::cout << "The elements of myvector add up to " << sum << '\n';
}

void	ft_push_back(){
	std::vector<int> myvector;
	for(int myint = 0; myint < 100 ; myint++){
    	myvector.push_back (myint);
	}

  std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
}

void	ft_assign(){
	  std::vector<int> first;
  std::vector<int> second;
  std::vector<int> third;

  first.assign (7,100);             // 7 ints with a value of 100

  std::vector<int>::iterator it;
  it=first.begin()+1;

  second.assign (it,first.end()-1); // the 5 central values of first

  int myints[] = {1776,7,4};
  third.assign (myints,myints+3);   // assigning from array.

  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
  std::cout << "Size of third: " << int (third.size()) << '\n';
}

void	ft_back(){
	 std::vector<int> myvector;

  myvector.push_back(10);

  while (myvector.back() != 0)
  {
    myvector.push_back ( myvector.back() -1 );
  }

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size() ; i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
}

void	ft_front(){
	std::vector<int> myvector;

  myvector.push_back(78);
  myvector.push_back(16);

  // now front equals 78, and back 16

  myvector.front() -= myvector.back();

  std::cout << "myvector.front() is now " << myvector.front() << '\n';
}

void	ft_at(){
	  std::vector<int> myvector (10);   // 10 zero-initialized ints

  // assign some values:
  for (unsigned i=0; i<myvector.size(); i++)
    myvector.at(i)=i;

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    std::cout << ' ' << myvector.at(i);
  std::cout << '\n';
  	try {
		std::cout << "one" << std::endl;
		myvector.at(10) = 42;
	}
	catch (std::out_of_range &e) {
		// std::cout << "two" << std::endl;
		std::cout << "Catch out_of_range exception! " << std::endl;
	}
}

void	ft_operator_brackets(){
	 std::vector<int> myvector (10);   // 10 zero-initialized elements

  std::vector<int>::size_type sz = myvector.size();

  // assign some values:
  for (unsigned i=0; i<sz; i++) myvector[i]=i;

  // reverse vector using operator[]:
  for (unsigned i=0; i<sz/2; i++)
  {
    int temp;
    temp = myvector[sz-1-i];
    myvector[sz-1-i]=myvector[i];
    myvector[i]=temp;
  }

  std::cout << "myvector contains:";
  for (unsigned i=0; i<sz; i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
}

void	ft_reserve(){
	std::cout<< "testing reserve" <<std::endl;
	  std::vector<int>::size_type sz;

  std::vector<int> foo;
  sz = foo.capacity();
  std::cout << "making foo grow:\n";
  std::cout<< "size : "<< foo.size()<< " | capacity : "<< foo.capacity() <<std::endl;
  for (int i=0; i<100; ++i) {
    foo.push_back(i);
    if (sz!=foo.capacity()) {
      sz = foo.capacity();
      std::cout << "capacity changed: " << sz << '\n';
    }
  }
  std::cout<< "size : "<< foo.size()<< " | capacity : "<< foo.capacity() <<std::endl;

  std::vector<int> bar;
  sz = bar.capacity();
  std::cout<< "size : "<< bar.size()<< " | capacity : "<< bar.capacity() <<std::endl;
  bar.reserve(100);   // this is the only difference with foo above
  std::cout<< "size : "<< bar.size()<< " | capacity : "<< bar.capacity() <<std::endl;
  std::cout << "making bar grow:\n";
  for (int i=0; i<100; ++i) {
    bar.push_back(i);
    if (sz!=bar.capacity()) {
      sz = bar.capacity();
      std::cout << "capacity changed: " << sz << '\n';
	  std::cout<< "size : "<< bar.size()<< " | capacity : "<< bar.capacity() <<std::endl;
    }
  }
  std::cout<< "size : "<< bar.size()<< " | capacity : "<< bar.capacity() <<std::endl;
      std::cout << '\n';
}

void	ft_empty(){
		std::cout<< "testing empty" <<std::endl;
	 std::vector<int> myvector;
  int sum (0);

  for (int i=1;i<=10;i++) myvector.push_back(i);
std::cout<< "size : "<< myvector.size()<< " | capacity : "<< myvector.capacity() <<std::endl;
  while (!myvector.empty())
  {
     sum += myvector.back();
     myvector.pop_back();
	 std::cout<< "size : "<< myvector.size()<< " | capacity : "<< myvector.capacity() <<std::endl;
  }
std::cout<< "size : "<< myvector.size()<< " | capacity : "<< myvector.capacity() <<std::endl;
  std::cout << "total: " << sum << '\n';
    std::cout << '\n';
}

void	ft_capacity(){
		std::cout<< "testing capacity" <<std::endl;
	  std::vector<int> myvector;

  // set some content in the vector:
  for (int i=0; i<100; i++) myvector.push_back(i);

  std::cout << "size: " << (int) myvector.size() << '\n';
  std::cout << "capacity: " << (int) myvector.capacity() << '\n';
  std::cout << "max_size: " << (int) myvector.max_size() << '\n';
    std::cout << '\n';
}

void	ft_resize(){
	std::cout<< "testing resize" <<std::endl;
	 std::vector<int> myvector;

  // set some initial content:
  for (int i=1;i<10;i++) myvector.push_back(i);
std::cout<< "size : "<< myvector.size()<< " | capacity : "<< myvector.capacity() <<std::endl;
  myvector.resize(5);
  std::cout<< "size : "<< myvector.size()<< " | capacity : "<< myvector.capacity() <<std::endl;
  myvector.resize(8,100);
  myvector.resize(12);
  std::cout<< "size : "<< myvector.size()<< " | capacity : "<< myvector.capacity() <<std::endl;

  std::cout << "myvector contains:";
  for (size_t i=0;i<myvector.size();i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
  std::cout << '\n';
}

void	ft_maxsize(){
	  std::vector<int> myvector;

  // set some content in the vector:
  for (int i=0; i<100; i++) myvector.push_back(i);

  std::cout << "size: " << myvector.size() << "\n";
  std::cout << "capacity: " << myvector.capacity() << "\n";
  std::cout << "max_size: " << myvector.max_size() << "\n";
}

void	ft_size(){
	 std::vector<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';

  for (int i=0; i<10; i++) myints.push_back(i);
  std::cout << "1. size: " << myints.size() << '\n';

  myints.insert (myints.end(),10,100);
  std::cout << "2. size: " << myints.size() << '\n';

  myints.pop_back();
  std::cout << "3. size: " << myints.size() << '\n';
}

void	ft_rend(){
	 std::vector<int> myvector (5);  // 5 default-constructed ints

  std::vector<int>::reverse_iterator rit = myvector.rbegin();

  int i=0;
  for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
    *rit = ++i;

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

void	ft_rbegin(){
	  std::vector<int> myvector (5);  // 5 default-constructed ints

  int i=0;

  std::vector<int>::reverse_iterator rit = myvector.rbegin();
  for (; rit!= myvector.rend(); ++rit)
    *rit = ++i;

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

void	ft_end(){
	  std::vector<int> myvector;
  for (int i=1; i<=5; i++) myvector.push_back(i);

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

void	ft_begin(){
	std::vector<int> myvector;
  for (int i=1; i<=5; i++) myvector.push_back(i);

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

void	ft_equal_op(){
	  std::vector<int> foo (3,0);
  std::vector<int> bar (5,0);

  bar = foo;
  foo = std::vector<int>();

  std::cout << "Size of foo: " << int(foo.size()) << '\n';
  std::cout << "Size of bar: " << int(bar.size()) << '\n';
}

void	ft_construct(){
	  std::vector<int> first;                                // empty vector of ints
	    std::cout << "The contents of first are:";
  for (std::vector<int>::iterator it = first.begin(); it != first.end(); ++it)
    std::cout << ' ' << *it;
	  std::cout << '\n';
  std::cout<< "size : "<< first.size()<< " | capacity : "<< first.capacity() <<std::endl;
std::cout << '\n';

  std::vector<int> second (4,100);                       // four ints with value 100
    std::cout << "The contents of second are:";
  for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
    std::cout << ' ' << *it;
	  std::cout << '\n';
	    std::cout<< "size : "<< second.size()<< " | capacity : "<< second.capacity() <<std::endl;
std::cout << '\n';

  std::vector<int> third(second.begin(),second.end());  // iterating through second
    std::cout << "The contents of third are:";
    for (std::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
    std::cout << ' ' << *it;
	  std::cout << '\n';
	  std::cout<< "size : "<< third.size()<< " | capacity : "<< third.capacity() <<std::endl;
std::cout << '\n';

  std::vector<int> fourth (third);                       // a copy of third
    std::cout << "The contents of fourth are:";
  for (std::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
std::cout<< "size : "<< fourth.size()<< " | capacity : "<< fourth.capacity() <<std::endl;
  std::cout << '\n';

  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29, 42};
  std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
  std::cout << "The contents of fifth are:";
  for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  std::cout<< "size : "<< fifth.size()<< " | capacity : "<< fifth.capacity() <<std::endl;
  std::cout << '\n';

fifth.push_back(12);
fifth.push_back(2645);
  std::cout << "The contents of fifth are:";
  for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  std::cout<< "size : "<< fifth.size()<< " | capacity : "<< fifth.capacity() <<std::endl;
  std::cout << '\n';

    int myints2[] = {16,2,77,29, 42,21,84,128,512};
  std::vector<int> sixth (myints2, myints2 + sizeof(myints2) / sizeof(int) );
  std::cout << "The contents of sixth are:";
  for (std::vector<int>::iterator it = sixth.begin(); it != sixth.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  std::cout<< "size : "<< sixth.size()<< " | capacity : "<< sixth.capacity() <<std::endl;
  std::cout << '\n';

sixth.push_back(12);
sixth.push_back(2645);
  std::cout << "The contents of sixth are:";
  for (std::vector<int>::iterator it = sixth.begin(); it != sixth.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  std::cout<< "size : "<< sixth.size()<< " | capacity : "<< sixth.capacity() <<std::endl;
  std::cout << '\n';


      int myints3[] = {16,2,77,29, 42,21,84,128,512,1000,1212};
  std::vector<int> seven (myints3, myints3 + sizeof(myints3) / sizeof(int) );
  std::cout << "The contents of seven are:";
  for (std::vector<int>::iterator it = seven.begin(); it != seven.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  std::cout<< "size : "<< seven.size()<< " | capacity : "<< seven.capacity() <<std::endl;
  std::cout << '\n';

seven.push_back(12);
seven.push_back(2645);
  std::cout << "The contents of seven are:";
  for (std::vector<int>::iterator it = seven.begin(); it != seven.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  std::cout<< "size : "<< seven.size()<< " | capacity : "<< seven.capacity() <<std::endl;
  std::cout << '\n';

        int myints4[] = {16};
  std::vector<int> eight (myints4, myints4 + sizeof(myints4) / sizeof(int) );
  std::cout << "The contents of eight are:";
  for (std::vector<int>::iterator it = eight.begin(); it != eight.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  std::cout<< "size : "<< eight.size()<< " | capacity : "<< eight.capacity() <<std::endl;
  std::cout << '\n';

eight.push_back(12);
  std::cout << "The contents of eight are:";
  for (std::vector<int>::iterator it = eight.begin(); it != eight.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  std::cout<< "size : "<< eight.size()<< " | capacity : "<< eight.capacity() <<std::endl;
  std::cout << '\n';
eight.push_back(2645);
  std::cout << "The contents of eight are:";
  for (std::vector<int>::iterator it = eight.begin(); it != eight.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  std::cout<< "size : "<< eight.size()<< " | capacity : "<< eight.capacity() <<std::endl;
  std::cout << '\n';

///

  std::vector<int> nine;
  std::cout << "The contents of nine are:";
  for (std::vector<int>::iterator it = nine.begin(); it != nine.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  std::cout<< "size : "<< nine.size()<< " | capacity : "<< nine.capacity() <<std::endl;
  std::cout << '\n';

nine.push_back(12);
  std::cout << "The contents of nine are:";
  for (std::vector<int>::iterator it = nine.begin(); it != nine.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  std::cout<< "size : "<< nine.size()<< " | capacity : "<< nine.capacity() <<std::endl;
  std::cout << '\n';
nine.push_back(2645);
  std::cout << "The contents of nine are:";
  for (std::vector<int>::iterator it = nine.begin(); it != nine.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  std::cout<< "size : "<< nine.size()<< " | capacity : "<< nine.capacity() <<std::endl;
  std::cout << '\n';

        int myints5[] = {16, 13, 15};
  std::vector<int> ten (myints5, myints5 + sizeof(myints5) / sizeof(int) );
    std::cout << "The contents of ten are:";
  for (std::vector<int>::iterator it = ten.begin(); it != ten.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  std::cout<< "size : "<< ten.size()<< " | capacity : "<< ten.capacity() <<std::endl;
  std::cout << '\n';
  ten.push_back(2645);
    for (std::vector<int>::iterator it = ten.begin(); it != ten.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  std::cout<< "size : "<< ten.size()<< " | capacity : "<< ten.capacity() <<std::endl;
  std::cout << '\n';
  ten.reserve(3);
      for (std::vector<int>::iterator it = ten.begin(); it != ten.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  std::cout<< "size : "<< ten.size()<< " | capacity : "<< ten.capacity() <<std::endl;
  std::cout << '\n';
  ten.resize(3);
        for (std::vector<int>::iterator it = ten.begin(); it != ten.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  std::cout<< "size : "<< ten.size()<< " | capacity : "<< ten.capacity() <<std::endl;
  std::cout << '\n';
  
}

int	main(void){
	ft_construct();
	ft_equal_op();
		ft_begin ();
		ft_end();
	ft_rbegin();
	ft_rend();
	ft_size();
	ft_maxsize();
		ft_resize();
		ft_capacity();
		ft_empty();
		ft_reserve();
	ft_operator_brackets();
	ft_at();
	ft_front();
	ft_back();
	ft_assign();
	ft_push_back();
	ft_pop_back();
	ft_insert();
	ft_erase();
	ft_swap();
	ft_relationnal_op();
	ft_swap_2();
	return 0;
}
