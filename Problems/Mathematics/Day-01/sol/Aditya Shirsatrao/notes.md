# Notes - Who's Opposite?

## Mathematical Intuition

In a circle of $n$ people numbered $1, 2, \dots, n$, the person opposite to $i$ is at a distance of $n/2$ steps.
If we are given that person $a$ is opposite person $b$, then:
$$|a - b| = \frac{n}{2} \implies n = 2 \times |a - b|$$

## Implementation Details

1. **Total People ($n$):** Calculated as $2 \times |a - b|$.
2. **Validity Check:**
   - The given $a, b, c$ must all be $\le n$ (and $\ge 1$, which is guaranteed by the constraints).
   - If any of $a, b, c$ exceed $n$, the configuration is impossible.
3. **Finding $c$'s Opposite:**
   - If $c \le n/2$, the opposite is $c + n/2$.
   - If $c > n/2$, the opposite is $c - n/2$.

## Complexity Analysis

- **Time Complexity:** $O(1)$ per test case. We perform a few arithmetic operations and comparisons.
- **Space Complexity:** $O(1)$. No extra data structures are used.
