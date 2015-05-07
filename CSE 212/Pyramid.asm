.model small
.stack 100H
.data 
.code
main proc
    include emu8086.inc
    mov ah,01h
    int 21h     
    printn
    sub al,48
    mov dl,1
    
    row:
    
        
        mov cl,al
        sub cl,dl
        mov bl,1
        space:
            cmp bl,cl
            jg next
            print " " 
            inc bl
            
        jmp space
        
        
        next:
        
        mov cl,1
        mov bl,dl
        add bl,bl
        dec bl
        star:        
            print "*" 
            inc cl
            cmp cl,bl
        jle star   
        
        
        printn
            
    
    
    inc dl
    cmp dl,al
    jle row
    
    
    mov ah,04ch
    int 21h   
    ret
main endp
end main