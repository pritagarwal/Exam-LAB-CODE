
public class NQUEEn {
    public static void main(String [] args){
        boolean[][]arr = new boolean[4][4];
        System.out.println(place(arr,0));
    }

    public static int  place(boolean[][]arr,int r){
        if(r == arr.length)
        {
            display(arr);
            System.out.println();
            return 1;
        }
        int count =0;
        for(int i =0;i<arr.length;i++){

            if(safe(arr,r,i)){
                arr[r][i] = true;
                count +=place(arr,r+1);
                arr[r][i] = false;
            }

        }
            return count;
    }

    private static void display(boolean[][] arr) {

        for (boolean[] booleans : arr) {
            for (int j = 0; j < arr.length; j++) {
                if (booleans[j]) {
                    System.out.print("Q");
                } else
                    System.out.print("X");
            }
            System.out.println();
        }
    }

    private static boolean safe(boolean[][] arr, int r, int c) {
        //Checking column
        for(int i=0;i<r;i++){
            if(arr[i][c])
                return false;
        }
        //Checking right diagonal
        int end = Math.min(r,arr.length-1-c);
        for(int j = 1;j<=end;j++){
            if(arr[r-j][c+j])
                return false;
        }
        //Checking left diagonal
        int end2 = Math.min(r,c);
        for(int j = 1;j<=end2;j++){
            if(arr[r-j][c-j])
                return false;

        }
        return true;
    }
}