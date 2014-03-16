class GraphTraversal {
	public static void main(String[] args) {
		GraphTraversal obj = new GraphTraversal();

		GraphNode root = obj.generateGraphNode(1);

		root.value = 1;
		root.neighbour[0] = obj.generateGraphNode(2);
		root.neighbour[1] = obj.generateGraphNode(3);
		root.neighbour[2] = obj.generateGraphNode(4);

		GraphNode secondNode = root.neighbour[0];
		secondNode.neighbour[0] = obj.generateGraphNode(5);

		//Graph represtation depth with be 2 
		//     1
		//  2  3  4
		//5 
		
		System.out.println(obj.getGraphDepth(root, 0));
	}

	public GraphNode generateGraphNode(int val) {
		GraphNode newNode = new GraphNode();
		newNode.value = val;
		return newNode;
	}

	public int getGraphDepth(GraphNode node, int depth) {
		int nodeDepth = depth;
		for (int t = 0; t < node.neighbour.length && node.neighbour[t] != null; t++) {
			int newDepth = getGraphDepth(node.neighbour[t], depth + 1);
			if (nodeDepth < newDepth) {
				nodeDepth = newDepth;
			}
		}
		return nodeDepth;
	}
}

class GraphNode {
	public int value;
	public GraphNode neighbour[] = new GraphNode[5];
	//Max 5 neighbour in the graph
}
