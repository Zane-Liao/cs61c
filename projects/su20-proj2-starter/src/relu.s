.globl relu

.text
# ==============================================================================
# FUNCTION: Performs an inplace element-wise ReLU on an array of ints
# Arguments:
# 	a0 (int*) is the pointer to the array
#	a1 (int)  is the # of elements in the array
# Returns:
#	None
#
# If the length of the vector is less than 1, 
# this function exits with error code 8.
# ==============================================================================
relu:
    # Prologue
    addi sp, sp, -12
    sw ra, 0(sp)
    sw a0, 4(sp)
    sw a1, 8(sp)

    li t0, 0

loop_start:
    bge t0, a1, loop_end     
    lw t1, 0(a0)

    blt t1, zero, set_zero

    j loop_continue

set_zero:
    sw zero 0(a0)

loop_continue:
    addi a0, a0, 4
    addi t0, t0, 1
    j loop_start

loop_end:
    lw ra, 0(sp)
    lw a0, 4(sp)
    lw a1, 8(sp)
    addi sp, sp, 12
    # Epilogue

    
	ret 