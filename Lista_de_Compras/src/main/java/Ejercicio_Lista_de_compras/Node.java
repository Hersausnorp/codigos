/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Ejercicio_Lista_de_compras;

/**
 *
 * @author mirok
 */
public class Node {
    int taskId;
    String taskName;
    String status;
    Node next;
    
    public Node(int taskId, String taskName){
        this.taskId =taskId;
        this.taskName = taskName;
        this.status = "Pendiente";
        this.next = null;
    }
    
}
