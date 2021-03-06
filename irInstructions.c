#include "irInstructions.h"
#include <stdlib.h>
#include <string.h>

IR_INSTRUCTION *make_instruction_movl(ARGUMENT *arg1, ARGUMENT *arg2) {
	IR_INSTRUCTION *new_instruction;
	new_instruction = NEW(IR_INSTRUCTION);
	new_instruction->id = 0;
	new_instruction->op_code = movl;
	new_instruction->arg1 = arg1;
	new_instruction->arg2 = arg2;
	return new_instruction;
}

IR_INSTRUCTION *make_instruction_cmp(ARGUMENT *arg1, ARGUMENT *arg2) {
	IR_INSTRUCTION *new_instruction;
	new_instruction = NEW(IR_INSTRUCTION);
	new_instruction->id = 0;
	new_instruction->op_code = cmp;
	new_instruction->arg1 = arg1;
	new_instruction->arg2 = arg2;
	return new_instruction;
}

IR_INSTRUCTION *make_instruction_jne(char *c) {
	IR_INSTRUCTION *new_instruction;
	new_instruction = NEW(IR_INSTRUCTION);
	new_instruction->id = 0;
	new_instruction->op_code = jne;
	new_instruction->label = calloc(strlen(c)+1,sizeof(char));
	new_instruction->label = c;
	return new_instruction;
}

IR_INSTRUCTION *make_instruction_intcode(char *c) {
	IR_INSTRUCTION *new_instruction;
	new_instruction = NEW(IR_INSTRUCTION);
	new_instruction->id = 0;
	new_instruction->op_code = intCode;
	new_instruction->label = calloc(strlen(c)+1,sizeof(char));
	new_instruction->label = c;
	return new_instruction;
}

IR_INSTRUCTION *make_instruction_notl(ARGUMENT *arg1) {
	IR_INSTRUCTION *new_instruction;
	new_instruction = NEW(IR_INSTRUCTION);
	new_instruction->id = 0;
	new_instruction->op_code = notl;
	new_instruction->arg1 = arg1;
	return new_instruction;
}

IR_INSTRUCTION *make_instruction_negl(ARGUMENT *arg1) {
	IR_INSTRUCTION *new_instruction;
	new_instruction = NEW(IR_INSTRUCTION);
	new_instruction->id = 0;
	new_instruction->op_code = negl;
	new_instruction->arg1 = arg1;
	return new_instruction;
}

IR_INSTRUCTION *make_instruction_jmp(char *c) {
	IR_INSTRUCTION *new_instruction;
	new_instruction = NEW(IR_INSTRUCTION);
	new_instruction->id = 0;
	new_instruction->op_code = jmp;
	new_instruction->label = calloc(strlen(c)+1,sizeof(char));
	new_instruction->label = c;
	return new_instruction;
}

IR_INSTRUCTION *make_instruction_JGE(char *c) {
	IR_INSTRUCTION *new_instruction;
	new_instruction = NEW(IR_INSTRUCTION);
	new_instruction->id = 0;
	new_instruction->op_code = JGE;
	new_instruction->label = calloc(strlen(c)+1,sizeof(char));
	new_instruction->label = c;
	return new_instruction;
}

IR_INSTRUCTION *make_instruction_JLE(char *c) {
	IR_INSTRUCTION *new_instruction;
	new_instruction = NEW(IR_INSTRUCTION);
	new_instruction->id = 0;
	new_instruction->op_code = JLE;
	new_instruction->label = calloc(strlen(c)+1,sizeof(char));
	new_instruction->label = c;
	return new_instruction;
}

IR_INSTRUCTION *make_instruction_jl(char *c) {
	IR_INSTRUCTION *new_instruction;
	new_instruction = NEW(IR_INSTRUCTION);
	new_instruction->id = 0;
	new_instruction->op_code = jl;
	new_instruction->label = calloc(strlen(c)+1,sizeof(char));
	strcpy(new_instruction->label,c);
	return new_instruction;
}

IR_INSTRUCTION *make_instruction_jg(char *c) {
	IR_INSTRUCTION *new_instruction;
	new_instruction = NEW(IR_INSTRUCTION);
	new_instruction->id = 0;
	new_instruction->op_code = jg;
	new_instruction->label = calloc(strlen(c)+1,sizeof(char));
	new_instruction->label = c;
	return new_instruction;
}

IR_INSTRUCTION *make_instruction_je(char *c) {
	IR_INSTRUCTION *new_instruction;
	new_instruction = NEW(IR_INSTRUCTION);
	new_instruction->id = 0;
	new_instruction->op_code = je;
	new_instruction->label = calloc(strlen(c)+1,sizeof(char));
	new_instruction->label = c;
	return new_instruction;
}

IR_INSTRUCTION *make_instruction_call(ARGUMENT *arg1) {
	IR_INSTRUCTION *new_instruction;
	new_instruction = NEW(IR_INSTRUCTION);
	new_instruction->id = 0;
	new_instruction->op_code = call;
	new_instruction->arg1 = arg1;
	new_instruction->arg2 = NULL;
	return new_instruction;
}

IR_INSTRUCTION *make_instruction_pushl(ARGUMENT *arg1) {
	IR_INSTRUCTION *new_instruction;
	new_instruction = NEW(IR_INSTRUCTION);
	new_instruction->id = 0;
	new_instruction->op_code = pushl;
	new_instruction->arg1 = arg1;
	new_instruction->arg2 = NULL;
	return new_instruction;
}

IR_INSTRUCTION *make_instruction_popl(ARGUMENT *arg1) {
	IR_INSTRUCTION *new_instruction;
	new_instruction = NEW(IR_INSTRUCTION);
	new_instruction->id = 0;
	new_instruction->op_code = popl;
	new_instruction->arg1 = arg1;
	new_instruction->arg2 = NULL;
	return new_instruction;
}

IR_INSTRUCTION *make_instruction_addl(ARGUMENT *arg1, ARGUMENT *arg2) {
	IR_INSTRUCTION *new_instruction;
	new_instruction = NEW(IR_INSTRUCTION);
	new_instruction->id = 0;
	new_instruction->op_code = addl;
	new_instruction->arg1 = arg1;
	new_instruction->arg2 = arg2;
	return new_instruction;
}

IR_INSTRUCTION *make_instruction_subl(ARGUMENT *arg1, ARGUMENT *arg2) {
	IR_INSTRUCTION *new_instruction;
	new_instruction = NEW(IR_INSTRUCTION);
	new_instruction->id = 0;
	new_instruction->op_code = subl;
	new_instruction->arg1 = arg1;
	new_instruction->arg2 = arg2;
	return new_instruction;
}

IR_INSTRUCTION *make_instruction_incl(ARGUMENT *arg1) {
	IR_INSTRUCTION *new_instruction;
	new_instruction = NEW(IR_INSTRUCTION);
	new_instruction->id = 0;
	new_instruction->op_code = incl;
	new_instruction->arg1 = arg1;
	return new_instruction;
}

IR_INSTRUCTION *make_instruction_decl(ARGUMENT *arg1) {
	IR_INSTRUCTION *new_instruction;
	new_instruction = NEW(IR_INSTRUCTION);
	new_instruction->id = 0;
	new_instruction->op_code = decl;
	new_instruction->arg1 = arg1;
	return new_instruction;
}

IR_INSTRUCTION *make_instruction_div(ARGUMENT *arg1) {
	IR_INSTRUCTION *new_instruction;
	new_instruction = NEW(IR_INSTRUCTION);
	new_instruction->id = 0;
	new_instruction->op_code = divl;
	new_instruction->arg1 = arg1;
	new_instruction->arg2 = NULL;
	return new_instruction;
}

IR_INSTRUCTION *make_instruction_imul(ARGUMENT *arg1, ARGUMENT *arg2) {
	IR_INSTRUCTION *new_instruction;
	new_instruction = NEW(IR_INSTRUCTION);
	new_instruction->id = 0;
	new_instruction->op_code = imul;
	new_instruction->arg1 = arg1;
	new_instruction->arg2 = arg2;
	return new_instruction;
}

IR_INSTRUCTION *make_instruction_xor(ARGUMENT *arg1, ARGUMENT *arg2) {
	IR_INSTRUCTION *new_instruction;
	new_instruction = NEW(IR_INSTRUCTION);
	new_instruction->id = 0;
	new_instruction->op_code = xor;
	new_instruction->arg1 = arg1;
	new_instruction->arg2 = arg2;
	return new_instruction;
}

IR_INSTRUCTION *make_instruction_directive(char * dlabel) {
	IR_INSTRUCTION *new_instruction;
	new_instruction = NEW(IR_INSTRUCTION);
	new_instruction->id = 0;
	new_instruction->op_code = directive;
	new_instruction->arg1 = NULL;
	new_instruction->arg2 = NULL;
	new_instruction->label = dlabel;
	return new_instruction;
}

IR_INSTRUCTION *make_instruction_label(char *clabel) {
	IR_INSTRUCTION *new_instruction;
	new_instruction = NEW(IR_INSTRUCTION);
	new_instruction->id = 0;
	new_instruction->op_code = label;
	new_instruction->arg1 = NULL;
	new_instruction->arg2 = NULL;
	new_instruction->label = clabel;
	return new_instruction;
}

IR_INSTRUCTION *make_instruction_ret() {
	IR_INSTRUCTION *new_instruction;
	new_instruction = NEW(IR_INSTRUCTION);
	new_instruction->id = 0;
	new_instruction->op_code = ret;
	new_instruction->arg1 = NULL;
	new_instruction->arg2 = NULL;
	return new_instruction;	
}


IR_INSTRUCTION *make_instruction_space(ARGUMENT *arg1,ARGUMENT *arg2){
	IR_INSTRUCTION *new_instruction;
	new_instruction = NEW(IR_INSTRUCTION);
	new_instruction->id = 0;
	new_instruction->op_code = space;
	new_instruction->arg1 = arg1;
	new_instruction->arg2 = arg2;
	return new_instruction;	
}

IR_INSTRUCTION *make_instruction_leal(ARGUMENT *arg1,ARGUMENT *arg2){
	IR_INSTRUCTION *new_instruction;
	new_instruction = NEW(IR_INSTRUCTION);
	new_instruction->id = 0;
	new_instruction->op_code = leal;
	new_instruction->arg1 = arg1;
	new_instruction->arg2 = arg2;
	return new_instruction;	
}

ARGUMENT *make_argument_address(int i, ARGUMENT *baseRegister) {
	ARGUMENT *new_argument;
	new_argument = NEW(ARGUMENT);
	new_argument->kind = address_arg;
	new_argument->base = baseRegister;
	new_argument->intConst = i;
	return new_argument;
}

ARGUMENT *make_argument_register(char *name) {
	ARGUMENT *new_argument;
	new_argument = NEW(ARGUMENT);
	new_argument->kind = register_arg;
	new_argument->charConst = calloc(strlen(name)+1,sizeof(char));
	new_argument->charConst = name;
	return new_argument;
}

ARGUMENT *make_argument_label(char *label) {
	ARGUMENT *new_argument;
	new_argument = NEW(ARGUMENT);
	new_argument->kind = label_arg;
	new_argument->label = calloc(strlen(label)+1,sizeof(char));
	new_argument->label = label;
	return new_argument;
}

ARGUMENT *make_argument_constant(int i) {
	ARGUMENT *new_argument;
	new_argument = NEW(ARGUMENT);
	new_argument->kind = constant_arg;
	new_argument->intConst = i;
	return new_argument;
}

ARGUMENT *make_argument_plain_constant(int i) {
	ARGUMENT *new_argument;
	new_argument = NEW(ARGUMENT);
	new_argument->kind = plain_constant_arg;
	new_argument->intConst = i;
	return new_argument;
}

ARGUMENT *make_argument_temp_register(int i){
	ARGUMENT *new_argument;
	new_argument = NEW(ARGUMENT);
	new_argument->kind = tempReg_arg;
	new_argument->temp_id = i;
	return new_argument;
}

ARGUMENT *make_argument_indexing(ARGUMENT *displace, ARGUMENT *base,
								 ARGUMENT *index){
	ARGUMENT *new_argument;
	new_argument = NEW(ARGUMENT);
	new_argument->displace = displace;
	new_argument->index = index;
	new_argument->base = base;
	new_argument->kind = indexing_arg;
	return new_argument;
}
