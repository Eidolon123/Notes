[BITS 16]
[ORG 0x7C00]
top:
        ;; Put 0 into ds (data segment)
        ;; Can't do it directly
        mov ax,0x0000
        mov ds,ax
        ;; si is the location relative to the data segment of the
        ;; string/char to display
        mov cl,5 ; mov 20 into the register ch
        mov dl,1
        call Tree
        jmp $ ; Spin

Tree:
        mov dh, dl
        mov ch, cl
        call spaceLoop
        call dotsLoop
        mov si, cr
        call writeString
        dec cl
        add dl,2
        cmp cl,0
        jne Tree
        mov cl, 5
        mov dl, 2
        call Trunk

spaceLoop:
        mov si, space
        call writeString
        dec ch
        cmp ch,0
        jne spaceLoop
        ret


dotsLoop:
        mov si, dot ; print the dot
        call writeString ; See below
        dec dh ; reduce what is in ch by 1
        cmp dh, 0 ; compare to see if what is store in ch is 0
        jne dotsLoop ; if ch does not contain 0 call dotsLoop again.
        ret ; when ch contains 0 return back to main code

Trunk:
        mov ch, cl
        call TrunkSpace
        mov si, dot
        call writeString
        mov si, cr
        call writeString
        dec dl
        cmp dl,0
        jne Trunk
        ret

TrunkSpace:
        mov si, space
        call writeString
        dec ch
        cmp ch,0
        jne spaceLoop
        ret


writeString:
        mov ah,0x0E ; Display a chacter (as before)
        mov bh,0x00
        mov bl,0x07

nextchar:
        Lodsb ; Loads [SI] into AL and increases SI by one
        ;; Effectively "pumps" the string through AL
        cmp al,0 ; End of the string?
        jz done
        int 0x10 ; BIOS interrupt
        jmp nextchar
done:
        ret
        space db ' ',0
        dot db '*',0
        cr db 13,10,0
        times 510-($-$$) db 0
        dw 0xAA55
