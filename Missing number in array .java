// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            String[] str = br.readLine().trim().split(" ");
            int[] array = new int[n - 1];
            for (int i = 0; i < n - 1; i++) {
                array[i] = Integer.parseInt(str[i]);
            }
            Solution sln = new Solution();
            System.out.println(sln.MissingNumber(array, n));
        }
    }
}// } Driver Code Ends


// User function Template for Java

class Solution {
    int MissingNumber(int array[], int n) {
        // Your Code Here
        Arrays.sort(array); //sort the array
        int num=1;  // keep a number counter
        
        int i;
        
        for(i=0; i<array.length; i++){
            if(array[i] != num){
                return num; // return missing number
            }
            num++;
        }
        
        // edge case
        if(i != n){
            return n;  // return last number, not present in array
        }
        
        return 0;
    
    }
}
