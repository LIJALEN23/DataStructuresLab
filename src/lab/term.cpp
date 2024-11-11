//#include "term.hpp"
//#include <ostream>
//
//namespace lab01
//{
//	Term Term::operator+(const Term& other) const
//	{
//		double new_coefficient = coefficient_ + other.coefficient_;
//		i32 new_exponent = other.exponent_;
//
//		////当指数和系数都为零时，不创建新的项了
//		//if (new_coefficient == 0 && new_exponent == 0)
//		//{
//		//	return Term();
//		//}
//
//		return Term(new_coefficient, new_exponent);
//	}
//
//	Term Term::operator*(const Term& other) const
//	{
//		return Term(coefficient_ * other.coefficient_, exponent_ + other.exponent_);
//	}
//
//	std::ostream& operator<<(std::ostream& os, const Term& term)
//	{
//		if (term.coefficient_ == 0)
//		{
//			return os;
//		}
//		else
//		{
//			if (term.coefficient_ > 0)
//			{
//				return term.exponent_ == 0 ? (os << " + " << term.coefficient_)
//					: (os << " + " << term.coefficient_ << "x^" << term.exponent_);
//			}
//			else
//			{
//				return term.exponent_ == 0 ? (os << " - " << -term.coefficient_)
//					: (os << " - " << -term.coefficient_ << "x^" << term.exponent_);
//			}
//		}
//	}
//
//	bool Term::operator<(const Term& other) const
//	{
//		if (exponent_ < other.exponent_)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//
//	bool Term::operator>(const Term& other) const
//	{
//		if (exponent_ > other.exponent_)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//
//	bool Term::operator==(const Term& other) const
//	{
//		if (exponent_ == other.exponent_)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//}