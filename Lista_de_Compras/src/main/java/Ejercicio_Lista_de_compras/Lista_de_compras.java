/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package Ejercicio_Lista_de_compras;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
/**
 *
 * @author mirok
 */
public class Lista_de_compras {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        TaskList taskList = new TaskList();
        int op = 0;
        
        do {
            System.out.println("\n1. Agregar nueva tarea");
            System.out.println("2. Eliminar tarea");
            System.out.println("3. Marcar tarea como completada");
            System.out.println("4. Mostrar todas las tareas");
            System.out.println("5. Mostrar tareas pendientes");
            System.out.println("6. Mostrar tareas completadas");
            System.out.println("7. Salir");
            System.out.print("Seleccione una opcion: ");
            op = scanner.nextInt();

            switch (op) {
                case 1:
                    System.out.print("Ingrese ID de la tarea: ");
                    int id = scanner.nextInt();
                    scanner.nextLine(); // Consumir el salto de línea
                    System.out.print("Ingrese nombre de la tarea: ");
                    String name = scanner.nextLine();
                    taskList.addTask(id, name);
                    break;

                case 2:
                    System.out.print("Ingrese ID de la tarea a eliminar: ");
                    int idToRemove = scanner.nextInt();
                    if (taskList.removeTask(idToRemove)) {
                        System.out.println("Tarea eliminada.");
                    } else {
                        System.out.println("Tarea no encontrada.");
                    }
                    break;

                case 3:
                    System.out.print("Ingrese ID de la tarea a marcar como completada: ");
                    int idToComplete = scanner.nextInt();
                    if (taskList.markAsCompleted(idToComplete)) {
                        System.out.println("Tarea marcada como completada.");
                    } else {
                        System.out.println("Tarea no encontrada.");
                    }
                    break;

                case 4:
                    System.out.println("Todas las tareas:");
                    taskList.displayAllTasks();
                    break;

                case 5:
                    System.out.println("Tareas pendientes:");
                    taskList.displayPendingTasks();
                    break;

                case 6:
                    System.out.println("Tareas completadas:");
                    taskList.displayCompletedTasks();
                    break;

                case 7:
                    System.out.println("Saliendo...");
                    break;

                default:
                    System.out.println("Opción no válida.");
            }
        } while (op != 7);

        scanner.close();
    }
}

