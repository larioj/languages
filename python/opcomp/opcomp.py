#! /usr/bin/env python

def flattenMult(s):
    if (5 > len(s)):
        return ""
    if (5 == len(s)):
        return s
    [lhs, rhs] = s.split("*")
    res = ""
    if (2 == len(lhs)):
        for i in range(len(rhs)/2):
            sym = rhs[2*i:2*i + 2]
            res += flattenMult(lhs + "*" + sym)
    else:
        for i in range(len(lhs)/2):
            sym = lhs[2*i:2*i + 2]
            res += flattenMult(sym + "*" + rhs);
    return res;

def sympMult(s):
    pairs = []
    tups = [s[i:i+5] for i in range(0, len(s), 5)]
    for tup in tups:
        if (tup[0] == tup[3]):
            pairs.append((1, tup[1] + tup[4]));
        else:
            pairs.append((-1, tup[1] + tup[4]));
    pairs = sumPairs(pairs, [])
    pairs = removeZeros(pairs)
    print(pairs)

def sumPairs(pairs, accum):
    if (0 == len(pairs)):
        return accum
    (hval, hsym) = pairs[0]
    matched = False
    for i in range(len(accum)):
        (val, sym) = accum[i]
        if (sym == hsym):
            accum[i] = (hval + val, sym)
            matched = True
            break
    if not (matched):
        accum.append(pairs[0])
    return sumPairs(pairs[1:], accum)

def removeZeros(pairs):
    res = []
    for pair in pairs:
        (hval,_) = pair;
        if not (0 == hval):
            res.append(pair)
    return res

sympMult("+a*-b+a*+b+c*+a")
