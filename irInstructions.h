#ifndef IR_INSTRUCTIONS_H
#define IR_INSTRUCTIONS_H

#include "kittyir.h"

IR_INSTRUCTION *make_instruction_movl(ARGUMENT *arg1, ARGUMENT *arg2);
IR_INSTRUCTION *make_instruction_cmp(ARGUMENT *arg1, ARGUMENT *arg2);
IR_INSTRUCTION *make_instruction_call(ARGUMENT *arg1, ARGUMENT *arg2);
IR_INSTRUCTION *make_instruction_pushl(ARGUMENT *arg1, ARGUMENT *arg2);
IR_INSTRUCTION *make_instruction_jmp(char *);
IR_INSTRUCTION *make_instruction_jne(char *);
IR_INSTRUCTION *make_instruction_popl();
IR_INSTRUCTION *make_instruction_addl(ARGUMENT *arg1, ARGUMENT *arg2);
IR_INSTRUCTION *make_instruction_subl(ARGUMENT *arg1, ARGUMENT *arg2);
IR_INSTRUCTION *make_instruction_xor(ARGUMENT *arg1, ARGUMENT *arg2);
IR_INSTRUCTION *make_instruction_div(ARGUMENT *arg1, ARGUMENT *arg2);
IR_INSTRUCTION *make_instruction_mul(ARGUMENT *arg1, ARGUMENT *arg2);
IR_INSTRUCTION *make_instruction_globl(ARGUMENT *arg1, ARGUMENT *arg2);
IR_INSTRUCTION *make_instruction_string(ARGUMENT *arg1);
IR_INSTRUCTION *make_instruction_ret();


ARGUMENT *make_argument_address();
ARGUMENT *make_argument_register(REGISTERS reg, char *name);
ARGUMENT *make_argument_label(char *);
ARGUMENT *make_argument_constant(int i);
ARGUMENT *make_argument_temp(int i);
ARGUMENT *make_argument_tempregister(int i);

#endif