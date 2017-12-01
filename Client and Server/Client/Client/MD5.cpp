#include "MD5.h"
#include <math.h>

MD5::MD5()
{
}


MD5::~MD5()
{
}

string MD5::to_hex(uint value) {
	string out;
	unsigned char hex;
	char hex_res[3];
	while (value) {
		hex = value % 256; _itoa_s(hex, hex_res, 16);
		if (hex_res[1] == '\0') {
			hex_res[1] = hex_res[0];
			hex_res[0] = '0';
			hex_res[2] = '\0';
		}
		out.append(hex_res);
		value /= 256;
	}
	return out;
}

uint MD5::F(uint X, uint Y, uint Z) { return ((X & Y) | ((~X) & Z)); }

uint MD5::G(uint X, uint Y, uint Z) { return (X & Z) | (Y & (~Z)); }

uint MD5::H(uint X, uint Y, uint Z) { return X ^ Y ^ Z; }

uint MD5::I(uint X, uint Y, uint Z) { return Y ^ (X | (~Z)); }

uint MD5::rotate_left(uint value, int shift) { return value << shift | value >> (32 - shift); }

string MD5::get_md5(string in) {
	int length = in.length();
	int rest = length % 64;
	int size = 0;

	if (rest < 56)
		size = length - rest + 56 + 8;
	else
		size = length + 64 - rest + 56 + 8;

	unsigned char *msg_for_decode = new unsigned char[size];

	for (int i = 0; i < length; i++)
		msg_for_decode[i] = in[i];

	msg_for_decode[length] = 0x80;

	for (int i = length + 1; i < size; i++)
		msg_for_decode[i] = 0;

	__int64 bit_length = (uint)(length) * 8;

	for (int i = 0; i < 8; i++)
		msg_for_decode[size - 8 + i] = (unsigned char)(bit_length >> i * 8);


	uint A = 0x67452301, B = 0xefcdab89, C = 0x98badcfe, D = 0x10325476;

	uint T[65];
	for (int i = 0; i <= 64; i++)
		T[i] = uint(pow(2, 32)*fabs(sin(i)));

	uint *X = (uint*)(msg_for_decode);

	uint AA, BB, CC, DD;

	for (int i = 0; i < size / 4; i += 16) {
		AA = A; BB = B; CC = C; DD = D;
		//раунд 1
		A = B + rotate_left((A + F(B, C, D) + X[i + 0] + T[1]), 7);
		D = A + rotate_left((D + F(A, B, C) + X[i + 1] + T[2]), 12);
		C = D + rotate_left((C + F(D, A, B) + X[i + 2] + T[3]), 17);
		B = C + rotate_left((B + F(C, D, A) + X[i + 3] + T[4]), 22);

		A = B + rotate_left((A + F(B, C, D) + X[i + 4] + T[5]), 7);
		D = A + rotate_left((D + F(A, B, C) + X[i + 5] + T[6]), 12);
		C = D + rotate_left((C + F(D, A, B) + X[i + 6] + T[7]), 17);
		B = C + rotate_left((B + F(C, D, A) + X[i + 7] + T[8]), 22);

		A = B + rotate_left((A + F(B, C, D) + X[i + 8] + T[9]), 7);
		D = A + rotate_left((D + F(A, B, C) + X[i + 9] + T[10]), 12);
		C = D + rotate_left((C + F(D, A, B) + X[i + 10] + T[11]), 17);
		B = C + rotate_left((B + F(C, D, A) + X[i + 11] + T[12]), 22);

		A = B + rotate_left((A + F(B, C, D) + X[i + 12] + T[13]), 7);
		D = A + rotate_left((D + F(A, B, C) + X[i + 13] + T[14]), 12);
		C = D + rotate_left((C + F(D, A, B) + X[i + 14] + T[15]), 17);
		B = C + rotate_left((B + F(C, D, A) + X[i + 15] + T[16]), 22);

		//раунд 2
		A = B + rotate_left((A + G(B, C, D) + X[i + 1] + T[17]), 5);
		D = A + rotate_left((D + G(A, B, C) + X[i + 6] + T[18]), 9);
		C = D + rotate_left((C + G(D, A, B) + X[i + 11] + T[19]), 14);
		B = C + rotate_left((B + G(C, D, A) + X[i + 0] + T[20]), 20);

		A = B + rotate_left((A + G(B, C, D) + X[i + 5] + T[21]), 5);
		D = A + rotate_left((D + G(A, B, C) + X[i + 10] + T[22]), 9);
		C = D + rotate_left((C + G(D, A, B) + X[i + 15] + T[23]), 14);
		B = C + rotate_left((B + G(C, D, A) + X[i + 4] + T[24]), 20);

		A = B + rotate_left((A + G(B, C, D) + X[i + 9] + T[25]), 5);
		D = A + rotate_left((D + G(A, B, C) + X[i + 14] + T[26]), 9);
		C = D + rotate_left((C + G(D, A, B) + X[i + 3] + T[27]), 14);
		B = C + rotate_left((B + G(C, D, A) + X[i + 8] + T[28]), 20);

		A = B + rotate_left((A + G(B, C, D) + X[i + 13] + T[29]), 5);
		D = A + rotate_left((D + G(A, B, C) + X[i + 2] + T[30]), 9);
		C = D + rotate_left((C + G(D, A, B) + X[i + 7] + T[31]), 14);
		B = C + rotate_left((B + G(C, D, A) + X[i + 12] + T[32]), 20);

		//раунд 3
		A = B + rotate_left((A + H(B, C, D) + X[i + 5] + T[33]), 4);
		D = A + rotate_left((D + H(A, B, C) + X[i + 8] + T[34]), 11);
		C = D + rotate_left((C + H(D, A, B) + X[i + 11] + T[35]), 16);
		B = C + rotate_left((B + H(C, D, A) + X[i + 14] + T[36]), 23);

		A = B + rotate_left((A + H(B, C, D) + X[i + 1] + T[37]), 4);
		D = A + rotate_left((D + H(A, B, C) + X[i + 4] + T[38]), 11);
		C = D + rotate_left((C + H(D, A, B) + X[i + 7] + T[39]), 16);
		B = C + rotate_left((B + H(C, D, A) + X[i + 10] + T[40]), 23);

		A = B + rotate_left((A + H(B, C, D) + X[i + 13] + T[41]), 4);
		D = A + rotate_left((D + H(A, B, C) + X[i + 0] + T[42]), 11);
		C = D + rotate_left((C + H(D, A, B) + X[i + 3] + T[43]), 16);
		B = C + rotate_left((B + H(C, D, A) + X[i + 6] + T[44]), 23);

		A = B + rotate_left((A + H(B, C, D) + X[i + 9] + T[45]), 4);
		D = A + rotate_left((D + H(A, B, C) + X[i + 12] + T[46]), 11);
		C = D + rotate_left((C + H(D, A, B) + X[i + 15] + T[47]), 16);
		B = C + rotate_left((B + H(C, D, A) + X[i + 2] + T[48]), 23);

		//раунд 4
		A = B + rotate_left((A + I(B, C, D) + X[i + 0] + T[49]), 6);
		D = A + rotate_left((D + I(A, B, C) + X[i + 7] + T[50]), 10);
		C = D + rotate_left((C + I(D, A, B) + X[i + 14] + T[51]), 15);
		B = C + rotate_left((B + I(C, D, A) + X[i + 5] + T[52]), 21);

		A = B + rotate_left((A + I(B, C, D) + X[i + 12] + T[53]), 6);
		D = A + rotate_left((D + I(A, B, C) + X[i + 3] + T[54]), 10);
		C = D + rotate_left((C + I(D, A, B) + X[i + 10] + T[55]), 15);
		B = C + rotate_left((B + I(C, D, A) + X[i + 1] + T[56]), 21);

		A = B + rotate_left((A + I(B, C, D) + X[i + 8] + T[57]), 6);
		D = A + rotate_left((D + I(A, B, C) + X[i + 15] + T[58]), 10);
		C = D + rotate_left((C + I(D, A, B) + X[i + 6] + T[59]), 15);
		B = C + rotate_left((B + I(C, D, A) + X[i + 13] + T[60]), 21);

		A = B + rotate_left((A + I(B, C, D) + X[i + 4] + T[61]), 6);
		D = A + rotate_left((D + I(A, B, C) + X[i + 11] + T[62]), 10);
		C = D + rotate_left((C + I(D, A, B) + X[i + 2] + T[63]), 15);
		B = C + rotate_left((B + I(C, D, A) + X[i + 9] + T[64]), 21);

		A += AA;
		B += BB;
		C += CC;
		D += DD;
	};
	delete[]msg_for_decode;

	string res = to_hex(A) + to_hex(B) + to_hex(C) + to_hex(D);

	return res;
}