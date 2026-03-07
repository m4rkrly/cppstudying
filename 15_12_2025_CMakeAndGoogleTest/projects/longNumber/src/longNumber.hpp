#pragma once

#include <iostream>

namespace tkr {
	class LongNumber {
		private:
			int* numbers;
			int length;
			int sign;
		
		public:
			LongNumber();
			LongNumber(int length, int sign);
			LongNumber(const char* const str);
			LongNumber(const LongNumber& x);
			LongNumber(LongNumber&& x);
			
			~LongNumber();
			
			LongNumber& operator = (const char* const str);
			LongNumber& operator = (const LongNumber& x);
			LongNumber& operator = (LongNumber&& x);
			
			bool operator == (const LongNumber& x) const;
			bool operator != (const LongNumber& x) const;
			bool operator > (const LongNumber& x) const;
			bool operator < (const LongNumber& x) const;
			
			LongNumber operator + (const LongNumber& x) const;
			LongNumber operator - (const LongNumber& x) const;
			LongNumber operator * (const LongNumber& x) const;
			LongNumber operator / (const LongNumber& x) const;
			LongNumber operator % (const LongNumber& x) const;

			int getLength() const noexcept;
			int getSign() const noexcept;
			int* getNumbers() const noexcept;

			friend std::ostream& operator << (std::ostream &os, const LongNumber& x);
	
		private:
			int getSign(const char* &ptr) const noexcept;
			int getLength(const char* ptr) const noexcept;
			int* getNumbers(const char* ptr, const int length) const noexcept;
			int* getNumbers(const int* ptr, const int length) const noexcept; 
			LongNumber summarize(const LongNumber& x, const LongNumber& y, const int offset = 0) const;
			LongNumber subtract(const LongNumber& x, const LongNumber& y) const;
			LongNumber multiply(const LongNumber& x, const LongNumber& y, const int offset) const;
			LongNumber getDigit(const LongNumber& number, const int index) const;
	};
}
