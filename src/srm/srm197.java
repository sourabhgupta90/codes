package srm;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Set;

class srm197 {
	public static void main(String[] args) {
		srm197 obj = new srm197();
		String pieces[] = { "2,1", "-1,-2" };
		obj.attackPositions(pieces);
	}

	public void attackPositions(String[] pieces) {
		String[] loc;
		Map<Integer, Integer> pos = new HashMap();
		for (int t = 0; t < pieces.length; t++) {
			pos.putAll(generateLoc(pieces[t]));
		}
		System.out.print(pos.size());
		Iterator<Integer> test = pos.keySet().iterator();
		while (test.hasNext()) {
			int testAr = test.next();
			System.out.print(pos.get(testAr));
		}

	}

	public Map<Integer, Integer> generateLoc(String piece) {
		int x = piece.charAt(0) - '0';
		int y = piece.charAt(2) - '0';
		Map<Integer, Integer> pos = new HashMap();
		for (int i = -2; i < 2; i++) {
			for (int j = -2; j < 2; j++) {
				if (Math.abs(i) != Math.abs(j) && i != 0 && j != 0) {
					pos.put(i + x, y + j);
				}
			}
		}
		return pos;
	}
}