.data
First_Name: .space 255
reverse_First_Name: .space 255
Last_Name: .space 255
reverse_Last_Name: .space 255
help: .asciiz "Please press enter to seperate First_Name and Last_Name inputs!\n"
input_name: .asciiz "Please input yout full name (First_Name Last_Name):\n"
output_reverse: .asciiz "Output: "
space: .asciiz " "

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

	#Input Last Name
li $v0, 8       	# take in input
la $a0, Last_Name  	# load byte space into address
li $a1, 255      	# allot the byte space for string
syscall

li $t1, 0
li $t5, 0

	#First Name reverse
first_name_length:
lbu $t0, First_Name($t1)
beqz $t0, first_name_end
addu $t1, $t1, 1
j first_name_length

first_name_end: 
li $t2, 0
addi $t1, $t1, -1

first_name_reverse:
blt $t1, $zero, first_name_done
lb $t3, First_Name($t1)
sb $t3, reverse_First_Name($t2)
sub $t1, $t1, 1
add $t2, $t2, 1
j first_name_reverse

first_name_done:
sb $zero, reverse_First_Name($t2)

	#Last Name reverse
last_name_length:
lbu $t4, Last_Name($t5)
beqz $t4, last_name_end
addu $t5, $t5, 1
j last_name_length

last_name_end: 
li $t6, 0
addi $t5, $t5, -1

last_name_reverse:
blt $t5, $zero, last_name_done
lb $t7, Last_Name($t5)
sb $t7, reverse_Last_Name($t6)
sub $t5, $t5, 1
add $t6, $t6, 1
j last_name_reverse

last_name_done:
sb $zero, reverse_Last_Name($t6)

	#Print output
la $a0, output_reverse
li $v0, 4
syscall

	#Output First name
la $a0, reverse_First_Name
li $v0, 4
syscall

	#Output Last name
la $a0, reverse_Last_Name
li $v0, 4
syscall

	#End
li $v0, 10
syscall