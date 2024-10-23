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
public class Stack <T>{
	Node<T> primerNodo;
	int tamaño = 0;
	
	public Stack(){
		limpiar();
	}

	public void limpiar(){
		primerNodo = null;
		tamaño = 0;
	}

	public boolean estaVacia(){
		if (tamaño == 0)
			return true;
		else
			return false;
	}

	public boolean push(T dato) {
        Node<T> nuevoNodo = new Node<>(dato);
        if (estaVacia()) {
            primerNodo = nuevoNodo;
        } else {
            nuevoNodo.sig = primerNodo;
            primerNodo = nuevoNodo;
        }
        tamaño = tamaño + 1;
        return true;
    }

	public T pop(){
		if (!estaVacia()) {
            T dato = primerNodo.getDato();
            primerNodo = primerNodo.sig;
            tamaño = tamaño - 1;
            return dato;
        } else {
            System.out.println("La Pila está vacía");
            return null;
            }
	}

	public T peek(){
		if(!estaVacia())
			return primerNodo.getDato();
		else
			System.out.println("La Pila está vacía");
            return null;
	}
        
        public int getTamaño(){
            return tamaño;
        }
}