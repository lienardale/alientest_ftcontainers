/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alienard <alienard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:26:29 by alienard          #+#    #+#             */
/*   Updated: 2021/05/21 11:25:45 by alienard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Stack/Stack.hpp"
#include <iostream>       // std::cout
#include "../Vector/Vector.hpp"         // ft::vector
#include "../List/List.hpp"          // ft::list

void	ft_rel_op(){
		ft::list<int> mylist (3,100);        // deque with 3 elements
		 ft::stack<int> foo (mylist);   // three ints with a value of 100
		 ft::list<int> mylist2 (20,2);        // deque with 3 elements
  ft::stack<int> bar (mylist2);   // two ints with a value of 200

  if (foo==bar) std::cout << "foo and bar are equal\n";
  if (foo!=bar) std::cout << "foo and bar are not equal\n";
  if (foo< bar) std::cout << "foo is less than bar\n";
  if (foo> bar) std::cout << "foo is greater than bar\n";
  if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
  if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
}

void	ft_pop(){
	  ft::stack<int> mystack;

  for (int i=0; i<5; ++i) mystack.push(i);

  std::cout << "Popping out elements...";
  while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  std::cout << '\n';
}

void	ft_push(){
	 ft::stack<int> mystack;

  for (int i=0; i<5; ++i) mystack.push(i);

  std::cout << "Popping out elements...";
  while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  std::cout << '\n';
}

void	ft_top(){
	  ft::stack<int> mystack;

  mystack.push(10);
  mystack.push(20);

  mystack.top() -= 5;

  std::cout << "mystack.top() is now " << mystack.top() << '\n';
}

void	ft_size(){
	  ft::stack<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';

  for (int i=0; i<5; i++) myints.push(i);
  std::cout << "1. size: " << myints.size() << '\n';

  myints.pop();
  std::cout << "2. size: " << myints.size() << '\n';
}

void	ft_empty(){
	  ft::stack<int> mystack;
  int sum (0);

  for (int i=1;i<=10;i++) mystack.push(i);

  while (!mystack.empty())
  {
     sum += mystack.top();
     mystack.pop();
  }

  std::cout << "total: " << sum << '\n';
}

void	ft_construct(){
	 ft::list<int> mydeque (3,100);          // deque with 3 elements
  ft::vector<int> myvector (2,200);        // vector with 2 elements

  ft::stack<int> first;                    // empty stack
  ft::stack<int> second (mydeque);         // stack initialized to copy of deque

  ft::stack<int,ft::vector<int> > third;  // empty stack using vector
  ft::stack<int,ft::vector<int> > fourth (myvector);

  std::cout << "size of first: " << first.size() << '\n';
  std::cout << "size of second: " << second.size() << '\n';
  std::cout << "size of third: " << third.size() << '\n';
  std::cout << "size of fourth: " << fourth.size() << '\n';
}

int	main(void){
	ft_construct();
	ft_empty();
	ft_size();
	ft_top();
	ft_push();
	ft_pop();
	ft_rel_op();
	return 0;
}