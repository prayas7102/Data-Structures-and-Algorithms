/**
 * IntersectionOfSortedArray
 */
public class IntersectionOfSortedArray {
	public static void main(String[] args) {
		int arr1[] = { 1, 1, 2, 3, 4, 5 };
		int arr2[] = { 2, 3, 4, 4, 5, 6 };
		// anser should be sorted intersection of above arrays
		int p1 = 0;
		int p2 = 0;
		int n = arr1.length;
		int m = arr2.length;
		int[] arr3 = new int[m + n];
		// last no. entered into array to filter identical no.
		int last = -1, i = 0;
		while (p1 < n && p2 < m) {
			if (arr1[p1] > arr2[p2]) {
				p2++;
			} else if (arr1[p1] < arr2[p2]) {
				p1++;
			} else if (arr1[p1] == arr2[p2]) {
				// checking if last ele is same as arr2[p2]
				int equalElement = arr2[p2];
				if (last == equalElement) {
					p2++;
					continue;
				}
				last = equalElement;
				arr3[i] = last;
				p2++;
				p1++;
				i++;
			}

		}
		// print final arrays
		for (int k = 0; k < n + m; k++) {
			System.out.print(arr3[k] + " ");
		}
	}
}