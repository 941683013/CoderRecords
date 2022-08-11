package LeetCode;

public class Solution_1374 {
    public String generateTheString(int n) {
        StringBuffer b = new StringBuffer();
        if(n % 2 ==0) {
            for(int i = 1; i < n; i++) b.append('a');
            b.append('b');
        }
        else {
            for(int i = 1; i <= n; i++) b.append('a');
        }
        return b.toString();
    }
}