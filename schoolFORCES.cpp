#include <iostream>
#include <vector>

using namespace std;

int g[100005];      // Người bạn thân
int nxt[100005];    // Người tiếp theo CÓ THỂ chưa biết tin
bool checked[100005];

// Hàm tìm người tiếp theo chưa biết tin (Path Compression)
int find_next(int u) {
    if (!checked[u]) return u;
    // Nếu người tiếp theo cũng đã biết tin, nhảy tiếp
    return nxt[u] = find_next(nxt[u]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    for (int i = 1; i <= n; i++) {
        cin >> g[i];
        nxt[i] = g[i]; // Ban đầu, người tiếp theo là bạn thân
    }

    vector<int> v(m), b(m);
    for (int i = 0; i < m; i++) cin >> v[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    int last_res = 0;

    for (int i = 0; i < m; i++) {
        long long a_calc = (1LL * v[i] + last_res - 1) % n + 1;
        int u = (int)a_calc;
        int hot = b[i];
        int current_res = 0;

        while (hot > 0) {
            // Nếu u đã biết tin, tìm người tiếp theo thực sự chưa biết
            if (checked[u]) {
                int next_u = find_next(u);
                
                // QUAN TRỌNG: Nếu cả vòng tròn đã biết tin (quay lại chính mình)
                // hoặc tìm mãi vẫn ra người đã biết, thì ta dừng truyền tin vì không còn ai mới.
                if (checked[next_u]) {
                    break; // Thoát vòng lặp while vì không còn ai để cộng res
                }
                u = next_u;
            }

            // Nếu u chưa biết tin
            if (!checked[u]) {
                checked[u] = true;
                current_res++;
                // Khi u biết tin, nxt[u] sẽ giúp nhảy đến bạn của u
                // find_next sẽ lo việc nén đoạn sau này
            }

            hot--;
            u = g[u]; // Luôn đi tiếp đến người bạn thân
        }

        cout << current_res << "\n";
        last_res = current_res;
    }

    return 0;
}