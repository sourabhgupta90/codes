package srm;

import java.util.LinkedList;
import java.util.Queue;

class srm609 {
	public static void main(String[] args) {
		srm609 obj = new srm609();
		System.out.print(obj.minPacks(78, 53, 64));
	}

	public int minPacks(int R, int G, int B) {
		LeftBalls newObj = new LeftBalls(R,G,B);
		Queue<LeftBalls> q = new LinkedList<LeftBalls>();
		q.add(newObj);
		int minPack = 2232323;
		while(!q.isEmpty()){
			LeftBalls child = q.poll();
			Queue<LeftBalls> cq = generatePackages(child);
			if (cq != null){
				q.addAll(cq);
			}
			if(checkBalls(child) && minPack > child.packageUsed){
				minPack = child.packageUsed;
			}
		}
		return minPack;
	}
	public boolean checkBalls(LeftBalls obj){
		if(obj.bl == 0 && obj.gl == 0 && obj.rl == 0){
			obj.lb = 0;
		}
		return obj.lb == 0;
	}
	public Queue<LeftBalls> generatePackages(LeftBalls obj) {
		if (checkBalls(obj) == true){
			return null;
		}
		Queue<LeftBalls> q = new LinkedList<LeftBalls>();
		int complicated = 0;
		if (obj.rl > 2) {
			q.add(createPack(0, obj));
			complicated++;
		}
		if (obj.gl > 2) {
			q.add(createPack(1, obj));
			complicated++;
		}
		if (obj.bl > 2) {
			q.add(createPack(2, obj));
			complicated++;
		}
		if (obj.bl > 0 && obj.gl > 0 && obj.rl > 0) {
			q.add(createPack(3, obj));
			complicated++;
		}
		if (complicated == 0){
			q.add(complicatedPack(obj));
		}
		return q;
	}
	
	public LeftBalls complicatedPack(LeftBalls obj1) {
		LeftBalls obj = new LeftBalls(obj1.rl, obj1.gl, obj1.bl);
		if (obj.rl > 0) {
			obj.rl = 0;
			obj.inPack(obj1.packageUsed);
		}
		if (obj.gl > 0) {
			obj.gl = 0;
			obj.inPack(obj1.packageUsed);
		}
		if (obj.bl > 0) {
			obj.bl = 0;
			obj.inPack(obj1.packageUsed);
		}
		return obj;
	}
	
	public LeftBalls createPack(int a, LeftBalls obj) {
		LeftBalls newObj = new LeftBalls(obj.rl, obj.gl, obj.bl);
		if (a == 0) {
			newObj.rl = newObj.rl  - 3; 
		}
		if (a == 1) {
			newObj.gl = newObj.gl  - 3;
		}
		if (a == 2) {
			newObj.bl = newObj.bl  - 3;
		}
		if (a == 3) {
			newObj.bl = newObj.bl  - 1;
			newObj.rl = newObj.rl  - 1;
			newObj.gl = newObj.gl  - 1;
		}
		newObj.inPack(obj.packageUsed);
		return newObj;
	}
}

class LeftBalls {
	public int rl;
	public int gl;
	public int bl;
	public int lb;
	public int packageUsed = 0;

	public LeftBalls(int R, int G, int B) {
		rl = R;
		gl = G;
		bl = B;
		lb = R + G + B;
	}

	public void inPack(int ppu) {
		packageUsed = ppu + 1;
	}
}