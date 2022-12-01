int N, a, b, n, m;
char inp[110];
char graph[100][100];
bool vis[100][100];
int x[4] = { 0, 0, -1, 1 };
int y[4] = { 1, -1, 0, 0 };
 
int fill(int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || graph[i][j] == '1')
        return 0;
    vis[i][j] = true;
    int ans = 1;
    for(int k = 0; k < 4; k++) {
        ans += fill(i + x[k], j + y[k]);
    }
    return ans;
}
int main() {
    scanf("%d", &N);
    while(N--) {
        scanf("%d %d\n", &a, &b);
        a--; b--;
        memset(vis, false, sizeof vis);
        n = 0;
        while(gets(inp) && strlen(inp) > 0) {
            strcpy(graph[n], inp);
            n++;
        }
        m = strlen(graph[0]);
        printf("%d\n", fill(a, b));
        if(N) printf("\n");
    }   
}
