
public class Solution {
	 public String convert(String s, int numRows) {
	        
		 String tempStr;
		 int length=s.length();
		 
		 if(numRows==1)
			 return s;
		 
		 tempStr=new String();
		 
		 for(int i=0;i<numRows;i++)
		 {
			 for(int j=i;j<length;j+=(2*(numRows-1)))
			 {
				 
				 tempStr+=s.substring(j, j+1);
				 if(i >0 && i<numRows-1 && (j+((numRows-i-1)*2)) < length)
				 {
					 tempStr+=s.substring(j+((numRows-i-1)*2), j+((numRows-i-1)*2)+1);
					 
				 }
			 }
		 }
		 return tempStr;
	    }
	 
	 public static void main(String args[]) 
	 {
		 Solution ss = new Solution();
		 String pattern="glzamzp";
		 String result = ss.convert(pattern, 3);
		 System.out.println(result);
	 }
}
