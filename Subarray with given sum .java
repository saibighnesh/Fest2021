import java.util.*;
import java.lang.*;
import java.io.*;

class Main{
	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        for (int i = 0; i < t; i++) {
            int n = sc.nextInt();
            int s = sc.nextInt();

            int[] m = new int[n];
            for (int j = 0; j < n; j++) {
                m[j] = sc.nextInt();
            }
            
            Solution obj = new Solution();
            ArrayList<Integer> res = obj.subarraySum(m, n, s);
            for(int ii = 0;ii<res.size();ii++)
                System.out.print(res.get(ii) + " ");
            System.out.println();
        }
    }

}// } Driver Code Ends


class Solution
{
    //Function to find a continuous sub-array which adds up to a given number.
    static ArrayList<Integer> subarraySum(int[] arr, int n, int s) 
    {
        // Your code here
        int start = 0;
        int currSum = arr[0];
        ArrayList<Integer> ret = new ArrayList<>();
        
        for(int i=1;i<=n;i++)
        {
            while(currSum > s && start < i-1)
            {
                currSum -= arr[start];
                start++;
            }
            
            if(currSum == s)
            {
                ret.add(start+1);
                ret.add(i);
                return ret;
            }
            
            if(i<n)
              currSum += arr[i];
            
        }
        
        ret.add(-1);
        return ret;
        
    }
}
