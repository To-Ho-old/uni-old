.data
.align 2
list:.space 200 #maximum size of list is 50, you can change this definition
size: .word 0 
min: .word 0
max: .word 0
space: .asciiz " "
prompt_input_size: .asciiz "Please enter the size of the list: \n"
prompt_input_element: .asciiz "Enter element(s): \n"
prompt_output_element: .asciiz "The element(s) in array is:\n"
prompt_max_element: .asciiz "\nThe maximum is: "
prompt_min_element: .asciiz "\nThe minimum is: "
#----------------------------------------------------------------------

.text
main:

la $s0, list
la $s1, 0				#use this for the max array size
la $s2, 0				#max
la $s3, 1000				#min
li $t1, 0				#initialize to 0 for index
li $t0, 0


#Prompt for array size
la $a0, prompt_input_size
li $v0, 4
syscall

li $v0, 5
syscall

la $a0, prompt_input_element 		#load address of "prompt_input_element" to a0
li $v0, 4 				#li: load integer, set v0 as 4 for output string in syscall
syscall

la $s1, size
sw $v0, 0($s1)
move $s1, $v0

input_loop:
bge $t1, $s1, prep

li $v0, 5 				#v0 = 5 for input integer function in syscall
syscall
sw $v0, list($t0)
add $t0, $t0, 4
add $t1, $t1, 1
j input_loop


prep:
li $t0, 0
li $t1, 0


find_minmax:
bge $t1, $s1, print_prompt

lw $t5, list($t0)

bge $t5, $s3, skip_min			#if greater than current min, then skip assignment
move $s3, $t5
skip_min:
blt $t5, $s2, skip_max			#if less than current max, then skip assignment
move $s2, $t5
skip_max:
la $t5, space
li $v0, 4                 		#print space between each output
syscall

add $t1, $t1, 1				#increment counter for next element
add $t0, $t0, 4
j find_minmax




print_prompt:
li $t1, 0				#set back to 0 before next loop
la $a0, prompt_output_element
li $v0, 4
syscall




print_loop:
bge $t1, $s1, print_minmax
lw $a0, 0($s0)            		#get the value pointed by s0
li $v0, 1                 		#print int
syscall
  	
la $a0, space
li $v0, 4                 		#print space between each output
syscall

addi $t1, $t1, 1			#increment counter for next element
addi $s0, $s0, 4
j print_loop




#prompt_max_element
print_minmax:
la $a0, prompt_max_element 		#load address of "prompt_max_element" to a0
li $v0, 4
syscall

move $a0, $s2
li $v0, 1
syscall

#prompt_min_element
la $a0, prompt_min_element 		#load address of "prompt_min_element" to a0
li $v0, 4
syscall

move $a0, $s3
li $v0, 1
syscall



exit:
li $v0, 10 #v0=10, exit function 
syscall

