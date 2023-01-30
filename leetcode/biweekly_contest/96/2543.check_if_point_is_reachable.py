#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# https://leetcode.cn/problems/check-if-point-is-reachable
def GCD(a, b):
    if b == 0:
        return a
    return GCD(b, a % b)


class Solution:
    def isReachable(self, targetX: int, targetY: int) -> bool:
        g = GCD(targetX, targetY)
        return (g & (g - 1)) == 0  # 2 的 x 次方？
