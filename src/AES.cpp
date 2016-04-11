/*
 * main.cpp

 *
 *  Created on: 6 apr. 2016
 *      Author: Jan-Willem
 */


#include <sstream>
#include <iostream>
#include <string>

using namespace std;

//CIPHER KEY:
unsigned char in[176];
unsigned char cipher_key_1[16]= {0x69, 0x20, 0xe2, 0x99, 0xa5, 0x20, 0x2a, 0x6d, 0x65, 0x6e, 0x63, 0x68, 0x69, 0x74, 0x6f, 0x2a,};
unsigned char cipher_key_2[16]= {0x69, 0x20, 0xe2, 0x99, 0xa5, 0x20, 0x2a, 0x6d, 0x65, 0x6e, 0x63, 0x68, 0x69, 0x74, 0x6f, 0x2b,};
unsigned char cipher_key_3[16]= {0x69, 0x20, 0xe2, 0x99, 0xa5, 0x20, 0x2a, 0x6d, 0x65, 0x6e, 0x63, 0x68, 0x69, 0x74, 0x6f, 0x2c,};
unsigned char cipher_key_4[16]= {0x69, 0x20, 0xe2, 0x99, 0xa5, 0x20, 0x2a, 0x6d, 0x65, 0x6e, 0x63, 0x68, 0x69, 0x74, 0x6f, 0x2d,};
unsigned char cipher_key[16];
//INPUT IN HEX PACKETS OF 128 BITS:
unsigned char input[16]= {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
string str_input;
//OUTPUT
string str_output, result, endresult;

unsigned char test[4]= {0xdb, 0x13, 0x53, 0x45};


unsigned char s[256] =
{
   0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
   0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0,
   0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC, 0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15,
   0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A, 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75,
   0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84,
   0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B, 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF,
   0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8,
   0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5, 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2,
   0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73,
   0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88, 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB,
   0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79,
   0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9, 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08,
   0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A,
   0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E, 0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E,
   0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94, 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF,
   0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16
};

unsigned char inv_s[256] =
{
   0x52, 0x09, 0x6A, 0xD5, 0x30, 0x36, 0xA5, 0x38, 0xBF, 0x40, 0xA3, 0x9E, 0x81, 0xF3, 0xD7, 0xFB,
   0x7C, 0xE3, 0x39, 0x82, 0x9B, 0x2F, 0xFF, 0x87, 0x34, 0x8E, 0x43, 0x44, 0xC4, 0xDE, 0xE9, 0xCB,
   0x54, 0x7B, 0x94, 0x32, 0xA6, 0xC2, 0x23, 0x3D, 0xEE, 0x4C, 0x95, 0x0B, 0x42, 0xFA, 0xC3, 0x4E,
   0x08, 0x2E, 0xA1, 0x66, 0x28, 0xD9, 0x24, 0xB2, 0x76, 0x5B, 0xA2, 0x49, 0x6D, 0x8B, 0xD1, 0x25,
   0x72, 0xF8, 0xF6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xD4, 0xA4, 0x5C, 0xCC, 0x5D, 0x65, 0xB6, 0x92,
   0x6C, 0x70, 0x48, 0x50, 0xFD, 0xED, 0xB9, 0xDA, 0x5E, 0x15, 0x46, 0x57, 0xA7, 0x8D, 0x9D, 0x84,
   0x90, 0xD8, 0xAB, 0x00, 0x8C, 0xBC, 0xD3, 0x0A, 0xF7, 0xE4, 0x58, 0x05, 0xB8, 0xB3, 0x45, 0x06,
   0xD0, 0x2C, 0x1E, 0x8F, 0xCA, 0x3F, 0x0F, 0x02, 0xC1, 0xAF, 0xBD, 0x03, 0x01, 0x13, 0x8A, 0x6B,
   0x3A, 0x91, 0x11, 0x41, 0x4F, 0x67, 0xDC, 0xEA, 0x97, 0xF2, 0xCF, 0xCE, 0xF0, 0xB4, 0xE6, 0x73,
   0x96, 0xAC, 0x74, 0x22, 0xE7, 0xAD, 0x35, 0x85, 0xE2, 0xF9, 0x37, 0xE8, 0x1C, 0x75, 0xDF, 0x6E,
   0x47, 0xF1, 0x1A, 0x71, 0x1D, 0x29, 0xC5, 0x89, 0x6F, 0xB7, 0x62, 0x0E, 0xAA, 0x18, 0xBE, 0x1B,
   0xFC, 0x56, 0x3E, 0x4B, 0xC6, 0xD2, 0x79, 0x20, 0x9A, 0xDB, 0xC0, 0xFE, 0x78, 0xCD, 0x5A, 0xF4,
   0x1F, 0xDD, 0xA8, 0x33, 0x88, 0x07, 0xC7, 0x31, 0xB1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xEC, 0x5F,
   0x60, 0x51, 0x7F, 0xA9, 0x19, 0xB5, 0x4A, 0x0D, 0x2D, 0xE5, 0x7A, 0x9F, 0x93, 0xC9, 0x9C, 0xEF,
   0xA0, 0xE0, 0x3B, 0x4D, 0xAE, 0x2A, 0xF5, 0xB0, 0xC8, 0xEB, 0xBB, 0x3C, 0x83, 0x53, 0x99, 0x61,
   0x17, 0x2B, 0x04, 0x7E, 0xBA, 0x77, 0xD6, 0x26, 0xE1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0C, 0x7D
};

unsigned char rcon[12] = {0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c};

void rotate(unsigned char *in) {
        unsigned char a,c;
        a = in[0];
        for(c=0;c<3;c++)
                in[c] = in[c + 1];
        in[3] = a;
        return;
}

void schedule_core(unsigned char *in, unsigned char i) {
        char a;
        /* Rotate the input 8 bits to the left */
        rotate(in);
        /* Apply Rijndael's s-box on all 4 bytes */
        for(a = 0; a < 4; a++)
                in[a] = s[in[a]];
        /* On just the first byte, add 2^i to the byte */
        in[0] ^= rcon[i];
}

void expand_key(unsigned char *in) {
        unsigned char t[4];
        /* c is 16 because the first sub-key is the user-supplied key */
        unsigned char c = 16;
        unsigned char i = 1;
        unsigned char a;

        /* We need 11 sets of sixteen bytes each for 128-bit mode */
        while(c < 176) {
                /* Copy the temporary variable over from the last 4-byte
                 * block */
                for(a = 0; a < 4; a++)
                        t[a] = in[a + c - 4];
                /* Every four blocks (of four bytes),
                 * do a complex calculation */
                if(c % 16 == 0) {
			schedule_core(t,i);
			i++;
		}
                for(a = 0; a < 4; a++) {
                        in[c] = in[c - 16] ^ t[a];
                        c++;
                }
        }
}

void AddRoundKey(unsigned char *input, int round){
	//round 1 should tart at 0 and end at 15 and not for 16 to 31.
	for (int i=(round-1)*16, j=0; i<((round-1)*16+16); i++, j++){
		//printf("%X ", input[j]);
		input[j] ^= in[i];
	}

	//printf("\nround: %i, First and last byte of key: %X %X \n",round, in[(round-1)*16], in[(round-1)*16+15]);
	//same key used for encrypting and decrypting
}

void SubBytes(unsigned char *input){
	for (int i=0; i<16; i++){
		input[i] = s[input[i]];
	}
}
void inv_SubBytes(unsigned char *input){
	for (int i=0; i<16; i++){
		input[i] = inv_s[input[i]];
	}
}

void ShiftRows(unsigned char *input){
	unsigned char temp;

	//first 4 bytes remain unchanged
	//row2
	temp = input[4];
	input[4]=input[5];	//6->5
	input[5]=input[6];	//7->6
	input[6]=input[7];	//8->7
	input[7]=temp;		//5->8
	//row3
	temp = input[8];
	input[8]=input[10];	//11->09
	input[10]=temp;		//09->11
	temp = input[9];
	input[9]=input[11];	//12->10
	input[11]=temp;		//10->12
	//row4
	temp = input[15];
	input[15]=input[14];	//15->16
	input[14]=input[13];	//14->15
	input[13]=input[12];	//13->14
	input[12]=temp;			//16->13

}

void inv_ShiftRows(unsigned char *input){
	unsigned char temp;

	//first 4 bytes remain unchanged
	//row2
	temp = input[7];
	input[7]=input[6];	//7->8
	input[6]=input[5];	//6->7
	input[5]=input[4];	//5->6
	input[4]=temp;		//8->5
	//row3
	temp = input[8];
	input[8]=input[10];	//11->09
	input[10]=temp;		//09->11
	temp = input[9];
	input[9]=input[11];	//12->10
	input[11]=temp;		//10->12
	//row4
	temp = input[12];
	input[12]=input[13];//14->13
	input[13]=input[14];//15->14
	input[14]=input[15];//16->15
	input[15]=temp;		//12->16

}

unsigned char gmul(unsigned char a, unsigned char b) {
	unsigned char p = 0;
	unsigned char counter;
	unsigned char hi_bit_set;
	for(counter = 0; counter < 8; counter++) {
		if((b & 1) == 1)
			p ^= a;
		hi_bit_set = (a & 0x80);
		a <<= 1;
		if(hi_bit_set == 0x80)
			a ^= 0x1b;
		b >>= 1;
	}
	return p;
}

void gmix_column(unsigned char *r) {
        unsigned char a[4];
	unsigned char c;
	for(c=0;c<4;c++) {
		a[c] = r[c];
		}
	r[0] = gmul(a[0],2) ^ gmul(a[3],1) ^ gmul(a[2],1) ^ gmul(a[1],3);
	r[1] = gmul(a[1],2) ^ gmul(a[0],1) ^ gmul(a[3],1) ^ gmul(a[2],3);
	r[2] = gmul(a[2],2) ^ gmul(a[1],1) ^ gmul(a[0],1) ^ gmul(a[3],3);
	r[3] = gmul(a[3],2) ^ gmul(a[2],1) ^ gmul(a[1],1) ^ gmul(a[0],3);
}

void inv_mix_column(unsigned char *r) {
        unsigned char a[4];
        unsigned char c;
        for(c=0;c<4;c++) {
                a[c] = r[c];
                }
        r[0] = gmul(a[0],14) ^ gmul(a[3],9) ^ gmul(a[2],13) ^ gmul(a[1],11);
        r[1] = gmul(a[1],14) ^ gmul(a[0],9) ^ gmul(a[3],13) ^ gmul(a[2],11);
        r[2] = gmul(a[2],14) ^ gmul(a[1],9) ^ gmul(a[0],13) ^ gmul(a[3],11);
        r[3] = gmul(a[3],14) ^ gmul(a[2],9) ^ gmul(a[1],13) ^ gmul(a[0],11);
}



void MixColumns(unsigned char *input){
	//column1
	for (int i=0; i<4; i++){test[i]=input[i*4];}
	gmix_column(test);
	for (int i=0; i<4; i++){input[i*4]=test[i];}
	//column2
	for (int i=0; i<4; i++){test[i]=input[i*4+1];}
	gmix_column(test);
	for (int i=0; i<4; i++){input[i*4+1]=test[i];}
	//column3
	for (int i=0; i<4; i++){test[i]=input[i*4+2];}
	gmix_column(test);
	for (int i=0; i<4; i++){input[i*4+2]=test[i];}
	//column4
	for (int i=0; i<4; i++){test[i]=input[i*4+3];}
	gmix_column(test);
	for (int i=0; i<4; i++){input[i*4+3]=test[i];}
}

void inv_MixColumns(unsigned char *input){
	//column1
	for (int i=0; i<4; i++){test[i]=input[i*4];}
	inv_mix_column(test);
	for (int i=0; i<4; i++){input[i*4]=test[i];}
	//column2
	for (int i=0; i<4; i++){test[i]=input[i*4+1];}
	inv_mix_column(test);
	for (int i=0; i<4; i++){input[i*4+1]=test[i];}
	//column3
	for (int i=0; i<4; i++){test[i]=input[i*4+2];}
	inv_mix_column(test);
	for (int i=0; i<4; i++){input[i*4+2]=test[i];}
	//column4
	for (int i=0; i<4; i++){test[i]=input[i*4+3];}
	inv_mix_column(test);
	for (int i=0; i<4; i++){input[i*4+3]=test[i];}
}

string string_to_hex(const string& str_input)
{
    static const char* const lut = "0123456789ABCDEF";
    size_t len = str_input.size();
    string output;
    output.reserve(2 * len);
    for (size_t i = 0; i < len; ++i)
    {
        const unsigned char c = str_input[i];
        output.push_back(lut[c >> 4]);
        output.push_back(lut[c & 15]);
    }
    return output;
}

unsigned char hexval(unsigned char c)
{
    if ('0' <= c && c <= '9')
        return c - '0';
    else if ('a' <= c && c <= 'f')
        return c - 'a' + 10;
    else if ('A' <= c && c <= 'F')
        return c - 'A' + 10;
    else abort();
    return 0;
}

string hex_to_string(const std::string& result)
{
	string out;
	out.clear();
	    out.reserve(result.length() / 2);
	    for (string::const_iterator p = result.begin(); p != result.end(); p++)
	    {
	       unsigned char c = hexval(*p);
	       p++;
	       if (p == result.end()) break; // incomplete last digit - should report error
	       c = (c << 4) + hexval(*p); // + takes precedence over <<
	       out.push_back(c);
	    }
	    return out;


}

string encryption(string message, int en_or_de, int person){
	/*printf("%s \n",message.c_str());
	printf("en_or_de = %i\n",en_or_de);
	printf("person = %i\n",person);*/
	endresult= "";
	string hex_message;

	for (int i=0; i<16; i++){
		if (person == 1){cipher_key[i] = cipher_key_1[i];}	//Sertac
		if (person == 2){cipher_key[i] = cipher_key_2[i];}	//Gerrit
		if (person == 3){cipher_key[i] = cipher_key_3[i];}	//Yvo
		if (person == 5){cipher_key[i] = cipher_key_4[i];}	//JW
	}

//This part turns the message string into a hexadecimal string
if (en_or_de == 0){		//if encrypt, message->hex_message
	hex_message = string_to_hex(message);					//THIS PART FUCKS UP
	message = hex_message;

}

//general part
int number_of_blocks = (message.size()-1)/32+1;
//printf("\n%i, %i\n", (signed)message.size(), number_of_blocks);
string complete_message = message;

for (int i=complete_message.size()-1; (signed)complete_message.size() < 32*number_of_blocks; i++){
	complete_message += "0"; //to fill last block with 0's to make that block 32 characters long
}

for (int i=0; i<number_of_blocks; i++){
//	printf("\nblock number: %i", i);
	for (int j=0; j<32; j++){
		message[j]=complete_message[(i*32)+j];
	}







//this part turns the hexadecimal string into a unsigned char array
	unsigned  int number = 0;
	for (int i=0; i<16; i=i+1){
		sscanf(&message[i*2], "%02x", &number);
		input[i] = (unsigned char)number;
	}


	int number_of_rounds=10;		//excluding initial round, for 128 bit keys this should be 10

	//KeyExpansions
		for (int i=0; i<16; i++){
			in[i] = cipher_key[i];
		}
		expand_key(in);		//EXPANDS KEY USING RIJNDAEL KEY SCHEDULE
/*		printf("Keys: ");
		for (int i=0, j=0, k=0; i<176 && j<11; i++){
			if (k==0){printf("\nRound %i: ", j+1);}
			printf("%X ",in[i]);
			k++;
			if (k==16){j++; k=0;}
		}*/

if (en_or_de == 0){
	/*printf("\nEncrypting: ");
	for (int i=0; i<16; i++){
		if (input[i]<16){printf("0");}
		printf("%X ",input[i]);
	}*/


		//ENCRYPTION//
	int round = 1;

		//InitialRound								//1 initial round
		AddRoundKey(input, round);
		round++;
		//Rounds
		for (int i=0; i<number_of_rounds-1; i++){	//9 normal cycles
			SubBytes (input);
			ShiftRows (input);
			MixColumns (input);
			AddRoundKey(input, round);
			round++;
		}
		//FinalRound								//1 slightly different final cycle
		SubBytes (input);
		ShiftRows (input);
		AddRoundKey(input, round);


		/*printf("\nEncrypted: ");
		for (int i=0; i<16; i++){
			if (input[i]<16){printf("0");}
			printf("%X ",input[i]);
		}*/
}
if (en_or_de == 1){
		//DECRYTION//
	int round=11;

		//inv_FinalRound							//1 inverse final round
		AddRoundKey(input, round);
		inv_ShiftRows (input);
		inv_SubBytes (input);
		round--;
		//inv_Rounds
		for (int i=0; i<number_of_rounds-1; i++){	//9 normal cycles in reverse order
			AddRoundKey(input, round);
			inv_MixColumns (input);
			inv_ShiftRows (input);
			inv_SubBytes (input);
			round--;
		}
		//inv_InitialRound							//1 inverse initial round
		AddRoundKey(input, round);

		/*printf("\nDecrypted: ");
		for (int i=0; i<16; i++){
			if (input[i]<16){printf("0");}
			printf("%X ",input[i]);
		}*/
}


//This part turns the unsigned char array into a 'normal' string
string s;
stringstream stream;
int y;

for (int i=0; i<16; i=i+1){
	s = to_string(input[i]);
	istringstream (s) >> y;
	if (y<16){stream << 0;}
	stream << hex << y;
}
result = (stream.str());


//this turns the hexadecimal string back to readable text
if (en_or_de == 1){
	for (int j=2, i=30; i>0; i=i-2, j=j+2){		// decreases the size of the last packages if possible
		if (result[i]== '0' && result [i+1]== '0'){result.resize(32-j);}
		else break;
	}
	result = hex_to_string(result);
}

//printf("\n end string block: %s", result.c_str());
endresult = endresult + result;
//printf("\n endresult: %s", endresult.c_str());
}

		return endresult;
};


