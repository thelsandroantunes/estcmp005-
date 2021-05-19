section .data ;Constants variables section

    msg3 db "", 0xA, 0xD
    len_msg3 equ $ - msg3

section .bss
    num1 resb 6 
    num2 resb 6
    num_greater resb 6

section .text ;Code section
    global _start

    _start:        
             
        mov edx, 8 
        mov ecx, num1
        mov ebx, 0 
        mov eax, 3 
        int 0x80   
          
        mov edx, 8 
        mov ecx, num2
        mov ebx, 0 
        mov eax, 3 
        int 0x80   

        mov eax, [num1] 
        
        mov ebx, [num2] 
        
        cmp eax, ebx ;is eax > ebx?
        jg _exit     ;if yes, jump to _exit
        mov eax, ebx ;if no, moves ebx content into eax

        
        _exit:

            
            mov   [num_greater], eax 
            
            
            mov   edx, len_msg3
            mov   ecx, msg3
            mov   ebx, 1	
            mov   eax, 4	
            int   0x80	
                
            
            mov   edx, 8 
            mov   ecx, num_greater
            mov   ebx, 1
            mov   eax, 4
            int   0x80	

           
            mov   eax, 1
            int   0x80 
