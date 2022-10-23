.data
array1: .space 40 #array for 2 integers
prompt_input_first: .asciiz "Please enter the first integer: "
prompt_input_second: .asciiz "Please enter the second integer: "
prompt_output_add: .asciiz "The addition result is: "
prompt_output_sub: .asciiz "The subtraction result is: "
prompt_output_mul: .asciiz "The multiplication result is: "
prompt_output_div: .asciiz "The division is: "
next_line: .asciiz "\n"

.text
main:

#prompt first input
la $a0, prompt_input_first
li $v0, 4
syscall

#first integer
li $v0, 5
syscall
la $t0, array1
sw $v0, 0($t0)

#prompt second input
la $a0, prompt_input_second
li $v0, 4
syscall

#second integer
li $v0, 5
syscall
la $t0, array1
sw $v0, 4($t0)

lw $s0, 0($t0)
lw $s1, 4($t0)

#addition result output
la $a0, prompt_output_add
li $v0, 4
syscall

#addition
li $v0, 1
add $a0, $s0, $s1
syscall

#next line
la $a0, next_line
li $v0, 4
syscall

#subtraction result output
la $a0, prompt_output_sub
li $v0, 4
syscall

#subtraction
li $v0, 1
sub $a0, $s0, $s1
syscall

#next line
la $a0, next_line
li $v0, 4
syscall


#multiplicaiton result output
la $a0, prompt_output_mul
li $v0, 4
syscall

#multiplication
li $v0, 1
mul $a0, $s0, $s1
syscall

#next line
la $a0, next_line
li $v0, 4
syscall

#division result output
la $a0, prompt_output_div
li $v0, 4
syscall

#division
li $v0, 1
div $a0, $s0, $s1
syscall

#Exit
li $v0, 10
syscall