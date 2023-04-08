"""
Baekjoon Online Judge #6597
https://www.acmicpc.net/problem/6597
"""

from sys import stdin
from typing import Dict, List, Optional, Tuple

infast = lambda: stdin.readline().strip()

while True:
    try:
        preorder, inorder = infast().split()
        preorder_lookup = dict((k, v) for v, k in enumerate(preorder))
        inorder_lookup = dict((k, v) for v, k in enumerate(inorder))
        stack: List[Tuple[int, int, int, int]] = [(0, len(preorder), 0, len(inorder))]
        tree: Dict[str, Tuple[Optional[str], Optional[str]]] = dict()
        while stack:
            lo_pre, hi_pre, lo_in, hi_in = stack.pop()
            if hi_pre - lo_pre == 0:
                continue
            root = preorder[lo_pre]
            root_in = inorder_lookup[root]
            left_size = root_in - lo_in
            right_size = hi_in - root_in - 1
            left_lo_pre = lo_pre + 1
            left_hi_pre = left_lo_pre + left_size
            right_lo_pre = left_hi_pre
            right_hi_pre = right_lo_pre + right_size
            stack.append((right_lo_pre, right_hi_pre, lo_in + left_size + 1, hi_in))
            stack.append((left_lo_pre, left_hi_pre, lo_in, lo_in + left_size))
            tree[root] = (
                preorder[left_lo_pre] if left_size > 0 else None,
                preorder[right_lo_pre] if right_size > 0 else None,
            )
        postorder_stack: List[Tuple[Optional[str], bool]] = [(preorder[0], False)]
        res = []
        while postorder_stack:
            root, revisit = postorder_stack.pop()
            if root is None:
                continue
            if revisit:
                res.append(root)
                continue
            left_root, right_root = tree[root]
            postorder_stack.append((root, True))
            postorder_stack.append((right_root, False))
            postorder_stack.append((left_root, False))
        print("".join(res))
    except:
        break
