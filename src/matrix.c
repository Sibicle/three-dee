#include <stdio.h>

#include "matrix.h"

mat4_t mat4_make_identity(void) {
  mat4_t m = {{ 0 }};

  m.m[0][0] = 1.0;
  m.m[1][1] = 1.0;
  m.m[2][2] = 1.0;
  m.m[3][3] = 1.0;

  return m;
}

mat4_t mat4_make_scale(float sx, float sy, float sz) {
  mat4_t m = mat4_make_identity();

  m.m[0][0] = sx;
  m.m[1][1] = sy;
  m.m[2][2] = sz;

  return m;
}

mat4_t mat4_make_scale_uniform(float s) {
  return mat4_make_scale(s, s, s);
}
mat4_t mat4_make_trans(float tx, float ty, float tz) {
  mat4_t m = mat4_make_identity();

  m.m[0][3] = tx;
  m.m[1][3] = ty;
  m.m[2][3] = tz;

  return m;
}

void mat4_mul_vec4_inplace(mat4_t * m, vec4_t * v) {
  vec4_t prod = VEC4_ZERO;

  prod.x = m->m[0][0] * v->x + m->m[0][1] * v->y + m->m[0][2] * v->z + m->m[0][3] * v->w;
  prod.y = m->m[1][0] * v->x + m->m[1][1] * v->y + m->m[1][2] * v->z + m->m[1][3] * v->w;
  prod.z = m->m[2][0] * v->x + m->m[2][1] * v->y + m->m[2][2] * v->z + m->m[2][3] * v->w;
  prod.w = m->m[3][0] * v->x + m->m[3][1] * v->y + m->m[3][2] * v->z + m->m[3][3] * v->w;

  v->x = prod.x;
  v->y = prod.y;
  v->z = prod.z;
  v->w = prod.w;
}

void mat4_to_string(char * str, mat4_t * m) {
  int len = 0;

  len += sprintf(str + len, "┌ %0.1f  %0.1f  %0.1f  %0.1f  ┐\n", m->m[0][0], m->m[0][1], m->m[0][2], m->m[0][3]);
  len += sprintf(str + len, "│ %0.1f  %0.1f  %0.1f  %0.1f  │\n", m->m[1][0], m->m[1][1], m->m[1][2], m->m[1][3]);
  len += sprintf(str + len, "│ %0.1f  %0.1f  %0.1f  %0.1f  │\n", m->m[2][0], m->m[2][1], m->m[2][2], m->m[2][3]);
  len += sprintf(str + len, "└ %0.1f  %0.1f  %0.1f  %0.1f  ┘\n", m->m[3][0], m->m[3][1], m->m[3][2], m->m[3][3]);
}
