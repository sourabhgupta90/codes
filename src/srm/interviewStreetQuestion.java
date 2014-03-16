package srm;

import java.util.ArrayList;
import java.util.List;
class interviewStreetQuestion {
	public static void main(String[] args) {
		int n = 10;
		List <Integer> factor = new ArrayList<Integer>();
	    for (int t = 2; t < n; t++) {
	        if( n % t == 0 ){
	            factor.add(t);
	        }
	    }
	    int a = 1;
	    int b = 1;
	    
	    for (int t = 0; t < factor.size(); t++) {
	        a *= factor.get(t);
	        System.out.print(factor.get(t));
	    }
	    for (int t = n-1; t > 0 ; t--) {
	        b *= factor.get(t);
	    }
	    
	    System.out.print("start");
	    System.out.print(a);
	    System.out.print(" ");
	    System.out.print(b);
	}

	public int getNumbered(int n, int t) {
		int count = 0;
		if (t > n || (n < 10 && t == 0)) {
			return 0;
		}

		int array[] = new int[n + 1];

		for (int i = 0; i <= 9; i++) {
			if (t == 0 && i == 0) {
				array[i] = 1;

			} else if (t == i) {
				array[i] = 1;
				count++;
			}
		}

		if (n < 10) {
			return array[t];
		}

		for (int i = 10; i <= n; i++) {
			int pre = i / 10;
			array[i] = array[pre] + array[i % 10];
			count = count + array[pre] + array[i % 10];
		}

		return count;
	}
}
