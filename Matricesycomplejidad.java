/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.matricesycomplejidad;

/**
 *
 * @author mirok
 */

import java.util.Random;
import java.util.Scanner;

public class Matricesycomplejidad {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n;
        
        //Tamaño de la matriz
        do{
            System.out.print("Ingrese el tamaño de la matriz ( 2 <= n <= 10): ");
            n = scanner.nextInt();
        } while(n < 2 || n > 10);
        
        int[][] matriz = new int[n][n]; //Creacion de la matriz
        Random random = new Random(); // Generar numeros aleatorios
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                matriz[i][j] = random.nextInt(25)+1;
            }
        }
        
        //Imprimir matriz
        System.out.println("Matriz Generada:");
        imprimirMatriz(matriz);
        
        //---------------------------------------------------------
        //Anillo (1...5)
        int maxAnillos = (n + 1) / 2;
        int anillo;
        do{
            System.out.print("Ingrese el numero de anillo a rotar (1 hasta " + maxAnillos + "): ");
            anillo = scanner.nextInt();
        }while(anillo < 1 || anillo > maxAnillos);
        
        //---------------------------------------------------------
        //Orientacion
        int direccion;
        do{
            System.out.print("Ingrese la direccion de rotacion |1| Izquierda / |2| Derecha : ");
            direccion = scanner.nextInt();
        }while(direccion != 1 && direccion != 2);
        
        //---------------------------------------------------------
        //Grados
        int grados;
        do{
            System.out.print("Ingrese los grados de rotacion (90, 180, 270): ");
            grados = scanner.nextInt();
        }while(grados != 90 && grados != 180 && grados != 270);
    }
    
    private static void imprimirMatriz(int[][] matriz)
    {
        for(int[] fila : matriz)
        {
            for(int num : fila)
            {
                System.out.print(num + "\t");
            }
            System.out.println();
        }
    }
    
    
    
}


