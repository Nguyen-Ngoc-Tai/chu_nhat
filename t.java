package bai_java;

import java.util.Scanner;

public class tai {
	
	public static String getterPointABC (double point) {
		if ( point >= 8.5 ) return "A";
		else if ( point >= 7 && point <= 8.4 ) return "B";
		else if ( point >= 5.5 && point <= 6.9 ) return "C";
		else if ( point >= 4 && point <= 5.4 ) return "D";
		else return "F";
	}
	
	public static String getterType (String pointABC) {
		String result = pointABC;
		switch (result) {
			case "A" :
				return "gioi";
			case "B" :
				return "Kha";
			case "C" :
				return "Trung Binh";
			case "D" :
				return "Yeu";
			case "F" :
				return "Kem";
		}
		return result;
	}

	public static void main(String[] args) {
		
		Scanner input = new Scanner (System.in);
		
		//Var declaration
		String name, className, pointNMLTABC, pointKTLTABC, typeNMLT, typeKTLT;
		double pointNMLT, pointKTLT;
		
		//Input data
		System.out.println("Nhap ho ten sinh vien");
		name = input.nextLine();
		System.out.println("Nhap ten lop");
		className = input.nextLine();
		
		do {
			System.out.println("Nhap diem mon nhap mon lap trinh");
			pointNMLT = input.nextDouble();
		} while ( pointNMLT < 0 );
		pointNMLTABC = getterPointABC(pointNMLT);
//		typeNMLT = getterType(pointNMLTABC);
		
		do {
			System.out.println("Nhap diem mon ki thuat lap trinh");
			pointKTLT = input.nextDouble();
		} while ( pointKTLT < 0 );
		pointKTLTABC = getterPointABC(pointKTLT);
		//typeKTLT = getterType(pointKTLTABC);
	
		
		//Output data
		System.out.println("Ho va ten sinh vien : " + name);
		System.out.println("Lop : " + className);
		System.out.println("Ket qua hoc tap cac mon lap trinh : ");
		System.out.println("1.Nhap mon lap trinh : " + pointNMLT + " Diem chu : " + pointNMLTABC /*+ " Xep loai : " + typeNMLT*/ );
		System.out.println("2.Ki thuat lap trinh : " + pointKTLT + " Diem chu : " + pointKTLTABC /*+ " Xep loai : " + typeKTLT*/ );
		System.out.print("bai nay viet de up len github");
		System.out.print("Nguyen Ngoc Tai");
        System.out.print("Oke bay gio thi sua mot ti nao");
	}

}