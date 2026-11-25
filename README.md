<div align="center">

<img src="https://capsule-render.vercel.app/api?type=waving&color=0:6366f1,50:8b5cf6,100:ec4899&height=220&section=header&text=Data%20Structures&fontSize=60&fontColor=ffffff&fontAlignY=38&desc=Algorithms%20%C2%B7%20Recursion%20%C2%B7%20Trees%20%C2%B7%20Linear%20Structures&descSize=18&descAlignY=60" alt="Data Structures banner" width="100%"/>

<br/>

<a href="https://github.com/AhmedMustafa-0817/data-structures"><img src="https://img.shields.io/badge/FAST--NUCES-Karachi-6366f1?style=for-the-badge" alt="FAST-NUCES"/></a>
<img src="https://img.shields.io/badge/Language-C%2B%2B-ec4899?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++"/>
<img src="https://img.shields.io/badge/Course-Data%20Structures-8b5cf6?style=for-the-badge" alt="Course"/>
<img src="https://img.shields.io/github/last-commit/AhmedMustafa-0817/data-structures?style=for-the-badge&color=22c55e" alt="Last commit"/>
<img src="https://img.shields.io/github/stars/AhmedMustafa-0817/data-structures?style=for-the-badge&color=f59e0b" alt="Stars"/>

<br/><br/>

**Every algorithm written from scratch. No STL shortcuts, no black boxes.**

</div>

---

## ✦ Contents

| | Module | What's inside |
|---|---|---|
| 🔹 | [**Simple Sorting**] | Bubble · Selection · Insertion · Comb · Shell |
| 🔸 | [**Advanced Sorting**] | Merge · Quick · Radix |
| 🧩 | [**Recursion & Backtracking**] | Recursive patterns · N-Queens · Rat in a Maze |
| 🌳 | [**Binary Search Tree**] | Insert · Delete · Search · Traversals |
| 📚 | [**Stack · Queue · Linked List**] | Array & Linked List implementations |
| 🔗 | [**Linked List Variants**] | Singly · Doubly · Circular |
| 🌲 | [**AVL Tree**] | Self-balancing BST · LL / RR / LR / RL rotations · Traversals |
| ⛰️ | [**Heaps**] | Binary Heap · Min Heap · Max Heap · Heap Sort · Priority Queue |
| 🕸️ | [**Graphs**] | BFS · DFS · Dijkstra · Prim's MST · Kruskal's MST |
| 🧠 | [**More Backtracking**] | Combinations · Word Search · Sudoku Solver |
| 🔍 | [**Searching**] | Binary Search |
| 🧪 | [**Lab Tasks**] | Weekly lab exercises (Labs 2 – 10) |

---

## ✦ Complexity Cheat Sheet

### Sorting

| Algorithm | Best | Average | Worst | Space | Stable |
|---|:---:|:---:|:---:|:---:|:---:|
| Bubble | `O(n)` | `O(n²)` | `O(n²)` | `O(1)` | ✅ |
| Selection | `O(n²)` | `O(n²)` | `O(n²)` | `O(1)` | ❌ |
| Insertion | `O(n)` | `O(n²)` | `O(n²)` | `O(1)` | ✅ |
| Merge | `O(n log n)` | `O(n log n)` | `O(n log n)` | `O(n)` | ✅ |
| Quick | `O(n log n)` | `O(n log n)` | `O(n²)` | `O(log n)` | ❌ |
| Radix | `O(nk)` | `O(nk)` | `O(nk)` | `O(n+k)` | ✅ |
| Comb | `O(n log n)` | `O(n²/2ᵖ)` | `O(n²)` | `O(1)` | ❌ |
| Shell | `O(n log n)` | `O(n^1.25)` | `O(n²)` | `O(1)` | ❌ |
| Heap | `O(n log n)` | `O(n log n)` | `O(n log n)` | `O(1)` | ❌ |

k = number of digits / length of key · p = number of gap passes

### Searching

| Algorithm | Best | Average | Worst | Space |
|---|:---:|:---:|:---:|:---:|
| Binary Search | `O(1)` | `O(log n)` | `O(log n)` | `O(1)` |

<sub>requires a sorted array</sub>

### Core Operations

| Structure | Access | Search | Insert | Delete |
|---|:---:|:---:|:---:|:---:|
| Stack | `O(n)` | `O(n)` | `O(1)` | `O(1)` |
| Queue | `O(n)` | `O(n)` | `O(1)` | `O(1)` |
| Linked List | `O(n)` | `O(n)` | `O(1)`* | `O(1)`* |
| BST (balanced) | `O(log n)` | `O(log n)` | `O(log n)` | `O(log n)` |
| BST (skewed) | `O(n)` | `O(n)` | `O(n)` | `O(n)` |
| Doubly / Circular LL | `O(n)` | `O(n)` | `O(1)`* | `O(1)`* |
| AVL Tree | `O(log n)` | `O(log n)` | `O(log n)` | `O(log n)` |
| Binary Heap (min / max) | `O(1)`† | `O(n)` | `O(log n)` | `O(log n)`‡ |
| Priority Queue (heap) | `O(1)`† | `O(n)` | `O(log n)` | `O(log n)`‡ |

<sub>* at a known position / head · † peek at root (min / max) · ‡ delete root / dequeue · building a heap from an array is `O(n)`</sub>

### Graphs

| Algorithm | Purpose | Time (adj. matrix) | Time (adj. list + heap) | Space |
|---|---|:---:|:---:|:---:|
| BFS | Level-order traversal, shortest path (unweighted) | `O(V²)` | `O(V + E)` | `O(V)` |
| DFS | Depth-first traversal | `O(V²)` | `O(V + E)` | `O(V)` |
| Dijkstra | Single-source shortest path (non-negative weights) | `O(V²)` | `O((V + E) log V)` | `O(V)` |
| Prim's | Minimum spanning tree (grows from a vertex) | `O(V²)` | `O(E log V)` | `O(V)` |
| Kruskal's | Minimum spanning tree (sorts edges + union-find) | — | `O(E log E)` | `O(V + E)` |

<sub>V = vertices · E = edges · the BFS, DFS, Dijkstra and Prim's code here uses an adjacency matrix</sub>

### Backtracking

| Problem | Time | Space |
|---|:---:|:---:|
| N-Queens | `O(N!)` | `O(N²)` |
| Rat in a Maze | `O(2^(N²))` | `O(N²)` |
| Combinations (n choose k) | `O(k · C(n, k))` | `O(k)` |
| Word Search (grid) | `O(R · C · 4^L)` | `O(L)` |
| Sudoku (9×9) | `O(9^m)` | `O(1)` |

<sub>R × C = grid size · L = word length · m = number of empty cells</sub>

---

## ✦ Quick Start

```bash
# clone
git clone https://github.com/AhmedMustafa-0817/data-structures.git
cd data-structures

# compile any file
g++ -std=c++17 -Wall -o run 04-binary-search-tree/bst.cpp

# run
./run
```

---

---

---

<div align="center">

⭐ *If this helped you study, a star is appreciated.*

<img src="https://capsule-render.vercel.app/api?type=waving&color=0:6366f1,50:8b5cf6,100:ec4899&height=100&section=footer" width="100%" alt=""/>

</div>
