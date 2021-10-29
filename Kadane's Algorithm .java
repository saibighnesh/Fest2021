import java.io.*;

class Main {
    
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine().trim()); //Inputting the testcases
		while(t-->0){
		    //size of array
		    int n = Integer.parseInt(br.readLine().trim());
		    int arr[] = new int[n];
		    String inputLine[] = br.readLine().trim().split(" ");
		    
		    //adding elements
		    for(int i=0; i<n; i++){
		        arr[i] = Integer.parseInt(inputLine[i]);
		    }
		    
		    Solution obj = new Solution();
		    
		    //calling maxSubarraySum() function
		    System.out.println(obj.maxSubarraySum(arr, n));
		}
	}
}

// } Driver Code Ends

class Solution{
    //Function to find the sum of contiguous subarray with maximum sum.
    long maxSubarraySum(int arr[], int n){
        
        long maxh = 0, maxf = arr[0];
        
        //Iterating over the array.
	    for(int i=0; i<n; i++){
	        
	        //Updating max sum till current index.
	        maxh+=arr[i];
	        //Storing max sum so far by choosing maximum between max 
            //sum so far and max sum till current index.
	        if(maxf<maxh)
                maxf=maxh; 
	        
	        //If max sum till current index is negative, we do not need to add
            //it to result so we update it to zero.
	        if(maxh<0)
	            maxh=0;

        }
         //returning the result.   
        return maxf;
    }
    
}
