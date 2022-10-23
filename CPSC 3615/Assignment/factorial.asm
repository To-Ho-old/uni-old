.data
input_integer: .asciiz "Please enter an integer: "
input_invalid: .asciiz "The integer is invalid!"
output_result: .asciiz "The factorial is: "
new_line: .asciiz "\n"

.text
main:

li $s1, 1 #result
li $s2, 0 #0
li $s3, 12 #12

#print input
la $a0, input_integer
li $v0, 4
syscall

li $v0, 5
syscall
move $s0, $v0 #s0: input integer

#if function for invalid input
blt $s0, $s2, invalid_input
bgt $s0, $s3, invalid_input

factorial_loop:
beq $s0, $s2, print_result
mul $s1, $s1, $s0
addi $s0, $s0, -1

j factorial_loop

invalid_input:
la $a0, input_invalid
li $v0, 4
syscall

j exit

print_result:
#print output
la $a0, output_result
li $v0, 4
syscall

li $v0, 1
move $a0, $s1
syscall

exit:
li $v0, 10
syscall