package srm;

import java.util.*;

class srm604 {
	public double xc;
	public double yc;

	public static void main(String[] args) {
		srm604 obj = new srm604();
		System.out.print(obj.BFSPowerofThree(1093, 2187));
	}

	public String BFSPowerofThree(double x, double y) {
		xc = x;
		yc = y;

		if (isRobatReached(0, 0)) {
			return "Possible";
		}

		Queue<double[]> q = new LinkedList<double[]>();

		double a[] = { 0, 0, 0 };
		q.add(a);

		int count = 0;

		while (!q.isEmpty()) {
			double currentNode[] = q.poll();

			for (double[] s : generatePossiblePositions(currentNode)) {
				if (isRobatReached(s[0], s[1])) {
					return "Possible";
				}
				q.add(s);
			}
			if (count == 2) {
				;
			}
			count++;

		}
		return "Impossible";
	}

	public Queue<double[]> generatePossiblePositions(double[] parentNode) {
		Queue<double[]> childQueue = new LinkedList<double[]>();
		double power = Math.pow(3, parentNode[2]);
		if (xc > parentNode[0]) {
			double node1[] = new double[3];
			node1[0] = parentNode[0] + power;
			node1[1] = parentNode[1];
			node1[2] = parentNode[2] + 1;
			childQueue.add(node1);
		}

		if (yc > parentNode[1]) {

			double node2[] = new double[3];
			node2[1] = parentNode[1] + power;
			node2[0] = parentNode[0];
			node2[2] = parentNode[2] + 1;
			System.out.println(node2[2]);
			childQueue.add(node2);
		}

		return childQueue;
	}

	public boolean isRobatReached(double x, double y) {

		return xc == x && yc == y;
	}

}
