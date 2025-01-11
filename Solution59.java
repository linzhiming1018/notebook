class Solution59 {
    public int[][] generateMatrix(int n) {
        int[][] a = new int[n][n];
        // 1 <= n <= 20
        if (n > 1) {
            int round = 0, step = n - 1, count = 0;
            while (round < n / 2) {
                // rightward
                for (int i = 0; i < step; i++)
                    a[round][round + i] = ++count;
                // downward
                for (int i = 0; i < step; i++)
                    a[round + i][n - 1 - round] = ++count;
                // leftward
                for (int i = 0; i < step; i++)
                    a[n - 1 - round][n - 1 - round - i] = ++count;
                // upward
                for (int i = 0; i < step; i++)
                    a[n - 1 - round - i][round] = ++count;
                step -= 2;
                round++;
            }
            if (n % 2 == 1)
                a[n / 2][n / 2] = ++count;
        } else
            a[0][0] = 1;
        return a;
    }
}