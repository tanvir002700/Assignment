
org 100h 
include emu8086.inc

; add your code here 

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



printn "Output ----- ----- ----- "


mov cl,bl
dec bl

mov ah,0
mov al,[bx]
sub al,48
mov dl,2 
div dl   
cmp ah,0 
jne not_div_by_2
printn "divide by 2"
jmp end_of_testing_2
not_div_by_2:
printn "not divide by 2"
end_of_testing_2:


mov ax,0
mov bl,0
testing_3:
mov dx,[bx]
sub dx,48
add ax,dx
inc bl
cmp bl,cl
jl  testing_3

          
mov dx,ax
mov al,dl

mov ah,0
mov dl,3 
div dl   
cmp ah,0 
jne not_div_by_3
printn "divide by 3"
jmp end_of_testing_3
not_div_by_3:
printn "not divide by 3"
end_of_testing_3:


mov bl,cl
sub bl,2
mov ax,0
cmp bl,0
jl step1
mov ax,[bx]
sub ax,48
step1: 
inc bl
mov dx,10
mul dx 
mov dx,[bx]
sub dx,48
add ax,dx



mov dx,ax
mov al,dl

mov ah,0
mov dl,4 
div dl   
cmp ah,0 
jne not_div_by_4
printn "divide by 4"
jmp end_of_testing_4
not_div_by_4:
printn "not divide by 4"
end_of_testing_4: 




mov bl,cl
dec bl
mov al,[bx]
cmp al,'5'
je divide_by_5
cmp al,'0'
je divide_by_5
printn "not divide by 5"
jmp finish
divide_by_5:
printn "divide by 5"

finish:

mov ah,04ch
int 21h

ret




