//#pragma once
//#include "linkedlist.hpp"
//#include "term.hpp"
//#include <ostream>
//#include <string>
//
//namespace lab01
//{
//	using std::string;
//	using linkedlist::LinkedList;
//	using linkedlist::Node;
//
//	class Polynomial
//	{
//	public:
//		Polynomial() : formula_() {}
//		Polynomial(LinkedList<Term>&& a_formula) : formula_(std::move(a_formula)) {}
//		Polynomial(const string& formula_str);
//		~Polynomial() = default;
//
//		Polynomial operator+(const Polynomial& other) const;
//		Polynomial operator*(const Polynomial& other) const;
//		Polynomial& operator=(const Polynomial& other);
//		friend std::ostream& operator<<(std::ostream& os, const Polynomial& polynomial);
//		//string toString();
//		bool isEmpty() { return formula_.isEmpty(); }
//		void clear();
//
//	private:
//		LinkedList<Term> formula_;
//
//		Term* parseStr(const string& formula_str, u32& term_size);
//	};
/