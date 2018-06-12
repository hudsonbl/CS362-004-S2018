

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
public class UrlValidatorTest extends TestCase {
		
		public UrlValidatorTest(String testName) {
			super(testName);
		}
		
		public void testManualTest()
	   {
			String Scheme = "http";
			String Authority = "google.com";
			String Path = "/123";
			String Query = "?action=view";
			String Fragment  = "\0";
			String token = "f";
			String target = "g";
		
			long flag = 0;
		
			UrlValidator.isValidScheme(Scheme);
			UrlValidator.isValidAuthority(Authority);
			UrlValidator.isValidPath(Path);
			UrlValidator.isValidQuery(Query);
			UrlValidator.isValidFragment(Fragment);
			UrlValidator.countToken(string token, string target);
			UrlValidator.isOn(long flag);
	   	}
			 
		public void testYourFirstPartition()
		{
			String Scheme = "http";
			String Authority = "google.com";
		    String Path = "/123";
			String Query = "?action=view";
		    String Fragment  = "\0";
		    String token = "f";
		    String target = "g";
		
			long flag = 0;
		
			UrlValidator.isValidScheme(Scheme);
			UrlValidator.isValidAuthority(Authority);
			UrlValidator.isValidPath(Path);
			UrlValidator.isValidQuery(Query);
			UrlValidator.isValidFragment(Fragment);
		    UrlValidator.countToken(string token, string target);
		    UrlValidator.isOn(long flag);
		}
		
		public void testYourSecondPartition()
		{
		
			String Scheme = "hhtp";
			String Authority = "booble.coc";
			String Path = "123";
		    String Query = "action=view";
		    String Fragment  = "0";
		    String token = "f";
		    String target = "g";
		
			long flag = 0;
		
			UrlValidator.isValidScheme(Scheme);
			UrlValidator.isValidAuthority(Authority);
			UrlValidator.isValidPath(Path);
			UrlValidator.isValidQuery(Query);
			UrlValidator.isValidFragment(Fragment);
			UrlValidator.countToken(string token, string target);
			UrlValidator.isOn(long flag);
		
		}
		
		public void testIsValid()
		{
			do {
				StringBuilder testBuffer = new StringBuilder();
				boolean expected = true;
				for (int testPartsIndexIndex = 0; testPartsIndexIndex < testPartsIndex.length; ++testPartsIndexIndex) {
					int index = testPartsIndex[testPartsIndexIndex];
					ResultPair[] part = (ResultPair[]) testObjects[testPartsIndexIndex];
					testBuffer.append(part[index].item);
					expected &= part[index].valid;
				}
				String url = testBuffer.toString();
				boolean result = urlVal.isValid(url);
				if(result == true)
					System.out.println(url);
				assertEquals(url, expected, result);
	         	if (printStatus) {
	         		if (printIndex) {
	         			System.out.print(testPartsIndextoString());
	         		} else {
	            		if (result == expected) {
	                 		System.out.print('.');
	            		} else {
	            			System.out.print('X');
	            		}
	            	}
	         			printed++;
	            	if (printed == statusPerLine) {
	            		System.out.println();
	               		printed = 0;
	            	}
	         	}
				UrlValidator urlVal = new UrlValidator(null, null, allowAllSchemes);
			      //UrlValidator urlVal = new UrlValidator(null, allowAllSchemes);
				assertTrue(urlVal.isValid("http://www.google.com"));
				assertTrue(urlVal.isValid("http://www.google.com/"));
				int statusPerLine = 60;
				int printed = 0;
			} while (incrementTestPartsIndex(testPartsIndex, testObjects));
	      if (printStatus) {
	         System.out.println();
	      }
	   
		}
		
}

