#include <vector>
#include <iostream>
#include <string>
using namespace std;

class SegmentTree {
public:
    SegmentTree(long long n, vector<long long>& a) {
        this->n = n;
        tree.resize(4 * n);
        lazy.resize(4 * n);
        build(1, 0, n - 1, a);
    }

    void build(long long v, long long tl, long long tr, vector<long long>& a) {
        if (tl == tr) {
            tree[v] = a[tl];
        }
        else {
            long long tm = (tl + tr) / 2;
            build(v * 2, tl, tm, a);
            build(v * 2 + 1, tm + 1, tr, a);
            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }
    }

    void push(long long v, long long tl, long long tr) {
        if (lazy[v] != 0) {
            tree[v] += (tr - tl + 1) * lazy[v];
            if (tl != tr) {
                lazy[v * 2] += lazy[v];
                lazy[v * 2 + 1] += lazy[v];
            }
            lazy[v] = 0;
        }
    }

    void update(long long v, long long tl, long long tr, long long l, long long r, long long addend) {
        push(v, tl, tr);
        if (l > r) {
            return;
        }
        if (l == tl && r == tr) {
            lazy[v] += addend;
            push(v, tl, tr);
        }
        else {
            long long tm = (tl + tr) / 2;
            update(v * 2, tl, tm, l, min(r, tm), addend);
            update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);
            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }
    }

    long long query(long long v, long long tl, long long tr, long long l, long long r) {
        push(v, tl, tr);
        if (l > r) {
            return 0;
        }
        if (l == tl && r == tr) {
            return tree[v];
        }
        long long tm = (tl + tr) / 2;
        return query(v * 2, tl, tm, l, min(r, tm)) +
            query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }

private:
    long long n;
    vector<long long> tree;
    vector<long long> lazy;
};

int main() {
    long long n, q;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    SegmentTree tree(n, a);
    cin >> q;
    for (long long i = 0; i < q; i++) {
        string query;
        cin >> query;
        if (query == "Add") {
            long long l, r, x;
            cin >> l >> x;
            r = l;
            tree.update(1, 0, n - 1, l, r, x);
        }
        else {
            long long l, r;
            cin >> l >> r;
            cout << tree.query(1, 0, n - 1, l, r - 1) << endl;
        }
    }
    return 0;
}
