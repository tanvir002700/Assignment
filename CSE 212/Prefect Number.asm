.model small
.stack 100H
.data
.code
main proc    
        include emu8086.inc
        mov ah,01h ;take input
        int 21h  
        printn
					;Here bx is array in assembly language. And in this programme Array[0] use for save input value
					;And Array[1] index is use for save divisor sum value
					
        mov dl,al 	;move input value al to dl
        sub dl,48 	;make input number character to integer number by subtract 48
        mov bx,0  	;set array index=0
        mov [bx],dl ;save the input number in array 0 index
        mov bx,1	;now index=1
        mov [bx],0	;take array 1 position to 0 for store divisor sum value
        
        
        mov cl,1	;now cl=1 for loop, there cl value is divisor value
        check:		;loop level
        mov bx,0	;now take array index 0, to take input value
        mov dl,[bx] ;take input value to dl from array first element
        cmp cl,dl	;if cl is equal to input value then jump to perfect level. coz in perfect number we take divisor 1<=d<N in range
        je  perfect 
        mov ah,0	;set ah=0 Because previous value can be remove 
        mov al,0	;set al=0
        mov al,[bx] ;take input value to al for division operation
        mov dl,cl 	;take divisor value in dl
        div dl		;division operation, al/dl. division in al and reminder in ah
        cmp ah,0	;compare reminder equal to zero, that means cl is a divisor of input value
        je sum		;then jump to sum level for sum operation
        level:		;return from sum operation
        inc cl		;increment cl value
        jmp check	;jmp above check level for loop complete 
        
        
        perfect:	;here is the level for final checking
        mov bx,1	;increment array index value for take sum value from array
        mov dl,[bx]	;take the sum value to dl
        mov bx,0	;take the index in 0 for take input value
        mov al,[bx] ;take input value in al
        cmp dl,al	;then compare input value == divisor sum, which is condition of perfect number
        je Yes		;if satisfied then jump yes level
        jmp No		;otherwise jump no level
        
        
        
        sum:		
        mov bx,1	;for sum operation array index value take in 1
        add [bx],cl ;add divisor value in array index 1
        jmp level	;then jump above level here he/she came
        
        
        Yes:
            printn "perfect Number" ;if number is perfect
            jmp finish ;then jump finish level
        No:
            printn "not perfect" ;if number is not perfect
        
        finish:
        
        mov ah,04ch
        int 21h

    
main endp

end main