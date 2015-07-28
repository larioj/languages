.section .init
.globl _start
_start:

/* address of the GPIO controller */
ldr r0,=0x20200000

/* enable ouput to the 16th GPIO pin */
mov r1,#1
lsl r1,#18
str r1,[r0,#4]

/* begin the loop */
loop$:

/* set pin to low to turn on light */
mov r1,#1
lsl r1,#16
str r1,[r0,#40]

/* wait for a while */
mov r2,#0x3F0000
wait1$:
sub r2,#1
cmp r2,#0
bne wait1$

/* set pin to high to turn off light */
str r1,[r0,#28]

/* wait again */
mov r2,#0x3F0000
wait2$:
sub r2,#1
cmp r2,#0
bne wait2$

/* go to beggining of loop */
b loop$
