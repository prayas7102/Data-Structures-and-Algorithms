/**
 * secondLargestElement
 */
public class SecondLargestElement {

	public static void main(String[] args) {
		int arr[] = { 1, 7, 7, 7, 7, 7, 7 };
		int sec = -1, lar = arr[0];
		for (var i = 1; i < arr.length; i++) {
			if (arr[i] > lar) {
				sec = lar;
				lar = arr[i];
			}
		}
		System.out.println(sec);
	}
}
