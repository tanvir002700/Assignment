.model small
.stack 100H
.data 
.code
main proc
    include emu8086.inc
    
    mov ah,01h
    int 21h 
    printn
    mov bx,0  
    sub al,'0'
    mov [bx],al
    mov dl,2
    check:       
    cmp dl,[bx]
    je prime
    mov ah,0
    mov al,[bx]
    div dl
    cmp ah,0
    je not_prime
    inc dl
    jmp check
    
    
    prime:
    printn "Prime Number"
    jmp finish
    not_prime: 
    mov ah,02h
    printn "Not Prime Number"
    finish:
    mov ah,04ch
    int 21h   
    ret
main endp
end main