package algorithm;

import java.util.Scanner;

public class Codeforces1059B {
	public static Scanner scanner = new Scanner(System.in);
	public static int n, m;
	public static char[][] arr = new char[1001][1001];
	public static int[][] curr = new int[1001][1001];
	public static void main(String[] args) {
		n = scanner.nextInt();
		m = scanner.nextInt();
		scanner.nextLine();
		for(int i=1; i<=n; i++){
			String string = scanner.nextLine();
			String[] stringArray = string.split("");

			for(int j=1; j<=m; j++){
				arr[i][j] = stringArray[j-1].charAt(0);
			}
		}
		String ret = "YES";
		for(int i=1; i<=n-2; i++){
			for(int j=1; j<=m-2; j++){
				boolean need = true;
				for(int ii=i; ii<=i+2; ii++){
					for(int jj=j; jj<=j+2; jj++){
						if(ii==i+1&&jj==j+1) continue;
						need &= (arr[ii][jj]=='#');
					}
				}
				if(need){
					for(int ii=i; ii<=i+2; ii++){
						for(int jj=j; jj<=j+2; jj++){
							if(ii==i+1&&jj==j+1) continue;
							curr[ii][jj]++;
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				if(arr[i][j]=='#' && curr[i][j]==0){
					ret = "NO";
				}
			}
		}
		System.out.println(ret);
	}
}
