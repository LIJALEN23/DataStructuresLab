//#pragma once
//#include "myint.hpp"
//#include <ostream>
//
//namespace lab01
//{
//	struct Term 
//	{
//		double coefficient_;
//		i32 exponent_;
//
//		Term(double coefficient = 0, i32 exponent = 0) : coefficient_(coefficient), exponent_(exponent) {}
//
//		bool equals(const Term& other) const { return coefficient_ == other.coefficient_ && exponent_ == other.exponent_; }
//
//		Term operator+(const Term& other) const;
//		Term operator*(const Term& other) const;
//		bool operator<(const Term& other) const;
//		bool operator>(const Term& other) const;
//		bool operator==(const Term& other) const;
//		friend std::ostream& operator<<(std::ostream& os, const Term& term);
//	};
/