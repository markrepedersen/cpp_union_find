#include <vector>

using namespace std;

class DisjointSet {
public:
  int cost;
  int src;
  int dst;
};

int find(int x, vector<int> &parent) {
  if (parent[x] != x) {
    parent[x] = find(parent[x], parent);
  }
  return parent[x];
}

bool join(int a, int b, vector<int> &parent, vector<int> &rnk) {
  a = find(a, parent);
  b = find(b, parent);

  if (a == b) {
    return false;
  }

  if (rnk[a] > rnk[b]) {
    parent[b] = a;
  } else if (rnk[b] > rnk[a]) {
    parent[a] = b;
  } else {
    parent[b] = a;
    rnk[a]++;
  }
  return true;
}

int main() {}
