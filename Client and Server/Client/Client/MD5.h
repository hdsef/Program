#pragma once
#include <iostream>
#include <string>
using namespace std;
typedef unsigned int uint;
class MD5
{
private:
	string to_hex(uint value);
	uint F(uint X, uint Y, uint Z);
	uint G(uint X, uint Y, uint Z);
	uint H(uint X, uint Y, uint Z);
	uint I(uint X, uint Y, uint Z);
	uint rotate_left(uint value, int shift);
	
public:
	MD5();
	~MD5();
	string get_md5(string in);
};

