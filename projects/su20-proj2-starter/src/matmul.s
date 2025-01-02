.globl matmul

.text
# =======================================================
# FUNCTION: Matrix Multiplication of 2 integer matrices
# 	d = matmul(m0, m1)
#   The order of error codes (checked from top to bottom):
#   If the dimensions of m0 do not make sense, 
#   this function exits with exit code 2.
#   If the dimensions of m1 do not make sense, 
#   this function exits with exit code 3.
#   If the dimensions don't match, 
#   this function exits with exit code 4.
# Arguments:
# 	a0 (int*)  is the pointer to the start of m0 
#	a1 (int)   is the # of rows (height) of m0
#	a2 (int)   is the # of columns (width) of m0
#	a3 (int*)  is the pointer to the start of m1
# 	a4 (int)   is the # of rows (height) of m1
#	a5 (int)   is the # of columns (width) of m1
#	a6 (int*)  is the pointer to the the start of d
# Returns:
#	None (void), sets d = matmul(m0, m1)
# =======================================================
matmul:

    # Error checks
    ble a1, zero, exit_92
    ble a2, zero, exit_92
    ble a4, zero, exit_93
    ble a5, zero, exit_93
    bne a2, a4, exit_94
    # Prologue
    li t0, 0
    li t1, 0
    li t2, 0
    li s0, 0


outer_loop_start:
    blt t0, a1, outer_loop_end
    j inner_loop_start

inner_loop_start:
    lw s1, 0(a2)
    lw s2, 0(a5)
    lw s3, 0(a0)
    lw s4, 0(a3)
    lw s5, 0(a6)

    jal ra dot
    mv s5, a0

    blt t1, a5, inner_loop_end

inner_loop_end:
    mul t3, s1, t0
    add t3, t1, t3
    slli t3, t3, 2
    add t3, t3, s3

    lw a6, 0(t3)

    j outer_loop_start


outer_loop_end:
    mv a0, s5
    # Epilogue
    
    
    ret

exit_92:
    li a1, 2
    j exit2

exit_93:
    li a1, 3
    j exit3

exit_94:
    li a1, 4
    j exit4