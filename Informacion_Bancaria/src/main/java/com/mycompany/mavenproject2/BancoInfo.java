/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.mavenproject2;

/**
 *
 * @author mirok
 */
public class BancoInfo {
    
    private BankNode head;
    
    public BancoInfo(){
    head = null;
}
    
    //Metodo agregar cuenta
    public void Addaccount(int idCuenta, int saldo, String nombre){
        BankNode newAccount = new BankNode(idCuenta, saldo, nombre);
        
        if(head == null){
            head = newAccount;
        }else{
            BankNode temp = head;
            while(temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = newAccount;
        }
        System.out.println("\nCuenta agregada");
    }
    
    public void search(int idCuenta){
        if(head == null){
            System.out.println("No hay cuentas registradas");
            return;
        }
        
        BankNode temp = head;
        
        while(temp != null){
            if(temp.idCuenta == idCuenta){
                System.out.println("Saldo actual de la cuenta: #" + idCuenta + ": $" + temp.saldo);
                return;
            }
            
            temp = temp.next;
        }
        
        System.out.println("No se encontro la cuenta");
    }
    
    public void deposit(int idCuenta, int saldo){
        
        BankNode temp = head;
        
        while(temp != null){
            if(temp.idCuenta == idCuenta){
                temp.saldo += saldo;
                System.out.println("Deposito exitoso. Nuevo saldo: $" + temp.saldo);
                return;
            }
            temp = temp.next;
        }
        System.out.println("Cuenta no encontrada");
    }
    
    public void withdraw(int idCuenta, int saldo){
        BankNode temp = head;
        
        while(temp != null){
            if(temp.idCuenta == idCuenta){
                if(temp.saldo >= saldo){
                    temp.saldo -= saldo;
                    System.out.println("Nuevo saldo: $" + temp.saldo);
                }else{
                    System.out.println("Saldo insuficiente");
                }
                return;
            }
            temp = temp.next;
        }
        System.out.println("Cuenta no encontrada");
    }
    
    public void deleteAccount(int idCuenta){
        if(head == null){
            System.out.println("No hay cuentas registradas");
            return;
        }
        
        if(head.idCuenta == idCuenta){
            head = head.next;
            System.out.println("Cuenta eliminada");
            return;
        }
        
        BankNode temp = head;
        
        while(temp.next != null){
            if(temp.idCuenta == idCuenta){
                temp.next = temp.next.next;
                System.out.println("Cuenta eliminada");
                return;
            }
            temp = temp.next;
        }
        System.out.println("Cuenta no encontrada");
    }
    
    public void showAccounts(){
        if(head == null){
            System.out.println("No hay cuentas registradas");
            return;
        }
        
        BankNode temp = head;
        while(temp != null){
            System.out.println("ID: " + temp.idCuenta + ", Cliente: " + temp.nombre + ", Saldo: $" + temp.saldo);
            temp = temp.next;
        }
        
    }
}
