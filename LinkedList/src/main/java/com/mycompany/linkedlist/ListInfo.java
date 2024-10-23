/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.linkedlist;

/**
 *
 * @author mirok
 */
public class ListInfo {
    
    private ListNode head;
    
    public ListInfo(){
        head = null;
    }
    
    public void add(int numero){
        
        ListNode newNumber = new ListNode(numero);
        
        if(head == null){
            head = newNumber;
        }else{
            ListNode temp = head;
            while(temp.next != null){
                temp = temp.next;
            }
            temp.next = newNumber; 
        }
    }
    
    public void reverse(){
        ListNode previous = null;
        ListNode temp = head;
        ListNode next = null;
        
        while(temp != null){
            
            next = temp.next;
            temp.next = previous;
            previous = temp;
            temp = next;
        }
        head = previous;
        
        showList();
    }
    
    public void showList(){
        ListNode temp = head;
        
        while(temp != null){
            System.out.print(temp.numero + " -> ");
            temp = temp.next;
            
        }
    }
}
