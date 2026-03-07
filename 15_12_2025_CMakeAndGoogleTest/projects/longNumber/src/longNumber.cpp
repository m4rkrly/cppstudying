#include <iostream>
#include "longNumber.hpp"

using tkr::LongNumber;

void printNumbers(const int* numbers, const int length, const int sign) {
	for (int i = 0; i < length; i++) {
		std::cout << *numbers++ << ' ';
	}
	std::cout << std::endl;
	std::cout << "Address: " << numbers - length << std::endl;
	std::cout << "Length: " << length << std::endl;
	std::cout << "Sign: " << sign << std::endl;
}

int LongNumber::getSign(const char* &ptr) const noexcept {
	int sign = 1;
	if (*ptr == '-') {
		sign = -1;
		ptr++;
	}
	return sign;
}

int LongNumber::getLength(const char* ptr) const noexcept {
	int length = 0;
	while (*ptr != '\0') {
		length++;
		ptr++;
	}
	return length;
}

int* LongNumber::getNumbers(const char* ptr, const int length) const noexcept { 
	int* numbers = new int[length]{0};
	numbers = numbers + length - 1;
	for (int i = length - 1; i >= 0; i--) {
		*numbers = int(*ptr - '0');
		numbers--; ptr++;
	}
	numbers += 1;
	return numbers;
}

int* LongNumber::getNumbers(const int* ptr, const int length) const noexcept {
	int* numbers = new int[length]{0};
	for (int i = 0; i < length; i++) {
		*numbers = *ptr;
		numbers++; ptr++;
	}
	numbers -= length;
	return numbers;
}
int compare(const LongNumber& l, const LongNumber& r, bool checkSign = true) {
	if (l.getSign() > r.getSign() && checkSign == true) {
		return -1;
	} else if (l.getSign() < r.getSign() && checkSign == true) {
		return 1;
	}
		
	if (l.getLength() > r.getLength()) {
		return -1;
	} else if (l.getLength() < r.getLength()) {
		return 1;
	}
	
	const int sign = l.getSign();
	const int length = l.getLength();
	const int* numbersL = l.getNumbers(); 
	const int* numbersR = r.getNumbers(); 

	for (int i = 0; i < length; i++) {
		if (*numbersL > *numbersR) {
			return -1 * ((checkSign == true) ? sign : 1);
		} else if (*numbersL < *numbersR) {
			return 1 * ((checkSign == true) ? sign : 1);
		}
		numbersL++; numbersR++;
	}
	return 0;
}

LongNumber::LongNumber() {
	sign = 1;
	length = 1;
	numbers = new int[length]{0};
}

LongNumber::LongNumber(int length, int sign) {
	this->sign = sign;
	this->length = length;
	numbers = new int[length]{0};
}

LongNumber::LongNumber(const char* const str) {
	const char* ptr = str; 

	sign = getSign(ptr);
	length = getLength(ptr);
	numbers = getNumbers(ptr, length);

	ptr = nullptr; 
	// TEMP
}

LongNumber::LongNumber(const LongNumber& x) {
	const int* ptr = x.numbers;

	sign = x.sign;
	length = x.length;
	numbers = getNumbers(ptr, length);

	ptr = nullptr;
}

LongNumber::LongNumber(LongNumber&& x) {
	sign = x.sign;
	length = x.length; 
	numbers = x.numbers;

	x.sign = 0;
	x.length = 0;
	x.numbers = nullptr; 
}

LongNumber::~LongNumber() {
	delete[] numbers;
	numbers = nullptr;
}

LongNumber& LongNumber::operator = (const char* const str) {
	delete[] numbers;
	const char* ptr = str; 
	
	sign = getSign(ptr);
	length = getLength(ptr);
	numbers = getNumbers(ptr, length);

	ptr = nullptr;

	return *this;
}

LongNumber& LongNumber::operator = (const LongNumber& x) {
	if (this->numbers == x.numbers) { return *this; }
	delete[] numbers;
	const int* ptr = x.numbers;

	sign = x.sign;
	length = x.length;
	numbers = getNumbers(ptr, length);

	ptr = nullptr;
	return *this;
}

LongNumber& LongNumber::operator = (LongNumber&& x) {
	delete[] numbers;
	sign = x.sign;
	length = x.length; 
	numbers = x.numbers;

	x.sign = 0;
	x.length = 0;
	x.numbers = nullptr; 
	return *this;
 }


bool LongNumber::operator == (const LongNumber& x) const {
	return compare(*this, x) == 0;
}

bool LongNumber::operator != (const LongNumber& x) const {
	return compare(*this, x) != 0;
}

bool LongNumber::operator > (const LongNumber& x) const {
	return compare(*this, x) == -1;
}

bool LongNumber::operator < (const LongNumber& x) const {
	return compare(*this, x) == 1;
}

LongNumber LongNumber::summarize(const LongNumber& x, const LongNumber& y, const int offset) const {
	int lengthX = x.length;
	int* numbersX = x.numbers;
	int lengthY = y.length + offset;
	int* numbersY = y.numbers;
	
	int lengthMax = (lengthX > lengthY) ? lengthX : lengthY;
	LongNumber result(lengthMax + 1, x.sign); 
	int* numbersResult = result.numbers;

	int overflow = 0;
	for (int i = 0; i < lengthMax; i++) {
		int digit1 = (i < lengthX) ? numbersX[i] : 0;
		int digit2 = 0;
		if ((i - offset) < lengthY and i >= offset) { digit2 = numbersY[i-offset]; }
		
		int temp = digit1 + digit2 + overflow;
		numbersResult[i] = temp % 10;
		overflow = temp / 10;
	}

	if (overflow != 0) {
		numbersResult[lengthMax] = overflow;
		result.length = lengthMax + 1;
	} else {
		while (numbersResult[result.length - 1] == 0 and result.length > 1) {
			result.length -= 1;
		}
	}

	return result;
}

LongNumber LongNumber::subtract(const LongNumber& x, const LongNumber& y) const {
	int lengthX = x.length;
	int* numbersX = x.numbers;
	int lengthY = y.length;
	int* numbersY = y.numbers;
	
	int lengthMax = (lengthX > lengthY) ? x.length : y.length;
	LongNumber result(lengthMax, x.sign); 
	int* numbersResult = result.numbers;

	int debt = 0;
	for (int i = 0; i < lengthMax; i++) {
		int digit1 = (i < lengthX) ? numbersX[i] : 0;
		int digit2 = (i < lengthY) ? numbersY[i] : 0;

		int temp = digit1 - digit2 + debt;
		if (temp < 0) {
			temp += 10; 
			debt = -1;
		} else {
			debt = 0;
		}

		numbersResult[i] = temp; 
	}
	
	while (numbersResult[result.length - 1] == 0 and result.length > 1) {
		result.length -= 1;
	}

	return result;
}


LongNumber LongNumber::operator + (const LongNumber& x) const {
	if (this->sign == x.sign) {
		return summarize(*this, x);
	} else {
		if (compare(*this, x, false) == -1) {
			LongNumber result = subtract(*this, x);
			return result;
		} else {
			LongNumber result = subtract(x, *this);
			return result;
		}
	} 
}

LongNumber LongNumber::operator - (const LongNumber& x) const {
	if (this->sign == x.sign) {
		return subtract(*this, x);
	} else {
		if (compare(*this, x, false) == -1) {
			LongNumber result = summarize(*this, x);
			return result;
		} else {
			LongNumber result = summarize(x, *this);
			return result;
		}
	}
}

LongNumber LongNumber::multiply(const LongNumber& x, const LongNumber& y, const int offset) const {
		
	int length = x.length;
	LongNumber result(length + 1, 1);
	int* numbersResult = result.numbers;
	int* numbersX = x.numbers;
	int* numbersY = y.numbers;
	
	int currentDigit = numbersY[offset];
	int overflow = 0;
	for (int i = 0; i < length; i++) {
		int temp = (numbersX[i] * currentDigit) + overflow;
		overflow = temp / 10;
		numbersResult[i] = temp % 10;
	}

	if (overflow != 0) {
		numbersResult[length] = overflow;
		result.length = length + 1;
	} else {
		while (numbersResult[result.length - 1] == 0 and result.length > 1) {
			result.length -= 1;
		}
	}
	return result;
}

LongNumber LongNumber::operator * (const LongNumber& x) const {
	int lengthL = this->length;
	int lengthR = x.length; 
	int lengthMax = lengthL + lengthR;
	int signResult = this ->sign * x.sign;
	
	LongNumber result(lengthMax, signResult);

	for (int offset = 0; offset < lengthR; offset++) {
		result = summarize(result, multiply(*this, x, offset), offset);
	}
	return result;
}

LongNumber div(const LongNumber& divided, const LongNumber& divisor) {
	LongNumber q = "0";
	LongNumber one = "1";
	while	((divided - (divisor * q)) > divisor or (divided - (divisor * q)) == divisor) {
		q = q + one;
	}
	return q;
}

LongNumber mod(const LongNumber& divided, const LongNumber& divisor) {
	LongNumber q = "0";
	LongNumber one = "1";
	while	((divided - (divisor * q)) > divisor or (divided - (divisor * q)) == divisor) {
		q = q + one;
	}
	return divided - (divisor * q);
}

LongNumber LongNumber::getDigit(const LongNumber& number, const int index) const {
	LongNumber result;
	result.numbers[0] = number.numbers[index];
	return result;
}


LongNumber LongNumber::operator / (const LongNumber& x) const {
	int length = this->length;
	int i = length - 1;
	LongNumber q;
	LongNumber r;
	LongNumber temp;
	LongNumber result;

	while (i >= 0) {
		while (temp < x and i >= 0) {	
			temp = (temp * LongNumber("10")) + getDigit(*this, i);
			i--;
		}

	return temp;
	}
}

LongNumber LongNumber::operator % (const LongNumber& x) const {
	return getDigit(*this, 1);
}


int LongNumber::getSign() const noexcept {
	return this->sign;
}

int LongNumber::getLength() const noexcept {
	return this->length;
}

int* LongNumber::getNumbers() const noexcept {
	return this->numbers;
}

// ----------------------------------------------------------
// PRIVATE
// ----------------------------------------------------------

// ----------------------------------------------------------
// FRIENDLY
// ----------------------------------------------------------
namespace tkr {
	std::ostream& operator << (std::ostream &os, const LongNumber& x) {
		// TODO
	}
}
