import java.util.ArrayList;
import java.util.Iterator;

import org.antlr.v4.runtime.Token;

public class itercount extends CBaseListener{
    int countfor=0;
    int countdo=0;
    int countwhile=0;

    ArrayList<Integer> forlines = new ArrayList<Integer>();
    ArrayList<Integer> dolines = new ArrayList<Integer>();
    ArrayList<Integer> whilelines = new ArrayList<Integer>();


    @Override
    public void enterIterationStatement(CParser.IterationStatementContext ctx) {
        Token firstToken = ctx.getStart();
        int line = firstToken.getLine();
        if (ctx.For()!= null) forlines.add(line);
        else if (ctx.Do()!=null) dolines.add(line);
        else whilelines.add(line);
        countfor=forlines.size();
        countdo=dolines.size();
        countwhile=whilelines.size();

    }

    private void elsif(boolean b) {
    }

    @Override
    public void exitCompilationUnit(CParser.CompilationUnitContext ctx) {
        //System.out.println("Número de ciclos for:"+ countfor);
        Iterator<Integer> Iterfor = forlines.iterator();
        Iterator<Integer> Iterdo = dolines.iterator();
        Iterator<Integer> Iterwhile = whilelines.iterator();
        //while(Iterfor.hasNext()) System.out.print(Iterfor.next()+"cc ");
        //System.out.println("\nNúmero de ciclos do:"+ countdo);
        //while(Iterdo.hasNext()) System.out.print(Iterdo.next()+" ");
        //System.out.println("\nNúmero de ciclos while:"+ countwhile);
        //while(Iterwhile.hasNext()) System.out.print(Iterwhile.next()+" ");
        unapprox.numfor=countfor;
        unapprox.numdo=countdo;
        unapprox.numwhile=countwhile;
    }

}
