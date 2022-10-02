/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hacktoberfest;

import java.util.Scanner;

/**
 *
 * @author vuvie
 */
public class TriangeArea {
    private double params [] = new double[3];
    private String [] position = {"first", "second", "third"};
    
    public double [] getEdges() {
        return this.params;
    }
    
    private Scanner scanner = new Scanner(System.in);
    
    private void inputData(int i) {
        do{
            System.out.println("================");
            System.out.print("Please enter " + position[i] + " edge: ");
            try{
                String s = scanner.nextLine();
                params[i] = Double.parseDouble(s.trim());
                if(params[i] <= 0) {
                    System.out.println("Triangle's edge should be positive");
                    continue;
                }
                break;
            }catch(Exception ex){
                System.out.println("Please enter a number");
            }
            
        } while (true);
        
    }
    
    private double sum(double [] arrays){
        int sum = 0;
        for (double array : arrays) {
            sum += array;
        }
        return sum;
    }
    
    public double area() {
        double p = sum(params) / 2;
        return Math.sqrt(p * (p - params[0]) * (p - params[1]) * (p - params[2]));
    }
    
    public boolean isTriangle(double [] edges) {
        if(edges[0] > 0 && edges[1] > 0 && edges[2] > 0 && edges[0] + edges[1] > edges[2] 
                && edges[1] + edges[2] > edges[0] && edges [0] + edges[2] > edges[1]){
            return true;
        } else {
            return false;
        }
    }
    
    public static void main(String[] args) {
        TriangeArea triangle = new TriangeArea();
        for (int i = 0; i < 3; i++) {
            triangle.inputData(i);
        }
        if(triangle.isTriangle(triangle.getEdges())){
            System.out.println("Area of the triagle is " + triangle.area());
        } else {
            System.out.println("These edges can not create a triangle");
        }
        
    }
}
