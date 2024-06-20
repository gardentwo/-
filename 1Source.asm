.686
.model flat,stdcall
.stack 100h
.data
X dw 121;
Y dw 35;
Z dw 4 ;
F dw 5; /*умножение числа на Z 5*/
D dw 1; /*Число для инверсии 4 старших бит в числе 9*/
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
MOV REZ, ax; /*передача результата в переменную REZ*/
exit:
Invoke ExitProcess, REZ; /*вывод результатат на экран*/
End Start