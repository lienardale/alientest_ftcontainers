/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alienard@student.42.fr <alienard>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 11:59:27 by alienard          #+#    #+#             */
/*   Updated: 2021/05/21 13:37:21 by alienard@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <vector>
#include <cmath>
#include <cctype>
#include "../List/List.hpp"
#include "../algorithm.hpp"
#include "../iterator_traits.hpp"

void	ft_comparison(){
	  ft::list<int> a;
  ft::list<int> b;
  ft::list<int> c;

  a.push_back(10);
  a.push_back(20);
  a.push_back(30);
  b.push_back(10);
  b.push_back(20);
  b.push_back(30);
    c.push_back(30);
  c.push_back(20);
  c.push_back(10);

  if (a==b) std::cout << "a and b are equal\n";
  if (b!=c) std::cout << "b and c are not equal\n";
  if (b<c) std::cout << "b is less than c\n";
  if (c>b) std::cout << "c is greater than b\n";
  if (a<=b) std::cout << "a is less than or equal to b\n";
  if (a>=b) std::cout << "a is greater than or equal to b\n";
  
}

void	ft_rbegin_rend(){
  ft::list<int> mylist;
  for (int i=1; i<=5; ++i) mylist.push_back(i);

  std::cout << "mylist backwards:";
  for (ft::list<int>::reverse_iterator rit=mylist.rbegin(); rit!=mylist.rend(); ++rit)
    std::cout << ' ' << *rit;

  std::cout << '\n';
}

void	ft_reverse(){
		std::cout << "Reverse test." << std::endl;
	  ft::list<int> mylist;

  for (int i=1; i<10; ++i) mylist.push_back(i);

  mylist.reverse();

  std::cout << "mylist contains:";
  for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';

}

bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

void ft_merge()
{
	std::cout << "Merge test." << std::endl;
  ft::list<double> first, second;

  first.push_back (3.1);
  first.push_back (2.2);
  first.push_back (2.9);

  second.push_back (3.7);
  second.push_back (7.1);
  second.push_back (1.4);

  first.sort();
  second.sort();

  first.merge(second);

  // (second is now empty)

  second.push_back (2.1);

  first.merge(second,mycomparison);

  std::cout << "first contains:";
  for (ft::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}



// comparison, not case sensitive.
bool compare_nocase (const std::string& first, const std::string& second)
{
  unsigned int i=0;
  while ( (i<first.length()) && (i<second.length()) )
  {
    if (tolower(first[i])<tolower(second[i])) return true;
    else if (tolower(first[i])>tolower(second[i])) return false;
    ++i;
  }
  return ( first.length() < second.length() );
}

void	ft_sort ()
{
	std::cout << "Sort test." << std::endl;
  ft::list<std::string> mylist;
  ft::list<std::string>::iterator it;
  mylist.push_back ("one");
  mylist.push_back ("two");
  mylist.push_back ("Three");

  mylist.sort();

  std::cout << "mylist contains:";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  mylist.sort(compare_nocase);

  std::cout << "mylist contains:";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
  bool operator() (double first, double second)
  { return (fabs(first-second)<5.0); }
};

void ft_unique ()
{
	std::cout << "Unique test." << std::endl;
  double mydoubles[]={ 12.15,  2.72, 73.0,  12.77,  3.14,
                       12.77, 73.35, 72.25, 15.3,  72.25 };
  ft::list<double> mylist (mydoubles,mydoubles+10);

  mylist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
                             // 15.3,  72.25, 72.25, 73.0,  73.35

  mylist.unique();           //  2.72,  3.14, 12.15, 12.77
                             // 15.3,  72.25, 73.0,  73.35

  mylist.unique (same_integral_part);  //  2.72,  3.14, 12.15
                                       // 15.3,  72.25, 73.0

  mylist.unique (is_near());           //  2.72, 12.15, 72.25

  std::cout << "mylist contains:";
  for (ft::list<double>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

void	ft_remove(){
	std::cout << "Remove test." << std::endl;
	  int myints[]= {17,89,7,14};
  ft::list<int> mylist (myints,myints+4);

  mylist.remove(89);

  std::cout << "mylist contains:";
  for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

void	ft_splice(){
	std::cout << "Splice test." << std::endl;
	 ft::list<int> mylist1, mylist2;
  ft::list<int>::iterator it;

  // set some initial values:
  for (int i=1; i<=4; ++i)
     mylist1.push_back(i);      // mylist1: 1 2 3 4

  for (int i=1; i<=3; ++i)
     mylist2.push_back(i*10);   // mylist2: 10 20 30

  it = mylist1.begin();
  ++it;                         // points to 2

  mylist1.splice(it, mylist2); // mylist1: 1 10 20 30 2 3 4
                                // mylist2 (empty)
                                // "it" still points to 2 (the 5th element)

  std::cout << "after 1 mylist1 contains:";
  for (ft::list<int>::iterator  it2=mylist1.begin(); it2!=mylist1.end(); ++it2)
    std::cout << ' ' << *it2;
  std::cout << '\n';

  std::cout << "after 1 mylist2 contains:";
  for (ft::list<int>::iterator  it2=mylist2.begin(); it2!=mylist2.end(); ++it2)
    std::cout << ' ' << *it2;
  std::cout << '\n';

  mylist2.splice(mylist2.begin(),mylist1, it);
                                // mylist1: 1 10 20 30 3 4
                                // mylist2: 2
                                // "it" is now invalid.

  std::cout << "after 2 mylist1 contains:";
  for (ft::list<int>::iterator  it2=mylist1.begin(); it2!=mylist1.end(); ++it2)
    std::cout << ' ' << *it2;
  std::cout << '\n';

  std::cout << "after 2 mylist2 contains:";
  for (ft::list<int>::iterator  it2=mylist2.begin(); it2!=mylist2.end(); ++it2)
    std::cout << ' ' << *it2;
  std::cout << '\n';


  it = mylist1.begin();
  ft::advance(it,3);           // "it" points now to 30

  mylist1.splice( mylist1.begin(), mylist1, it, mylist1.end());
                                // mylist1: 30 3 4 1 10 20

  std::cout << "mylist1 contains:";
  for (it=mylist1.begin(); it!=mylist1.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "mylist2 contains:";
  for (it=mylist2.begin(); it!=mylist2.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

void	ft_resize(){
	std::cout << "Resize test." << std::endl;
	  ft::list<int> mylist;

  // set some initial content:
  for (int i=1; i<10; ++i) mylist.push_back(i);
  std::cout << "mylist contains:";
  for (ft::list<int>::iterator  it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
	  std::cout << '\n';
  mylist.resize(5);
    std::cout << "mylist contains:";
  for (ft::list<int>::iterator  it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
	  std::cout << '\n';
  mylist.resize(8,100);
    std::cout << "mylist contains:";
  for (ft::list<int>::iterator  it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
	  std::cout << '\n';
  mylist.resize(12);

  std::cout << "mylist contains:";
  for (ft::list<int>::iterator  it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';
}

void	ft_swap(){
	std::cout << "Swap test." << std::endl;
	  ft::list<int> first (3,100);   // three ints with a value of 100
  ft::list<int> second (5,200);  // five ints with a value of 200

  first.swap(second);

  std::cout << "first contains:";
  for (ft::list<int>::iterator it=first.begin(); it!=first.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "second contains:";
  for (ft::list<int>::iterator it=second.begin(); it!=second.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

void	ft_erase(){
	std::cout << "Erase test." << std::endl;
	  ft::list<int> mylist;
  ft::list<int>::iterator it1,it2;

  // set some values:
  for (int i=1; i<10; ++i) mylist.push_back(i*10);

                              		// 10 20 30 40 50 60 70 80 90
  it1 = it2 = mylist.begin(); 		// ^^
	ft::advance (it2,6);            // ^                 ^
  ++it1;                      		//    ^              ^

  it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90
                              //    ^           ^

  it2 = mylist.erase (it2);   // 10 30 40 50 60 80 90
                              //    ^           ^

  ++it1;                      //       ^        ^
  --it2;                      //       ^     ^

  mylist.erase (it1,it2);     // 10 30 60 80 90
                              //        ^

  std::cout << "mylist contains:";
  for (it1=mylist.begin(); it1!=mylist.end(); ++it1)
    std::cout << ' ' << *it1;
  std::cout << '\n';
}

void	ft_insert(){
	std::cout << "Insert test." << std::endl;
	  ft::list<int> mylist;
  ft::list<int>::iterator it;

  // set some initial values:
  for (int i=1; i<=5; ++i) mylist.push_back(i); // 1 2 3 4 5

  it = mylist.begin();
  it++;       // it points now to number 2           ^

  mylist.insert (it,10);                        // 1 10 2 3 4 5

  // "it" still points to number 2                      ^
  mylist.insert (it,2,20);                      // 1 10 20 20 2 3 4 5
  it--;       // it points now to the second 20            ^


  std::cout << "mylist contains:";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

void	ft_pop_back(){
	std::cout << "Pop_back test." << std::endl;
	  ft::list<int> mylist;
  int sum (0);
  mylist.push_back (100);
  mylist.push_back (200);
  mylist.push_back (300);

  while (!mylist.empty())
  {
    sum+=mylist.back();
    mylist.pop_back();
  }

  std::cout << "The elements of mylist summed " << sum << '\n';
}

void	ft_pop_front(){
	std::cout << "Pop_front test." << std::endl;
	ft::list<int> mylist;
  mylist.push_back (100);
  mylist.push_back (200);
  mylist.push_back (300);

  std::cout << "Popping out the elements in mylist:";
  while (!mylist.empty())
  {
    std::cout << ' ' << mylist.front();
    mylist.pop_front();
  }

  std::cout << "\nFinal size of mylist is " << mylist.size() << '\n';
}

void ft_push_front(){
	std::cout << "Push_front test." << std::endl;
  ft::list<int> mylist (2,100);         // two ints with a value of 100
  mylist.push_front (200);
  mylist.push_front (300);

  std::cout << "mylist contains:";
  for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';
}

void ft_front(){
	std::cout << "Front test." << std::endl;
	ft::list<int> mylist;

  mylist.push_back(77);
  mylist.push_back(22);

  // now front equals 77, and back 22

  mylist.front() -= mylist.back();

  std::cout << "mylist.front() is now " << mylist.front() << '\n';
}

void	ft_back(){
	std::cout << "Back test." << std::endl;
	ft::list<int> mylist;

  mylist.push_back(10);

  while (mylist.back() != 0)
  {
    mylist.push_back ( mylist.back() -1 );
  }

  std::cout << "mylist contains:";
  for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end() ; ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';
}

void	ft_assign(){
	std::cout << "Assign test." << std::endl;
	 ft::list<int> first;
  ft::list<int> second;

  first.assign (7,100);                      // 7 ints with value 100

  second.assign (first.begin(),first.end()); // a copy of first

  int myints[]={1776,7,4};
  first.assign (myints,myints+3);            // assigning from array

  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
}

void	ft_clear(){
	std::cout << "Clear test." << std::endl;
	ft::list<int> mylist;
  ft::list<int>::iterator it;

  mylist.push_back (100);
  mylist.push_back (200);
  mylist.push_back (300);

  std::cout << "mylist contains:";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  mylist.clear();
  mylist.push_back (1101);
  mylist.push_back (2202);

  std::cout << "mylist contains:";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}


template<typename T, typename I>
void	ft_create(T& tmp, I& p){
	std::cout << "Create test." << std::endl;
	std::cout << tmp.size() << std::endl;
	std::cout << tmp.empty() << std::endl;
	tmp.push_back(4);
	tmp.push_back(2);
	while (p != tmp.end()){
		std::cout << *p;
		p++;
	}
	std::cout << std::endl;

	tmp.push_back(2);
	tmp.push_back(1);
	p = tmp.begin();
	while (p != tmp.end()){
		std::cout << *p;
		p++;
	}
	std::cout << std::endl;
	while (p != tmp.begin()){
		// on decremente avant de dereferencer parce que le contenu de .end() est undefined
		p--;
		std::cout << *p;
	}
	std::cout << std::endl;
	std::cout << tmp.size() << std::endl;
	std::cout << tmp.empty() << std::endl;
	tmp.push_back(0);
	tmp.push_back(-42);
	tmp.push_back(2147483647);
	tmp.push_back(-2147483648);
	while (p != tmp.end()){
		std::cout << *p;
		p++;
	}
	std::cout << std::endl;
}

int	main(){
	std::cout << "Default constructor test." << std::endl;
	ft::list<int> tmp;
	ft::list<int>::iterator p = tmp.begin();
	ft_create(tmp, p);

	std::cout << "Fill constructor test." << std::endl;
	ft::list<int> tmp2(42,42);
	p = tmp2.begin();
	ft_create(tmp2, p);

	std::cout << "Range constructor test." << std::endl;
	ft::list<int> tmp3(tmp.begin(), tmp.end());
	p = tmp3.begin();
	ft_create(tmp3, p);
	
	std::cout << "Copy constructor test." << std::endl;
	ft::list<int> tmp4 = tmp3;
	p = tmp4.begin();
	ft_create(tmp4, p);

	ft_clear();
	ft_back();
	ft_front();
	ft_push_front();
	ft_pop_front();
	ft_pop_back();
	ft_insert();
	ft_erase();
	ft_swap();
	ft_resize();
	ft_splice();
	ft_remove();
	ft_unique();
	ft_sort();
	ft_merge();
	ft_reverse();
	ft_rbegin_rend();
	ft_comparison();
	return 0;
}