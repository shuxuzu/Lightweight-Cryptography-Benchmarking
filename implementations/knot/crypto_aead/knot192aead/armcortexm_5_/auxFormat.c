
#include"auxFormat.h"
void ROUND384_Three(unsigned int *s, unsigned char  *c,int lunnum) {\
	unsigned int t,t1,t2;
	u32 rci;
	rci=c[0];
	ROUND384_1(rci);
	t = 1;
	while (lunnum--) {
		rci=c[t];
		ROUND384_2(rci);
		t++;
		rci=c[t];
		ROUND384_3(rci);
		t++;
		rci=c[t];
		ROUND384_4(rci);
		t++;
	}
}




void packU96FormatToThreePacket(u32 * out, u8 * in) {
	u32 temp0[3] = { 0 };
	u32 temp1[3] = { 0 };
	u32 temp2[3] = { 0 };
	temp0[0] = U32BIG(((u32*)in)[0]); 
	temp0[1] = U32BIG(((u32*)in)[0]) >> 1; 
	temp0[2] = U32BIG(((u32*)in)[0]) >> 2;
	puckU32ToThree_1(temp0[0]);
	puckU32ToThree_1(temp0[1]);
	puckU32ToThree_1(temp0[2]);
	temp1[0] = U32BIG(((u32*)in)[1]); 
	temp1[1] = U32BIG(((u32*)in)[1]) >>1; 
	temp1[2] = U32BIG(((u32*)in)[1]) >> 2;
	puckU32ToThree_1(temp1[0]);
	puckU32ToThree_1(temp1[1]);
	puckU32ToThree_1(temp1[2]);
	temp2[0] = U32BIG(((u32*)in)[2]); 
	temp2[1] = U32BIG(((u32*)in)[2]) >> 1; 
	temp2[2] = U32BIG(((u32*)in)[2]) >> 2;
	puckU32ToThree_1(temp2[0]);
	puckU32ToThree_1(temp2[1]);
	puckU32ToThree_1(temp2[2]);
	out[0] = (temp2[1]<<21)	|(temp1[0]<<10)	|temp0[2];
	out[1] = (temp2[0] << 21) | (temp1[2] << 11) | temp0[1];
	out[2] = (temp2[2] << 22) | (temp1[1] << 11) | temp0[0];
}
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
	temp0[0] = U32BIG(((u32*)in)[0]); 
	temp0[1] = U32BIG(((u32*)in)[0]) >> 1; 
	temp0[2] = U32BIG(((u32*)in)[0]) >> 2;
	puckU32ToThree_1(temp0[0]);
	puckU32ToThree_1(temp0[1]);
	puckU32ToThree_1(temp0[2]);
	temp1[0] = t1; 
	temp1[1] = t1 >> 1; 
	temp1[2] = t1 >> 2;
	puckU32ToThree_1(temp1[0]);
	puckU32ToThree_1(temp1[1]);
	puckU32ToThree_1(temp1[2]);
	out[0] =  (temp1[0] << 10) | temp0[2];
	out[1] =  (temp1[2] << 11) | temp0[1];
	out[2] = (temp1[1] << 11) | temp0[0];
}
