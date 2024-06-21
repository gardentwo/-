#include <8051.h>
void main()
{
int k=0;
int n=0;
unsigned char i,j;
unsigned char massiv [11]=
{
0xC0,
0xC0,
0xF9,
0xA4,
0xB0,
0x99,
0x92,
0x82,
0xF8,
0x80,
0x90,
};
P2=0xFF ;
P1=massiv [11];
P31=1;

do
{
if(i!=10)
{
if(P31==0)
{
i--;

}
else{

i++;

}
}else
{
i=0;
};
P2=massiv[i];
for(j=0;j<100;j++) {