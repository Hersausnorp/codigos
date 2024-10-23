/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package resources;

/**
 *
 * @author Andres Valencia 0222110032
 */

/******************************************
 * Juan Carlos García Ojeda               *
 *                                        * 
 * Programa de Ingeniería de Sistemas     *
 * Facultad de Ingeniería                 *
 * ==============================         *
 * Universidad de Cartagena - 2022        *
 ******************************************/
public class Soluciones {
    
    public static Stack<Integer> decimal_Binary(int n){
        Stack<Integer> stack = new Stack<>();
        
        while(n > 0 ){
            int aux = n % 2;
            n /= 2;
            stack.push(aux);
        }
        
        return stack;
    }
    
    public static boolean esPalindromo(String palabra){
        Stack<Character> stack = new Stack<>();
        
        String[] pair = palabra.toUpperCase().split(" & ");
        if (pair.length != 2) {
            System.out.println("Formato incorrecto");
            return false;
        }

        String X = pair[0];
        String Y = pair[1];

        for (int i = 0; i < Y.length(); i++) {
            stack.push(Y.charAt(i));    
        }

        if (stack.getTamaño() != X.length()) {
            return false;
        }

        int index = 0;
        while (!stack.estaVacia()) {
            if (X.charAt(index) != stack.pop()) {
                return false;
            }
            index++;
        }

        return true;
        
        
    }
}
