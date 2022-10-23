.text
main:

#printing the prompt of "Please enter the element\n"
la $a0, prompt_input_element #load address of "prompt_input_element" to a0
li $v0, 4 #li: load integer, set v0 as 4 for output string function in syscall
syscall

#taking the input
li $v0, 5 #v0=5 for input integer fuction in syscall
syscall

#move the input integer to the array
la $t0, list #la: load address, loading the begining address of list in $t0
sw $v0, 0($t0) #store the input integer to the begining address of list

#the following instructions print the string of "The element(s) in the array is:\n"
la $a0, prompt_output_element #load address of the defined string "prompt_output_element" to a0
li $v0, 4 #set v0 as 4 for output string function in syscall
syscall

#the follwing instructions for printing the element
la $t0, list #loading the address of list to $t0
output_element: #lable for output-poop in multiple-elements array
lw $a0, 0($t0) #load the first element to a0
li $v0, 1 #set v0=1 for print integer function in syscall
syscall

li $v0, 10 #v0=10, exit function
syscall

.data
list: .space 100 #maximum size of list is 25, you can change this definition
size: .word 0
dataflag1: .word 0x12345678
charflag1: .ascii "abc"
dataflag4: .word 0x22227890
prompt_input_size: .asciiz "Please enter the size of the list:\n"
prompt_input_element: .asciiz "Please enter the element\n"
dataflag2: .word 0x88881111
Input: .space 20 #Allocate 20 bytes of storage for the input string
dataflag3: .word 0x99996666
prompt_output_element: .asciiz "The element(s) in the array is:\n"
daraflag5: .word 0x00400048
