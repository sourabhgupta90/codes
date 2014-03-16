import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class CodeForces {
	public static void main(String[] args) {
		CodeForces obj = new CodeForces();
		obj.Multitasking();
	}

	public void Multitasking() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int k = sc.nextInt();

		int sortArrays[][] = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int input = sc.nextInt();
				sortArrays[i][j] = input;
			}
		}

		Map<Integer, List<Integer>> keys = new HashMap<Integer, List<Integer>>();
		for (int i = 0; i < n; i++) {
			Map<Integer, List<Integer>> newKeys = getSortOperation(sortArrays[i]);
			keys.putAll(newKeys);
		}
		
		Set <Integer> setEle =  keys.keySet();
		Iterator<Integer> IterEle= setEle.iterator();
		int count = 0;
		
		while(IterEle.hasNext()){
			int keyStored = IterEle.next();
			count++;
			count += (keys.get(keyStored).size()-1);
		}
		System.out.println(count);
		IterEle= setEle.iterator();
		while(IterEle.hasNext()){
			int keyStored = IterEle.next();
			List<Integer> storedValues = keys.get(keyStored);
			for (int i = 0; i < storedValues.size(); i++) {
				System.out.print(keyStored);
				System.out.print(" ");
				System.out.println(storedValues.get(i));
			}
			
		}
		
	}

	public Map<Integer, List<Integer>> getSortOperation(int sortArray[]) {
		Map<Integer, List<Integer>> keys = new HashMap<Integer, List<Integer>>();
		if (sortArray.length >= 2) {
			for (int i = 0; i < sortArray.length - 1; i++) {
				for (int j = i + 1; j < sortArray.length; j++) {
					if(sortArray[i] > sortArray[j]){
						int temp = sortArray[i];
						sortArray[i] = sortArray[j]; 
						sortArray[j] = temp;
						List <Integer> tempArray = new ArrayList<Integer>();
						if(keys.containsKey(i+1)){
							tempArray = keys.get(i+1);
							tempArray.add(j+1); 
						}else{
							tempArray.add(j+1);
						}
						keys.put(i+1, tempArray);
					}
				}
			}
		}

		return keys;
	}
}
