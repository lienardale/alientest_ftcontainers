/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alienard <alienard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:26:20 by alienard          #+#    #+#             */
/*   Updated: 2021/05/21 11:21:16 by alienard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Queue/Queue.hpp"

#include <iostream>       // std::cout
#include <../List/List.hpp>           // ft::list
#include "../Queue/Queue.hpp"          // ft::queue

void	ft_rel_op(){
	ft::list<int> mylist (3,100);        // list with 3 elements
		 ft::queue<int> foo (mylist);   // three ints with a value of 100
		 ft::list<int> mylist2 (20,2);        // list with 3 elements
  ft::queue<int> bar (mylist2);   // two ints with a value of 200

  if (foo==bar) std::cout << "foo and bar are equal\n";
  if (foo!=bar) std::cout << "foo and bar are not equal\n";
  if (foo< bar) std::cout << "foo is less than bar\n";
  if (foo> bar) std::cout << "foo is greater than bar\n";
  if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
  if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
}

void	ft_pop(){
	  ft::queue<int> myqueue;

	for(int myint = 0; myint < 100 ; myint++){
    	myqueue.push (myint);
	}
	
  std::cout << "myqueue contains: ";
  while (!myqueue.empty())
  {
    std::cout << ' ' << myqueue.front();
    myqueue.pop();
  }
  std::cout << '\n';
}

void	ft_push(){
	  ft::queue<int> myqueue;

	for(int myint = 0; myint < 100 ; myint++){
    	myqueue.push (myint);
	}

  std::cout << "myqueue contains: ";
  while (!myqueue.empty())
  {
    std::cout << ' ' << myqueue.front();
    myqueue.pop();
  }
  std::cout << '\n';
}

void	ft_back(){
	  ft::queue<int> myqueue;

  myqueue.push(12);
  myqueue.push(75);   // this is now the back

  myqueue.back() -= myqueue.front();

  std::cout << "myqueue.back() is now " << myqueue.back() << '\n';
}

void	ft_front(){
	  ft::queue<int> myqueue;

  myqueue.push(77);
  myqueue.push(16);

  myqueue.front() -= myqueue.back();    // 77-16=61

  std::cout << "myqueue.front() is now " << myqueue.front() << '\n';
}

void	ft_size(){
	  ft::queue<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';

  for (int i=0; i<5; i++) myints.push(i);
  std::cout << "1. size: " << myints.size() << '\n';

  myints.pop();
  std::cout << "2. size: " << myints.size() << '\n';
}

void	ft_empty(){
	ft::queue<int> myqueue;
  int sum (0);

  for (int i=1;i<=10;i++) myqueue.push(i);

  while (!myqueue.empty())
  {
     sum += myqueue.front();
     myqueue.pop();
  }

  std::cout << "total: " << sum << '\n';
}

void	ft_construct(){
  ft::list<int> mylist (2,200);         // list with 2 elements
  ft::list<int> mylist2 (3,100);        // deque with 3 elements

  ft::queue<int> first;                 // empty queue
  ft::queue<int> second (mylist2);       // queue initialized to copy of deque

  ft::queue<int,ft::list<int> > third; // empty queue with list as underlying container
  ft::queue<int,ft::list<int> > fourth (mylist);

  std::cout << "size of first: " << first.size() << '\n';
  std::cout << "size of second: " << second.size() << '\n';
  std::cout << "size of third: " << third.size() << '\n';
  std::cout << "size of fourth: " << fourth.size() << '\n';
}

int	main(void){
	ft_construct();
	ft_empty();
	ft_size();
	ft_front();
	ft_back();
	ft_push();
	ft_pop();
	ft_rel_op();
	return 0;
}
