
org 100h

; add your code here    


    include emu8086.inc
    printn "Enter Number of input:"
    mov ah,01h
    int 21h
    mov dl,al
    sub dl,48
    
    
    mov cl,dl
    mov bx,0
    input:
    int 21h
    mov [bx],al
    inc bl
    loop input  
    
    
    
    mov cl,bl
    mov bl,0
    mov ah,02h
    mov dl,[bx]
    
    
    
    Min:
    cmp dl,[bx]
    jg Set_min
    level:
    inc bl
    loop Min 
    
    
    jmp finish1
    
    
    Set_min: 
    mov dl,[bx]
    jmp level 
    
    
    
    finish1:    
    printn
    print "minimum value "
    int 21h        
    
    
    
    mov cl,bl
    mov bl,0
    mov dl,[bx]
    
    
    
    Max:
    cmp dl,[bx]
    jl Set_max
    level2:
    inc bl
    loop Max 
    
    
    jmp finish2
    
    
    Set_max: 
    mov dl,[bx]
    jmp level2 
    
    
    
    finish2:    
    printn
    print "maximum value "
    int 21h
    
    mov ah,04ch
    int 21h
    
    
    
    ret




