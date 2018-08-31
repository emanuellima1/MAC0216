# Algumas dicas para lidar com assembly:

### Montagem e Ligação:
> as prog.s -o prog.o   
> ld -o prog prog.o

### Para montar programas de 32bits num Linux 64bits:
> as --32 prog.s -o prog.o  
> ld -melf_i386 -o prog prog.o

### Estrutura geral dos comandos:
> label: mnemônico operando1, operando2 #comentário  

### Mnemônico mov:
Move valores do operando1 para o operando2  
> mov %registrador|(memória)|$constante, %registrador  
> mov %registrador|$constante, (memória)  

### Mnemônico xcgh:
Troca os valores do operando1 pelo do operando2 e vice versa.  
> xcgh %registrador|(memória), %registrador  
> xcgh %registrador, (memória)   

### Mnemônico add:
Soma o valor do operando2 ao valor do operando1, armazenando o resultado no operando1.
> add %registrador|(memória)|$constante, %registrador  

### Mnemônico sub:
Subtrai o valor do operando2 do valor do operando1, armazenando o resultado no operando1.
> sub %registrador|(memória)|$constante, %registrador  

### Mnemônico inc e dec:
Incrementa ou decrementa o valor do operando em 1.
> inc %registrador|(memória)  
> dec %registrador|(memória)   
