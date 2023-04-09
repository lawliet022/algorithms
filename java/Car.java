import java.awt.*;

public class Car{
	
	int averageKilometerPerHour;
	String licensePlate;
	Color paintColor;
	boolean isLuxary;
	
	public Car(int inputAverageKilometerPerHour, String inputLicensePlate, Color inputPaintColor, boolean inputIsLuxary){
		this.averageKilometerPerHour = inputAverageKilometerPerHour;
		this.licensePlate = inputLicensePlate;
		this.paintColor = inputPaintColor;
		this.isLuxary = inputIsLuxary;
	}
}
