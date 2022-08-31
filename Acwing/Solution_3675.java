package Acwing;

import java.util.*;

public class Solution_3675 {

    public static int dx[] = {0, 1, 0, -1};
    public static int dy[] = {1, 0, -1, 0};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        while(t-- > 0) {
            int m = sc.nextInt(), n = sc.nextInt();
            String[] s = new String[m];
            for(int i = 0; i < m; i++) s[i] = sc.next();

            int k = sc.nextInt(), y1 = sc.nextInt(), x1 = sc.nextInt();
            int y2 = sc.nextInt(), x2 = sc.nextInt();

            int[][] dis = new int[m + 1][n + 1];
            for(int i = 0; i <= m; i++) {
                Arrays.fill(dis[i], Integer.MAX_VALUE);
            }

            PriorityQueue<Node> q = new PriorityQueue<>();;

            for(int i = 0; i < 4; i++) {
                q.add(new Node(0, x1, y1, i));
            }

            while(!q.isEmpty()) {
                Node cur = q.remove();
                int cnt = cur.dir;
                int x = cur.x;
                int y = cur.y;
                int dir = cur.dir;

                for(int i = 0; i < 4; i++) {
                    int a = x + dx[i];
                    int b = y + dy[i];
                    if(a >= 1 && a <= m && b >= 1 && b <= n && s[a - 1].charAt(b) == '.') {

                        if(i != dir) {
                            if(k == cnt) {
                                continue;
                            }
                            else {
                                if(cnt + 1 <= dis[a][b]) {
                                    dis[a][b] = cnt + 1;
                                    q.add(new Node(cnt + 1, a, b, i));
                                }
                            }
                        }
                        else if(cnt <= dis[a][b]) {
                            dis[a][b] = cnt;
                            q.add(new Node(cnt, a, b, i));
                        }
                    }
                }
            }

            if(dis[x2][y2] > k) {
                System.out.println("no");
            }
            else {
                System.out.println("yes");
            }

        }
    }

    static class Node implements Comparator<Node> {
        int dirCnt;
        int x;
        int y;
        int dir;

        public Node(int dirCnt, int x, int y, int dir) {
            this.dirCnt = dirCnt;
            this.dir = dir;
            this.x = x;
            this.y = y;
        }

        @Override
        public int compare(Node o1, Node o2) {
            return o1.dirCnt - o2.dirCnt;
        }

    }
}