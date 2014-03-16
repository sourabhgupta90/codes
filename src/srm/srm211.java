package srm;

import java.util.*;

class srm211 {
	public static void main(String[] args) {
		srm211 obj = new srm211();
		String []rectangles = {"0 292 399 307"};

		System.out.print(obj.sortedAreas(rectangles));
	}

	public int[] sortedAreas(String [] rectangles){
		int[] rectangleCoordinates = getRectangleCoordinate(rectangles);
		return rectangleCoordinates;
	}

	
	public int [] getRectangleCoordinate(String [] rectangles){
		int [][] rectanglesInt = {{}}; 
		for(int t = 0 ; t < rectangles.length ; t++){
			for(int i = 0 ; i < 2; i++){
				rectanglesInt[t][i] = Integer.parseInt(rectangles[t].split(" ")[i]);;
			}
			
		}
		return rectanglesInt;
	}
		
}






