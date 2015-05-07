.MODEL SMALL
.STACK 100H
.DATA
.CODE
MAIN PROC  
    include emu8086.inc

    mov bx,0     	;set 1st index of array
    mov [bx],0   	;set 1st value of fibonacci series
    inc bx       	;increment array index (1)
    mov [bx],1   	;set 2nd value of fibonacci series
    inc bx       	;increment array index (2)

    fib:         	;level for fibonacci calculate iteration
    mov cx,bx    	;save index value
    dec bx       	;decrement index value to find previous value i-1
    mov dx,[bx]  	;store previous i-1 value in dx
    dec bx       	;decrement index value fo find previous value i-2
    add dx,[bx]  	;add value of i-1th to i-2th
    mov bx,cx    	;move index value cx to bx
    mov [bx],dx  	;store ith value to array 
    inc bx       	;increment index value
    cmp bx,7     	;compair with 7
    jl fib       	;jump condition to complete loop

    mov bx,0     	;set index value 0

    mov ah,02h   	;load print function
    print:       	;level for print calculated fibonacci series
    mov dx,[bx]  	;move array value to data register
    add dx,48    	;add 48 to make value to character
    int 21h      	;print value
    printn
    inc bx       	;increment index
    cmp bx,7     
    jl print     	;jump to level print with condition


    mov ax,4c00h
    int 21h    
    
    ret
MAIN ENDP
END MAIN
