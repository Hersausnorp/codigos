/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.valencia_andres_0222110032_taller5_colas_prioridad;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

/**
 *
 * @author Andres Valencia 0222110032
 */
public class Principal {

    public static void main(String[] args) {
        Cola<ProcesoCola> colaProceso = new Cola<>();
        
        //Lector del archivo plano
        try (BufferedReader br = new BufferedReader(new FileReader("src/lectura/procesos.txt"))) {
            String linea;
            while ((linea = br.readLine()) != null) {
               
                String[] partes = linea.split(";");
                String nombre = partes[0];
                int prioridad = Integer.parseInt(partes[1]);
                ProcesoCola proceso = new ProcesoCola(nombre, prioridad);

             
                colaProceso.encolar(new Nodo<>(proceso));
            }
        } catch (IOException e) {
            System.out.println("Error al leer el archivo: " + e.getMessage());
        }
        
        System.out.println("Orden de ejecución de los procesos:");
        while (!colaProceso.estaVacia()) {
            ProcesoCola proceso = colaProceso.decolar();
            System.out.println(proceso);
        }

    }
}
