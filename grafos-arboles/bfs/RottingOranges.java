package grafos.bfs;

import java.util.LinkedList;
import java.util.Queue;

public class RottingOranges {
  public int rotting(int[][] cultivo){
    if (cultivo==null || cultivo.length==0){
      return 0;
    }
    int cantidadFrescas=0;
    Queue<int[]> cola=new LinkedList<>();
    for(int i=0;i<cultivo.length;i++){
      for(int j=0;j<cultivo[0].length;j++){
        if (cultivo[i][j]==2){
          cola.offer(new int[]{i,j});
        }else if(cultivo[i][j]==1){
          cantidadFrescas++;
        }
      }
    }
    if(cantidadFrescas==0){
      return 0;
    }
    int dias=0;
    int[][] direcciones={{1,0},{-1,0},{0,1},{0,-1}};
    while (!cola.isEmpty()){
      dias++;
      for (int i=0;i<cola.size();i++){
        int[] posicionActual=cola.poll();
        for (int direccion[]: direcciones){
          int y=direccion[1]+posicionActual[1];
          int x=direccion[0]+posicionActual[0];
          if(0<=x && x<cultivo.length && 0<=y && y<cultivo[0].length && cultivo[x][y]==1){
            cultivo[x][y]=2;
            cola.offer(new int[] {x,y});
            cantidadFrescas--;
          }
        }
      }
    }
    return cantidadFrescas==0?dias-1:-1;
  }
}
