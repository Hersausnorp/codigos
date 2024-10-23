/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.linkedlist;

import java.util.Scanner;

/**
 *
 * @author mirok
 */
public class LinkedList {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ListInfo Listinfo = new ListInfo();
        int op = 0;
        
        do{
            System.out.println("1. Agregar Lista");
            System.out.println("2. Mostrar lista");
            System.out.println("3. Revertir");
            op = scanner.nextInt();
            
            switch(op)
            {
                case 1:
                    System.out.print("Digite el numero: ");
                    int n1 = scanner.nextInt();
                    Listinfo.add(n1);
                    break;
                    
                case 2:
                    Listinfo.showList();
                    System.out.println("");
                    break;
                
                case 3:
                    Listinfo.reverse();
                    break;
                    
            }
            
        }while(op != 3);
        
        
    }
}
