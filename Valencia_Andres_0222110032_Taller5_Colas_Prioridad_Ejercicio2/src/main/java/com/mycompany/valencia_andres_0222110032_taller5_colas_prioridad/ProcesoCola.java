/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.valencia_andres_0222110032_taller5_colas_prioridad;

/**
 *
 * @author mirok
 */
public class ProcesoCola {
     String proceso;
    int llegada;
    
    public ProcesoCola(String proceso, int llegada){
        this.proceso = proceso;
        this.llegada = llegada;
        
    }
    
    public String getproceso(){
        return proceso;
    }
    
    public int getllegada(){
        return llegada;
    }
    
    @Override
    public String toString() {
        return proceso + ";" + llegada;
    }
}
