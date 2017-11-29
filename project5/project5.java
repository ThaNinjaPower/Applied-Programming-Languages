import java.util.*;
import java.io.*;

class HashReader {
	public HashSet<HashObject> hashSet;
	public HashObject[] hashObjects;
	public String[] hashStrings;
	
	private File f;
	
	HashReader(HashSet<HashObject> hashSet, File f) {
		this.hashSet = hashSet;
		this.f = f;
	}
	
	public void addHashObjects() {
		try {
			FileReader fr = new FileReader(f);
			BufferedReader br = new BufferedReader(fr);
		
			String line = br.readLine();
			hashStrings = line.split(" ");
		
			hashObjects = new HashObject[hashStrings.length];
		
			for (int i = 0; i < hashStrings.length; i++) {
				hashObjects[i] = new HashObject(hashStrings[i]);
				hashSet.add(hashObjects[i]);
			}
		}
		catch (Exception e) {
			System.out.println("File not found.");
			System.exit(0);
		}
	}
}

// Set is an interface so you must use extend operator
class HashObject extends HashSet {
	public String element;
	public int count = 1;
	
	// Constructor
	HashObject(String input) {
		element = input;
	}
	
	public String getElement() {
		return element;
	}
	
	public int getCount() {
		return count;
	}
	
	// Find appropriate base class to override that include the hashCode
	// and equals memeber functions
	public int hashCode() {
		return element.hashCode();
	}

	public boolean equals(Object input) {
		HashObject inputHash = (HashObject) input;
		if (element.equals(inputHash.element)) {
			inputHash.count++;
			return true;
		}
		else {
			return false;
		}
	}
}

public class project5 {
	public static void main(String[] args) {
		HashSet<HashObject> hashSet = new HashSet<HashObject>();
		File f = new File("input.txt");
		HashReader hr = new HashReader(hashSet, f);
		
		hr.addHashObjects();
		
		/*
		HashObject hashObject = new HashObject("Mary");
		hashSet.add(hashObject);
		
		HashObject hashObject1 = new HashObject("Thomas");
		hashSet.add(hashObject1);
		
		HashObject hashObject2 = new HashObject("Kevin");
		hashSet.add(hashObject2);
		
		HashObject hashObject4 = new HashObject("Mary");
		hashSet.add(hashObject4);*/
		
		// Iterate over the hash set
		Iterator<HashObject> iter = hashSet.iterator();
		
		HashObject hashObject;
		while (iter.hasNext()) {
			hashObject = iter.next();
			System.out.println(hashObject.getElement() + " " + hashObject.getCount());
		}
	}
}