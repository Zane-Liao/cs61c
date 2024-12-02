.globl argmax

.text
# =================================================================
# FUNCTION: Given a int vector, return the index of the largest
#	element. If there are multiple, return the one
#	with the smallest index.
# Arguments:
# 	a0 (int*) is the pointer to the start of the vector
#	a1 (int)  is the # of elements in the vector
# Returns:
#	a0 (int)  is the first index of the largest element
#
# If the length of the vector is less than 1, 
# this function exits with error code 7.
# =================================================================
argmax:

    # Prologue
    # addi sp, sp, -12
    # sw ra, 0(sp)
    # sw a0, 4(sp)
    # sw a1, 8(sp)

    lw t1, 0(a0) # Maxvalue[t1]
    li t2, 0 # The index after each update
    li t0, 1 # Starting index for updating

loop_start:
    bge t0, a1, loop_end

    slli t3, t0, 2 # t0 * 4, Update Index
    add t3, t3, a0 # Updated Index Address
    lw t4, 0(t3) # Updated Value

    blt t4, t1, loop_continue

update_index_element:
    mv t1, t4
    mv t2, t0

loop_continue:
    # addi a0, a0, 4
    addi t0, t0, 1
    j loop_start

loop_end:
    mv a0, t2
    # lw ra, 0(sp)
    # lw a0, 4(sp)
    # lw a1, 8(sp)
    # addi sp, sp, 12
    
    # Epilogue


    ret