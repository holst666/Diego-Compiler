#include <stdio.h>
#include <stdarg.h> 
#include "kittyprinter.h"
 
static int indentation = 0;
static int tabSize = 4;

#define NEXT_INDENT_LEVEL (tab_indentation++)
#define PREV_INDENT_LEVEL (tab_indentation--)



/*Line shift with the current indentations level */
void lineShift(){

	printf("\n");

	int i;
	for (i = (indentation * tabSize); i > 0; i--){
		printf("%s", " ");
	}

}

void printer_function(FUNC *func) {
	printf("%s\n", "Func ");
	printer_head(func->head);

}

void printer_head (HEAD *header){
	printf("%s ( ", header->id);
	printer_par_decl_list(header->pdlist);
	printf(") :");
	printer_type(header->returntype);
}

void printer_body (BODY *body){
	indentation++;
	lineShift();
	printer_decl_list(body->decl_list);
	printer_statement_list(body->statement_list);
	indentation--;
}



void printer_type ( TYPE *type){
	switch(type->kind){
		case TYPE_ID:
			printf(" %s", type->value.id);
			break;
		case TYPE_INT:
			printf(" int");
			break;
		case TYPE_BOOL:
			printf(" bool");
			break;
		case TYPE_ARRAY:
			printf(" array of");
			printer_type(type->value.type);
			break;
		case TYPE_RECORD:
			printf(" record of {");
			printer_var_decl_list(type->value.var_decl_list);
			printf("};");
			break;
	}
}
	
void printer_par_decl_list ( PAR_DECL_LIST *pdecl){
	switch(pdecl->kind){
		case PAR_DECL_LIST_LIST:
			printer_var_decl_list(pdecl->var_decl_list);
			break;
		case PAR_DECL_LIST_EMPTY:
			break;

	}
}

void printer_var_decl_list ( VAR_DECL_LIST *vdecl){
	switch(vdecl->kind){
		case VAR_DECL_LIST_LIST:
			printer_var_decl_list(vdecl->var_decl_list);
			printf(" , ");
			printer_var_type(vdecl->var_type);
			break;
		case VAR_DECL_LIST_TYPE:
			printer_var_type(vdecl->var_type);
			break;
	}
}

void printer_var_type ( VAR_TYPE *vtype){
	printf("%s :", vtype->id);
	printer_type(vtype->type);
}

void printer_decl_list ( DECL_LIST *dlst){
	switch(dlst->kind){
		case DECL_LIST_LIST:
			printer_decl_list(dlst->decl_list);		
			printer_declaration(dlst->declaration);
			break;
		case DECL_LIST_EMPTY:
			break;
	}
}


void printer_declaration ( DECLARATION *decl){
	indentation++;
	switch(decl->kind){
		case DECLARATION_ID:

			printer_type(decl->value.declaration_id.type);
			break;
		case DECLARATION_FUNC:
			printer_function(decl->value.function);
			break;
		case DECLARATION_VAR:

			printer_var_decl_list(decl->value.var_decl_list);
			printf(";\n");
			break;
	}
	indentation--;
}

void printer_statement_list ( STATEMENT_LIST *slst){
	switch(slst->kind){
		case STATEMENT_LIST_STATEMENT:
			printer_statement(slst->statement);
			break;
		case STATEMENT_LIST_LIST: 
			printer_statement_list(slst->statement_list);
			printer_statement(slst->statement);
			break;
	}
}

void printer_statement ( STATEMENT *st){
	indentation++;
	switch(st->kind){
		case STATEMENT_RETURN:

			printer_expression(st->value.statement_return.exp);
			printf(";\n"); 	
			break;
		case STATEMENT_WRITE:

			printer_expression(st->value.exp);
			printf(";\n");
			break;
		case STATEMENT_ALLOCATE:
		
			printer_variable(st->value.statement_allocate.var);
			printer_opt_length(st->value.statement_allocate.opt_length);
			printf(";\n");
			break;
		case STATEMENT_ASSIGN:
			printer_variable(st->value.statement_assign.var);
			printf(" := ");
			printer_expression(st->value.statement_assign.exp);
			printf(";\n");
			break;
		case STATEMENT_IFBRANCH:

			printer_expression(st->value.statement_ifbranch.exp);
			printf(" then\n");
			printer_statement(st->value.statement_ifbranch.statement);
			printer_opt_else(st->value.statement_ifbranch.opt_else);
			printf("\n");
			break;
		case STATEMENT_WHILE:
	
			printer_expression(st->value.statement_while.exp);
			printer_statement(st->value.statement_while.statement);
			printf("\n");
			break;
		case STATEMENT_LISTS:
	
			printer_statement_list(st->value.statement_list);
		
			break; 
	}
	indentation--;
} 

void printer_opt_length ( OPT_LENGTH *oplen){
	switch(oplen->kind){
		case OPT_LENGTH_EXPRES:
			printf(" length of ");
			printer_expression(oplen->exp);
			break;
		case OPT_LENGTH_EMPTY:
			break;
	}
}

void printer_opt_else ( OPT_ELSE *opel){
	switch(opel->kind){
		case OPT_ELSE_STATEMENT:
			
			printer_statement(opel->statement);
			break;
		case OPT_ELSE_EMPTY:
			break;
	}
}

void printer_variable ( VAR *var){
	switch(var->kind){
		case VAR_ID:
			printf("%s",var->id);
			break;
		case VAR_ARRAY:
			printer_variable(var->value.var_array.var);
			printf("[ ");
			printer_expression(var->value.var_array.exp);
			printf(" ] ");
			break;
		case VAR_RECORD:
			printer_variable(var->value.var_record.var);
			printf(".%s",var->value.var_record.id );
			break;
	}
}

void printer_expression ( EXPRES *exp){
	switch(exp->kind){
		case EXPRES_TERM:
			printer_term(exp->value.term);
			break;
		case EXPRES_PLUS:
			printf("(");
			printer_expression(exp->value.sides.left);
			printf(" + ");
			printer_expression(exp->value.sides.right);
			printf(")");
			break;
		case EXPRES_MINUS:
			printf("(");
			printer_expression(exp->value.sides.left);
			printf(" - ");
			printer_expression(exp->value.sides.right);
			printf(")");
			break;
		case EXPRES_TIMES:
			printf("(");
			printer_expression(exp->value.sides.left);
			printf(" * ");
			printer_expression(exp->value.sides.right);
			printf(")");
			break;
		case EXPRES_DIVIDE:
			printf("(");
			printer_expression(exp->value.sides.left);
			printf(" / ");
			printer_expression(exp->value.sides.right);
			printf(")");
			break;
		case EXPRES_EQ:
			printf("(");
			printer_expression(exp->value.sides.left);
			printf(" == ");
			printer_expression(exp->value.sides.right);
			printf(")");
			break;
		case EXPRES_NEQ:
			printf("(");
			printer_expression(exp->value.sides.left);
			printf(" != ");
			printer_expression(exp->value.sides.right);
			printf(")");
			break;
		case EXPRES_GREATER:
			printf("(");
			printer_expression(exp->value.sides.left);
			printf(" > ");
			printer_expression(exp->value.sides.right);
			printf(")");
			break;
		case EXPRES_LESS:
			printf("(");
			printer_expression(exp->value.sides.left);
			printf(" < ");
			printer_expression(exp->value.sides.right);
			printf(")");
			break;
		case EXPRES_LEQ:
			printf("(");
			printer_expression(exp->value.sides.left);
			printf(" <= ");
			printer_expression(exp->value.sides.right);
			printf(")");
			break;
		case EXPRES_GEQ:
			printf("(");
			printer_expression(exp->value.sides.left);
			printf(" >= ");
			printer_expression(exp->value.sides.right);
			printf(")");
			break;
		case EXPRES_AND:
			printf("(");
			printer_expression(exp->value.sides.left);
			printf(" && ");
			printer_expression(exp->value.sides.right);
			printf(")");
			break;
		case EXPRES_OR:
			printf("(");
			printer_expression(exp->value.sides.left);
			printf(" || ");
			printer_expression(exp->value.sides.right);
			printf(")");
			break;
	}

}

void printer_term ( TERM *term){
	switch(term->kind){
		case TERM_VAR:
			printer_variable(term->value.var);
			break;
		case TERM_ACT_LIST:
			printf("%s (", term->value.term_act_list.id);
			printer_act_list(term->value.term_act_list.actlist);
			printf(")");
			break;
		case TERM_NOT:
			printf("!");
			printer_term(term->value.term);
			break;
		case TERM_PARENTESES:
			printf("(");
			printer_expression(term->value.exp);
			printf(")");
			break;
		case TERM_ABS:
			printf("|");
			printer_expression(term->value.exp);
			printf("|");
			break;
		case TERM_NULL:
			printf("NULL");
			break;
		case TERM_TRUE:
			printf("TRUE");
			break;
		case TERM_FALSE:
			printf("FALSE");
			break;
		case TERM_NUM:
			printf("%i",term->value.intconst);
			break;
	}
}

void printer_act_list ( ACT_LIST *actlst){
	switch(actlst->kind){
		case ACT_LIST_EXPLIST:
			printer_expression_list(actlst->exp_list);
			break;
		case ACT_LIST_EMPTY:
			break;
	}
}

void printer_expression_list ( EXP_LIST *explst){
	switch(explst->kind){
		case EXP_LIST_EXP:
			printer_expression(explst->exp);
			break;
		case EXP_LIST_LIST:
			printer_expression_list(explst->explist);
			printf(",");
			printer_expression(explst->exp);
			break;
	}
}