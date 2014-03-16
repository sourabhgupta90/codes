package srm;

import java.util.ArrayList;
import java.util.List;

class srm146 {
	public static void main(String[] args) {
		srm146 obj = new srm146();
		int[] times = { 2, 4, 2, 4, 3, 6 };
		System.out.print(obj.minTime(times));
	}

	public int minTime(int[] times) {
		List <Integer> onOtherside =  new ArrayList<Integer>();
		List <Integer> timesList = new ArrayList<Integer>();
		for (int i : times){
			timesList.add(i);
		}
		return calculateCost(timesList, onOtherside, 0);
	}

	public List<Integer> removeList(List <Integer> onstart, int i){
		List<Integer> a = new ArrayList<Integer>();
		a.addAll(onstart);
		a.remove(i);
		return a;
	}
	public List<Integer> addList(List <Integer> onstart, int ele){
		List<Integer> a = new ArrayList<Integer>();
		a.addAll(onstart);
		a.add(ele);
		return a;
	}
	public int calculateCost( List <Integer> onstart, List <Integer> farside, int cost) {
		List <Integer> costList =  new ArrayList<Integer>();
		for (int i = 0 ; i < onstart.size(); i++){
			int ele = onstart.indexOf(i);
			costList.add(calculateCost(removeList(onstart, i), addList(farside, ele), cost));
		}
		int minEleCost = costList.indexOf(0);
		for(int t = 0; t < costList.size() ; t++ ){
			if(minEleCost > costList.indexOf(t)){
				minEleCost = costList.indexOf(t);
			}
		}
		return cost + minEleCost;
	}
}