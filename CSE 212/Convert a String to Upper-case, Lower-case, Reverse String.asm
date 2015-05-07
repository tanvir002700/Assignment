                         
.model small
.stack 100h
.data
.code
main proc
 
    include 'emu8086.inc'
    printn "enter string size: "
    mov ah,01h
    int 21h
    
    printn
    
    mov cl,al
    sub cl,48
    mov bl,0
            
    mov ah,01h         
    input:   
    int 21h
    mov [bx],al 
    inc bl
    cmp bl,cl
    jl input
    
    printn
    printn "output lower to upper/ upper to lower : "
    
    mov bl,0
    output:
    mov dl,[bx]  
    cmp dl,'a'
    jge check1
    
    main1:
    cmp dl,'A'
    jge check2
    
    main2:
    mov ah,02h
    int 21h
    inc bl
    cmp bl,cl
    jl output
    
    
    cmp bl,cl
    je finish
    
    check1:
    cmp dl,'z'
    jle func2
    jmp main1
    
    
    check2:
    cmp dl,'Z'
    jle func1
    jmp main2
    
    func1:
    add dl,32
    jmp main2
    
    func2:
    sub dl,32
    jmp main2
    
    
    finish: 
    
    printn
    printn "Reverse String : "
    mov ah,02h
    mov bl,cl
    dec bl    
    
    rev:    
    mov dx,[bx]
    int 21h
    dec bl
    cmp bl,0
    jge rev
    
    
    
     
    mov ax, 4c00h 
    int 21h
    
    
    ret

main endp
end main



