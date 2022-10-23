.data
First_Name: .space 255
reverse_First_Name: .space 255
Last_Name: .space 255
reverse_Last_Name: .space 255
help: .asciiz "Please press enter to seperate First_Name and Last_Name inputs!\n"
input_name: .asciiz "Please input yout full name (First_Name Last_Name):\n"
output_reverse: .asciiz "Output: "
space: .asciiz " "
nothing: .asciiz "HAHSHDH"
.text
main:

	#Print Help
la $a0, help
li $v0, 4
syscall

	#Prompt user input
la $a0, input_name
li $v0, 4
syscall

	#Input First name
li $v0, 8       	# take in input
la $a0, First_Name  	# load byte space into address
li $a1, 255      	# allot the byte space for string
syscall
move $t0, $a0

loop:
beq $t0, space, print
addi $t0, $t0, 1
j loop

la $a0, nothing
li $v0, 4
syscall 

print:
la $a0, output_reverse
li $v0, 4
syscall


	#End
li $v0, 10
syscall