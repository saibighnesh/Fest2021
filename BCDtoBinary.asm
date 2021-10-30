DATA SEGMENT                           
    BCD DB 58H  
    BINA DB 3 DUP<0>
DATA ENDS                              
CODE SEGMENT                           
    ASSUME CS:CODE, DS:DATA            
    START:                             
    MOV AX,DATA              
    MOV DS,AX                          
    MOV AH,BCD          ;LOAD THE BCD NUMBER TO AH                
    MOV BH,AH           ;MOVE THE VALUE OF AH TO BH                
    AND BH,0FH          ;AND BH WITH 0FH TI KEEP THE LAST 4 BITS                
    AND AH,0F0H         ;AND AH WITH F0H TO KEEP THE FIRST 4 BITS                
    ROR AH,04           ;ROTATE RIGHT AH 4 TIMES                 
    MOV CL,10           ;LOAD CL WITH 10                  
    MOV AL,AH           ;MOVE THE VALUE OF AH TO AL              
    AND AX,00FFH        ;AND AX WITH 00FFH TO KEEP THE LAST 8 BITS           
    MUL CL              ;MULTIPLY AX WITH CL              
    ADD AL,BH           ;ADD BH TO AL               
    MOV BINA,AL         ;MOVE THE VALUE OF AL TO BINA VARIABLE 
    MOV AH,4CH 
    INT 21H 
    CODE ENDS 
END START
