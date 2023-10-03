import java.util.HashSet;
import java.util.Set;

public class RemoveElementFromSortedArray {
	public static void main(String[] args) {
		int[] arr = { 1, 1, 4, 4, 6, 6, 7, 8, 9, 9 };

		// O(nlogn) complexity
		Set<Integer> s = new HashSet<Integer>(64);
		for (var i = 0; i < arr.length; i++) {
			s.add(arr[i]);
		}
		
		// O(n) complexity
		int j = 0;
		for (int i = 1; i < arr.length; i++) {
			System.out.println(arr[j] + " " + arr[i]);
			if (arr[i] != arr[j]) {
				arr[j+1] = arr[i];
				j++;
			}
		}
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
	}
}
