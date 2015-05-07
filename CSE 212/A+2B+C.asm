.model small
.stack 100H
.data 
.code
main proc
    include emu8086.inc
    mov ah,01h
    int 21h 
    print " "
    mov bx,0
    sub al,48
    mov [bx],al
    inc bx
    int 21h 
    printn " "
    sub al,48
    mov [bx],al
    inc bx
    int 21h  
    printn 
    sub al,48
    mov [bx],al
    mov bx,1
    mov al,[bx]
    mov dl,2 
    mul dl
    mov bx,0
    add al,[bx]
    mov bx,2
    add al,[bx]
    mov dl,al
    add dl,48
    mov ah,02h
    int 21h
    
    
    
    
    mov ah,04ch
    int 21h   
    ret
main endp
end main