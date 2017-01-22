#!/usr/bin/env python3
# -*- coding: utf-8 -*-

cxrs = ['caaaar',
        'caaar',
        'caaddr',
        'cadaar',
        'cadar',
        'cadddr',
        'cdaaar',
        'cdaar',
        'cdaddr',
        'cddaar',
        'cddar',
        'cddddr',
        'caaadr',
        'caadar',
        'caadr',
        'cadadr',
        'caddar',
        'caddr',
        'cdaadr',
        'cdadar',
        'cdadr',
        'cddadr',
        'cdddar',
        'cdddr']

result = '(begin\n'
for cxr in sorted(cxrs):
    t = '  (define ({0} pair) '.format(cxr)
    s = 'pair'
    for x in reversed(cxr[1:-1]):
        s = '(c{0}r {1})'.format(x, s)
    t += '{0})\n'.format(t)
    result += t

result += ')'
with open('compound_procedures.scm', 'w') as f:
    print(result, file=f)
