.686
.model flat,stdcall
.stack 100h
.data
X dw 121;
Y dw 35;
Z dw 4 ;
F dw 5; /*��������� ����� �� Z 5*/
D dw 1; /*����� ��� �������� 4 ������� ��� � ����� 9*/
Rez dw ?;
.code
ExitProcess PROTO STDCALL :DWORD
Start:
mov ax,X;
mov bx,Y;
mov cx,Z;
IMUL cx,5;
XOR ax,1;
XOR bx,1;
AND ax,bx;
ADD ax,cx;
MOV REZ, ax; /*�������� ���������� � ���������� REZ*/
exit:
Invoke ExitProcess, REZ; /*����� ����������� �� �����*/
End Start