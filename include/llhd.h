// Copyright (c) 2016 Fabian Schuiki
#include <stddef.h>

typedef struct llhd_module * llhd_module_t;
typedef struct llhd_type * llhd_type_t;
typedef struct llhd_value * llhd_value_t;

enum llhd_type_kind {
	LLHD_TYPE_VOID   = 1,
	LLHD_TYPE_LABEL  = 2,
	LLHD_TYPE_TIME   = 3,
	LLHD_TYPE_INT    = 4,
	LLHD_TYPE_LOGIC  = 5,
	LLHD_TYPE_STRUCT = 6,
	LLHD_TYPE_ARRAY  = 7,
	LLHD_TYPE_PTR    = 8,
	LLHD_TYPE_SIGNAL = 9,
	LLHD_TYPE_FUNC   = 10,
	LLHD_TYPE_COMP   = 11,
};

enum llhd_unit_kind {
	LLHD_UNIT_DECL       = 1,
	LLHD_UNIT_DEF_FUNC   = 2,
	LLHD_UNIT_DEF_ENTITY = 3,
	LLHD_UNIT_DEF_PROC   = 4,
};

enum llhd_inst_kind {
	LLHD_INST_BRANCH = 1,
};

llhd_module_t llhd_module_new(const char *name);
void llhd_module_free(llhd_module_t);
llhd_value_t llhd_module_get_first_unit(llhd_module_t);
llhd_value_t llhd_module_get_last_unit(llhd_module_t);
void llhd_verify_module_selfcontained(llhd_module_t);
const char *llhd_module_get_name(llhd_module_t);

llhd_value_t llhd_unit_next(llhd_value_t);
llhd_value_t llhd_unit_prev(llhd_value_t);
void llhd_unit_append_to(llhd_value_t,llhd_module_t);
void llhd_unit_prepend_to(llhd_value_t,llhd_module_t);
void llhd_unit_insert_after(llhd_value_t,llhd_value_t);
void llhd_unit_insert_before(llhd_value_t,llhd_value_t);
int llhd_unit_is_def(llhd_value_t);
int llhd_unit_is_decl(llhd_value_t);
llhd_value_t llhd_unit_get_first_block(llhd_value_t);
llhd_value_t llhd_unit_get_last_block(llhd_value_t);

llhd_value_t llhd_block_next(llhd_value_t);
llhd_value_t llhd_block_prev(llhd_value_t);
llhd_value_t llhd_block_get_first_inst(llhd_value_t);
llhd_value_t llhd_block_get_last_inst(llhd_value_t);
int llhd_block_is_entry(llhd_value_t);
int llhd_block_has_predecessors(llhd_value_t);
int llhd_block_has_successors(llhd_value_t);
void llhd_block_get_predecessors(llhd_value_t, llhd_value_t**, unsigned*);
void llhd_block_get_successors(llhd_value_t, llhd_value_t**, unsigned*);

llhd_value_t llhd_inst_next(llhd_value_t);
llhd_value_t llhd_inst_prev(llhd_value_t);
void llhd_inst_append_to(llhd_value_t,llhd_value_t);
void llhd_inst_prepend_to(llhd_value_t,llhd_value_t);
void llhd_inst_insert_after(llhd_value_t,llhd_value_t);
void llhd_inst_insert_before(llhd_value_t,llhd_value_t);
int llhd_inst_is(llhd_value_t,int);

llhd_value_t llhd_inst_branch_new_uncond(llhd_value_t);
llhd_value_t llhd_inst_branch_new_cond(llhd_value_t, llhd_value_t, llhd_value_t);
llhd_value_t llhd_inst_branch_get_condition(llhd_value_t);
llhd_value_t llhd_inst_branch_get_dst0(llhd_value_t);
llhd_value_t llhd_inst_branch_get_dst1(llhd_value_t);

int llhd_const_is_null(llhd_value_t);

int llhd_value_is_const(llhd_value_t);
const char *llhd_value_get_name(llhd_value_t);
void llhd_value_replace_uses(llhd_value_t,llhd_value_t);
void llhd_value_unlink_from_parent(llhd_value_t);
void llhd_value_unlink_uses(llhd_value_t);
void llhd_value_unlink(llhd_value_t);
void llhd_value_free(llhd_value_t);

void *llhd_alloc(size_t);
void *llhd_realloc(void*,size_t);
void llhd_free(void*);
