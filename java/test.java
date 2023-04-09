public class test{
	public static void main(String[] args){
		Dog d = new Dog(2,"Brown","German Sephard",2.5);
		d.bark();
		d.eat();
		d.changeBreed("Lebra");
		
		System.out.println(d.breed);
		
		System.out.println(Math.pow(5,2));
		
	}
}
