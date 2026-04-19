/*## Problem Statement

---

### Monk and the Magical Candy Bags

---

**Background:**

Our Monk loves candy! While taking a stroll in the park, he stumbled upon **N bags** with candies. The **i'th** bag contains **A_i** candies.

---

**What happens when Monk eats:**

He picks up a bag, eats **all the candies** in it and drops it on the ground. But as soon as he drops the bag, the number of candies in the bag **increases magically!**

Say the bag that used to contain **X** candies (before eating), now contains **⌊X/2⌋** candies, where **⌊ ⌋** is the **Greatest Integer / Floor Function**.

---

**The Goal:**

Amazed by the magical spell, Monk can now have a lot more candies! But he has to return home in **K minutes**.

In a **single minute**, Monk can consume all the candies in a **single bag**, regardless of the number of candies in it.

**Find the maximum number of candies that Monk can consume.**

---

**Input Format:**
```
First line  → Integer T (number of test cases)

For each test case:
  Line 1 → Two integers N and K
            N = number of bags
            K = number of minutes Monk has
  Line 2 → N space-separated integers
            representing candies in each bag
```

**Output Format:**
```
Print the answer to each test case on a new line.
```

**Constraints:**
```
1  ≤  T        ≤  10
1  ≤  N        ≤  10⁵
0  ≤  K        ≤  10⁵
0  ≤  A_i      ≤  10¹⁰
```

---

**Sample Input:**
```
1
5 3
2 1 7 4 2
```

**Sample Output:**
```
14
```

---

**Explanation:**
```
Initial state of bags → [2, 1, 7, 4, 2]

Step 1: Eat bag with 7 candies → bag becomes ⌊7/2⌋ = 3
        Bags now → [2, 1, 3, 4, 2]    Total eaten = 7

Step 2: Eat bag with 4 candies → bag becomes ⌊4/2⌋ = 2
        Bags now → [2, 1, 3, 2, 2]    Total eaten = 11

Step 3: Eat bag with 3 candies → bag becomes ⌊3/2⌋ = 1
        Bags now → [2, 1, 1, 2, 2]    Total eaten = 14

Hence Monk eats 7 + 4 + 3 = 14 ✅
```

---

**Time Limit:** 2 seconds
**Memory Limit:** 256 MB*/


#include <iostream>
#include <queue>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        priority_queue<long long> pq;

        for (int i = 0; i < N; i++) {
            long long x;
            cin >> x;
            pq.push(x);
        }

        long long total = 0;

        for (int i = 0; i < K; i++) {
            long long maxCandies = pq.top();
            pq.pop();

            total += maxCandies;

            long long newValue = maxCandies / 2;
            pq.push(newValue);
        }

        cout << total << endl;
    }

    return 0;
}
