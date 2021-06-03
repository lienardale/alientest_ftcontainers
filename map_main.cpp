/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alienard@student.42.fr <alienard>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:49:31 by alienard          #+#    #+#             */
/*   Updated: 2021/05/21 13:38:24 by alienard@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <cctype>
#include "../Map/Map.hpp"
#include "../Map/Map_node.hpp"
#include "../Map/Map_iterators.hpp"
#include "../utility.hpp"
#include "../algorithm.hpp"
#include "../iterator_traits.hpp"

template<class Key,class T>
void	ft_print_map(ft::map<Key,T> *first){
	for (ft::map<char, int>::iterator it = first->begin(); it != first->end() ; it++) {
		std::cout<< "first : " << it->first << " | second : " << it->second << std::endl;
	}
	std::cout << std::endl;
}

template<class Key,class T>
void	ft_print_map(ft::map<Key,T> first){
	for (ft::map<char, int>::iterator it = first.begin(); it != first.end() ; it++) {
		std::cout<< "first : " << it->first << " | second : " << it->second << std::endl;
	}
	std::cout << std::endl;
}

template<class Key,class T,class Compare>
void	ft_print_map(ft::map<Key,T,Compare> first){
	for (ft::map<char, int>::iterator it = first.begin(); it != first.end() ; it++) {
		std::cout<< "first : " << it->first << " | second : " << it->second << std::endl;
	}
	std::cout << std::endl;
}

void	ft_relationnal_operators(){
	  ft::map<char,int> foo,bar;
  foo['a']=100;
  foo['b']=200;
  bar['a']=10;
  bar['z']=1000;

  // foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
  if (foo==bar) std::cout << "foo and bar are equal\n";
  if (foo!=bar) std::cout << "foo and bar are not equal\n";
  if (foo< bar) std::cout << "foo is less than bar\n";
  if (foo> bar) std::cout << "foo is greater than bar\n";
  if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
  if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
}

void	ft_rend(){
	 ft::map<char,int> mymap;

  mymap['x'] = 100;
  mymap['y'] = 200;
  mymap['z'] = 300;

  // show content:
  ft::map<char,int>::reverse_iterator rit;
  for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
    std::cout << rit->first << " => " << rit->second << '\n';
}

void	ft_rbegin(){
	 ft::map<char,int> mymap;

  mymap['x'] = 100;
  mymap['y'] = 200;
  mymap['z'] = 300;

  // show content:
  ft::map<char,int>::reverse_iterator rit;
  for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
    std::cout << rit->first << " => " << rit->second << '\n';
}

void	ft_operator_brackets(){
	  ft::map<char,std::string> mymap;

  mymap['a']="an element";
  mymap['b']="another element";
  mymap['c']=mymap['b'];

  std::cout << "mymap['a'] is " << mymap['a'] << '\n';
  std::cout << "mymap['b'] is " << mymap['b'] << '\n';
  std::cout << "mymap['c'] is " << mymap['c'] << '\n';
  std::cout << "mymap['d'] is " << mymap['d'] << '\n';

  std::cout << "mymap now contains " << mymap.size() << " elements.\n";
}

void	ft_upper_bound(){
	 ft::map<char,int> mymap;
  ft::map<char,int>::iterator itlow,itup;

  mymap['a']=20;
  mymap['b']=40;
  mymap['c']=60;
  mymap['d']=80;
  mymap['e']=100;

  itlow=mymap.lower_bound ('b');  // itlow points to b
  itup=mymap.upper_bound ('d');   // itup points to e (not d!)

  mymap.erase(itlow,itup);        // erases [itlow,itup)

  // print content:
  for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
}

void	ft_lower_bound(){
	 ft::map<char,int> mymap;
  ft::map<char,int>::iterator itlow,itup;

  mymap['a']=20;
  mymap['b']=40;
  mymap['c']=60;
  mymap['d']=80;
  mymap['e']=100;

  itlow=mymap.lower_bound ('b');  // itlow points to b
  itup=mymap.upper_bound ('d');   // itup points to e (not d!)
  mymap.erase(itlow,itup);        // erases [itlow,itup)

  // print content:
  for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
}

void	ft_find(){
	  ft::map<char,int> mymap;
  ft::map<char,int>::iterator it;

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

void	ft_insert(){
	  ft::map<char,int> mymap;

  // first insert function version (single parameter):

  mymap.insert ( ft::pair<char,int>('a',100) );
  mymap.insert ( ft::pair<char,int>('z',200) );

  ft::pair<ft::map<char,int>::iterator,bool> ret;
  ret = mymap.insert ( ft::pair<char,int>('z',500) );
  if (ret.second==false) {
    std::cout << "element 'z' already existed";
    std::cout << " with a value of " << ret.first->second << '\n';
  }

  // second insert function version (with hint position):
  ft::map<char,int>::iterator it = mymap.begin();
  mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
  mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting

  // third insert function version (range insertion):
  ft::map<char,int> anothermap;
  anothermap.insert(mymap.begin(),mymap.find('c'));

  // showing contents:
  std::cout << "mymap contains:\n";
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "anothermap contains:\n";
  for (it=anothermap.begin(); it!=anothermap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

}

void	ft_swap_2(){
	 ft::map<char,int> foo,bar;

  foo['x']=100;
  foo['y']=200;

  bar['a']=11;
  bar['b']=22;
  bar['c']=33;

  swap(foo,bar);

  std::cout << "foo contains:\n";
  for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "bar contains:\n";
  for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
}

void	ft_swap(){
	  ft::map<char,int> foo,bar;

  foo['x']=100;
  foo['y']=200;

  bar['a']=11;
  bar['b']=22;
  bar['c']=33;

  foo.swap(bar);

  std::cout << "foo contains:\n";
  for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "bar contains:\n";
  for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
}

void ft_equal_range(){
	  ft::map<char,int> mymap;

  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;

  ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
  ret = mymap.equal_range('b');

  std::cout << "lower bound points to: ";
  std::cout << ret.first->first << " => " << ret.first->second << '\n';

  std::cout << "upper bound points to: ";
  std::cout << ret.second->first << " => " << ret.second->second << '\n';
}

void	ft_count(){
	 ft::map<char,int> mymap;
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

void	ft_max_size(){
	 int i;
  ft::map<int,int> mymap;

  if (mymap.max_size()>1000)
  {
    for (i=0; i<1000; i++) mymap[i]=0;
    std::cout << "The map contains 1000 elements.\n";
  }
  else std::cout << "The map could not hold 1000 elements.\n";
}

void	ft_size(){
	std::cout << "Size test\n";
	 ft::map<char,int> mymap;
  mymap['a']=101;
  mymap['b']=202;
  mymap['c']=302;

  std::cout << "mymap.size() is " << mymap.size() << '\n';
}

void	ft_empty(){
	std::cout << "Empty test\n";
	 ft::map<char,int> mymap;

  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;

  while (!mymap.empty())
  {
    std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
    mymap.erase(mymap.begin());
  }
}

void	ft_erase(){
		std::cout<< "testing erase" << std::endl;
	ft::map<char,int> mymap;
  ft::map<char,int>::iterator it;

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
	
	std::cout<< "erase ok" << std::endl;
	std::cout<< std::endl;
}

void	ft_clear(){
		std::cout<< "testing clear" << std::endl;
	  ft::map<char,int> mymap;

  mymap['x']=100;
  mymap['y']=200;
  mymap['z']=300;

  std::cout << "mymap contains:\n";
  for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
  mymap.clear();
  mymap['a']=1101;
  mymap['b']=2202;

  std::cout << "mymap contains:\n";
  for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
		std::cout<< "clear ok" << std::endl;
	std::cout<< std::endl;
}

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

void	ft_assign_op(){
	ft::map<char,int> first;            // default constr
	ft::map<char,int> second = first;
	ft_print_map(second);
	first['z']=42;
	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;
	first['e']=20;
	first['e']=5120;
	ft::map<char,int> third = first;
	ft_print_map(third);
	std::cout<< "copy constr ok" << std::endl;
}

void	ft_constructor_w_ptr_as_comp(){
	bool(*fn_pt)(char,char) = fncomp;
	ft::map<char,int,bool(*)(char,char)> first (fn_pt); // function pointer as Compare
	ft_print_map(first);
	first['z']=42;
	ft_print_map(first);
	first['a']=10;
	first['b']=30;
	ft_print_map(first);
	first['c']=50;
	first['d']=70;
	first['e']=20;
	first['e']=5120;
	ft_print_map(first);
	std::cout<< "fct ptr as comp constr ok" << std::endl;

}

void	ft_constructor_w_class_as_comp(){
	ft::map<char,int,classcomp> first;                 // class as Compare
	ft_print_map(first);
	first['z']=42;
	ft_print_map(first);
	first['a']=10;
	first['b']=30;
	ft_print_map(first);
	first['c']=50;
	first['d']=70;
	first['e']=20;
	first['e']=5120;
	ft_print_map(first);
	std::cout<< "class as comp constr ok" << std::endl;

}

void	ft_cpy_constructor(){
	ft::map<char,int> first;            // default constr
	ft::map<char,int> second (first);
	ft_print_map(second);
	first['z']=42;
	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;
	first['e']=20;
	first['e']=5120;
	ft::map<char,int> third (first);
	ft_print_map(third);
	std::cout<< "copy constr ok" << std::endl;
}

void	ft_range_constructor(){
	ft::map<char,int> first;            // default constr
	ft::map<char,int> second (first.begin(),first.end());
	ft_print_map(&second);
	first['z']=42;
	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;
	first['e']=20;
	first['e']=5120;
	ft::map<char,int> third (first.begin(),first.end());
	ft_print_map(&third);
	std::cout<< "range constr ok" << std::endl;
}

void	ft_constructor(){
	ft::map<char,int> first;            // default constr
	ft_print_map(&first);
	first['z']=42;
	ft_print_map(&first);
	first['a']=10;
	first['b']=30;
	ft_print_map(&first);
	first['c']=50;
	first['d']=70;
	first['e']=20;
	first['e']=5120;
	ft_print_map(&first);
	std::cout<< "default constr ok" << std::endl;
}

void	ft_basics(){
	ft::map<int,int> bst;
	bst[8]=8;
	bst[18]=18;
	bst[5]=5;
	bst[15]=15;
	bst[17]=17;
	bst[40]=40;
	bst[80]=80;
	bst[21]=21;

	ft::map<int,int>::iterator it;
	int i = 0;
	for (it = bst.begin() ; it != bst.end() ; it++){
		std::cout << "node["<<i<<"]:first["<< it->first<<"] | second[" <<it->second<< "]" <<std::endl;
		i++;
	}
	std::cout << std::endl;
	std::cout<< "begin : " << bst.begin()->first << " | begin : " << bst.begin()->second << std::endl;
	it = bst.end();
	it--;
	std::cout<< "end-1 : " << it->first << "   | end-1 : " << it->second << std::endl;

	for (; it != bst.begin() ; it--){
		std::cout << "node["<<i<<"]:first["<< it->first<<"] | second[" <<it->second<< "]" <<std::endl;
		i--;
	}
}

int	main(){

	ft_basics();
	ft_constructor();
	ft_range_constructor();
	ft_cpy_constructor();
	ft_constructor_w_class_as_comp();
	ft_constructor_w_ptr_as_comp();
	ft_assign_op();
	ft_clear();
	ft_erase();
	ft_find();
	ft_insert();
	ft_operator_brackets();
	ft_empty();
	ft_size();
	ft_max_size();
	ft_count();
	ft_upper_bound();
	ft_lower_bound();
	ft_equal_range();
	ft_rend();
	ft_rbegin();
	ft_swap();
	ft_swap_2();
	ft_relationnal_operators();
	return 0;
}
