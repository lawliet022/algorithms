public class Dog{
	int age;
	String color;
	String breed;
	double height;
	
	public Dog(int inputAge, String inputColor, String inputBreed, double inputHeight){
		this.age = inputAge;
		this.color = inputColor;
		this.breed = inputBreed;
		this.height = inputHeight;
	}
	
	public void bark(){
		System.out.println("Dog is barking");
	}
	public void eat(){
		System.out.println("Dog is Sleeping");
	}
	public void changeBreed(String newBreed){
		this.breed = newBreed;
	}
	
}
