package srm;

import java.util.LinkedList;
import java.util.Queue;

class srm207500 {
	public static void main(String[] args) {
		String knight = "a1";
		String rook = "b3";
		String queen = "c5";

		srm207500 obj = new srm207500(knight, rook, queen);
		System.out.print(obj.CaptureThemAllBFS());
	}

	public String knightPos;
	public String rookPos;
	public String queenPos;

	public srm207500(String knight, String rook, String queen) {
		knightPos = knight;
		rookPos = rook;
		queenPos = queen;
	}

	public int CaptureThemAllBFS() {
		Queue<currentState> queue = new LinkedList<currentState>();
		currentState root = new currentState(knightPos);
		queue.add(root);
		int minimumSteps = 231221213;
		while (!queue.isEmpty()) {
			currentState currentNode = queue.poll();

			for (currentState childNodes : generatePos(currentNode)) {
				if (childNodes.cq == 1 && childNodes.cr == 1
						&& childNodes.steps < minimumSteps) {
					minimumSteps = childNodes.steps;
				}
			}
		}
		return minimumSteps;
	}

	public Queue<currentState> generatePos(currentState obj) {
		Queue<currentState> childNodes = new LinkedList<currentState>();

		for (int t = -2; t < 2; t++) {
			for (int j = -2; j < 2; j++) {
				if (Math.abs(t) != Math.abs(j) && t != 0 && j != 0) {
					childNodes.add(createChild(t, j, obj));
				}
			}
		}
		return childNodes;
	}

	public currentState createChild(int t, int j, currentState obj) {
		currentState childNode = new currentState();
		t = obj.cpos[0] + t;
		j = obj.cpos[1] + j;

		int childCQ = isCurrentPositionCapture(queenPos, t, j, obj.cq);
		int childCr = isCurrentPositionCapture(rookPos, t, j, obj.cr);
		childNode.intializeVariabe(t, j, childCQ, childCr);
		return childNode;
	}

	public int isCurrentPositionCapture(String obj, int t, int j,
			int captureStatus) {
		if (captureStatus == 1 && t == obj.charAt(0) - 'a'
				&& j == obj.charAt(1) - '0') {
			return 1;
		}
		return 0;
	}
}

class currentState {
	public int cq = 0;
	public int cr = 0;
	public int cpos[] = new int[2];
	public int steps = 0;

	public currentState() {

	}

	public void intializeVariabe(int t, int j, int pcq, int pcr) {
		cq = pcq;
		cr = pcr;
		cpos[0] = t;
		cpos[1] = j;
	}

	public currentState(String kPos) {
		cpos[0] = kPos.charAt(0) - 'a';
		cpos[1] = kPos.charAt(1) - '0';
	}
}
