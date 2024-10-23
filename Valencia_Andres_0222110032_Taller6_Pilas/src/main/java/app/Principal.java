/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package app;
import resources.Node;
import resources.Stack;
import resources.Soluciones;
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
public class Principal {

    public static void main(String[] args) {
         int n = 49;
        Stack<Integer> binaryStack = Soluciones.decimal_Binary(n);
        System.out.print("Numero " + n + " en binario es: ");
        while (!binaryStack.estaVacia()) {
            System.out.print(binaryStack.pop());
        }
        System.out.println();

        
        String expresion1 = "cuarto & otrauc";
        String expresion2 = "anita & atina";

        boolean esPalindromo1 = Soluciones.esPalindromo(expresion1);
        boolean esPalindromo2 = Soluciones.esPalindromo(expresion2);

        System.out.println("Expresion: " + expresion1 + " es palindromo: " + esPalindromo1);
        System.out.println("Expresion: " + expresion2 + " es palindromo: " + esPalindromo2);
    }
}

