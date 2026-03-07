#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iostream>

#include "longNumber.hpp"

int compare(const int* ptr1, const int* ptr2, const int length) {
	int status = -1;
	for (int i = 0; i < length; i++) {
		if (*ptr1 != *ptr2) {
			status = i;  
			break;
		}
		ptr1++; ptr2++;
	}
	return status;
}

TEST(Constructors, Default) {
	tkr::LongNumber x;
	const int* expected = new int[1]{0};
	const int* actual = x.getNumbers();
	const int length = x.getLength();
	
	int status = compare(expected, actual, length);
	ASSERT_EQ(status, -1)
		<< "Массивы чисел не совпадают в элементе по индексу "
		<< status;
}

TEST(Constructors, ByChar) {
	tkr::LongNumber x("-123");
	const int length = x.getLength();
	
	const int expectedSign = -1;
	const int* expectedNumbers = new int[]{3, 2, 1};
	
	const int actualSign = x.getSign();
	const int* actualNumbers = x.getNumbers();

	int status = compare(expectedNumbers, actualNumbers, length);
	ASSERT_EQ(expectedSign, actualSign)
		<< "Знак чисел не совпадает";
	ASSERT_EQ(status, -1)
		<< "Массивы чисел не совпадают в элементе по индексу "
		<< status; 
}

TEST(Constructors, Copy) {
	tkr::LongNumber x("-9745");
	tkr::LongNumber y(x);

	const int expectedLength = x.getLength();
	const int expectedSign = x.getSign();
	const int* expectedNumbers = x.getNumbers();

	const int actualLength = y.getLength();
	const int actualSign = y.getSign();
	const int* actualNumbers = y.getNumbers();

	int status = compare(expectedNumbers, actualNumbers, expectedLength);
	ASSERT_EQ(status, -1)
		<< "Массивы чисел не совпадают в элементе по индексу "
		<< status;
}

TEST(Constructors, Move) {
	tkr::LongNumber x("631");
	
	const int expectedYSign = x.getSign();
	const int expectedYLength = x.getLength();
	const int* expectedYNumbers = x.getNumbers();

	const int expectedXSign = 0;
	const int expectedXLength = 0;
	const int* expectedXNumbers = nullptr;
	
	tkr::LongNumber y(std::move(x));

	const int actualYSign = y.getSign();
	const int actualYLength = y.getLength();
	const int* actualYNumbers = y.getNumbers();
	
	const int actualXSign = x.getSign();
	const int actualXLength = x.getLength();
	const int* actualXNumbers = x.getNumbers();	

	ASSERT_EQ(expectedYSign, actualYSign)
		<< "Знак перемещённого числа не совпадает";
	ASSERT_EQ(expectedYLength, actualYLength)
		<< "Длина перемещённого числа не совпадает";
	
	int status = compare(expectedYNumbers, actualYNumbers, expectedYLength);
	ASSERT_EQ(status, -1)
		<< "Массив перемещённого числа не совпадает с перемещаемым в элементе с индексом "
		<< status;

	ASSERT_EQ(expectedXSign, actualXSign)
		<< "Знак перемещаемого числа не обнулился";
	ASSERT_EQ(expectedXLength, actualXLength)
		<< "Длина перемещаемого числа не обнулилась";
	
	ASSERT_EQ(expectedXNumbers, actualXNumbers)
		<< "Массив перемещённого числа не обнулился";
}

TEST(Constructors, AssignmentOperatorChar) {
	tkr::LongNumber x = "-916441";
	tkr::LongNumber y;
	y = "-916441";

	const int length = x.getLength();
	
	const int expectedSign = -1;
	const int* expectedNumbers = new int[]{1, 4, 4, 6, 1, 9}; 
	const int actualXSign = x.getSign();
	const int* actualXNumbers = x.getNumbers();

	const int actualYSign = y.getSign();
	const int* actualYNumbers = y.getNumbers();

	int statusX = compare(expectedNumbers, actualXNumbers, length);
	int statusY = compare(expectedNumbers, actualYNumbers, length);

	ASSERT_EQ(expectedSign, actualXSign)
		<< "Знак числа при присвоении новому объекту не сходится";	
	ASSERT_EQ(expectedSign, actualYSign)
		<< "Знак числа при присвоении созданному объекту не сходится";
	
	ASSERT_EQ(statusX, -1)
		<< "Массивы чисел при присвоении новому объекту не совпадают в элементе по индексу "
		<< statusX; 
	
	ASSERT_EQ(statusY, -1)
		<< "Массивы чисел при присвоении созданному объекту не совпадают в элементе по индексу "
		<< statusY; 
}

TEST(Constructors, AssignmentOperatorLongNumber) {
	tkr::LongNumber x = "76149";
	tkr::LongNumber y;
	y = x;
	y = y;

	const int length = x.getLength();
	
	const int expectedSign = x.getSign();
	const int* expectedNumbers = x.getNumbers();
	
	const int actualSign = y.getSign();
	const int* actualNumbers = y.getNumbers();

	int status = compare(expectedNumbers, actualNumbers, length);

	ASSERT_EQ(expectedSign, actualSign)
		<< "Знак числа при присвоении новому объекту не сходится";	

	ASSERT_EQ(status, -1)
		<< "Массивы чисел при присвоении новому объекту не совпадают в элементе по индексу "
		<< status; 
}


TEST(Constructors, AssignmentOperatorMove) {
	tkr::LongNumber x("-87537");
	
	const int expectedYSign = x.getSign();
	const int expectedYLength = x.getLength();
	const int* expectedYNumbers = x.getNumbers();

	const int expectedXSign = 0;
	const int expectedXLength = 0;
	const int* expectedXNumbers = nullptr;
	
	tkr::LongNumber y = std::move(x);

	const int actualYSign = y.getSign();
	const int actualYLength = y.getLength();
	const int* actualYNumbers = y.getNumbers();
	
	const int actualXSign = x.getSign();
	const int actualXLength = x.getLength();
	const int* actualXNumbers = x.getNumbers();	

	ASSERT_EQ(expectedYSign, actualYSign)
		<< "Знак перемещённого числа не совпадает";
	ASSERT_EQ(expectedYLength, actualYLength)
		<< "Длина перемещённого числа не совпадает";
	
	int status = compare(expectedYNumbers, actualYNumbers, expectedYLength);
	ASSERT_EQ(status, -1)
		<< "Массив перемещённого числа не совпадает с перемещаемым в элементе с индексом "
		<< status;

	ASSERT_EQ(expectedXSign, actualXSign)
		<< "Знак перемещаемого числа не обнулился";
	ASSERT_EQ(expectedXLength, actualXLength)
		<< "Длина перемещаемого числа не обнулилась";
	ASSERT_EQ(expectedXNumbers, actualXNumbers)
		<< "Массив перемещённого числа не обнулился";
}

TEST(Comparations, EqualityAndInequality) {
	tkr::LongNumber a = "1064";
	tkr::LongNumber b = "-1064";
	tkr::LongNumber c = a;
	tkr::LongNumber d = "51064";

	ASSERT_FALSE(a == b);
	ASSERT_TRUE(a == c);
	ASSERT_FALSE(a == d);

	ASSERT_TRUE(a != b);
	ASSERT_FALSE(a != c);
	ASSERT_TRUE(a != d);
}

TEST(Comparations, LessAndGreater) {
	tkr::LongNumber a = "851";
	tkr::LongNumber b = "-851";
	tkr::LongNumber c = a;
	tkr::LongNumber d = "46";
	tkr::LongNumber e = "-83";
	tkr::LongNumber f = "0";

	ASSERT_FALSE(a > c);
	ASSERT_FALSE(b > d);
	ASSERT_TRUE(a > d);
	ASSERT_TRUE(f > e);

	ASSERT_FALSE(a < c);
	ASSERT_TRUE(b < d);
	ASSERT_FALSE(a < d);
	ASSERT_FALSE(f < e);
}

TEST(Arithmetics, Addition) {
	tkr::LongNumber a = "123";
	tkr::LongNumber b = "99";
	tkr::LongNumber c = "222";

	ASSERT_EQ(a + b, c);

	a = "-123";
	b = "99";
	c = "-24";

	ASSERT_EQ(a + b, c);
	
	a = "123";
	b = "-99";
	c = "24";

	ASSERT_EQ(a + b, c);


	a = "-123";
	b = "-99";
	c = "-222";

	ASSERT_EQ(a + b, c);
}

TEST(Arithmetics, Subtraction) {
	tkr::LongNumber a = "123";
	tkr::LongNumber b = "99";
	tkr::LongNumber c = "24";

	ASSERT_EQ(a - b, c);

	a = "-123";
	b = "99";
	c = "-222";

	ASSERT_EQ(a - b, c);
	
	a = "123";
	b = "-99";
	c = "222";

	ASSERT_EQ(a - b, c);


	a = "-123";
	b = "-99";
	c = "-24";

	ASSERT_EQ(a - b, c);
}

TEST(Arithmetics, Multiplication) {
	tkr::LongNumber a = "123";
	tkr::LongNumber b = "999";
	tkr::LongNumber c = "122877";

	ASSERT_EQ(a * b, c);

	a = "-659";
	b = "74";
	c = "-48766";
	ASSERT_EQ(a * b, c);

	a = "-64";
	b = "-8";
	c = "512";
	ASSERT_EQ(a * b, c);
}

TEST(Arithmetics, Division) {
	//tkr::LongNumber a = "124";
	//tkr::LongNumber b = "2";
	//tkr::LongNumber answ = "62";

	//ASSERT_EQ(a / b, answ);

	//a = "-891";
	//b = "91"; 
	//answ = "-9";
	//ASSERT_EQ(a / b, answ);

	//a = "-95619";
	//b = "-142";
	//answ = "673";
	//ASSERT_EQ(a / b, answ);
	
	//a = "-125";
	//b = "2";
	//answ = "-125";
	//ASSERT_EQ((a/b)*b + (a%b), answ);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS(); 
}
