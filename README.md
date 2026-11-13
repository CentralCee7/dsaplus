# DSA Plus — Divide and Conquer Practice & Solutions

This repository contains C++ implementations and practice variations for **Divide and Conquer** algorithms, including **Merge Sort**, **Max-Min**, and **28 Practice Variations**.

---

## Repository Structure

| File(s) | Description |
| :--- | :--- |
| [`devideandconq.cpp`](devideandconq.cpp) | Interactive menu-driven solution covering all **28 Divide & Conquer Practice Variations** across 7 categories. |
| [`cat1.cpp`](cat1.cpp) – [`cat74.cpp`](cat74.cpp) | Standalone C++ programs for each individual variation from the 28 Practice Variations sheet. |
| [`mergeSort.cpp`](mergeSort.cpp) | Interactive menu-driven solution for the **5 Merge Sort Practice Problems**. |
| [`minmax.cpp`](minmax.cpp) | Interactive menu-driven solution for the **6 Max-Min Practice Problems**. |
| [`docs/`](docs/) | Original PDF problem sheets and practice guides. |

### PDF Documents Included
- [Divide and Conquer — 28 Practice Variations with C++ Solutions](docs/Divide_and_Conquer_28_Practice_Variations.pdf)
- [Merge Sort Practice Problems](docs/Merge_Sort_Practice_Problems.pdf)
- [Max-Min Practice Problems](docs/Max_Min_Practice_Problems.pdf)

---

## Part 1: Merge Sort Practice Problems
*Implemented in [`mergeSort.cpp`](mergeSort.cpp)*

1. **Apply merge sort to sort the elements in descending order (largest to smallest).**
   - **Sample Input:** `{7, 2, 9, 4, 3, 8, 6, 1}`
   - **Sample Output:** `9 8 7 6 4 3 2 1`

2. **Sort the elements in a specific range using merge sort. The start and end index of the range will be given by the user.**
   - **Sample Input:** `{7, 2, 9, 4, 3, 8, 6, 1}`, `start index = 2`, `end index = 6`
   - **Sample Output:** `7 2 3 4 6 8 9 1`

3. **Sort integers according to their absolute values in ascending order, but keep the original signs. Use merge sort.**
   - **Sample Input:** `{7, -2, -9, 4, 3, -8, 6, -1}`
   - **Sample Output:** `-1 -2 3 4 6 7 -8 -9`

4. **Given an array of non-negative integers, sort the numbers according to the sum of their digits in ascending order using merge sort.**
   - **Sample Input:** `{19, 22, 37, 14, 41, 28, 30}`
   - **Digit sums:** `10(1+9), 4(2+2), 10(3+7), 5(1+4), 5(4+1), 10(2+8), 3(3+0)`
   - **Sample Output:** `30 22 14 41 19 37 28`

5. **Sort only the elements at odd indices (1st, 3rd, 5th, ...) in ascending order using Merge Sort.**
   - **Sample Input:** `{9, 8, 7, 6, 5, 4, 3, 2}`
   - **Sample Output:** `9 2 7 4 5 6 3 8`

---

## Part 2: Max-Min Practice Problems (Divide and Conquer)
*Implemented in [`minmax.cpp`](minmax.cpp)*

1. **Find the difference between the largest and smallest elements using divide and conquer.**
   - **Sample Input:** `{7, 2, 50, 4, 3, 8, 6, 1}`
   - **Sample Output:** `49`

2. **Given an array, find maximum and minimum values only between indices `p` and `q`, inclusive using divide and conquer. Take the value of `p` and `q` from user.**
   - **Sample Input:** `{7, 2, 9, 4, 3, 8, 6, 1}`, `p = 4`, `q = 7`
   - **Sample Output:** `Max: 8, Min: 1`

3. **Find the largest and smallest absolute values in an array containing both positive and negative integers using divide and conquer.**
   - **Sample Input:** `{-7, -9, 1}`
   - **Sample Output:** `Max: 9, Min: 1`

4. **Find the maximum and minimum among elements stored at even indices (0th, 2nd, 4th, …) using divide and conquer.**
   - **Sample Input:** `{11, 200, -6, 90, 7, 120, 4, 80, 12}`
   - **Sample Output:** `Max: 12, Min: -6`

5. **Given an array containing an even number of elements, pair the first element with the last, the second with the second-last, and so on using divide and conquer.**
   - **Input:** `A = {1, 2, 9, 4, 3, 8, 6, 1}`
   - **Mirror pairs:** `1 + 1 = 2`, `2 + 6 = 8`, `9 + 8 = 17`, `4 + 3 = 7`
   - **Output:** `Maximum pair sum: 17`, `Minimum pair sum: 2`

6. **Given an array of integers, find the largest and smallest absolute differences between consecutive elements, using divide and conquer.**
   - **Sample Input:** `{6, 1, -9, 8, 14, 10, 3}`
   - **Adjacent gaps:** `|6-1| = 5`, `|1+9| = 10`, `|-9-8| = 17`, `|8-14| = 6`, `|14-10| = 4`, `|10-3| = 7`
   - **Sample Output:** `Max: 17, Min: 4`

---

## Part 3: Divide and Conquer — 28 Practice Variations with C++ Solutions
*Based on the supplied Merge Sort and Max-Min code. Implemented in [`devideandconq.cpp`](devideandconq.cpp) and individual `cat*.cpp` files.*

> **Convention:** For second maximum/minimum, values are distinct. For the minimum-sum subarray, a non-empty consecutive subarray is required. The power function assumes `n >= 0`.

### Category 1 — Merge Sort Variations
*Practice: ordering and split strategy.*

#### 1. Sort the array in descending order ([`cat1.cpp`](cat1.cpp))
- **Change from base:** Reverse the comparison in `merge()`: choose `L[i]` when `L[i] >= R[j]`. Only the ordering comparison changes from `<=` to `>=`; the divide and combine structure remains the same.
```cpp
void merge(int A[], int l, int m, int r) {
    vector<int> L(A + l, A + m + 1), R(A + m + 1, A + r + 1);
    int i = 0, j = 0, k = l;
    while (i < (int)L.size() && j < (int)R.size()) {
        if (L[i] >= R[j]) A[k++] = L[i++];
        else A[k++] = R[j++];
    }
    while (i < (int)L.size()) A[k++] = L[i++];
    while (j < (int)R.size()) A[k++] = R[j++];
}
void mergeSort(int A[], int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeSort(A, l, m); mergeSort(A, m + 1, r);
    merge(A, l, m, r);
}
```

#### 2. Sort by dividing into three sections ([`cat12.cpp`](cat12.cpp))
- **Change from base:** Replace the two recursive calls with three ranges and merge three sorted parts.
```cpp
void merge3(int A[], int l, int m1, int m2, int r) {
    vector<int> T(A + l, A + r + 1);
    int i = 0, j = m1-l+1, k = m2-l+1, out = l;
    int e1 = j, e2 = k, e3 = (int)T.size();
    while (i < e1 || j < e2 || k < e3) {
        int best = INT_MAX, from = -1;
        if (i < e1 && T[i] < best) best=T[i], from=1;
        if (j < e2 && T[j] < best) best=T[j], from=2;
        if (k < e3 && T[k] < best) best=T[k], from=3;
        A[out++] = best;
        if (from==1) ++i; else if (from==2) ++j; else ++k;
    }
}
void mergeSort3(int A[], int l, int r) {
    if (l >= r) return;
    int n = r-l+1, m1 = l+n/3-1, m2 = l+2*n/3-1;
    if (m1 < l) m1=l;
    if (m2 <= m1) m2=m1+1;
    if (m2 >= r) { int m=(l+r)/2; mergeSort3(A,l,m); mergeSort3(A,m+1,r); return; }
    mergeSort3(A,l,m1); mergeSort3(A,m1+1,m2); mergeSort3(A,m2+1,r);
    merge3(A,l,m1,m2,r);
}
```

#### 3. Sort in descending order using three sections ([`cat13.cpp`](cat13.cpp))
- **Change from base:** Use three recursive sections, and choose the largest current value during merge (`INT_MIN` as initial best value instead of `INT_MAX`).
```cpp
// Core combine rule for descending 3-way merge:
if (i < e1 && T[i] > best) best=T[i], from=1;
if (j < e2 && T[j] > best) best=T[j], from=2;
if (k < e3 && T[k] > best) best=T[k], from=3;
```

#### 4. Sort only the first `n` elements in ascending order, where `n` is passed to the function ([`cat14.cpp`](cat14.cpp))
- **Change from base:** Make the array range parameterized; call `mergeSort(A, 0, n-1)`.
```cpp
void mergeSort(int A[], int l, int r) {
    if (l >= r) return;
    int m = l + (r-l)/2;
    mergeSort(A, l, m);
    mergeSort(A, m+1, r);
    merge(A, l, m, r); // same merge() as base code
}
// Call: mergeSort(A, 0, n-1);
```

---

### Category 2 — Sum of Even Numbers
*The returned value from each subproblem is its even-number sum.*

1. **Find the sum of even elements in `{4, 7, 2, 9}`** ([`cat2.cpp`](cat2.cpp)) — *Expected result: `6`*
2. **Find the sum of even elements in `{-6, 3, 10, 5, 8}`** ([`cat22.cpp`](cat22.cpp)) — *Expected result: `12`*
3. **Find the sum of even elements in an array of 1 element** ([`cat23.cpp`](cat23.cpp)) — *Example: `A={11}` -> `0`*
4. **Find the sum of even elements in `{0, 1, 2, 3, 4, 5, 6}`** ([`cat24.cpp`](cat24.cpp)) — *Expected result: `12`*

```cpp
int evenSum(int A[], int l, int r) {
    if (l == r) return (A[l] % 2 == 0 ? A[l] : 0);
    int m = (l+r)/2;
    return evenSum(A,l,m) + evenSum(A,m+1,r);
}
```

---

### Category 3 — Second Maximum
*Every recursive result returns `(maximum, second maximum)`.*

1. **Find the second maximum in `{7, 2, 9, 4, 3, 8, 6, 1}`** ([`cat3.cpp`](cat3.cpp)) — *Result: max = `9`, second max = `8`*
2. **Find the second maximum in `{12, 5, 18, 3, 14, 9}`** ([`cat32.cpp`](cat32.cpp)) — *Result: `14`*
3. **Find the second maximum in `{-8, -2, -15, -4}`** ([`cat33.cpp`](cat33.cpp)) — *Result: `-4`*
4. **Find the second maximum in `{21, 17, 30, 25, 11, 28, 19, 23}`** ([`cat34.cpp`](cat34.cpp)) — *Result: `28`*

```cpp
struct Pair { int mx, second; };
Pair secondMax(int A[], int l, int r) {
    if (r-l+1 == 2) {
        if (A[l] > A[r]) return {A[l], A[r]};
        return {A[r], A[l]};
    }
    int m=(l+r)/2;
    Pair L=secondMax(A,l,m), R=secondMax(A,m+1,r);
    int vals[4]={L.mx,L.second,R.mx,R.second};
    sort(vals, vals+4, greater<int>());
    return {vals[0], vals[1]};
}
```

---

### Category 4 — Second Minimum
*Minimum-version of the pair-returning Max-Min strategy.*

1. **Find the second minimum in `{7, 2, 9, 4, 3, 8, 6, 1}`** ([`cat4.cpp`](cat4.cpp)) — *Result: min = `1`, second min = `2`*
2. **Find the second minimum in `{12, 5, 18, 3, 14, 9}`** ([`cat42.cpp`](cat42.cpp)) — *Result: `5`*
3. **Find the second minimum in `{-8, -2, -15, -4}`** ([`cat43.cpp`](cat43.cpp)) — *Result: `-8`*
4. **Find the second minimum in `{21, 17, 30, 25, 11, 28, 19, 23}`** ([`cat44.cpp`](cat44.cpp)) — *Result: `17`*

```cpp
struct Pair { int mn, second; };
Pair secondMin(int A[], int l, int r) {
    if (r-l+1 == 2) {
        if (A[l] < A[r]) return {A[l], A[r]};
        return {A[r], A[l]};
    }
    int m=(l+r)/2;
    Pair L=secondMin(A,l,m), R=secondMin(A,m+1,r);
    int vals[4]={L.mn,L.second,R.mn,R.second};
    sort(vals, vals+4);
    return {vals[0], vals[1]};
}
```

---

### Category 5 — Calculate $b^n$
*Exponentiation by squaring (`n >= 0`).*

1. **Calculate $2^{10}$** ([`cat5.cpp`](cat5.cpp)) — *Result: `1024`*
2. **Calculate $3^5$** ([`cat52.cpp`](cat52.cpp)) — *Result: `243`*
3. **Calculate $7^0$** ([`cat53.cpp`](cat53.cpp)) — *Result: `1`*
4. **Calculate $(-2)^6$** ([`cat54.cpp`](cat54.cpp)) — *Result: `64`*

```cpp
long long power(long long b, int n) {
    if (n == 0) return 1;
    long long half = power(b, n/2);
    long long ans = half * half;
    if (n % 2 == 1) ans *= b;
    return ans;
}
```

---

### Category 6 — Count Multiples of 3 or 5
*Base case contributes `1` or `0`; combine step adds the counts.*

1. **Count qualifying values in `{3, 4, 5, 7, 9}`** ([`cat6.cpp`](cat6.cpp)) — *Count: `3` (`3, 5, 9`)*
2. **Count qualifying values in `{10, 11, 12, 13, 15, 20}`** ([`cat62.cpp`](cat62.cpp)) — *Count: `4` (`10, 12, 15, 20`)*
3. **Count qualifying values in `{-6, -2, 0, 8, 25}`** ([`cat63.cpp`](cat63.cpp)) — *Count: `3` (`-6, 0, 25`)*
4. **Count qualifying values in `{1, 2, 4, 7, 8, 11}`** ([`cat64.cpp`](cat64.cpp)) — *Count: `0`*

```cpp
int countMultiples(int A[], int l, int r) {
    if (l == r)
        return (A[l] % 3 == 0 || A[l] % 5 == 0) ? 1 : 0;
    int m=(l+r)/2;
    int left=countMultiples(A,l,m);
    int right=countMultiples(A,m+1,r);
    return left+right;
}
```

---

### Category 7 — Minimum-Sum Consecutive Subarray
*Divide-and-conquer summary stores total sum, minimum prefix, minimum suffix, and minimum subarray sum.*

1. **Find the minimum consecutive sum in `{3, -2, 5, -4, 6, -1, -2, 3, -5, 2}`** ([`cat7.cpp`](cat7.cpp)) — *Minimum sum: `-5` (from `[-5]`)*
2. **Find the minimum consecutive sum in `{4, -7, 2, -3, 5}`** ([`cat72.cpp`](cat72.cpp)) — *Minimum sum: `-8` (from `[-7, 2, -3]`)*
3. **Find the minimum consecutive sum in `{-2, -4, -1, -6}`** ([`cat73.cpp`](cat73.cpp)) — *Minimum sum: `-13` (from `[-2, -4, -1, -6]`)*
4. **Find the minimum consecutive sum in `{5, 2, 1, 4}`** ([`cat74.cpp`](cat74.cpp)) — *Minimum sum: `1` (from `[1]`)*

```cpp
struct Ans { int sum, prefix, suffix, best; };
Ans solveMinSub(int A[], int l, int r) {
    if (l == r) return {A[l], A[l], A[l], A[l]};
    int m=(l+r)/2;
    Ans L=solveMinSub(A,l,m), R=solveMinSub(A,m+1,r);
    Ans out;
    out.sum = L.sum + R.sum;
    out.prefix = min(L.prefix, L.sum + R.prefix);
    out.suffix = min(R.suffix, R.sum + L.suffix);
    out.best = min(min(L.best, R.best), L.suffix + R.prefix);
    return out;
}
```
