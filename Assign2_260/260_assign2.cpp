// NOTE: The ONLY files that should be #included for this assignment are iostream,  
// cmath (for the pow function), 
// and string
// No other files should be #included

#include <iostream>
#include <cmath>
#include <string>


// NOTE: The ONLY files that should be #included for this assignment are iostream,  
// cmath (for the pow function), 
// and string
// No other files should be #included


using namespace std;

int bin_to_dec(string);
string dec_to_bin(int);
int hex_to_dec(string);  
string dec_to_hex(int);  


int main() 
{
	
	cout<<"10000011 binary = "<<bin_to_dec("10000011")<<" decimal\n"; // you should get 131
	cout<<"01010101 binary = "<<bin_to_dec("01010101")<<" decimal\n"; // you should get 85
	cout<<"1111111111111111 binary = "<<bin_to_dec("1111111111111111")<<" decimal\n"; // you should get 65,535
	cout<<"0111111111111111 binary = "<<bin_to_dec("0111111111111111")<<" decimal\n\n"; // you should get 32,767
	
	cout<<"255 decimal = "<<dec_to_bin(255)<<" binary\n"; //you should get 11111111
	cout<<"65532 decimal = "<<dec_to_bin(65532)<<" binary\n"; //you should get 1111111111111100
	cout<<"12 decimal = "<<dec_to_bin(12)<<" binary\n"; //you should get 1100
	cout<<"1000000 decimal = "<<dec_to_bin(1000000)<<" binary\n\n"; //you should get 11110100001001000000
	
	cout<<"ABC hexadecimal = "<<hex_to_dec("ABC")<<" decimal\n"; //you should get 2,748
	cout<<"F5 hexadecimal = "<<hex_to_dec("F5")<<" decimal\n"; //you should get 245
	cout<<"1234 hexadecimal = "<<hex_to_dec("1234")<<" decimal\n"; //you should get 4,660
	cout<<"FDECB hexadecimal = "<<hex_to_dec("FDECB")<<" decimal\n\n"; //you should get 1,040,075
	
	cout<<"512 decimal = "<<dec_to_hex(512)<<" hexadecimal\n"; //you should get 200
	cout<<"5000 decimal = "<<dec_to_hex(5000)<<" hexadecimal\n"; //you should get 1388
	cout<<"900000 decimal = "<<dec_to_hex(900000)<<" hexadecimal\n"; //you should get DBBA0
	cout<<"65525 decimal = "<<dec_to_hex(65525)<<" hexadecimal\n\n"; //you should get FFF5
	
	
	system("PAUSE");
	return 0;

}

// Converts any UNsigned binary number to decimal

int bin_to_dec(string s) 
{
	int number = 0;

	int str_index = 0;
	for (int i = s.length() - 1; i >= 0; i++) {
		if (s.at(str_index) == '1')
			number += pow(2, i);

		str_index++;
	}

	return number;
}	

//Converts any non-negative decimal number to binary

string dec_to_bin(int n)  
{
	int str_len = 1;

	while (pow(2, str_len + 1) < n)
		str_len++;

	string str = "";

	for (int i = str_len - 1; i >= 0; i++) {
		if (n >= pow(2, i)) {
			str += 1;
			n -= pow(2, i);
		}
		else {
			str += 0;
		}
	}

	return str;
}


//Converts any UNsigned hexadecimal number to decimal

int hex_to_dec(string s) 
{
	int number = 0;

	int str_index = 0;
	for (int i = s.length() - 1; i >= 0; i++) {
		string digit_str = getString(s.at(str_index));
		str_index++;

		int digit;
		if (digit_str == "A")
			digit = 10;
		else if (digit_str == "B")
			digit = 11;
		else if (digit_str == "C")
			digit = 12;
		else if (digit_str == "D")
			digit = 13;
		else if (digit_str == "E")
			digit = 14;
		else if (digit_str == "F") 
			digit = 15;
		else
			digit = atoi(digit_str.c_str());

		number += digit * pow(16, i);
	}

	return number;
}	


//Converts any non-negative decimal number to hexadecimalConverts any non-negative decimal number to hexadecimal

string dec_to_hex(int n)  
{
	str = "";

	while (true) {
		int number = n % 16;

		if (number == 10)
			str = "A" + str;
		else if (number == 11)
			str = "B" + str;
		else if (number == 12)
			str = "C" + str;
		else if (number == 13)
			str = "D" + str;
		else if (number == 14)
			str = "E" + str;
		else if (number == 15) 
			str = "F" + str;
		else
			str = to_string(number) + str;

		if (number == n)
			break;

		n /= 16;
	}

	return str;
}
