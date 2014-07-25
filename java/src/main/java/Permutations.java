import java.util.ArrayList;
import java.util.List;

public class Permutations {
  public static void main(String[] args) {
    for (String s: getPermutations("abcd", "")) {
      System.out.println(s);
    }
  }

  public static List<String> getPermutations(String orig, String prefix) {
    ArrayList<String> permutations = new ArrayList<String>();
    for (int i = 0; i < orig.length(); i++) {
      char c = orig.charAt(i);
      // bug: this will be a problem if there are multiple copies of a digit
      if (prefix.indexOf(c) == -1) {
        // base case
        if (prefix.length() == orig.length()-1) {
          permutations.add(Character.toString(c));
        } else {
          for (String permutation: getPermutations(orig, prefix+orig.charAt(i))) {
            permutations.add(orig.charAt(i)+permutation);
          }
        }
      }
    }
    return permutations;
  }
}