import java.util.*;

public class travellingSalesPerson {
	
	public static int cost[][], n;

	public static void read() {
		Scanner sc = new Scanner(System.in);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cost[i][j] = sc.nextInt();
			System.out.print("\t");
		}
	}

	public static int tsp(int start, int[] tour) {
		int temp[] = new int[n];
		int mintour[] = new int[n];
		int mincost;
		int ccost;
		if (start == n - 2)
			return cost[tour[n - 2]][tour[n - 1]] + cost[tour[n - 1]][0];
		mincost = 999;
		for (int i = start + 1; i < n; i++) {
			for (int j = 0; j < n; j++)
				temp[j] = tour[j];
			temp[start + 1] = tour[i];
			temp[i] = tour[start + 1];
			if (cost[tour[start]][tour[i]] + (ccost = tsp(start + 1, temp)) < mincost) {
				mincost = cost[tour[start]][tour[i]] + ccost;
				for (int k = 0; k < n; k++)
					mintour[k] = temp[k];
			}
		}
		for (int i = 0; i < n; i++)
			tour[i] = mintour[i];
		return mincost;
	}

	public static void main(String[] args) {
		System.out.println("\nWELCOME\n\nEnter:-");
		Scanner sc = new Scanner(System.in);
		System.out.print(" Number of Cities: ");
		n = sc.nextInt();
		cost = new int[n][n];
		int[] tour = new int[n];
		System.out.print(" (" + n + " X " + n +") Cost Matrix:\n\t");
		read();
		for (int i = 0; i < n; i++)
			tour[i] = i;
		int min = tsp(0, tour);
		System.out.println("\nMinimum Cost: " + min);
		System.out.print("\nPath:-\n ");
		for (int i = 0; i < n; i++)
			System.out.print((tour[i] + 1 ) + " --> ");
		System.out.println("1");
	}
}

