/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.mavenproject2;

/**
 *
 * @author mirok
 */
public class BankNode {
    
    int idCuenta;
    int saldo;
    String nombre;
    BankNode next;
    
    public BankNode(int idCuenta, int saldo, String nombre){
        this.idCuenta = idCuenta;
        this.saldo = saldo;
        this.nombre = nombre;
        this.next = null;
    }
    
}
