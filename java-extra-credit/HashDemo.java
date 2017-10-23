import java.util.*;

// Set is an interface so you must use extend operator
class HashObject extends HashSet {
	public String element;
	
	// Constructor
	HashObject(String input) {
		element = input;
	}
	
	// Find appropriate base class to override that include the hashCode
	// and equals memeber functions
	public int hashCode() {
		return element.hashCode();
	}	

	boolean equals(String inputParam) {
		if (element == inputParam) {
			return true;
		}
		else {
			return false;
		}
	}
}

public class HashDemo {
	public static void main(String[] args) {
		HashSet<HashObject> hashSet = new HashSet<HashObject>();
		HashObject hashObject = new HashObject("Mary");
		hashSet.add(hashObject);
		
		HashObject hashObject1 = new HashObject("Thomas");
		hashSet.add(hashObject1);
		
		HashObject hashObject2 = new HashObject("Kevin");
		hashSet.add(hashObject2);
		
		// Iterate over the hash set
		Iterator<HashObject> iter = hashSet.iterator();
		
		HashObject hashObject3;
		while (iter.hasNext()) {
			hashObject3 = iter.next();
			System.out.println("The current element is " + hashObject3.element);
		}
	}
}