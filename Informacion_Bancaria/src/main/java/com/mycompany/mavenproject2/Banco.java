/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.mavenproject2;

import java.util.Scanner;

/**
 *
 * @author mirok
 */
public class Banco {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BancoInfo Bancoinfo = new BancoInfo();
        int op = 0;
        
        do {
            System.out.println("\n1. Agregar nueva Cuenta");
            System.out.println("2. Buscar cuenta");
            System.out.println("3. Realizar depositos");
            System.out.println("4. Realizar retiro");
            System.out.println("5. Eliminar cuenta");
            System.out.println("6. Mostrar todas las cuentas");
            System.out.println("7. Salir");
            System.out.print("\nSeleccione una opcion: ");
            op = scanner.nextInt();
            
            switch(op){
                case 1:
                    System.out.print("\nIngrese id de la cuenta: ");
                    int id = scanner.nextInt();
                    scanner.nextLine();
                    System.out.print("Ingrese el saldo inicial: ");
                    int saldo = scanner.nextInt();
                    System.out.print("Ingrese su nombre: ");
                    String name = scanner.nextLine();
                    scanner.nextLine();
                    
                    Bancoinfo.Addaccount(id, saldo, name);
                    break;
                    
                case 2:
                    System.out.println("\nIngrese id de la cuenta: ");
                    int id2 = scanner.nextInt();
                    Bancoinfo.search(id2);
                    break;
                    
                case 3:
                    System.out.print("\nIngrese el id de la cuenta: ");
                    int id3 = scanner.nextInt();
                    System.out.print("Saldo a depositar: $");
                    int amount = scanner.nextInt();
                    Bancoinfo.deposit(id3, amount);
                    break;
                    
                case 4:
                    System.out.print("\nIngrese el id de la cuenta: ");
                    int id4 = scanner.nextInt();
                    System.out.print("Valor a retirar: $");
                    int amount2 = scanner.nextInt();
                    Bancoinfo.withdraw(id4, amount2);
                    break;
                    
                case 5:
                    System.out.println("Ingrese el id de la cuenta: ");
                   int id5 = scanner.nextInt();
                   Bancoinfo.deleteAccount(id5);
                   break;
                   
                case 6:
                    Bancoinfo.showAccounts();
                    break;
                    
                case 7:
                    System.out.println("Saliendo del sistema...");
                    break;
                    
                default:
                    System.out.println("Opcion invalida");
            }
            
    }while(op != 7);
        
        scanner.close();
}
}