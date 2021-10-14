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
//format of these function: ax^2 + bx + c = 0
public class QuadraticEquation {
    private double params [] = new double[3];
    private double x1 = 0;
    private double x2 = 0;
    private double delta = 0;
    private String [] position = {"first", "second", "third"};
    
    public double getX1() {
        return this.x1;
    }
    
    public double getX2() {
        return this.x2;
    }
    
    private Scanner scanner = new Scanner(System.in);
    
    private void inputData(int i) {
        do{
            System.out.print("Please enter " + position[i] + " parameter: ");
            try{
                String s = scanner.nextLine();
                params[i] = Double.parseDouble(s.trim());
                if(i == 0 && params[i] == 0){
                    System.out.println("First parameter should be different from 0");
                    continue;
                }
                break;
            }catch(Exception ex){
                System.out.println("Please enter a number");
            }
            
        } while (true);
        System.out.println("================");
    }
    
    
    
    
    
    public QuadraticEquation(){
        
        
    }
    
    public boolean  solve(){
        delta = params[1] * params[1] - 4 * params[0] * params[2];
        if (delta >= 0) {
            x1 = (-params[1] + Math.sqrt(delta)) / (2 * params[0]);
            x2 = (-params[1] - Math.sqrt(delta)) / (2 * params[0]);
            return true;
        } else {
            return false;
        }
    }
    
    public static void main(String[] args) {
        QuadraticEquation equation = new QuadraticEquation();
        for (int i = 0; i < 3; i++) {
            equation.inputData(i);
        }
        if(equation.solve()){
            if(equation.getX1() == equation.getX2()) {
                System.out.println("Function has only 1 solution is " + equation.getX1());
            } else {
                System.out.println("Function has 2 solutions:");
                System.out.println("x1 = " + equation.getX1());
                System.out.println("x2 = " + equation.getX2());
            }
        } else {
            System.out.println("function has no solution");
        }
    }
    
}
