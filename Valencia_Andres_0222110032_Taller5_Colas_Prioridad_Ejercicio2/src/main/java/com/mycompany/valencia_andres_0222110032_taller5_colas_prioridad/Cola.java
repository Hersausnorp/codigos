/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.valencia_andres_0222110032_taller5_colas_prioridad;

/**
 *
 * @author mirok
 */
public class Cola <T extends ProcesoCola>{
    Nodo<T> primero;
    Nodo<T> ultimo;
    int tamaño = 0;
    
    public Cola(){
        limpiar();
    }
    
    //Limpiar la cola
    private void limpiar(){
        primero = null;
        ultimo = null;
        tamaño = 0;
    }
    
    public boolean estaVacia(){
        if(tamaño == 0){
            return true;
        }else{
            return false;
        }
    }
    
     public T decolar(){
        T aux = null;
        if (!estaVacia()) {
            aux = primero.getDato();
            primero = primero.next;
            tamaño--;
        } else {
            System.out.println("La Cola está vacía");
        }
        return aux;
    }
    
      public boolean encolar(Nodo<T> nuevoNodo){
        if (estaVacia()) {
            primero = nuevoNodo;
            ultimo = nuevoNodo;
        } else {
           
            Nodo<T> actual = primero;
            Nodo<T> anterior = null;

            while (actual != null && actual.getDato().getllegada()>= nuevoNodo.getDato().getllegada()) {
                anterior = actual;
                actual = actual.next;
            }

            if (anterior == null) {
                // Insertar al inicio
                nuevoNodo.next = primero;
                primero = nuevoNodo;
            } else if (actual == null) {
                // Insertar al final
                anterior.next = nuevoNodo;
                ultimo = nuevoNodo;
            } else {
                // Insertar en el medio
                anterior.next = nuevoNodo;
                nuevoNodo.next = actual;
            }
        }
        tamaño++;
        return true;
    }
     
}
