package srm;

import java.awt.List;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;

class srm233 {
	public static void main(String[] args) {
		String start = "aaaa";
		String end = "zzzz";
		String forbid[] = { "a a a z", "a a z a", "a z a a", "z a a a",
				"a z z z", "z a z z", "z z a z", "z z z a" };
		srm233 s = new srm233();
		s.BFS(start, end, forbid);
	}

	public void BFS(String start, String end, String[] forbid) {
		Queue<String> queueNodes = new LinkedList<String>();
		queueNodes.add(start);
		Map<String, Integer> dist = new HashMap<String, Integer>();
		dist.put(start, 0);
		int stepsRequired = 0;
		while (!queueNodes.isEmpty()) {
			String v = queueNodes.poll();
			for (String childNodes : generateNodes(v, end, forbid)) {
				if(childNodes.equals(end)){
					stepsRequired = dist.get(v) + 1;
					break;
				}
				if(dist.containsKey(childNodes)){
					continue;
				}
				int distV = dist.get(v);
				dist.put(childNodes, distV+1 );
			}
		}
	}

	public Queue<String> generateNodes(String v, String end, String forbid[]) {
		Queue<String> childNodes = new LinkedList<String>();
		for (int t = 0; t < v.length(); t++) {
			String child = generateString(v, end, t);
			if (!findOnForbid(forbid, child)) {
				childNodes.add(child);
			}
		}
		return childNodes;
	}

	public boolean findOnForbid(String[] forbid, String child) {
		for (int t = 0; t < forbid.length; t++) {
			if (forbid[t].equals(child)) {
				return false;
			}
		}
		return true;
	}

	public String generateString(String v, String end, int index) {
		char charStr[] = new char[v.length()];
		for (int i = 0; i < v.length(); i++) {
			charStr[i] = v.charAt(i);
		}
		charStr = v.toCharArray();
		int updateChar = charStr[index];
		if (charStr[index] < end.charAt(index)) {
			updateChar = updateChar + 1;
		} else {
			updateChar = updateChar + 1;
		}
		charStr[index] = (char) updateChar;

		return new String(charStr);
	}
}