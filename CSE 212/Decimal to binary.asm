
org 100h

include emu8086.inc  
mov ah,01h
int 21h
sub al,48
mov ah,0

 
mov bx,0
bin:  
mov dl,2
mov ah,0
div dl

mov dl,al
mov al,ah
mov ah,0
mov [bx],ax
inc bl
mov al,dl
cmp al,0
jne bin



mov ah,02h
mov cl,bl
dec bl

printn 
printn "Binary number: " 
print:
mov dl,[bx]  
add dl,48
int 21h    
dec bl
loop print


mov ah,04ch
int 21h



ret




