import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.tree.*;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;

import static java.lang.Integer.parseInt;

public class unapprox{
    public static int numfor;
    public static int numdo;
    public static int numwhile;
    public static void main(String[] args) throws Exception {
        try{

            int[][] perFor;
            String fileout;

            // crear un analizador léxico que se alimenta a partir de la entrada (archivo  o consola)
            CLexer lexer;
            if (args.length>0) {
                try {
                    // crear un analizador léxico que se alimenta a partir de la entrada (archivo  o consola)
                    // CLexer lexer;

                    lexer = new CLexer(CharStreams.fromFileName(args[0]));

                    // Identificar al analizador léxico como fuente de tokens para el sintactico
                    CommonTokenStream tokens = new CommonTokenStream(lexer);
                    // Crear el analizador sintáctico que se alimenta a partir del buffer de tokens
                    CParser parser = new CParser(tokens);
                    ParseTree tree = parser.compilationUnit(); // comienza el análisis en la regla inicial
                    ParseTreeWalker walker = new ParseTreeWalker();
                    walker.walk(new itercount(), tree);

                    //  System.out.println(tree.toStringTree(parser)); // imprime el árbol en forma textual
                } catch (Exception e) {
                    System.err.println("Error (Test): " + e);
                }
                if (args.length > 1) {
                    if (args.length == 3) {
                        fileout = args[2];
                    } else {
                        fileout = "out.c";
                    }
                    lexer = new CLexer(CharStreams.fromFileName(args[0]));
                    String filecsv = args[1];
                    List<String> contentCSV = new ArrayList<>();
                    try (BufferedReader br = new BufferedReader(new FileReader(filecsv))) {
                        String line = "";
                        while ((line = br.readLine()) != null) {
                            String[] str = line.split(",");
                            contentCSV.addAll(Arrays.asList(str));
                        }
                      //  int lastFor = parseInt(contentCSV.get(contentCSV.size() - 3));

                        perFor = new int[numfor][2];
                        for (int i = 0; i < contentCSV.size(); i = i + 3) {
                            perFor[parseInt(contentCSV.get(i))][0] = parseInt(contentCSV.get(i + 1));
                            perFor[parseInt(contentCSV.get(i))][1] = parseInt(contentCSV.get(i + 2));
                        }

                      /*  for (int i = 0; i < perFor.length; i++) {

                            // Loop through all elements of current row
                            for (int j = 0; j < perFor[i].length; j++)
                                System.out.print(perFor[i][j] + " ");
                            System.out.println(" \n");
                        }*/


                        // Identificar al analizador léxico como fuente de tokens para el sintactico
                        CommonTokenStream tokens = new CommonTokenStream(lexer);
                        // Crear el analizador sintáctico que se alimenta a partir del buffer de tokens
                        CParser parser = new CParser(tokens);
                        ParseTree tree = parser.compilationUnit(); // comienza el análisis en la regla inicial
                        approxvisitor<Object> loader = new approxvisitor<Object>();
                        loader.receive_data(perFor, fileout);
                        loader.visit(tree);

                    } catch (Exception e) {
                        System.err.println("Error reading csv file: " + e);
                    }
                } else if (args.length == 1) {

                    System.out.println("Número de ciclos for:" + numfor);
                    System.out.println("Número de ciclos do:" + numdo);
                    System.out.println("Número de ciclos while:" + numwhile);
                }
            }
            else
                System.out.println("Usage: java -jar unapprox.jar sourceFile.c <forFile.csv>");
        } catch (Exception e){
            System.err.println("Error (Test): " + e);
        }
    }
}
