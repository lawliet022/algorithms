import java.util.*;
public class Main2{
	public static void main(String[] args){
		// Arrays
		String s = "Hello World";
		char[] s2 = s.toCharArray();
		s2[4] = 'p';
		System.out.println(s2);
		
		int[] b = new int[5];
		System.out.println(s2.length);
		
		int[] a = {5,4,3,2,1};
		Arrays.sort(a);

		System.out.println(Arrays.toString(a));
		for(int i = 0; i < a.length; i++)
			System.out.print(a[i] + " ");
			
	}
}
