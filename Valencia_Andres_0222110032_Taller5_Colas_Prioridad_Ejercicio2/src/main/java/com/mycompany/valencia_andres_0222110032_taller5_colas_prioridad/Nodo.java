/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.valencia_andres_0222110032_taller5_colas_prioridad;

/**
 *
 * @author mirok
 */
public class Nodo<T> {
	T dato;
	Nodo<T> next;
	public Nodo(T dato){
		this.dato=dato;
		this.next=null;
	}
	public Nodo(T dato, Nodo<T> sig){
		this.dato=dato;
		this.next=sig;
	}
	public T getDato(){
		return this.dato;
	}
}