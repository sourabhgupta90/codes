package srm;

public class srm605 {
	public static void main(String[] args) {

		srm605 obj = new srm605();
		String[] board = {"WBBB",
				 		  "WBBB",
		 				  "WWWW"};
		System.out.print(obj.measureSquareArea(board));
	}

	public int getNumber(String[] board) {
		int maxArea = 1;
		return maxArea;
	}

	public int getLength(int i, int j, int boardLength) {
		int width = boardLength - i;
		int length = boardLength - j;
		return width > length ? length  : width ;
	}

	public int measureSquareArea(String[] board) {
		int maxArea = 1;
		for (int x1 = 0; x1 < board.length; x1++) {
			for (int y1 = 0; y1 < board.length; y1++) {
				for (int sqlen = getLength(x1, y1, board.length); sqlen >= 2; sqlen--) {
					int squarePossible = 1;
					for (int x2 = x1 + sqlen; x2 > x1; x2--) {
						for (int y2 = y1 + sqlen; y2 > y1; y2--) {
							if (board[x2].charAt(y2) != 'W') {
								squarePossible = 0;
							}
						}
					}
					if (squarePossible == 1 && (sqlen)*(sqlen) > maxArea) {
						maxArea = (sqlen)*(sqlen);
						break;
					}
				}
			}
		}
		return maxArea;
	}

}
