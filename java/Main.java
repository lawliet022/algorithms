import java.util.Scanner;
import java.awt.*;


public class Main{
	public static void main(String[] args){
		System.out.println("Hello Girl");
		Car myCar = new Car(125,"HR13B0409",Color.BLUE,false);
		Car herCar = new Car(420,"DL12B0101",Color.RED,true);
		
		System.out.println("Her Car is Luxary ? " + herCar.isLuxary);
		System.out.println("Color of my car is " + myCar.paintColor);
		
		
		// *** Strings ***
		System.out.print("Her Name - ");
		
		Scanner sc = new Scanner(System.in);
		String s;
		s = sc.next();
		if(s.contains("pa")){
			System.out.println(s + " is " + "L"+ + "ve :p");
		
		}
		s.concat(" Hi!");		// would not affect s as a new copy is created but not assigned to anyone
		s += " Hi";				// new copy is created and assigned to s
		s = s.concat(" There!");
		
		// s[0] = 'x';	// can't do this as strings are immutable
		
		System.out.println(s.toLowerCase());
		int p = sc.nextInt();
		
		
		// *** String Builder ***
			System.out.print("nickname - ");
			StringBuilder s2 = new StringBuilder(sc.next());
			s2.setCharAt(2,'x');
			s2.append(s2);
			System.out.println(s2);
	}
}
