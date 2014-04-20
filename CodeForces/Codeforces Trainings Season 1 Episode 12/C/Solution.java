
import java.io.*;
import java.util.*;

public class Solution {
	public static void main(String[] s) {
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		double p = scanner.nextDouble();

    	long[][] C = new long[N + 1][N + 1];

		for (int i = 0; i <= N; ++i) {
			C[i][0] = 1;
			for (int j = 1; j <= i; ++j) {
				C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			}
		}

		BigDecimal[] F = new BigDecimal[N + 1];
		BigDecimal[] P = new BigDecimal[N * N + 1];
		P[0] = 1;

		System.out.println(N);
		System.out.println(P);
	}
}