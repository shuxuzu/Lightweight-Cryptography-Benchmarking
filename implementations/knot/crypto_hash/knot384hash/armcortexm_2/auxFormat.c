#include"auxFormat.h"
void unpackU96FormatToThreePacket(u8 * out, u32 * in) {
	u32 temp0[3] = { 0 };
	u32 temp1[3] = { 0 };
	u32 temp2[3] = { 0 };
	u32 t[3] = { 0 };
	temp0[0] = in[2] & 0x7ff;
	temp0[1] = in[1] & 0x7ff;
	temp0[2] = in[0] & 0x3ff;
	temp1[0] = (in[0]>>10) & 0x7ff;
	temp1[1] = (in[2] >>11 ) & 0x7ff;
	temp1[2] = (in[1] >> 11) & 0x3ff;
	temp2[0] = in[1] >> 21;
	temp2[1] = in[0] >> 21;
	temp2[2] = in[2] >> 22;
	unpuckU32ToThree_1(temp0[0]);
	unpuckU32ToThree_1(temp0[1]);
	unpuckU32ToThree_1(temp0[2]);
	t[0] = temp0[0] | temp0[1] << 1 | temp0[2] << 2;
	unpuckU32ToThree_1(temp1[0]);
	unpuckU32ToThree_1(temp1[1]);
	unpuckU32ToThree_1(temp1[2]);
	t[1] = temp1[0] | temp1[1] << 1 | temp1[2] << 2;
	unpuckU32ToThree_1(temp2[0]);
	unpuckU32ToThree_1(temp2[1]);
	unpuckU32ToThree_1(temp2[2]);
	t[2] = temp2[0] | temp2[1] << 1 | temp2[2] << 2;
	memcpy(out, t, 12 * sizeof(unsigned char));
}

void packU48FormatToThreePacket(u32 * out, u8 * in) {
	u32 t1 = (u32)U16BIG(*(u16*)(in + 4));
	u32 temp0[3] = { 0 };
	u32 temp1[3] = { 0 };
	temp0[0] = U32BIG(((u32*)in)[0]); temp0[1] = U32BIG(((u32*)in)[0]) >> 1; temp0[2] = U32BIG(((u32*)in)[0]) >> 2;
	puckU32ToThree_1(temp0[0]);
	puckU32ToThree_1(temp0[1]);
	puckU32ToThree_1(temp0[2]);
	temp1[0] = t1; temp1[1] = t1 >> 1; temp1[2] = t1 >> 2;
	puckU32ToThree_1(temp1[0]);
	puckU32ToThree_1(temp1[1]);
	puckU32ToThree_1(temp1[2]);
	out[0] =  (temp1[0] << 10) | temp0[2];
	out[1] =  (temp1[2] << 11) | temp0[1];
	out[2] = (temp1[1] << 11) | temp0[0];
}

unsigned char  constant7Format[104] = {
	/*constant7Format[127]:  12*9=108*/
0x01,0x08,0x40,0x02,0x10,0x80,0x05,0x09,0x48,0x42,0x12,0x90,
0x85,0x0c,0x41,0x0a,0x50,0x82,0x15,0x89,0x4d,0x4b,0x5a,0xd2,
0x97,0x9c,0xc4,0x06,0x11,0x88,0x45,0x0b,0x58,0xc2,0x17,0x99,
0xcd,0x4e,0x53,0x9a,0xd5,0x8e,0x54,0x83,0x1d,0xc9,0x4f,0x5b,
0xda,0xd7,0x9e,0xd4,0x86,0x14,0x81,0x0d,0x49,0x4a,0x52,0x92,
0x95,0x8c,0x44,0x03,0x18,0xc0,0x07,0x19,0xc8,0x47,0x1b,0xd8,
0xc7,0x1e,0xd1,0x8f,0x5c,0xc3,0x1f,0xd9,0xcf,0x5e,0xd3,0x9f,
0xdc,0xc6,0x16,0x91,0x8d,0x4c,0x43,0x1a,0xd0,0x87,0x1c,0xc1,
0x0f,0x59,0xca,0x57,0x9b,0xdd,0xce,0x56,};
void P384(unsigned int *s, unsigned char *round, unsigned char lunNum) {
	u32 rci,t1,t2;
	unsigned char  i;
	for (i = 0; i < lunNum; i++) {
		rci=constant7Format[i];
		P384_ARC_SC1(rci,s[3],s[6],s[9]);
		P384_2SC(s[1],s[4],s[7],s[10],s[2],s[5],s[8],s[11]);
		P384_SR();
	}
}
