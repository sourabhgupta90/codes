package srm;

import java.util.Scanner;

class hackerRankCodeSprint5 {
	public static void main(String[] args) {
		hackerRankCodeSprint5 obj = new hackerRankCodeSprint5();
		long fiboSe = 10000;
		int[] fibi_1 = obj.getFiboSeriesEle(10000);
		

		System.out.println("Ele Starts");
		for (int i = 0; i < fibi_1.length; i++) {
			System.out.print(fibi_1[i]);
		}
		System.out.println("Ele ends");
	}

	public void IsFibo() {
		Scanner sc = new Scanner(System.in);
		int testCase = sc.nextInt();
		long fiboArray[] = new long[testCase];

		for (int t = 0; t < testCase; t++) {
			fiboArray[t] = sc.nextInt();
		}
		for (int t = 0; t < testCase; t++) {
			int[] result = getFiboSeriesEle(fiboArray[t]);
			System.out.println("Ele Starts");
			for (int i = 0; i < result.length; i++) {
				System.out.println(result[i]);
			}
			System.out.print("Ele ends");

		}
	}

	public int[] getFiboSeriesEle(long fiboEle) {
		int fibi_1[] = { 0 };
		int fibi_2[] = { 1 };
		int fibi_i[] = { 1 };
		for (double t = 2; t <= fiboEle; t++) {
			fibi_i = sumFibiEle(fibi_1, fibi_2);
			fibi_1 = fibi_2;
			fibi_2 = fibi_i;
		}
		return fibi_i;
	}

	public int[] sumFibiEle(int[] fibi_1, int[] fibi_2) {
		int sum[] = new int[fibi_2.length + 1];
		int carry = 0;

		int i = fibi_1.length - 1;
		int j = fibi_2.length - 1;

		for (; i >= 0 && j >= 0; i--, j--) {
			sum[j + 1] = ((fibi_2[j] + fibi_1[i] + carry)) % 10;
			carry = ((fibi_2[j] + fibi_1[i] + carry) / 10) % 10;
		}

		for (; j >= 0; j--) {
			sum[j + 1] = ((fibi_2[j] + carry)) % 10;
			carry = ((fibi_2[j] + carry) / 10) % 10;
		}

		if (carry != 0) {
			sum[j + 1] = carry;
		}
		
		return removePrefixZero(sum);
	}
	
	public int [] removePrefixZero(int [] sum){
		int i = 0 ;
		while(sum[i] == 0){
			i++;
		}
		int [] withoutZero = new int [sum.length - i];
		for(int t = 0; i < sum.length; i++, t++){
			withoutZero[t] = sum[i];
		}
		return withoutZero;
	}
}
