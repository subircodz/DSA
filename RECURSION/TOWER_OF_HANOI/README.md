# Tower of Hanoi

This folder contains the classic Tower of Hanoi recursive problem implemented in C.

## File

```text
tower_of_hanoi.c
```

## Problem Statement

The Tower of Hanoi consists of:

- One Source Rod
- One Auxiliary Rod
- One Destination Rod
- N Disks of different sizes

The objective is to move all disks from the source rod to the destination rod while following these rules:

1. Only one disk can be moved at a time.
2. A larger disk cannot be placed on a smaller disk.
3. Only the top disk of a rod may be moved.

## Recursive Strategy

To move N disks:

1. Move N-1 disks from Source to Auxiliary.
2. Move the largest disk from Source to Destination.
3. Move N-1 disks from Auxiliary to Destination.

## Example

For:

```c
toh(3, 'A', 'B', 'C');
```

Output:

```text
Move disc 1 from A to C
Move disc 2 from A to B
Move disc 1 from C to B
Move disc 3 from A to C
Move disc 1 from B to A
Move disc 2 from B to C
Move disc 1 from A to C
```

## Time Complexity

```text
O(2^n)
```

## Space Complexity

```text
O(n)
```

due to recursive call stack usage.

## Concepts Practiced

- Recursion
- Base Case
- Recursive Case
- Call Stack
- Divide and Conquer Thinking

## Mathematical Formula

Minimum moves required:

```text
2^n - 1
```

where:

```text
n = number of disks
```

## YouTube Tutorial

Detailed explanation available on:

https://youtube.com/@ssutradhar35

## Author

Subir Sutradhar
