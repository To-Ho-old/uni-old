.text
main:

#input the size of the list
la $a0, prompt_input_size
li $v0, 4
syscall

li $v0, 5
syscall

#copy the size from v0 to the variable size
la $t0, size
sw $v0, 0($t0)
move $a1, $v0

#input the elements of the list
li $s1, 0
la $t0, list
li $t2, 0

input_loop:
addi $s1, $s1, 1
bgt $s1, $a1, end_input_loop

#printing the prompt of "Please enter the element\n
la $a0, prompt_input_element
li $v0, 4
syscall

#taking the input
li $v0, 5
syscall

add $t3, $t0, $t2
sw $v0, 0($t3)
addi $t2, $t2, 4

j input_loop

#move the input integer to the array
la $t0, list
sw $v0, 0($t0)

end_input_loop:
li $v0, 10
syscall

#print "The element(s) in the array is:\n"
li $s1, 0
la $a0, prompt_output_element
li $v0, 4
syscall

#print the elements in the list
la $t0, size
move $a1, $t0

li $s1, 0
la $t0, list
li $t2, 0

output_loop:
addi $s1, $s1, 1
bgt $s1, $a1, end_output_loop

#printing the element
add $t3, $t0, $t2
move $a0, $t3 #load the current element from address of t3 to a0

li $v0, 1 #syscall to print integer
syscall

#print space
la $a0, prompt_space
li $v0, 4
syscall

addi $t2, $t2, 4

j output_loop

end_output_loop:
li $v0, 10
syscall





.data
list:.space 20 #maximum size of list is 5, you can change this definition 
size: .word 0
min: .word 0
max: .word 0
space: .asciiz " "
prompt_input_size: .asciiz "please enter size of the list: \n"
prompt_input_element: .asciiz "please enter the element\n"
prompt_output_element: .asciiz "The Element(s) in array is:\n"
prompt_space: .asciiz " "

