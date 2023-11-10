#include "MutantStack.hpp"
#include <list>
#include <string>
#include <deque>

typedef MutantStack<int, std::list<int> > ms_type;

int main(void)
{
	{
		std::cout << RED << "- - - - - -" << NC << "\n MAIN TEST\n" << RED << "- - - - - -" << NC << std::endl;
		ms_type mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		ms_type::iterator it = mstack.begin();
		ms_type::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		ms_type s(mstack);
		std::cout << CYN << "\n- - - - - -" << NC;
		std::cout << "\n";
	}

	{
		std::list<int> llist;
		llist.push_back(5);
		llist.push_back(17);
		std::cout << llist.back() << std::endl;
		llist.pop_back();
		std::cout << llist.size() << std::endl;
		llist.push_back(3);
		llist.push_back(5);
		llist.push_back(737);
		llist.push_back(0);
		std::list<int>::iterator it = llist.begin();
		std::list<int>::iterator ite = llist.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::list<int> s(llist);
		std::cout << "\n";
	}

	{
		std::cout << RED << "\n- - - - - -" << NC << "\nOTHER TEST\n" << RED << "- - - - - -" << NC << std::endl;
		int myints[] = {'c','o','u','c','o','u'};
		std::list<int> l_list (myints, myints + sizeof(myints) / sizeof(int));
		ms_type	m_stack;
		for (int i = 0; i < 6; i++)
			m_stack.push(myints[i]);
		std::cout << "\nStack is empty ? " << GRN << m_stack.empty() << NC << "\n" <<
		"List is empty ? " << GRN << l_list.empty() << NC << std::endl;
		std::cout << "\n";
		ms_type::iterator firstStack = m_stack.begin();
		ms_type::iterator lastStack = m_stack.end();
		for (; firstStack != lastStack; ++firstStack)
			std::cout << static_cast<char>(*firstStack);
		std::cout << "\n";
		std::list<int>::iterator firstList = l_list.begin();
		std::list<int>::iterator lastList = l_list.end();
		for (; firstList != lastList; ++firstList)
			std::cout << static_cast<char>(*firstList);
		firstStack = m_stack.begin();
		lastStack = m_stack.end();
		std::cout << "\n\nStack before suppression : " << CYN << m_stack.size() << NC << "\n" <<
		"List before suppression : " << CYN << l_list.size() << NC << std::endl;
		for (;m_stack.size();)
		{
			m_stack.pop();
			l_list.pop_back();
		}
		std::cout << "\nStack is empty ? " << GRN << m_stack.empty() << NC << "\n" <<
		"List is empty ? " << GRN << l_list.empty() << NC << std::endl;		
	}
	{
		std::cout << RED << "\n- - - - - -" << NC << "\nOTHER TEST\n" << RED << "- - - - - -" << NC << std::endl;
		int myints[] = {-9, 76, 5, 234, 23, 6, 6767, 726, 512, 223234, 123133, 65};
		std::deque<int> d_deque (myints, myints + sizeof(myints) / sizeof(int));
		ms_type	m_stack;
		for (int i = 0; i < 12; i++)
			m_stack.push(myints[i]);
		std::cout << "Stack is empty ? " << GRN << m_stack.empty() << NC << "\n" <<
		"deque is empty ? " << GRN << d_deque.empty() << NC << std::endl;
		std::cout << "\nStack top : " << m_stack.top() << std::endl;
		std::cout << "Deque back : " << d_deque.back() << std::endl;
		ms_type::iterator firstStack = m_stack.begin();
		ms_type::iterator lastStack = m_stack.end();
		for (; firstStack != lastStack; ++firstStack)
			std::cout << (*firstStack) << " ";
		std::cout << "\n";
		std::deque<int>::iterator firstdeque = d_deque.begin();
		std::deque<int>::iterator lastdeque = d_deque.end();
		for (; firstdeque != lastdeque; ++firstdeque)
			std::cout << (*firstdeque) << " ";
		firstStack = m_stack.begin();
		lastStack = m_stack.end();
		std::cout << "\n\nStack before suppression : " << CYN << m_stack.size() << NC << "\n" <<
		"deque before suppression : " << CYN << d_deque.size() << NC << std::endl;
		for (; m_stack.size();)
		{
			m_stack.pop();
			d_deque.pop_back();
		}
		std::cout << "\nStack is empty ? " << GRN << m_stack.empty() << NC << "\n" <<
		"deque is empty ? " << GRN << d_deque.empty() << NC << std::endl;
		firstdeque = d_deque.begin();
		lastdeque = d_deque.end();
		for (; firstdeque != lastdeque; ++firstdeque)
			std::cout << (*firstdeque) << " ";		
	}
	return (0);
}