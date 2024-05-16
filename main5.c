#include <8051.h>

const unsigned char key_tab[5] = {0x1E, 0x1D, 0x1B, 0x17,0x0F};
unsigned int scan_key();
void Write(unsigned char data, unsigned char position);
void wait();

int main()
{
unsigned char num[26] = {' ', '1', '2', '3','D','/', '4', '5', '6','E','*','7', '8', '9', 'F','-' ,'A', 'B', 'C','G','+','Z', 'X', 'V',',','.'};
unsigned int ix;
unsigned char position = 0;
ix = 0;
P1 = 0xFF;
P3 = 0xFF;
P0 = 0x80;
P2 = 0x1;
P2 = 0x0;

while(1)
{
ix = scan_key();
if (ix != 0)
{
Write(num[ix], position);
position++;
if (position >= 8)
position = 0;
}
}
}

unsigned int scan_key()
{
unsigned int i;
unsigned int key_value;
key_value = 0;

for(i = 0; i < 5; i++)
{
wait();
P1 = key_tab[i];

switch (P3)
{
case 0xFE:

key_value = 1 + i * 5;
return (key_value);
case 0xFD:
key_value = 2 + i * 5;

return (key_value);
case 0xFB:
key_value = 3 + i * 5;

return (key_value);
case 0xF7:
key_value = 4 + i * 5;

return (key_value);
case 0xEF:
key_value = 5 + i * 5;

return (key_value);
default:
break;
}
}

return (key_value);
}

void Write(unsigned char data, unsigned char position)
{
P0 = 0x80 | position;
P2 = 0x2;
P2 = 0x0;

P0 = data;
P2 = 0x3;
P2 = 0x2;
}
void wait(){
int j;
for(j=0;j<5;j++)
{
continue;
}
}