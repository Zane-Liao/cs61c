.globl dot

.text
# =======================================================
# FUNCTION: Dot product of 2 int vectors
# Arguments:
#   a0 (int*) is the pointer to the start of v0
#   a1 (int*) is the pointer to the start of v1
#   a2 (int)  is the length of the vectors
#   a3 (int)  is the stride of v0
#   a4 (int)  is the stride of v1
# Returns:
#   a0 (int)  is the dot product of v0 and v1
#
# If the length of the vector is less than 1, 
# this function exits with error code 5.
# If the stride of either vector is less than 1,
# this function exits with error code 6.
# =======================================================
dot:

    # Prologue

    lw t0, 0(a0)
    lw t1, 0(a0)
    li t2, 1
    li t3, 0

loop_start:
    bge t2, a2, loop_end

    mul t3, t2, a3
    add a0, a0, t3

update_element:
    mul t4, t0, t1
    add t0, t0, t4
    addi t2, t2, 1
    j loop_start


loop_end:
    mv a0, t0

    # Epilogue

    
    ret