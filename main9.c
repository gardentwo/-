#include<8051.h>
void delay(unsigned int t)
{
		TH0=-t>>8;
		TL0=-t;
		TF0=0;
		TR0=1;
		while(TF0==0);
		TR0=0;
}
void main()
{
int i;
TMOD=0x1;
while(1){
P0=0;
for(i=0;i<126;i++) delay(1280);
//
P0=128;
for(i=0;i<10;i++)
delay(180);
//2
for(i=128;i<255;i++)
{
P0=i;
delay(1930);
}
//
P0=128;
for(i=0;i<127;i++) delay(1930);
P0=255;
for(i=0;i<17;i++) delay(1280);
for(i=255;i>191;i--){
P0=i;
delay(3600);
				}
P0=0;
for(i=0;i<191;i++) delay(1680);
}
}