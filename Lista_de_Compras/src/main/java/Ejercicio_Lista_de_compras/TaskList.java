/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Ejercicio_Lista_de_compras;

/**
 *
 * @author mirok
 */
public class TaskList {
    
    private Node head;
    
    public TaskList(){
        head = null;
    }

    //Metodo Añadir tarea
    public void addTask(int taskId, String taskName){
        
        Node newTask = new Node(taskId, taskName);
            
        if(head == null)
        {
            head = newTask;
        }else{
            Node temp = head;
            while(temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = newTask;
        }
        System.out.println("Tarea añadida");
    }
    
    public boolean removeTask(int taskId){
        if(head == null){
            return false;
        }
        
        if(head.taskId == taskId)
        {
            head = head.next;
            return true;
        }
        
        Node temp = head;
        while(temp.next != null && temp.next.taskId != taskId){
            temp = temp.next;
        }
        
        if(temp.next == null){ //no se encontro la tarea
            return false;
        }
        
        temp.next = temp.next.next; //Eliminamos la tarea
        return true;
    }
    
    // Metodo para marcar una tarea completa
    public boolean markAsCompleted(int taskId){
        Node temp = head;
        while(temp != null){
            if(temp.taskId == taskId){
                temp.status = "Completada";
                return true;
            }
            temp = temp.next;
        }
        return false;// no se encontro la tarea
    }
    
    //Metodo para mostrar las tareas
    public void displayAllTasks(){
        Node temp = head;
        if(temp == null){
            System.out.println("No hay tareas para mostrar");
            return;
        }
        while(temp != null){
            System.out.println("ID: " + temp.taskId + ", Nombre: " + temp.taskName + ", Estado: " + temp.status);
            temp = temp.next;
        }
    }
    
    //Metodo para mostrar solo las tareas pendientes
    public void displayPendingTasks(){
        Node temp = head;
        boolean found = false;
        while(temp != null){
            if(temp.status.equals("Pendiente")){
                System.out.println("ID: " + temp.taskId + ", Nombre: " + temp.taskName );
                found = true;
            }
            temp = temp.next;
        }
        if(!found){
            System.out.println("No hay tareas pendientes");
            
        }
    }
    
    //Metodo mostrar solo tareas completadas
    public void displayCompletedTasks(){
        Node temp = head;
        boolean found = false;
        while(temp != null){
            if(temp.status.equals("Completada")){
                System.out.println("ID: " + temp.taskId + ", Nombre: " + temp.taskName );
                found = true;
            }
            temp = temp.next;
        }
        if(!found)
        {
            System.out.println("No hay tareas completadas");
        }
    }
    
}

















