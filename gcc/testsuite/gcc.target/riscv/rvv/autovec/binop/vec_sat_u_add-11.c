/* { dg-do compile } */
/* { dg-options "-march=rv64gcv -mabi=lp64d -O3 -ftree-vectorize -fdump-rtl-expand-details -fno-schedule-insns -fno-schedule-insns2" } */
/* { dg-skip-if "" { *-*-* } { "-flto" } } */
/* { dg-final { check-function-bodies "**" "" } } */

#include "../vec_sat_arith.h"

/*
** vec_sat_u_add_uint32_t_fmt_3:
** ...
** vsetvli\s+[atx][0-9]+,\s*[atx][0-9]+,\s*e32,\s*m1,\s*ta,\s*ma
** ...
** vsaddu\.vv\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+
** ...
*/
DEF_VEC_SAT_U_ADD_FMT_3(uint32_t)

/* { dg-final { scan-rtl-dump-times ".SAT_ADD " 4 "expand" } } */
