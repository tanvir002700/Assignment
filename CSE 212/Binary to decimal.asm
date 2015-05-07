
org 100h

; add your code here  
include emu8086.inc
mov ah,01h   
mov bl,0

input:
int 21h
cmp al,13
je level
mov [bx],al
inc bl
jmp input



level:
printn
mov ax,0
mov cl,bl
mov bl,0

deci: 
mov dl,2
mul dl
mov dl,[bx]
sub dl,48
add ax,dx
inc bl
loop deci

mov dx,ax
add dx,48
mov ah,02h
int 21h  


mov ah,04ch
int 21h


ret




