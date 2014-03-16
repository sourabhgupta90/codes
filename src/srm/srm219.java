package srm;

import java.util.LinkedList;
import java.util.Queue;

class srm219 {
	public static void main(String[] args) {

		srm219 obj = new srm219();
		String[] favorites = { "0 2", "1", "0 1" };
		System.out.println(obj.calculateTime(favorites));
	}

	public int calculateTime(String[] favorites) {
		int time = 0;
		Queue<state> queue = new LinkedList<state>();
		state root = new state();
		root.initializeRootNode(favorites);

		while (!queue.isEmpty()) {
			state curPos = queue.poll();
			updateNode(curPos);
			for (state v : generatePos(curPos.eatenState, curPos.startIndex,
					curPos.timeTaken)) {
				if (isReached(v)) {
					return v.timeTaken;
				}
			}
		}
		return time;

	}

	public void updateNode(state curpos) {
		curpos.timeTaken += curpos.timeTaken;
		
	}

	public Queue<state> generatePos(int[] pes, int si, int tt) {
		Queue<state> queue = new LinkedList<state>();

		return queue;
	}

	public boolean isReached(state s) {
		for (int t = 0; t < s.eatenState.length; t++) {
			if (s.eatenState[t] == 0) {
				return false;
			}
		}
		return true;
	}
}

class state {
	public int eatenState[];
	public int startIndex;
	public int timeTaken;
	

	public void state() {

	}

	public void initializeRootNode(String[] favorites) {
		timeTaken = 0;
		startIndex = 0;
		eatenState = new int[favorites.length];
		for (int t = 0; t < favorites.length; t++) {
			eatenState[t] = 0;
		}
	}
}
