.data
list:.space 20 #maximum size of list is 5, you can change this definition 
size:.word 5
min: .word 0
max: .word 0
space: .asciiz " "
#prompt_input_size: .asciiz "please enter size of the list: \n"
prompt_input_element: .asciiz "please enter the element\n"
prompt_output_element: .asciiz "The Element(s) in array is:\n"
prompt_max_element: .asciiz "\nThe Maximum is: "
prompt_min_element: .asciiz "\nThe Minimum is: "



.text
main:

la $s0, list
li $t1, 0			#initialize to 0 for index



input_loop:
bge $t1, 5, print_prompt
#printing the prompt of " Please enter the element\n"
la $a0, prompt_input_element 	#load address of "prompt_input_element" to a0
li $v0, 4 			#li: load integer, set v0 as 4 for output string in syscall
syscall

li $v0, 5 			#v0 = 5 for input integer function in syscall
syscall
sw $v0, list($t0)
sw $v0, max			#store last inputs to max/min for testing
sw $v0, min
add $t0, $t0, 4
add $t1, $t1, 1
j input_loop


print_prompt:
li $t1, 0				#set back to 0 before next loop
#load address of "prompt_output_element" to a0
la $a0, prompt_output_element
li $v0, 4
syscall


print_loop:
bge $t1, 5, print_minmax
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
la $a0, prompt_max_element 	#load address of "prompt_max_element" to a0
li $v0, 4
syscall

lw $a0, max
li $v0, 1
syscall

#prompt_min_element
la $a0, prompt_min_element 	#load address of "prompt_min_element" to a0
li $v0, 4
syscall

lw $a0, min
li $v0, 1
syscall



exit:
li $v0, 10 #v0=10, exit function 
syscall
