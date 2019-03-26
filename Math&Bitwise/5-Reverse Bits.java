
public class Solution {

    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int a = 1 << 31;
        int b = 1;
        // 从n的第0位和第31位开始比较
        do {
            boolean p = (n & a) == a;
            boolean q = (n & b) == b;
            // n的对称位不同时为0或1时，进行交换
            if(p != q) {
                if(p) {
                    n &= ~a;
                    n |= b;
                } else {
                    n &= ~b;
                    n |= a;
                }
            }
            a >>>= 1;
            b <<= 1;
        } while(a > b);

        return n;
    }
}
