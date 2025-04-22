# Leetcode-2959.-Number-of-Possible-Sets-of-Closing-Branches
# 🚀 Subsets with Bounded Shortest Paths (Floyd-Warshall Approach)

This repository contains an efficient C++ solution to count the number of subsets of nodes in a graph such that **all pairs of nodes within the subset have a shortest path distance ≤ `maxDistance`**. The approach uses the **Floyd-Warshall algorithm** for all-pairs shortest paths within each subset.

---

## 📌 Problem Statement

Given:
- An integer `n` (number of nodes, labeled from `0` to `n-1`)
- A list of bidirectional roads `roads[i] = [u, v, distance]`
- An integer `maxDistance`

Return the number of subsets (including empty and singleton sets) of the nodes such that for **every pair of nodes** in the subset, the **shortest distance between them does not exceed `maxDistance`**.

---

## 💡 Approach

For each subset of the nodes:
1. Build a subgraph using only the nodes in the subset and roads between them.
2. Use **Floyd-Warshall** to compute all-pairs shortest paths.
3. Check if all distances in this subset are ≤ `maxDistance`.
4. Count it if valid.

Optimizations:
- Skip Floyd-Warshall if the subset is empty or has only one node (always valid).
- Avoid unnecessary recomputation of indices by mapping node labels to matrix indices.

---
✨ Features

Handles large graphs efficiently (limited by subset enumeration).

Clean and modular code with comments.

Accurate distance comparisons with integer overflow protection.

---

📎 Related Topics
Graph Algorithms

Dynamic Programming

Bitmasking

All-Pairs Shortest Path

---

## 🧠 Algorithms Used

- **Bitmasking** for generating all subsets of nodes.
- **Floyd-Warshall Algorithm** for shortest paths in weighted graphs.

---

## 🧪 Example

```cpp
Input:
n = 3
roads = {{0, 1, 2}, {1, 2, 2}, {0, 2, 3}}
maxDistance = 4

Output:
6

Explanation:
Valid subsets include {}, {0}, {1}, {2}, {0,1}, {1,2}
