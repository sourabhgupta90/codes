package gfg.BTree;

class BTreeNode {

	int keys[];
	int t;
	BTreeNode C[];
	int n;
	boolean leaf;

	public BTreeNode(int _t, boolean _leaf) {
		t = _t;
		leaf = _leaf;
		keys = new int[2 * t - 1];
		C = new BTreeNode[2 * t];
		n = 0;
	}

	public void traverse() {
		int i;
		System.out.println("next Step");
		for (i = 0; i <= n; i++) {
			if (leaf == false) {
				C[i].traverse();
			}
			if (i != n) {
				System.out.println(keys[i]);
			}

		}
	}

	public void insertNonFull(int k, BTreeNode x) {

		int i = n; // index of rightmost element

		if (leaf == true) {
			// adding on roof node
			while (i >= 1 && keys[i - 1] > k) {
				keys[i] = keys[i - 1];
				i--;
			}
			keys[i] = k;
			n = n + 1;
		} else {
			while (i >= 1 && keys[i - 1] > k) {
				i--;
			}
			
			if (C[i].n == 2 * t - 1) {
				splitChild(i, x);

				if (keys[i] < k) {
					i++;
				}
			}
			C[i].insertNonFull(k, C[i]);
		}
	}

	public void splitChild(int i, BTreeNode newNode) {
		BTreeNode y = newNode.C[i];
		BTreeNode holdRestKeys = new BTreeNode(newNode.t, y.leaf);
		holdRestKeys.n = t - 1;
		for (int j = 0; j < t - 1; j++) {
			holdRestKeys.keys[j] = y.keys[j + t];
		}

		if (y.leaf == false) {
			for (int j = 0; j < t; j++) {
				holdRestKeys.C[j] = y.C[j + t];
			}
		}

		y.n = t - 1;

		// Here C and Keys are newNode attributes
		for (int j = n; j >= i + 1; j--) {
			C[j + 1] = C[j];
		}
		C[i + 1] = holdRestKeys;

		for (int j = n - 1; j >= i; j--) {
			keys[j + 1] = keys[j];
		}

		keys[i] = y.keys[t - 1];
		n = n + 1;
	}

}

class BTree {

	int t;
	BTreeNode root;

	public BTree(int k) {
		root = null;
		t = k;
	}

	public void insert(int k) {

		if (root == null) {
			root = new BTreeNode(t, true);
			root.keys[0] = k;
			root.n = 1;
		} else {
			// When array have a lot of elements
			if (root.n == 2 * t - 1) {
				BTreeNode newNode = new BTreeNode(t, false);
				newNode.C[0] = root;
				root = newNode;
				// splitting across i child
				newNode.splitChild(0, root);
				root.insertNonFull(k, root);
			} else {
				root.insertNonFull(k, root);

			}
		}
	}

	public void traverse() {
		root.traverse();
	}

	public static void main(String args[]) {
		BTree obj = new BTree(3);
		// [20, 44, 29, 29, 50, 3, 38, 28, 50, 12, 38, 44, 0, 13, 45, 30, 34,
		// 11, 9, 43]
		obj.insert(20);
		obj.insert(44);
		obj.insert(29);
		obj.insert(29);
		obj.insert(50);
		obj.insert(3);
		obj.insert(38);
		obj.insert(28);
		obj.insert(50);
		obj.insert(12);
		obj.insert(38);
		obj.insert(44);
		obj.traverse();
		// n element problem in it
		obj.insert(18);
		obj.insert(19);
		//
	}

}