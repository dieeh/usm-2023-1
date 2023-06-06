package INF246.laboratorio3;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class multithreading {

    public static class Hebra extends Thread {
        public void Cuadrante_multithread() {

        }
    }

    public static void main(String[] args) {
        Integer matrix[][];
        Integer N = 1;
        Integer T = 1;
        String Mtrx;

        try {
            File textfile = new File("ubicacion-tesoro.txt");
            Scanner inputfile = new Scanner(textfile);
            N = inputfile.nextInt();
            T = inputfile.nextInt();
            Mtrx = inputfile.nextLine();
            inputfile.close();
        } catch (FileNotFoundException error) {
            System.out.println("Ocurrió un error leyendo el archivo.");
            error.printStackTrace();
            System.exit(1);
        }

        matrix = new Integer[N][N];

    }

}