.text

.global _start                 # Diz para o ligador que aqui é o ponto de entrada

_start:
        movl  $4, %eax         # Chamada de sistema sys_write
	    movl  $1, %ebx         # stdout
	    movl  $msg, %ecx       # Endereço da mensagem 
	    movl  $len, %edx       # Tamanho da string de mensagem
	    int   $0x80            # Chamada ao kernel

	    movl  $1, %eax         # Chamada de sistema sys_exit
	    movl  $0, %ebx         # Retorna 0 (sucesso)
	    int   $0x80            # Chamada ao kernel


.data
msg: 
        .ascii "Hello, World\n"    # Mensagem e quebra de linha
        len = . - msg              # Tamanho da mensagem
