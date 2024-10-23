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
public class Node<T> {
    T dato;
    Node<T> sig;
    
    public Node(T dato){
        this.dato = dato;
        this.sig = null;
    }

    public T getDato() {
        return this.dato;
    }
}