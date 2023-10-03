public class MoveZeroToEnd {
	static void swap(int[] arr, int i, int j) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	public static void main(String[] args) {
		int[] array = { 1, 2, 3, 0, 0, 0, 8, 9, 0, 8, 6, 5, 7, 0 };
		int j = -1;
		for (int i = 0; i < array.length; i++) {
			if (array[i] == 0) {
				j = i;
				break;
			}
		}
		for (int i = j + 1; i < array.length; i++) {
			if (array[i] != 0) {
				swap(array, i, j);
				j++;
			}
		}
		for (int i = 0; i < array.length; i++) {
			System.out.print(array[i] + " ");
		}
	}
}
