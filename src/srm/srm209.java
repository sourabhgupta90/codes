package srm;
import java.lang.reflect.Array;
import java.util.*;
class srm209 {
	public static void main(String[] args) {
		String coun[] = { "ITA JPN AUS", "KOR TPE UKR", "KOR KOR GBR",
				"KOR CHN TPE" };
		Map<String, int[]> countryMedal = new HashMap<String, int[]>();
		for (int t = 0; t < coun.length; t++) {
			String s[] = coun[t].split(" ");
			for (int i = 0; i < s.length; i++) {
				if(countryMedal.containsKey(s[i])){
					int medal[] = countryMedal.get(s[i]);
					medal[i]++;
					countryMedal.put(s[i], medal);
				}else{
					int medal[] = new int[3];
					medal[i]++;
					countryMedal.put(s[i], medal);
				}
			}
		}
		
		for (String unicoun:  countryMedal.keySet() ) {
			System.out.print(unicoun);
			for(int t=0 ; t < countryMedal.get(unicoun).length; t++){
				System.out.print(countryMedal.get(unicoun)[t]);
			}
			System.out.println();
		}
	}
}
