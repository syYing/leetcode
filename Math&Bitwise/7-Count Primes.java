
public class Solution {
    public int countPrimes(int n) {
        int count = 0;
        boolean[] isPrime = new boolean[n];
        Arrays.fill(isPrime, true);
        for(int i = 2; i < n; i++) {
            if(isPrime[i]) {
                count++;
                int temp = i + i;
                while(temp < n) {
                    isPrime[temp] = false;
                    temp += i;
                }
            }
        }
        return count;
    }
}