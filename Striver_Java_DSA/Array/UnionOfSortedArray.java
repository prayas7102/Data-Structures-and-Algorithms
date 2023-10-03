public class UnionOfSortedArray {
	public static void main(String[] args) {
		int arr1[] = { 1, 1, 2, 3, 4, 5 };
		int arr2[] = { 2, 3, 4, 4, 5, 6 };
		int p1 = 0;
		int p2 = 0;
		int n = arr1.length;
		int m = arr2.length;
		int[] arr3 = new int[m + n];
		// last no. entered into array to filter identical no.
		int last = -1, i = 0;
		while (p1 < n && p2 < m) {
			if (arr1[p1] >= arr2[p2]) {
				// checking if last ele is same as arr2[p2]
				if (last == arr2[p2]) {
					p2++;
					continue;
				}
				last = arr2[p2];
				arr3[i] = last;
				p2++;
			} else {
				// checking if last ele is same as arr1[p1]
				if (last == arr1[p1]) {
					p1++;
					continue;
				}
				last = arr1[p1];
				arr3[i] = last;
				p1++;
			}
			i++;
		}
		// to cover left over ele if any in arr1
		if (p1 < n) {
			while (p1 < n) {
				arr3[i] = arr1[p1];
				p1++;
				i++;
			}
		}
		// to cover left over ele if any in arr2
		if (p2 < m) {
			while (p2 < m) {
				arr3[i] = arr2[p2];
				p2++;
				i++;
			}
		}
		for (int k = 0; k < n + m; k++) {
			System.out.print(arr3[k] + " ");
		}
	}
}
