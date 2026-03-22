This project has been created as part of the 42 curriculum by hsrour, gbaghsar

---

# push_swap

> Sort integers on a stack using the fewest possible operations.

---

## Description

**push_swap** is a sorting algorithm project from the 42 curriculum. The goal is to sort a list of integers loaded onto **stack A** using only two stacks (A and B) and a restricted set of operations, while minimising the total number of operations used.

What makes this challenging is that classical sorting algorithms cannot be applied directly — every "comparison" and "move" must be expressed as one of eleven specific stack operations. The project forces a deep understanding of algorithmic complexity by requiring four distinct sorting strategies, each suited to a different level of input disorder.

### Available Operations

| Operation | Description                           |
| --------- | ------------------------------------- |
| `sa`      | Swap the top two elements of stack A  |
| `sb`      | Swap the top two elements of stack B  |
| `ss`      | `sa` and `sb` simultaneously          |
| `pa`      | Push the top of B onto A              |
| `pb`      | Push the top of A onto B              |
| `ra`      | Rotate A upward (first becomes last)  |
| `rb`      | Rotate B upward (first becomes last)  |
| `rr`      | `ra` and `rb` simultaneously          |
| `rra`     | Reverse rotate A (last becomes first) |
| `rrb`     | Reverse rotate B (last becomes first) |
| `rrr`     | `rra` and `rrb` simultaneously        |

---

## Instructions

### Compilation

```bash
make        # builds push_swap
make bonus  # builds checker (bonus)
make clean  # removes object files
make fclean # removes object files and binaries
make re     # fclean + make
```

### Usage

```bash
# Basic usage — outputs the sorted operation sequence
./push_swap 3 1 4 1 5 9 2 6

# Force a specific algorithm
./push_swap --simple   5 4 3 2 1
./push_swap --medium   5 4 3 2 1
./push_swap --complex  5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1

# Benchmark mode — prints disorder %, strategy, and op counts to stderr
./push_swap --bench --adaptive 5 4 3 2 1
./push_swap --bench --simple   5 4 3 2 1

# Pass numbers as a single quoted string
./push_swap "3 1 4 1 5"

# Count total operations
ARG="4 67 3 87 23"; ./push_swap --adaptive $ARG | wc -l

# Verify correctness with the checker (bonus)
ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker $ARG

# Large input test
shuf -i 0-9999 -n 500 > args.txt
./push_swap $(cat args.txt) | wc -l
```

### Error Handling

The program prints `Error` to stderr and exits on:

- Non-integer arguments
- Integer overflow (out of `int` range)
- Duplicate values
- Invalid flags

```bash
./push_swap 0 one 2 3     # Error
./push_swap 3 2 3         # Error (duplicate)
./push_swap               # no output, exits cleanly
```

---

## Algorithm Design & Justification

The program measures **disorder** before sorting — a value between `0.0` (perfectly sorted) and `1.0` (fully reversed) computed as the fraction of inverted pairs:

```
disorder = (number of pairs where a[i] > a[j] for i < j) / total pairs
```

This score drives the **adaptive** strategy, and the four strategies are available individually via flags.

---

### 1. Simple — O(n²) — `--simple`

**Algorithm:** Selection sort via repeated minimum extraction.

**How it works:**

1. Scan stack A, find the minimum value's position.
2. Rotate A (forward or backward, whichever is shorter) to bring it to the top.
3. Push it to B.
4. Repeat until A is empty.
5. Push everything from B back to A.

Since elements are pushed to B in ascending order (smallest first), pushing them all back to A restores them in sorted order (smallest ends up on top).

**Why O(n²):** Each of the n extractions may require up to n/2 rotations to locate and surface the minimum — giving O(n) work per extraction and O(n²) total.

**Best for:** Nearly-sorted inputs (disorder < 0.2), where the minimum is usually already near the top, making each extraction cheap.

---

### 2. Medium — O(n√n) — `--medium`

**Algorithm:** Chunk-based sort with threshold partitioning.

**How it works — Phase 1 (push chunks to B):**

1. Compute chunk size = `√n` (via `radical(length)`).
2. Use a partial selection sort on the values to find the `chunk_size`-th smallest value — the **threshold**.
3. Mark all nodes with `value ≤ threshold` as rank 0 (current chunk).
4. Scan A and push every rank-0 node to B (using direction-optimised rotations).
5. Repeat with the next chunk until A is empty.

**How it works — Phase 2 (extract maximums back to A):**

1. Find the maximum remaining in B.
2. Rotate B (forward or backward, whichever is shorter) to bring it to the top.
3. Push it to A.
4. Repeat n times.

Because maximums are extracted in descending order and pushed onto A, larger values sink to the bottom first and the smallest arrives last — leaving A sorted ascending from top to bottom.

**Why O(n√n):** Phase 1 does n pushes with O(√n) average rotation cost each = O(n√n). Phase 2 does n extractions with O(√n) average rotation cost each = O(n√n). The chunk structure ensures B always has local order, keeping rotation costs low.

**Best for:** Medium disorder inputs (0.2 ≤ disorder < 0.5).

---

### 3. Complex — O(n log n) — `--complex`

**Algorithm:** LSD (Least Significant Bit first) Radix Sort.

**How it works:**

1. **Normalise:** Replace each value with its rank (0-based sorted position). This ensures all values are non-negative and contiguous — required for bit manipulation.
2. **Compute bits:** Determine how many bit passes are needed: `bits = ⌈log₂(n)⌉`.
3. **For each bit position i (LSB to MSB):**
   - Iterate through all elements in A:
     - If bit `i` of the element's rank is **1** → `ra` (keep in A, rotate to bottom).
     - If bit `i` of the element's rank is **0** → `pb` (push to B).
   - Push everything from B back to A.

After all bit passes, ranks in A are in ascending order 0..n-1, which corresponds to the original values being sorted.

**Why O(n log n):** Each of the `log₂(n)` passes touches all n elements exactly once = O(n log n) total operations. The number of passes is determined purely by the input size, not its disorder.

**Best for:** Highly disordered inputs (disorder ≥ 0.5) and large inputs where the guaranteed logarithmic pass count pays off.

---

### 4. Adaptive — `--adaptive` (default)

**Algorithm:** Automatically selects the best strategy based on the measured disorder.

```
disorder < 0.2   →  Simple   O(n²)       (nearly sorted, few moves needed)
0.2 ≤ disorder < 0.5  →  Medium   O(n√n)  (moderate disorder, chunks effective)
disorder ≥ 0.5   →  Complex  O(n log n)  (high disorder, radix guaranteed)
```

Before calling any main algorithm, `handler()` is always run first to handle the trivially small cases (2–5 elements) with hardcoded optimal move sequences, avoiding unnecessary overhead.

**Threshold rationale:**

- `0.2` is the boundary below which a nearly-sorted array has so few inversions that the O(n²) simple sort performs fewer actual operations than chunk sort's setup overhead.
- `0.5` is the midpoint of possible disorder. Beyond this, the input is more inverted than sorted, and radix sort's predictable O(n log n) behaviour outperforms chunk sort's O(n√n) average.

---

### Small-Input Handler (2–5 elements)

Before any main algorithm, `handler()` applies hardcoded optimal sequences:

- **2 elements:** swap if out of order. (1 op max)
- **3 elements:** 6 possible orderings → handled by `handle_3` + `handle_3_2` with at most 2 ops.
- **4 elements:** move minimum to B, sort remaining 3, push back. (~5 ops max)
- **5 elements:** move two smallest to B, sort remaining 3, restore B in correct order, push back. (~9 ops max)

---

### Performance Targets

| Input Size  | Pass        | Good       | Excellent  |
| ----------- | ----------- | ---------- | ---------- |
| 100 numbers | < 2000 ops  | < 1500 ops | < 700 ops  |
| 500 numbers | < 12000 ops | < 8000 ops | < 5500 ops |

---

## Resources

### Classic References

- **Donald Knuth** — _The Art of Computer Programming, Vol. 3: Sorting and Searching_ — the foundational reference for sorting algorithms and complexity analysis.
- **Radix Sort (LSD)** — [Wikipedia: Radix sort](https://en.wikipedia.org/wiki/Radix_sort)
- **Selection Sort** — [Wikipedia: Selection sort](https://en.wikipedia.org/wiki/Selection_sort)
- **Big-O Notation** — [Big-O Cheat Sheet](https://www.bigocheatsheet.com/)
- **Stack (data structure)** — [Wikipedia: Stack](<https://en.wikipedia.org/wiki/Stack_(abstract_data_type)>)

### 42-Specific Resources

- The official `push_swap` subject (this repository)
- `checker_linux` / `checker_Mac` — provided binaries for validating operation sequences

### AI Usage

1. To test edge cases and debugging.
2. For explanation and clarity.
3. Readme creation.

All AI-generated explanations were verified by manually tracing through the code and cross-checking with the actual implementation. No AI-generated code was directly used in the project.
