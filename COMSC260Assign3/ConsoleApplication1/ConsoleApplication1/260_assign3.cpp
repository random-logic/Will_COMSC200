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

string addbin(string, string);  
string addhex(string, string); 


int main()
{
	
	cout<<"binary 1101 + 1000 = "<<addbin("1101", "1000")<<endl;   //you should get 10101
	cout<<"binary 11000 + 1011 = "<<addbin("11000", "1011")<<endl; //you should get 100011
	cout<<"binary 11111111 + 1 = "<<addbin("11111111", "1")<<endl; //you should get 100000000
	cout<<"binary 101010 + 10 = "<<addbin("101010", "10")<<endl<<endl; //you should get 101100
	
	cout<<"hexadecimal A4 + A5 = "<<addhex("A4", "A5")<<endl;  //you should get 149
	cout<<"hexadecimal 2B + C = "<<addhex("2B",  "C")<<endl;    //you should get 37
	cout<<"hexadecimal FABC + 789 = "<<addhex("FABC", "789")<<endl;  //you should get 10245
	cout<<"hexadecimal FFFFFF + FF = "<<addhex("FFFFFF", "FF")<<endl<<endl; //you should get 10000FE
	

	system("PAUSE");
	return 0;
	
}


string addbin(string bin1, string bin2)
{
	string bin_1(bin1);
	string bin_2(bin2);

	//Add placeholder 0s to bin_1 if len < bin_2
	while (bin_1.length() < bin_2.length()) {
		bin_1 = "0" + bin_1;
	}

	//Add placeholder 0s to bin_2 if len < bin_1
	while (bin_2.length() < bin_1.length()) {
		bin_2 = "0" + bin_2;
	}

	int place_holder = 0;
	string sum = "";
	int init_bin_length = bin_1.length();

	for (int i = init_bin_length - 1; i >= 0; i--) {
		int digit_sum = 0;
		digit_sum += (int)bin_1[i] - (int)'0';
		digit_sum += (int)bin_2[i] - (int)'0';
		digit_sum += place_holder;

		place_holder = digit_sum / 2;
		sum = to_string(digit_sum % 2) + sum;
	}

	while (place_holder > 0) {
		sum = to_string(place_holder % 2) + sum;
		place_holder /= 2;
	}

	return sum;
}

string addhex(string hex1, string hex2)
{
	string hex_1(hex1);
	string hex_2(hex2);

	//Add placeholder 0s to hex_1 if len < hex_2
	while (hex_1.length() < hex_2.length()) {
		hex_1 = "0" + hex_1;
	}

	//Add placeholder 0s to hex_2 if len < hex_1
	while (hex_2.length() < hex_1.length()) {
		hex_2 = "0" + hex_2;
	}

	int place_holder = 0;
	string sum = "";
	int init_bin_length = hex_1.length();

	for (int i = init_bin_length - 1; i >= 0; i--) {
		int digit_sum = 0;
		if (isdigit(hex_1[i]))
			digit_sum += (int)hex_1[i] - (int)'0';
		else /* if (hex_1[i] is a character between 'A'-'F') */
			digit_sum += (int)hex_1[i] - (int)'A' + 10;
		
		if (isdigit(hex_2[i]))
			digit_sum += (int)hex_2[i] - (int)'0';
		else /* if (hex_2[i] is a character between 'A'-'F') */
			digit_sum += (int)hex_2[i] - (int)'A' + 10;
		
		digit_sum += place_holder;

		place_holder = digit_sum / 16;

		int digit_decimal_value = digit_sum % 16;

		char c;
		if (digit_decimal_value < 10 /* && digit_decimal_value >= 0*/)
			c = char((int)'0' + digit_decimal_value);
		else /* if (digit_decimal_value < 16) */
			c = char((int)'A' + digit_decimal_value - 10);
		sum = c + sum;
	}

	while (place_holder > 0) {
		sum = to_string(place_holder % 16) + sum;
		place_holder /= 16;
	}

	return sum;
}