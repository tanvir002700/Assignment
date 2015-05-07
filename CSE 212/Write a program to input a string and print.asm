.model small
.stack 100H
.data
.code
main proc    
    
   include emu8086.inc
    printn "size of string: "
    mov ah,01h
    int 21h
    mov cl,al 
    sub cl,'0'
    
    
    printn      
    mov bx,0
    input:  
    int 21h
    mov [bx],al
    inc bx
    dec cl
    cmp cl,0
    jg input
    
           
    printn
    printn "output "
    mov cx,bx
    mov bx,0
    mov ah,02h
    print:
    mov dx,[bx]
    int 21h
    inc bx
    dec cx
    cmp cx,0
    jg print
    
    
    
    
    
    
    mov ax,04CH
    int 21h  
    ret
    
     
main endp
end main